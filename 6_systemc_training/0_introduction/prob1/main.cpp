#include "prob1_mod.h"
#include "prob1_drv.h"

int sc_main(int argc, char* argv[]){
	sc_core::sc_report_handler::set_actions( "/IEEE_Std_1666/deprecated", sc_core::SC_DO_NOTHING );
	sc_signal<bool> t_reset, t_clear, t_data_in, t_data_out;
	sc_clock t_clock("clk", 10, SC_NS, 0.5, 2.5, SC_NS, false);
	
	seq_detector s1("s1");
	prob1_drv d1("d1");
	
	sc_trace_file *tfile = sc_create_vcd_trace_file("seq_detector");
	
	s1 << t_clock << t_reset << t_clear << t_data_in << t_data_out;
	
	d1.d_reset(t_reset);
	d1.d_clear(t_clear);
	d1.d_data_in(t_data_in);
	
	
	sc_trace(tfile, t_clock, "t_clock");
	sc_trace(tfile, t_reset, "t_reset");
	sc_trace(tfile, t_clear, "t_clear");
	sc_trace(tfile, t_data_in, "t_data_in");
	sc_trace(tfile, t_data_out, "t_data_out");
	
	sc_start(100, SC_NS);
	sc_close_vcd_trace_file(tfile);
	
	return(0);
}
