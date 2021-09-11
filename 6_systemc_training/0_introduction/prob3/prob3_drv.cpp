#include "prob3_drv.h"
#include <stdlib.h>
#include <time.h>

void prob3_driver::prc_driver(){
	srand (time(NULL));
	sc_uint<8> num1, num2, num3;
	sc_bv<4> storage;
	
	d_reset = 0;
	wait(7, SC_NS);
	d_reset = 1;
	
	//in3 given as constant
	num3 = 12;
	

	while(1){
		if (d_clear == 1)
			d_clear = 0;
		
		num1 = rand() % 256;
		num2 = rand() % 255;

		//random clears
		if (rand() % 8 == 0){
			d_clear = 1;
		}
		
		storage = 0;
		
		//random control signals

		if (rand() % 2 == 0)
			storage[0] = 1;
		if (rand() % 3 == 0)
			storage[1] = 1;
		if (rand() % 4 == 0)
			storage[2] = 1;
		if (rand() % 5 == 0)
			storage[3] = 1;
			
		d_in1 = num1;
		d_in2 = num2;
		d_load1 = storage[0].to_bool();
		d_load2 = storage[1].to_bool();
		d_dec1 = storage[2].to_bool();
		d_dec2 = storage[3].to_bool();
		wait(10, SC_NS);
	}

}
