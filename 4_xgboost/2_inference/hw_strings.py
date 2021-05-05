#top of hardware
header = '''
// Auto-generated kernel. Code will look a bit ugly due to improper indentation. 

extern "C" {
void xgboost(	const double* input_values,
		double* output_values){
          		
	double vin_buffer[INPUT_DATA_SIZE];
	double vout_buffer[OUTPUT_DATA_SIZE];
'''


tree_buffer = '''
	double tree^index^[OUTPUT_DATA_SIZE] = {0};'''


read_in = '''

	read_1:
	for (int j = 0; j < INPUT_DATA_SIZE; j++) {
#pragma HLS loop_tripcount min=600 max=600
		vin_buffer[j] = input_values[j];
	}
	
	inference_1:
	for(int j=0; j < OUTPUT_DATA_SIZE; j++){
#pragma HLS loop_tripcount min=150 max=150

	
'''


split = '''	
	if (*(vin_buffer + ^num_features^*j + ^a^) < ^b^){
		^option_1^
	}
	else{
		^option_2^
	}	
'''

leaf = "tree^index^[j] += ^a^;"


classification_logic = '''if (tree^index^[j] > max_value){
		vout_buffer[j] = (double) ^index^;
		max_value = tree^index^[j];
	}
	^class_logic^'''

write_out = '''
	}


	write_1:
	for (int j = 0; j < OUTPUT_DATA_SIZE; j++) {
#pragma HLS loop_tripcount min=150 max=150
		output_values[j] = vout_buffer[j];
	}
}
}
'''
