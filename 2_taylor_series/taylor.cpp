//Jan S Kowalski 4/4/21
//Taylor series approx.

#define BUFFER_SIZE 1024
#define DATA_SIZE 4096

const unsigned int c_len = DATA_SIZE / BUFFER_SIZE;
const unsigned int c_size = BUFFER_SIZE;

extern "C" {


//given the parameters for a third-order taylor series, return the approximation.
//the function being approximated is determined by the value of the weights
void taylor(	const double* input,
			const double* weight,	//assumed to only have a bias and three weights (four terms total)
         		double* output,
          		int size        	){


	double x2[BUFFER_SIZE]; //x**2
	double x3[BUFFER_SIZE]; //x**3

	double vin_buffer[BUFFER_SIZE];
	double vout_buffer[BUFFER_SIZE];

	#pragma HLS DATAFLOW

    	for (int i = 0; i < size; i += BUFFER_SIZE) {
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
		taylor:
		for(int j=0; j < chunk_size; j++){
			#pragma HLS LOOP_TRIPCOUNT min = c_size max = c_size
			#pragma HLS PIPELINE II = 1
			x2[j] = vin_buffer[j] * vin_buffer[j];
			x3[j] = x2[j] * vin_buffer[j];
			vout_buffer[j] = weight[0] + weight[1]*vin_buffer[j] + weight[2]*x2[j] + weight[3]*x3[j];
		}

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
