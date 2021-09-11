#include "prob2_drv.h"
#include <stdlib.h>
#include <time.h>

void com_device_driver::prc_driver(){
	srand (time(NULL));
	sc_bv<12> storage;
	storage = 0;
	
	d_reset = 0;
	wait(7, SC_NS);
	d_reset = 1;
	


	while(1){
		if (d_clear == 1)
			d_clear = 0;
		
		//type 1
		if (rand() % 6 == 0)
			storage.range(11,8) = 0;
		else
			storage.range(11,8) = 1;
		
		//payload
		storage.range(7,4) = rand() % 16;
		
		//parity bit
		storage[0] = rand() % 2;
		
		//random clears
		if (rand() % 8 == 0){
			d_clear = 1;
		}
		
		d_inData = storage;
		wait(10, SC_NS);
	}

}
