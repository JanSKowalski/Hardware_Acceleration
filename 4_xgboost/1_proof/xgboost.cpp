//Jan S Kowalski 5/1/21
//XGBoost hardware

#define BUFFER_SIZE 150
#define DATA_SIZE 150

const unsigned int c_len = DATA_SIZE / BUFFER_SIZE;
const unsigned int c_size = BUFFER_SIZE;

//input_values and output_values are expected to be of different sizes
//specifically, four input values (features) for every output
extern "C" {
void xgboost(	const double* input_values,
			const double* weights,	
         		double* output_values,
          		int size        	){

		double vin_buffer[4*BUFFER_SIZE];
		double tree1[BUFFER_SIZE];
		double tree2[BUFFER_SIZE];
		double tree3[BUFFER_SIZE];
		double vout_buffer[BUFFER_SIZE];

		int index;

		read1:
			for (int j = 0; j < 4*BUFFER_SIZE; j++) {
#pragma HLS loop_tripcount min=600 max=600

				vin_buffer[j] = input_values[j];

			}

			//software check is a file with expected prediction from this tree


			//18 weights
			// splits are 0-9
			//leaves are 10-17

			//the first value in a split tuple is the index of the feature being compared

			inference_1:
			for(int j=0; j < BUFFER_SIZE; j++){
#pragma HLS loop_flatten
#pragma HLS loop_tripcount min=150 max=150
				//tree 1
				if (*(vin_buffer + 4*j + (int) weights[0]) < weights[1])
					tree1[j] = weights[10];
				else
					tree1[j] = weights[11];

				//tree 2
				if (*(vin_buffer + 4*j + (int) weights[2]) < weights[3])
					tree2[j] = weights[12];
				else{
					if (*(vin_buffer + 4*j + (int) weights[4]) < weights[5])
						tree2[j] = weights[13];
					else
						tree2[j] = weights[14];
				}

				//tree 3
				if (*(vin_buffer + 4*j + (int) weights[6]) < weights[7]){
					if (*(vin_buffer + 4*j + (int) weights[8]) < weights[9])
						tree3[j] = weights[15];
					else
						tree3[j] = weights[16];
				}
				else
					tree3[j] = weights[17];

				//determine prediction
				if(tree1[j] > tree2[j]){
					if(tree1[j] > tree3[j])
						vout_buffer[j] = 0;
					else
						vout_buffer[j] = 2;
				} else{
					if(tree2[j] > tree3[j])
						vout_buffer[j] = 1;
					else
						vout_buffer[j] = 2;
				}
			}

			// burst write the result
			write:
			for (int j = 0; j < BUFFER_SIZE; j++) {
#pragma HLS loop_tripcount min=150 max=150
				output_values[j] = vout_buffer[j];
			}
		}
}
