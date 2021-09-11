#include "systemc.h"

SC_MODULE (seq_detector){
	sc_in<bool> clock;
	sc_in<bool> reset;
	sc_in<bool> clear;
	sc_in<bool> data_in;
	sc_out<bool> data_out;
	
	sc_uint<4> internal_regs;
	
	void prc_seq_detector();
	
	SC_CTOR (seq_detector){
		SC_METHOD(prc_seq_detector);
		sensitive << clock.pos() << reset.neg() << clear.pos();	
	}
};
