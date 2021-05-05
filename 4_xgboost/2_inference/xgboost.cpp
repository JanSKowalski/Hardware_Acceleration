#define INPUT_DATA_SIZE 2000
#define OUTPUT_DATA_SIZE 500

// Auto-generated kernel. Code will look a bit ugly due to improper indentation. 

extern "C" {
void xgboost(	const double* input_values,
		double* output_values){
          		
	double vin_buffer[INPUT_DATA_SIZE];
	double vout_buffer[OUTPUT_DATA_SIZE];

	double tree0[OUTPUT_DATA_SIZE] = {0};
	double tree1[OUTPUT_DATA_SIZE] = {0};
	double tree2[OUTPUT_DATA_SIZE] = {0};

	read_1:
	for (int j = 0; j < INPUT_DATA_SIZE; j++) {
#pragma HLS loop_tripcount min=600 max=600
		vin_buffer[j] = input_values[j];
	}
	
	inference_1:
	for(int j=0; j < OUTPUT_DATA_SIZE; j++){
#pragma HLS loop_tripcount min=150 max=150

	
	
	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] += 0.430622011;
	}
	else{
		tree0[j] += -0.220048919;
	}	
	
	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree1[j] += -0.215311036;
	}
	else{
			
	if (*(vin_buffer + 4*j + 3) < 1.75){
		tree1[j] += 0.372000009;
	}
	else{
		tree1[j] += -0.200518161;
	}	

	}	
	
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
			
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree2[j] += -0.219899267;
	}
	else{
		tree2[j] += 0.217241377;
	}	

	}
	else{
		tree2[j] += 0.402985066;
	}	


	double max_value = 0.0;
	if (tree0[j] > max_value){
		vout_buffer[j] = (double) 0;
		max_value = tree0[j];
	}
	if (tree1[j] > max_value){
		vout_buffer[j] = (double) 1;
		max_value = tree1[j];
	}
	if (tree2[j] > max_value){
		vout_buffer[j] = (double) 2;
		max_value = tree2[j];
	}
	
	}


	write_1:
	for (int j = 0; j < OUTPUT_DATA_SIZE; j++) {
#pragma HLS loop_tripcount min=150 max=150
		output_values[j] = vout_buffer[j];
	}
}
}
