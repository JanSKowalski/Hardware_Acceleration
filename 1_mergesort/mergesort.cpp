/**
* Copyright (C) 2020 Xilinx, Inc
*
* Licensed under the Apache License, Version 2.0 (the "License"). You may
* not use this file except in compliance with the License. A copy of the
* License is located at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
* WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
* License for the specific language governing permissions and limitations
* under the License.
*/


//Modified to mergesort bitonic hardware
// https://en.wikipedia.org/wiki/Bitonic_sorter
//Jan S Kowalski 3/8/21

#define BUFFER_SIZE 1024
#define DATA_SIZE 4096
#define KERNEL_PRECISION 8	//2, 4 or 8

const unsigned int c_len = DATA_SIZE / BUFFER_SIZE;
const unsigned int c_size = BUFFER_SIZE;

extern "C" {

void compare_2(int, int, unsigned int*, unsigned int*);

//compare every pair of numbers, rearrange as necessary
void mergesort(	const unsigned int* input,
         		unsigned int* output,
          		int size        	){


	unsigned int vin_buffer[BUFFER_SIZE];
	unsigned int vout_buffer[BUFFER_SIZE];

//#if KERNEL_PRECISION==4 || KERNEL_PRECISION==8
	unsigned int intermediate_a[BUFFER_SIZE];
	unsigned int intermediate_b[BUFFER_SIZE];
//#endif
//#if KERNEL_PRECISION==8
	unsigned int intermediate_c[BUFFER_SIZE];
	unsigned int intermediate_d[BUFFER_SIZE];
	unsigned int intermediate_e[BUFFER_SIZE];
//#endif



    	for (int i = 0; i < size; i += BUFFER_SIZE) {
#pragma HLS LOOP_TRIPCOUNT min = c_len max = c_len
		int chunk_size = BUFFER_SIZE;

	        // not sure
		if ((i + BUFFER_SIZE) > size) chunk_size = size - i;

	read1:
		for (int j = 0; j < chunk_size; j++) {
	#pragma HLS LOOP_TRIPCOUNT min = c_size max = c_size
	#pragma HLS PIPELINE II = 1
		            vin_buffer[j] = input[i + j];
		        }
//Every pair of inputs is ordered correctly
#if KERNEL_PRECISION==2
	mergesort_2:
		for(int j=0; j < chunk_size; j+=2){
	#pragma HLS LOOP_TRIPCOUNT min = c_size max = c_size
	#pragma HLS PIPELINE II = 1
	#pragma HLS inline recursive
			compare_2(j, j+1, vin_buffer, vout_buffer);
		}
#endif


//Every group of four inputs is ordered correctly
#if KERNEL_PRECISION==4
	mergesort_4:
		for(int j=0; j < chunk_size; j+=4){
	#pragma HLS LOOP_TRIPCOUNT min = c_size max = c_size
	#pragma HLS PIPELINE II = 1
	#pragma HLS inline recursive
			//layer 1
			compare_2(j, j+1, vin_buffer, intermediate_a);
			compare_2(j+3, j+2, vin_buffer, intermediate_a);
			//layer 2
			compare_2(j, j+2, intermediate_a, intermediate_b);
			compare_2(j+1, j+3, intermediate_a, intermediate_b);
			//layer 3
			compare_2(j, j+1, intermediate_b, vout_buffer);
			compare_2(j+2, j+3, intermediate_b, vout_buffer);
		}
#endif

//Every group of eight inputs is ordered correctly
#if KERNEL_PRECISION==8

	mergesort_8:
		for(int j=0; j < chunk_size; j+=8){
	#pragma HLS LOOP_TRIPCOUNT min = c_size max = c_size
	#pragma HLS PIPELINE II = 1
	#pragma HLS inline recursive
			//layer 1
			compare_2(j, j+1, vin_buffer, intermediate_a);
			compare_2(j+3, j+2, vin_buffer, intermediate_a);
			compare_2(j+4, j+5, vin_buffer, intermediate_a);
			compare_2(j+7, j+6, vin_buffer, intermediate_a);
			//layer 2
			compare_2(j, j+2, intermediate_a, intermediate_b);
			compare_2(j+1, j+3, intermediate_a, intermediate_b);
			compare_2(j+7, j+5, intermediate_a, intermediate_b);
			compare_2(j+6, j+4, intermediate_a, intermediate_b);
			//layer 3
			compare_2(j, j+1, intermediate_b, intermediate_c);
			compare_2(j+2, j+3, intermediate_b, intermediate_c);
			compare_2(j+7, j+6, intermediate_b, intermediate_c);
			compare_2(j+5, j+4, intermediate_b, intermediate_c);
			//layer 4
			compare_2(j, j+4, intermediate_c, intermediate_d);
			compare_2(j+1, j+5, intermediate_c, intermediate_d);
			compare_2(j+2, j+6, intermediate_c, intermediate_d);
			compare_2(j+3, j+7, intermediate_c, intermediate_d);
			//layer 5
			compare_2(j, j+2, intermediate_d, intermediate_e);
			compare_2(j+1, j+3, intermediate_d, intermediate_e);
			compare_2(j+4, j+6, intermediate_d, intermediate_e);
			compare_2(j+5, j+7, intermediate_d, intermediate_e);
			//layer 6
			compare_2(j, j+1, intermediate_e, vout_buffer);
			compare_2(j+2, j+3, intermediate_e, vout_buffer);
			compare_2(j+4, j+5, intermediate_e, vout_buffer);
			compare_2(j+6, j+7, intermediate_e, vout_buffer);

		}
#endif

	// burst write the result
	write:
 		for (int j = 0; j < chunk_size; j++) {
	#pragma HLS LOOP_TRIPCOUNT min = c_size max = c_size
	#pragma HLS PIPELINE II = 1
			output[i + j] = vout_buffer[j];
		}
	}
}

//if input_1 greater than input_2, switch. Otherwise stay the same
void compare_2(int index_1, int index_2, unsigned int* input_array, unsigned int* output_array){
	if(input_array[index_1] > input_array[index_2]){
		output_array[index_1] = input_array[index_2];
		output_array[index_2] = input_array[index_1];
	}
	else{
		output_array[index_1] = input_array[index_1];
		output_array[index_2] = input_array[index_2];
	}
}
}
