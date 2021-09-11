#include "systemc.h"

SC_MODULE (count_device){
	sc_in<bool> clock, reset, clear;
	sc_in<sc_uint<8> > in1, in2, in3;
	sc_in<bool> load1, load2, dec1, dec2;
	sc_out<sc_uint<8> > count1, count2;
	sc_out<bool> ended;
	
	
	sc_uint<9> counter1, counter2;
	sc_bit r_ended, r_overflow;
	
	void prc_prob3();
	
	SC_CTOR (count_device){
		SC_METHOD(prc_prob3);
		sensitive << clock.pos() << reset.neg() << clear.pos();
	}
};
