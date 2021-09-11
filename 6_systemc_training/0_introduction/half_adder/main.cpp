#include "driver.h"
#include "monitor.h"
#include "full_adder.h"

int sc_main(int argc, char* argv[]){
	sc_core::sc_report_handler::set_actions( "/IEEE_Std_1666/deprecated", sc_core::SC_DO_NOTHING );
	sc_signal<bool> t_a, t_b, t_cin, t_sum, t_cout;
	
	full_adder f1("f1");
	monitor m1("m1");
	driver d1("d1");
	
	sc_trace_file *tfile = sc_create_vcd_trace_file("full_adder");
	
	f1 << t_a << t_b << t_cin << t_sum << t_cout;
	
	d1.d_a(t_a);
	d1.d_b(t_b);
	d1.d_cin(t_cin);
	
	m1(t_a, t_b, t_cin, t_sum, t_cout);
	
	sc_trace(tfile, t_a, "t_a");
	sc_trace(tfile, t_b, "t_b");
	sc_trace(tfile, t_cin, "t_cin");
	sc_trace(tfile, t_sum, "t_sum");
	sc_trace(tfile, t_cout, "t_cout");
	
	sc_start(100, SC_NS);
	sc_close_vcd_trace_file(tfile);
	return(0);
}
