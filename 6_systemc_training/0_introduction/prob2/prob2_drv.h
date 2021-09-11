#include "systemc.h"

SC_MODULE(com_device_driver){
	sc_out<bool> d_reset, d_clear;
	sc_out<sc_bv<12> > d_inData;
	void prc_driver();
	SC_CTOR(com_device_driver){
		SC_THREAD(prc_driver);
	}
};
