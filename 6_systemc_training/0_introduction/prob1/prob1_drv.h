#include "systemc.h"

SC_MODULE(prob1_drv){
	sc_out<bool> d_reset, d_clear, d_data_in;
	
	void prc_prob1_drv();
	
	SC_CTOR(prob1_drv){
		SC_THREAD(prc_prob1_drv);
	}
};
