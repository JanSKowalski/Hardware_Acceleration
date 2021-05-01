# https://stackoverflow.com/questions/50175901/how-to-extract-decision-rules-features-splits-from-xgboost-model-in-python3
import re
import os

# write both split and leaf information to files for host.cc to read
def extract_information(model):

	# XGBClassifier wrapper blocks access to json from save_model, so we parse the text rep.
	intermediate_file = 'xgb_model.txt'
	model.get_booster().dump_model(intermediate_file, with_stats=True)

	
	# read the contents of the file
	with open(intermediate_file, 'r') as f:
    		txt_model = f.read()
    	
	# extract all patterns like "[f2<2.45]" into tuples (feature, threshold)
	splits = re.findall('\[f([0-9]+)<([0-9]+.[0-9]+)\]', txt_model)

	# extract all patterns like "leaf=0.3421"
	leaves = re.findall('leaf=(\-?[0-9]+.[0-9]+)', txt_model)

	# clean up
	f.close()
	#os.remove(intermediate_file)
	
	
	f = open("extracted.data", "w")

	#write out split information
	f.write("#### splits len: " + str(len(splits)) + " ####\n")
	for split in splits:
		line = split[0]+'\n'
		f.write(line)
		line = split[1]+'\n'
		f.write(line)

		
	#write out leaf information
	f.write("#### leaves len: " + str(len(leaves)) + " ####\n")
	for leaf in leaves:
		line = leaf + '\n'
		f.write(line)
	
	f.close()
	
def export_inputs_and_outputs(inputs, model_prediction):

	#write out model inputs
	f = open("inputs.data", "w")
	for data in inputs:
		line = str(data)+'\n'
		f.write(line)
	f.close()

	#write out expected predictions
	f = open("expected_results.data", "w")
	for result in model_prediction:
		line = str(result)+'\n'
		f.write(line)
	f.close()
	
