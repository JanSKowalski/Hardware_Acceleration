#include "prob1_mod.h"

void seq_detector :: prc_seq_detector(){
	//reset active low, clears internal and output registers
	if (!reset){
		internal_regs = 0;
		data_out = 0;
	}
	//clear active high, clears output registers
	else if (clear){
		data_out = 0;
	}
	//normal clock cycle
	else{
		internal_regs = internal_regs << 1;
		internal_regs[0] = data_in;
		if (internal_regs == 11)
			data_out = 1;
		else
			data_out = 0;
	}
}
