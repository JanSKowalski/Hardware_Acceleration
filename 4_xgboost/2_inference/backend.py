# https://stackoverflow.com/questions/50175901/how-to-extract-decision-rules-features-splits-from-xgboost-model-in-python3
import re
import os
import hw_strings

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
	
	
#right now limited to input/output with type double
def generate_classification_hardware(model):
	
	#I need to know:
	#	The number and type of inputs  (model.n_features_in_)
	#	The number and type of outputs (1 output
	#	The number of classes
	#
	
	#Open file
	try:
		hw_file = open("test_hardware.cpp", "w")
	except IOError as exception:
		raise RuntimeError('Failed to open hardware file') from exception
	
	
	buffer_size = 500
	
	line = "#define INPUT_DATA_SIZE " + str(model.n_features_in_ * buffer_size) + "\n"
	hw_file.write(line)
	line = "#define OUTPUT_DATA_SIZE " + str(buffer_size) + "\n"
	hw_file.write(line)
	
	hw_file.write(hw_strings.header)
	for num in range(0,model.n_classes_):
		hw_file.write(hw_strings.tree_buffer.replace("^index^", str(num)))
	hw_file.write(hw_strings.read_in)
	
	
	

	#Extract structure info from model
	intermediate_file = 'xgb_model.txt'
	model.get_booster().dump_model(intermediate_file, with_stats=True)
	try:
		xgb_model = open(intermediate_file, 'r') 
	except IOError as exception:
		raise RuntimeError('Failed to model file') from exception
	
	txt_model = xgb_model.read()
	xgb_model.seek(0)
	
	# extract all patterns like "[f2<2.45]" or "leaf=0.3421"
	#unformatted_weights = re.findall('\[f([0-9]+)|<([0-9]+.[0-9]+)\]|leaf=(\-?[0-9]+.[0-9]+)', txt_model)
	unformatted_weights = re.findall('\[f([0-9]+)|<([0-9]+.[0-9]+)\]|leaf=(\-?[0-9]+[.0-9]*)', txt_model)

	weight_values = []
	for weight in unformatted_weights:
		if(weight[0]):
			weight_values.append(weight[0])
		elif(weight[1]):
			weight_values.append(weight[1])
		elif(weight[2]):
			weight_values.append(weight[2])
		else:
			raise Exception("Regex did not parse xgb_model.txt correctly, null detected")

	
	current_class = 0
	weight_index = 0
	lines = xgb_model.readlines()
	tree = ""

	xgb_model.close()
	
	#allow a tree to be a single leaf

	for line in lines:
		#check if new tree
		if(re.search("booster", line)):
			#write tree to file, clear
			hw_file.write(tree)
			tree = ""
			#determine which class the current tree contributes to
			tree_number = int(re.search(r'[0-9]+', line).group(0))
			current_class = tree_number % model.n_classes_
			continue
		#write splits
		if(re.search("gain", line)):
			split = hw_strings.tree_structure
			split = split.replace("^num_features^", str(model.n_features_in_))
			split = split.replace("^a^", str(weight_values[weight_index]))
			weight_index += 1
			split = split.replace("^b^", str(weight_values[weight_index]))
			weight_index += 1
			
			if (tree == ""):
				tree = split
				continue
			
			
			try_1 = re.subn('\^option_1\^', split, tree, 1)
			if (try_1[1]):
				tree = try_1[0]
				continue
			else:
				try_2 = re.subn('\^option_2\^', split, tree, 1)
				if (try_2[1]):
					tree = try_2[0]
					continue
				else:
					raise Exception("Tree structure is somehow unexpected")

		#write leaves
		if(re.search("leaf", line)):
			leaf = hw_strings.leaf
			leaf = leaf.replace("^a^", str(weight_values[weight_index]))
			weight_index += 1
			leaf = leaf.replace("^index^", str(current_class))
			
			if (tree == ""):
				tree = leaf
				continue
				
			try_1 = re.subn('\^option_1\^', leaf, tree, 1)
			if (try_1[1]):
				tree = try_1[0]
				continue
			else:
				try_2 = re.subn('\^option_2\^', leaf, tree, 1)
				if (try_2[1]):
					tree = try_2[0]
					continue
				else:
					raise Exception("Tree structure is somehow unexpected")


	hw_file.write(tree)
	hw_file.write(hw_strings.write_out)
	
	hw_file.close()


























