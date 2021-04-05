//Jan S Kowalski 4/4/21
//Taylor series approx.

#define BUFFER_SIZE 1024
#define DATA_SIZE 4096
#define NUM_WEIGHTS 4

const unsigned int c_len = DATA_SIZE / BUFFER_SIZE;
const unsigned int c_size = BUFFER_SIZE;

extern "C" {


//given the parameters for a third-order taylor series, return the approximation.
//the function being approximated is determined by the value of the weights
void taylor(	const double* input,
			const double* weight,	//assumed to only have a bias and three weights (four terms total)
         		double* output,
          		int size        	){



	double vin_buffer[BUFFER_SIZE];
	//double intermediate_a[BUFFER_SIZE];
	//double intermediate_b[BUFFER_SIZE];
	//double intermediate_c[BUFFER_SIZE];
	double vout_buffer[BUFFER_SIZE];

    	for (int i = 0; i < size; i += BUFFER_SIZE) {
		//#pragma HLS Loop_merge
		#pragma HLS LOOP_TRIPCOUNT min = c_len max = c_len
		int chunk_size = BUFFER_SIZE;

		if ((i + BUFFER_SIZE) > size) chunk_size = size - i;

		read1:
		for (int j = 0; j < chunk_size; j++) {
			#pragma HLS LOOP_TRIPCOUNT min = c_size max = c_size
			#pragma HLS PIPELINE II = 1
		            vin_buffer[j] = input[i + j];
		        }


		//w[0] + w[1]x + w[2]x**2 + w[3]x**3
		taylor_1:
		for(int j=0; j < chunk_size; j++){
			#pragma HLS PIPELINE II = 1
			#pragma HLS LOOP_TRIPCOUNT min = c_size max = c_size
			#pragma HLS unroll factor=16
			vout_buffer[j] = weight[0] + weight[1]*vin_buffer[j] + weight[2]*vin_buffer[j]*vin_buffer[j] + weight[3]*vin_buffer[j]*vin_buffer[j]*vin_buffer[j];

		}


			//Implementations with higher latencies
			/*
			//https://github.com/Xilinx/HLS-Tiny-Tutorials/blob/master/memory_bottleneck_resolved/mem_bottleneck_resolved.cpp
			intermediate_a[j] = weight[1]*vin_buffer[j];
			intermediate_b[j] = weight[2]*vin_buffer[j]*vin_buffer[j];
			intermediate_c[j] = weight[3]*vin_buffer[j]*vin_buffer[j]*vin_buffer[j];
			vout_buffer[j] = weight[0] + intermediate_a[j] + intermediate_b[j] + intermediate_c[j];
			*/
			/*
			vout_buffer[j] = weight[0];
			inner_loop:
			for(int k=1; k< 4; k++){
				#pragma HLS loop_flatten
				vout_buffer[j] += weight[k]*vin_buffer[j];
				vin_buffer[j] *= vin_buffer[j];
			}
			*/
/*
#pragma HLS DATAFLOW
		//taylor_2
		i_a:
		for(int j=0; j < chunk_size; j++){
			#pragma HLS PIPELINE II = 1
			#pragma HLS LOOP_TRIPCOUNT min = c_size max = c_size

			intermediate_a[j] = weight[1]*vin_buffer[j];
		}
		i_b:
		for(int j=0; j < chunk_size; j++){
			#pragma HLS PIPELINE II = 1
			#pragma HLS LOOP_TRIPCOUNT min = c_size max = c_size
			intermediate_b[j] = weight[2]*vin_buffer[j]*vin_buffer[j];
		}
		i_c:
		for(int j=0; j < chunk_size; j++){
			#pragma HLS PIPELINE II = 1
			#pragma HLS LOOP_TRIPCOUNT min = c_size max = c_size
			intermediate_c[j] = weight[3]*vin_buffer[j]*vin_buffer[j]*vin_buffer[j];
		}
		final_result:
		for(int j=0; j < chunk_size; j++){
			#pragma HLS PIPELINE II = 1
			#pragma HLS LOOP_TRIPCOUNT min = c_size max = c_size
			vout_buffer[j] = weight[0] + intermediate_a[j] + intermediate_b[j] + intermediate_c[j];
		}

*/


		// burst write the result
		write:
 		for (int j = 0; j < chunk_size; j++) {
			#pragma HLS LOOP_TRIPCOUNT min = c_size max = c_size
			#pragma HLS PIPELINE II = 1
			output[i + j] = vout_buffer[j];
		}
	}
}
}
