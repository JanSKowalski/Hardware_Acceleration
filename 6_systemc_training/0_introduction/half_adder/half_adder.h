#include "systemc.h"

SC_MODULE(half_adder){
	sc_in<bool> a;
	sc_in<bool> b;
	sc_out<bool> sum;
	sc_out<bool> carry;
	
	void prc_half_adder();
	
	SC_CTOR(half_adder){
		SC_METHOD(prc_half_adder);
		sensitive << a << b;
	}
};
