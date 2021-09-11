#include "systemc.h"

SC_MODULE (com_device){
	sc_in<bool> clock;
	sc_in<bool> reset;
	sc_in<bool> clear;
	sc_in<sc_bv<12> > inData;
	sc_out<sc_bv<4> > payload;
	sc_out<sc_uint<8> > count;
	sc_out<sc_uint<8> > error;
	
	sc_bv<4> r_payload;
	sc_uint<8> r_count;
	sc_uint<8> r_error;
	
	void prc_com_device();
	
	SC_CTOR (com_device){
		SC_METHOD(prc_com_device);
		sensitive << clock.pos() << reset.neg() << clear.pos();
	}
};
