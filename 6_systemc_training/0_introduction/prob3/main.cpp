#include "prob3_mod.h"
#include "prob3_drv.h"

int sc_main(int argc, char* argv[]){
	sc_core::sc_report_handler::set_actions("/IEEE_Std_1666/deprecated", sc_core::SC_DO_NOTHING);
	sc_signal<bool> t_reset, t_clear;
	sc_clock t_clock("clk", 10, SC_NS, 0.5, 2.5, SC_NS, false);
	sc_signal<sc_uint<8> > t_in1, t_in2, t_in3;
	sc_signal<bool> t_load1, t_load2, t_dec1, t_dec2, t_ended;
	sc_signal<sc_uint<8> > t_count1, t_count2;
	
	count_device c1("c1");
	prob3_driver d1("d1");
	
	sc_trace_file *tfile = sc_create_vcd_trace_file("count_device");
	c1 << t_clock << t_reset << t_clear <<t_in1 << t_in2 << t_in3 << t_load1 << t_load2 << t_dec1 << t_dec2 << t_count1 << t_count2 << t_ended;
	
	d1(t_reset, t_clear, t_in1, t_in2, t_in3, t_load1, t_load2, t_dec1, t_dec2);
	
	sc_trace(tfile, t_clock, "t_clock");
	sc_trace(tfile, t_reset, "t_reset");
	sc_trace(tfile, t_clear, "t_clear");
	sc_trace(tfile, t_in1, "t_in1");
	sc_trace(tfile, t_in2, "t_in2");
	sc_trace(tfile, t_in3, "t_in3");
	sc_trace(tfile, t_load1, "t_load1");
	sc_trace(tfile, t_load2, "t_load2");
	sc_trace(tfile, t_in2, "t_dec1");
	sc_trace(tfile, t_in3, "t_dec2");
	sc_trace(tfile, t_count1, "t_count1");
	sc_trace(tfile, t_count2, "t_count2");
	sc_trace(tfile, t_ended, "t_ended");
	
	sc_start(500, SC_NS);
	sc_close_vcd_trace_file(tfile);
	return(0);
}
