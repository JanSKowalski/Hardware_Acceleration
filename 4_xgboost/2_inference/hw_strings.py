#top of hardware
header = '''

extern "C" {
void xgboost(	const double* input_values,
		double* output_values){
          		
	double vin_buffer[INPUT_DATA_SIZE];
	double vout_buffer[OUTPUT_DATA_SIZE];
'''


tree_buffer = '''
	double tree^index^[OUTPUT_DATA_SIZE] = 0;'''


read_in = '''

	read_1:
	for (int j = 0; j < INPUT_DATA_SIZE; j++) {
#pragma HLS loop_tripcount min=INPUT_DATA_SIZE max=INPUT_DATA_SIZE
		vin_buffer[j] = input_values[j];
	}
	
	inference_1:
	for(int j=0; j < OUTPUT_DATA_SIZE; j++){
#pragma HLS loop_tripcount min=OUTPUT_DATA_SIZE max=OUTPUT_DATA_SIZE

	
'''


tree_structure = '''
	if (*(vin_buffer + ^num_features^*j + ^a^) < ^b^){
		^option_1^
	}
	else{
		^option_2^
	}
	
'''

leaf = "tree^index^[j] = ^a^;"


write_out = '''
	}


	write_1:
	for (int j = 0; j < OUTPUT_DATA_SIZE; j++) {
#pragma HLS loop_tripcount min=OUTPUT_DATA_SIZE max=OUTPUT_DATA_SIZE
		output_values[j] = vout_buffer[j];
	}
}
}
'''
