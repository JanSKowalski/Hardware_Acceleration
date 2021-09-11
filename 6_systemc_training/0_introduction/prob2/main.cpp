#include "prob2_mod.h"
#include "prob2_drv.h"

int sc_main(int argc, char* argv[]){
	sc_core::sc_report_handler::set_actions("/IEEE_Std_1666/deprecated", sc_core::SC_DO_NOTHING);
	sc_signal<bool> t_reset, t_clear;
	sc_clock t_clock("clk", 10, SC_NS, 0.5, 2.5, SC_NS, false);
	sc_signal<sc_bv<12> > t_inData;
	sc_signal<sc_bv<4> > t_payload;
	sc_signal<sc_uint<8> > t_count, t_error;
	
	com_device c1("c1");
	com_device_driver d1("d1");
	
	sc_trace_file *tfile = sc_create_vcd_trace_file("com_device");
	c1 << t_clock << t_reset << t_clear << t_inData << t_payload << t_count << t_error;
	
	d1(t_reset, t_clear, t_inData);
	
	sc_trace(tfile, t_clock, "t_clock");
	sc_trace(tfile, t_reset, "t_reset");
	sc_trace(tfile, t_clear, "t_clear");
	sc_trace(tfile, t_inData, "t_data_in");
	sc_trace(tfile, t_payload, "t_payload");
	sc_trace(tfile, t_count, "t_count");
	sc_trace(tfile, t_error, "t_error");
	
	sc_start(200, SC_NS);
	sc_close_vcd_trace_file(tfile);
	return(0);
}
