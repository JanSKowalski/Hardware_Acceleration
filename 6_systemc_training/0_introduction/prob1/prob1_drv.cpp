#include "prob1_drv.h"
#include <stdlib.h>
#include <time.h>

void prob1_drv::prc_prob1_drv(){
	srand (time(NULL));
	sc_uint<2> storage;
	storage = 0;
	
	d_reset = 0;
	wait(7, SC_NS);
	d_reset = 1;

	while(1){
		storage[0] = rand() % 2;
		if (rand() % 20 == 0)
			storage[1] = 1;
			wait(5, SC_NS);
			storage[1] = 0;
		d_data_in = storage[0];
		d_clear = storage[1];
		wait(5, SC_NS);
	}

}
