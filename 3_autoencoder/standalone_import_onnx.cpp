#include <assert.h>
#include <vector>
#include </home/jan/Github_repos/ONNXRuntime/onnxruntime-linux-x64-1.4.0/include/onnxruntime_cxx_api.h>

//Largely based on the following file
// https://github.com/microsoft/onnxruntime/blob/master/csharp/test/Microsoft.ML.OnnxRuntime.EndToEndTests.Capi/CXX_Api_Sample.cpp

//To run
//g++ -L/home/jan/Github_repos/ONNXRuntime/onnxruntime-linux-x64-1.4.0/lib -o standalone_import_onnx.out standalone_import_onnx.cpp -lonnxruntime


// Read in a model in ONNX format, perform inference on it to double check.
// In this case, I am testing an autoencoder with one input/output
int main(int argc, char* argv[]) {

	// initialize  enviroment...one enviroment per process
	// enviroment maintains thread pools and other state info
	Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "test");

	// initialize session options if needed
	Ort::SessionOptions session_options;
	session_options.SetIntraOpNumThreads(1);

	// Sets graph optimization level
	// Available levels are
	// ORT_DISABLE_ALL -> To disable all optimizations
	// ORT_ENABLE_BASIC -> To enable basic optimizations (Such as redundant node removals)
	// ORT_ENABLE_EXTENDED -> To enable extended optimizations (Includes level 1 + more complex optimizations like node fusions)
	// ORT_ENABLE_ALL -> To Enable All possible opitmizations
	session_options.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_EXTENDED);

	//*************************************************************************
	// create session and load model into memory

	const char* model_path = "/home/jan/Xilinx/Vitis_hls/u200_dev/basic_inference/src/pytorch/autoencoder.onnx";

	printf("Using Onnxruntime C++ API\n");
	Ort::Session session(env, model_path, session_options);

	//*************************************************************************

	// print model input layer (node names, types, shape etc.)
	Ort::AllocatorWithDefaultOptions allocator;

	// print number of model input nodes
	size_t num_input_nodes = session.GetInputCount();
	std::vector<const char*> input_node_names(num_input_nodes);
	std::vector<int64_t> input_node_dims;

	printf("Number of inputs = %zu\n", num_input_nodes);

	// iterate over all input nodes
	for (int i = 0; i < num_input_nodes; i++) {
		// print input node names
		char* input_name = session.GetInputName(i, allocator);
		printf("Input %d : name=%s\n", i, input_name);
		input_node_names[i] = input_name;

		// print input node types
		Ort::TypeInfo type_info = session.GetInputTypeInfo(i);
		auto tensor_info = type_info.GetTensorTypeAndShapeInfo();

		ONNXTensorElementDataType type = tensor_info.GetElementType();
		printf("Input %d : type=%d\n", i, type);

		// print input shapes/dims
		input_node_dims = tensor_info.GetShape();
		printf("Input %d : num_dims=%zu\n", i, input_node_dims.size());
		for (int j = 0; j < input_node_dims.size(); j++)
			printf("Input %d : dim %d=%jd\n", i, j, input_node_dims[j]);
	}


	//*************************************************************************
	// Similar operations to get output node information.
	// Use OrtSessionGetOutputCount(), OrtSessionGetOutputName()
	// OrtSessionGetOutputTypeInfo() as shown above.
	//*************************************************************************

	// Run data through model to check weights

	// Might be a way to use OrtGetTensorShapeElementCount()
	size_t input_tensor_size = 1 ;
  	std::vector<float> input_tensor_values(input_tensor_size);

	//Specific to the ONNX model, I used https://netron.app/ to figure out the name of the output node
	//OrtSessionGetOutputName() might work as well
	std::vector<const char*> output_node_names = {"15"};

  	// create input tensor object from data values
  	auto memory_info = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);


	for (unsigned int i = 0; i < 29; i++){
    		//Initialize input to random value
    		input_tensor_values[0] = (float) rand() / (RAND_MAX);

		//Prepare inputs for inference
  		Ort::Value input_tensor = Ort::Value::CreateTensor<float>(memory_info, input_tensor_values.data(), input_tensor_size, input_node_dims.data(), 1);
  		assert(input_tensor.IsTensor());

		//Get output values
  		auto output_tensors = session.Run(Ort::RunOptions{nullptr}, input_node_names.data(), &input_tensor, 1, output_node_names.data(), 1);
  		assert(output_tensors.size() == 1 && output_tensors.front().IsTensor());

  		//Convert output to printf readable format (as float)
  		float* floatarr = output_tensors.front().GetTensorMutableData<float>();
		printf("Score for input [%f] =  %f\n", input_tensor_values[0], floatarr[0]);
	}

	printf("Done!\n");
	return 0;
}
