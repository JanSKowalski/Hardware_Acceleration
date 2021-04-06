//Jan S Kowalski 4/4/21
//Taylor series approx.

#include "taylor.hpp"

#define BUFFER_SIZE 1024
#define DATA_SIZE 4096
#define NUM_WEIGHTS 4

const unsigned int c_len = DATA_SIZE / BUFFER_SIZE;
const unsigned int c_size = BUFFER_SIZE;

extern "C" {
//given the parameters for a third-order taylor series, return the approximation.
//the function being approximated is determined by the value of the weights
void taylor(	const qdouble* input_values,
				const qdouble* weight,	//assumed to only have a bias and three weights (four terms total)
         		qdouble* output_values,
          		int size        	){


		qdouble vin_buffer[BUFFER_SIZE];
		qdouble vout_buffer[BUFFER_SIZE];

		main_buffer_access:
    	for (int i = 0; i < size; i += BUFFER_SIZE) {


			#pragma HLS LOOP_TRIPCOUNT min = c_len max = c_len
			int chunk_size = BUFFER_SIZE;

			if ((i + BUFFER_SIZE) > size) chunk_size = size - i;

			read1:
			for (int j = 0; j < chunk_size; j++) {
				#pragma HLS LOOP_TRIPCOUNT min = c_size max = c_size
				#pragma HLS PIPELINE II = 1 rewind
						vin_buffer[j] = input_values[i + j];
			}


			//w[0] + w[1]x + w[2]x**2 + w[3]x**3
			taylor_1:
			for(int j=0; j < chunk_size; j++){
				#pragma HLS PIPELINE II = 1
				#pragma HLS LOOP_TRIPCOUNT min = c_size max = c_size
				#pragma HLS unroll factor=16
				vout_buffer[j] = weight[0] + weight[1]*vin_buffer[j] + weight[2]*vin_buffer[j]*vin_buffer[j] + weight[3]*vin_buffer[j]*vin_buffer[j]*vin_buffer[j];

			}

			// burst write the result
			write:
			for (int j = 0; j < chunk_size; j++) {
				#pragma HLS LOOP_TRIPCOUNT min = c_size max = c_size
				#pragma HLS PIPELINE II = 1 rewind
				output_values[i + j] = vout_buffer[j];
			}
		}
	}
}
