#include "xcl2.hpp"
#include <algorithm>
#include <vector>
#include <time.h>
#include <math.h>
#include <string>
#include <iostream>
#include <fstream> 



#define DATA_SIZE 150
#define NUM_WEIGHTS 18
#define INPUTS_PATH "src/data/inputs.data"
#define EXPECTED_PATH "src/data/expected_outputs.data"



int main(int argc, char** argv) {

	std::cout<< "Running program" <<std::endl;


	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <XCLBIN File>" << std::endl;
		return EXIT_FAILURE;
	}

	//******************* Declare variables ******************************

	std::string binaryFile = argv[1];
	size_t vector_data_size_bytes = sizeof(double) * DATA_SIZE * 4;
	size_t vector_results_size_bytes = sizeof(double) * DATA_SIZE;

	std::vector<double, aligned_allocator<double> > initial_values(4*DATA_SIZE);
	std::vector<double, aligned_allocator<double> > source_hw_results(DATA_SIZE);
	std::vector<double, aligned_allocator<double> > source_sw_results(DATA_SIZE);

	cl_int err;
	cl::Kernel krnl_taylor;
	cl::CommandQueue q;
	cl::Context context;

	//******************* Read in data from files ***************************

	std::string input_buffer;
	
	//inputs
	std::ifstream input_data_file(INPUTS_PATH);
	if(!input_data_file.is_open()){
		std::cout<< "Unable to open input data file" <<std::endl;
		return EXIT_FAILURE;	
	}
	int i=0;
	while (getline (input_data_file, input_buffer)) {
		sscanf(input_buffer.c_str(),"[%lf %lf %lf %lf]", &initial_values[i], &initial_values[i+1], &initial_values[i+2], &initial_values[i+3]);
		i = i+4;
	}
	input_data_file.close(); 


	//expected outputs
	std::ifstream expected_output_file(EXPECTED_PATH);
	if(!expected_output_file.is_open()){
		std::cout<< "Unable to open expected output file" <<std::endl;
		return EXIT_FAILURE;	
	}
	i=0;
	while (getline (expected_output_file, input_buffer)) {
		source_sw_results[i] = std::stod(input_buffer);
		i++;
	}
	expected_output_file.close(); 

	for (int i = 0; i < DATA_SIZE; i++) {
		source_hw_results[i] = (double) 0;
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
			OCL_CHECK(err, krnl_taylor = cl::Kernel(program, "xgboost", &err));
			valid_device = true;
			break;
		}
	}
	if (!valid_device) {
		std::cout << "Failed to program any device found, exit!\n";
		exit(EXIT_FAILURE);
	}


	//************************  Inteface with kernel ********************

	OCL_CHECK(err, cl::Buffer buffer_input(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, vector_data_size_bytes, initial_values.data(), &err));
	OCL_CHECK(err, cl::Buffer buffer_output(context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY, vector_results_size_bytes, source_hw_results.data(), &err));

	//send arguments to hls function
	OCL_CHECK(err, err = krnl_taylor.setArg(0, buffer_input));
	OCL_CHECK(err, err = krnl_taylor.setArg(1, buffer_output));

	//send data to hls function
	OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_input}, 0));
	//run function
	OCL_CHECK(err, err = q.enqueueTask(krnl_taylor));
	//load results
	OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_output}, CL_MIGRATE_MEM_OBJECT_HOST));
	q.finish();




	//************************  Check results ****************************

	std::cout << "Checking xgboost hardware"<< std::endl;;
	

	bool match = true;
	for (int i = 0; i < DATA_SIZE; i++) {
		//determine if hardware performed correctly		
		if (source_hw_results[i] != source_sw_results[i]) {
			std::cout << "Error: Result mismatch" << std::endl;
			std::cout << "i = " << i << " CPU result = " << source_sw_results[i] << " Device result = " << source_hw_results[i] << std::endl;
			std::cout << "Input causing error: " << initial_values[4*i] << ", " << initial_values[4*i+1] << ", " << initial_values[4*i+2] << ", " << initial_values[4*i+3] << std::endl;
			match = false;
			//break;
		}
	}

	std::cout << "TEST " << (match ? "PASSED" : "FAILED") << std::endl;
	return (match ? EXIT_SUCCESS : EXIT_FAILURE);
}



