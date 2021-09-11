#include "prob2_mod.h"

void com_device :: prc_com_device(){
	if (!reset){
		//reset registers
		r_payload = 0;
		r_count = 0;
		r_error = 0;
		//clear outputs
		payload = 0;
		count = 0;
		error = 0;
	}
	else if (clear){
		//clear outputs
		payload = 0;
		count = 0;
		error = 0;
	}
	else{
		sc_bv<12> temp = inData;
		if (temp.range(11,8) == 1){
			r_payload = temp.range(7,4);
			r_count = r_count + 1;
		
			if ((temp[7] ^ temp[6] ^ temp[5] ^ temp[4] ^ temp[0]) != 1){	
				r_error = r_error + 1;
			} 
		}
		payload = r_payload;
		count = r_count;
		error = r_error;
	}
}
