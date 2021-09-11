#include "prob3_mod.h"

void count_device :: prc_prob3(){
	if (!reset){
		//reset registers
		r_overflow = 0;
		counter1 = 0;
		counter2 = 0;
		//clear outputs
		count1 = 0;
		count2 = 0;
		ended = 0;
	}
	else if (clear){
		//clear outputs
		count1 = 0;
		count2 = 0;
		ended = 0;
	}
	else{
		//counter1 rules
		if (load1){
			counter1 = (0,in1);
			r_overflow = 0;
		}
		if (dec1 && !r_overflow)
			counter1 = counter1 - 1;

		//counter2 rules
		if (load2){
			counter2 = (0,in2);
			r_overflow = 0;
		}
		if (dec2 && !r_overflow)
			counter2 = counter2 - (0,in3);
		
		if (counter1 == counter2)
			r_ended = 1;
		else
			r_ended = 0;
			
		if (counter1[8] == 1 || counter2[8] == 1){
			r_ended = 1;
			r_overflow = 1;
		}

		count1 = counter1;
		count2 = counter2;
		ended = r_ended;
	}
}
