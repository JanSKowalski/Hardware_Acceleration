/**
* Copyright (C) 2020 Xilinx, Inc
*
* Licensed under the Apache License, Version 2.0 (the "License"). You may
* not use this file except in compliance with the License. A copy of the
* License is located at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
* WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
* License for the specific language governing permissions and limitations
* under the License.
*/

#include "xcl2.hpp"
#include <algorithm>
#include <vector>
#include <time.h>

//Make sure this information matches the kernel!
#define DATA_SIZE 4096
#define KERNEL_PRECISION 8	//2, 4 or 8

//void mergesort(int, int, void*);
void mergesort(int, int, std::vector<int, aligned_allocator<int>>&);

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <XCLBIN File>" << std::endl;
		return EXIT_FAILURE;
	}

	clock_t start, end;

	//start timer
	start = clock();

	//******************* Declare variables ******************************

	std::string binaryFile = argv[1];
	size_t vector_size_bytes = sizeof(int) * DATA_SIZE;

	std::vector<int, aligned_allocator<int> > source_values(DATA_SIZE);
	std::vector<int, aligned_allocator<int> > source_hw_results(DATA_SIZE);
	std::vector<int, aligned_allocator<int> > source_sw_results(DATA_SIZE);

	cl_int err;
	cl::Kernel krnl_mergesort;
	cl::CommandQueue q;
	cl::Context context;

	//******************* Generate data ******************************

	std::generate(source_values.begin(), source_values.end(), std::rand);

	for (int i = 0; i < DATA_SIZE; i++) {
		source_sw_results[i] = source_values[i];
		source_hw_results[i] = 0;
	}

	std::sort(source_sw_results.begin(), source_sw_results.end());


//	for (int i = 0; i < DATA_SIZE; i+=2) {
//		if (source_sw_results[i] > source_sw_results[i+1]){
//			source_sw_results[i] = source_values[i+1];
//			source_sw_results[i+1] = source_values[i];
//		}
//	}

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
			OCL_CHECK(err, krnl_mergesort = cl::Kernel(program, "mergesort", &err));
			valid_device = true;
			break;
		}
	}
	if (!valid_device) {
		std::cout << "Failed to program any device found, exit!\n";
		exit(EXIT_FAILURE);
	}


	//************************  Inteface with kernel ********************

	OCL_CHECK(err, cl::Buffer buffer_input(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, vector_size_bytes, source_values.data(), &err));
	OCL_CHECK(err, cl::Buffer buffer_output(context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY, vector_size_bytes, source_hw_results.data(), &err));

	//send arguments to hls function
	int size = DATA_SIZE;
	OCL_CHECK(err, err = krnl_mergesort.setArg(0, buffer_input));
	OCL_CHECK(err, err = krnl_mergesort.setArg(1, buffer_output));
	OCL_CHECK(err, err = krnl_mergesort.setArg(2, size));

	//send data to hls function
	OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_input}, 0));
	//run function
	OCL_CHECK(err, err = q.enqueueTask(krnl_mergesort));
	//load results
	OCL_CHECK(err, err = q.enqueueMigrateMemObjects({buffer_output}, CL_MIGRATE_MEM_OBJECT_HOST));
	q.finish();

	//************************  Run mergesort ****************************


	//assumes DATA_SIZE is a multiple of 2
	mergesort(0, DATA_SIZE-1, source_hw_results);


	//************************  Check results ****************************

	std::cout << "Ran " << KERNEL_PRECISION << "-wise bitonic mergesort" << std::endl;
	bool match = true;
	for (int i = 0; i < DATA_SIZE; i++) {
		if (source_hw_results[i] != source_sw_results[i]) {
			std::cout << "Error: Result mismatch" << std::endl;
			std::cout << "i = " << i << " CPU result = " << source_sw_results[i]
			      << " Device result = " << source_hw_results[i] << std::endl;
			match = false;
			break;
		}
	}

	//stop timer
	end = clock();
	printf("Runtime: %.04f\n", (double)(end-start)/CLOCKS_PER_SEC);


	std::cout << "TEST " << (match ? "PASSED" : "FAILED") << std::endl;
	return (match ? EXIT_SUCCESS : EXIT_FAILURE);
}

//run mergesort with a partially sorted list
//arguments: first accessable index, last accessable index, pointer to array
	//assumes DATA_SIZE is a multiple of 2
//void mergesort(int begin, int end, void* array){
void mergesort(int begin, int end, std::vector<int, aligned_allocator<int>>& array){

	//kernel should have sorted n-wise groups
	if(end-begin<KERNEL_PRECISION) return;

	mergesort(begin, begin+(end-begin)/2, array);
	mergesort(begin+(end-begin)/2+1, end, array);


	//sort the rest
	int i, j, a, b, start_of_b;
	a=begin;
	b=begin+(end-begin)/2+1;
	start_of_b = b;

	int sorted[end-begin+1];

	int a_saturated = 0;
	int b_saturated = 0;

	//sort subarray
	for(i=0; i<end-begin+1; i++){

		if (a_saturated) {sorted[i] = array[b++]; continue;}
		if (b_saturated) {sorted[i] = array[a++]; continue;}

		sorted[i] = (array[a] > array[b]) ? array[b++] : array[a++];

		if (a >= start_of_b) a_saturated=1;
		if (b > end) b_saturated=1;
	}

	i=0;
	//replace original with sorted
	for(j=begin; j<end+1; j++){
		array[j] = sorted[i++];
	}

}

