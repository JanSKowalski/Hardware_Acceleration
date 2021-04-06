#include "xcl2.hpp"
#include <algorithm>
#include <vector>
#include <time.h>
#include <math.h>
#include <string>
#include <iostream>
#include <fstream> 

#include "taylor.hpp"

#define PI 3.14159265
#define DATA_SIZE 4096
#define NUM_WEIGHTS 4
#define WEIGHT_FILE_PATH "src/weights.data"

//Threshold with quantization (14 bits, 3 for whole num)
#define ERROR_THRESHOLD 0.005 //14b threshold
//#define ERROR_THRESHOLD 0.02 //10b threshold

//Threshold without quantization
//#define ERROR_THRESHOLD 0.00001

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <XCLBIN File>" << std::endl;
		return EXIT_FAILURE;
	}

	//******************* Declare variables ******************************

	std::string binaryFile = argv[1];
	size_t vector_data_size_bytes = sizeof(qdouble) * DATA_SIZE;
	size_t vector_weights_size_bytes = sizeof(qdouble) * NUM_WEIGHTS;

	std::vector<double, aligned_allocator<double> > initial_values(DATA_SIZE);
	std::vector<qdouble, aligned_allocator<qdouble> > quantized_values(DATA_SIZE);
	std::vector<double, aligned_allocator<double> > initial_weights(NUM_WEIGHTS);
	std::vector<qdouble, aligned_allocator<qdouble> > quantized_weights(NUM_WEIGHTS);
	std::vector<qdouble, aligned_allocator<qdouble> > source_hw_results(DATA_SIZE);
	std::vector<qdouble, aligned_allocator<qdouble> > source_sw_results(DATA_SIZE);

	cl_int err;
	cl::Kernel krnl_taylor;
	cl::CommandQueue q;
	cl::Context context;

	//******************* Read in weights ******************************

	std::string input_buffer;

	std::ifstream weight_file(WEIGHT_FILE_PATH);
	if(!weight_file.is_open()){
		std::cout<< "Unable to open weight file" <<std::endl;
		return EXIT_FAILURE;	
	}
	int i=0;
	while (getline (weight_file, input_buffer)) {
		initial_weights[i] = std::stod(input_buffer);
		quantized_weights[i] = (qdouble) initial_weights[i];
		i++;
	}
	weight_file.close(); 
	
	//******************* Generate data ********************************

	//std::generate(source_values.begin(), source_values.end(), std::rand);

	for (int i = 0; i < DATA_SIZE; i++) {
		initial_values[i] = ((double) rand() / (RAND_MAX))*2*PI - PI;
		quantized_values[i] = (qdouble) initial_values[i];
		//w[0] + w[1]x + w[2]x**2 + w[3]x**3
		double squared = initial_values[i]*initial_values[i];
		double cubed = squared*initial_values[i];
		source_sw_results[i] =  (qdouble) (initial_weights[0] + initial_weights[1]*initial_values[i] + initial_weights[2]*squared + initial_weights[3]*cubed);
		source_hw_results[i] = (qdouble) 0;
	}

	//******************* Try to access platform ************************

	auto devices = xcl::get_xil_devices();
	auto fileBuf = xcl::read_binary_file(binaryFile);
	cl::Program::Binaries bins{{fileBuf.data(), fileBuf.size()}};
	bool valid_device = false;
	for (unsigned int i = 0; i < devices.size(); i++) {
		auto device = devices[i];
		OCL_CHECK(err, context = cl::Context(device, NULL, NULL, NULL, &err));
		OCL_CHECK(err, q = cl::CommandQueue(context, device, CL_QUEUE_PROFILING_ENABLE, &err));
		std::cout << "Trying to program device[" << i << "]: " << device.getInfo<CL_DEVICE_NAME>() << std::endl;
		cl::Program program(context, {device}, bins, NULL, &err);
		if (err != CL_SUCCESS) {
			std::cout << "Failed to program device[" << i << "] with xclbin file!\n";
		} else {
			std::cout << "Device[" << i << "]: program successful!\n";
			OCL_CHECK(err, krnl_taylor = cl::Kernel(program, "taylor", &err));
			valid_device = true;
			break;
		}
	}
	if (!valid_device) {
		std::cout << "Failed to program any device found, exit!\n";
		exit(EXIT_FAILURE);
	}


	//************************  Inteface with kernel ********************

	OCL_CHECK(err, cl::Buffer buffer_input(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, vector_data_size_bytes, quantized_values.data(), &err));
	OCL_CHECK(err, cl::Buffer buffer_weights(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, vector_weights_size_bytes, quantized_weights.data(), &err));
	OCL_CHECK(err, cl::Buffer buffer_output(context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY, vector_data_size_bytes, source_hw_results.data(), &err));

	//send arguments to hls function
	int size = DATA_SIZE;
	OCL_CHECK(err, err = krnl_taylor.setArg(0, buffer_input));
	OCL_CHECK(err, err = krnl_taylor.setArg(1, buffer_weights));
	OCL_CHECK(err, err = krnl_taylor.setArg(2, buffer_output));
	OCL_CHECK(err, err = krnl_taylor.setArg(3, size));

	//send data to hls function
	OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_input}, 0));
	OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_weights}, 0));
	//run function
	OCL_CHECK(err, err = q.enqueueTask(krnl_taylor));
	//load results
	OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_output}, CL_MIGRATE_MEM_OBJECT_HOST));
	q.finish();


	//************************  Check results ****************************

	std::cout << "Checking taylor series approximation"<< std::endl;;

	bool match = true;
	qdouble approx_error, actual_sin_value, difference;
	double sum_of_differences = 0;
	for (int i = 0; i < DATA_SIZE; i++) {
		//record how well the weights predict sin(x)
		actual_sin_value = (qdouble) sin(initial_values[i]);
		approx_error = (source_hw_results[i] > actual_sin_value) ? source_hw_results[i] - actual_sin_value :  actual_sin_value - source_hw_results[i];
		sum_of_differences += (double) approx_error;
		
		//determine if hardware performed correctly		
		difference = (source_hw_results[i] > source_sw_results[i]) ? source_hw_results[i] - source_sw_results[i] :  source_sw_results[i] - source_hw_results[i];
		if (difference > ERROR_THRESHOLD) {
			std::cout << "Error: Result mismatch" << std::endl;
			std::cout << "i = " << i << " CPU result = " << source_sw_results[i] << " Device result = " << source_hw_results[i] << std::endl;
			std::cout << "Input causing error: " << quantized_values[i] << std::endl;
			match = false;
			//break;
		}
	}

	std::cout << "Average error in taylor approx: " << sum_of_differences / DATA_SIZE << std::endl;

	std::cout << "TEST " << (match ? "PASSED" : "FAILED") << std::endl;
	return (match ? EXIT_SUCCESS : EXIT_FAILURE);
}



