#define INPUT_DATA_SIZE 2000
#define OUTPUT_DATA_SIZE 500


extern "C" {
void xgboost(	const double* input_values,
		double* output_values){
          		
	double vin_buffer[INPUT_DATA_SIZE];
	double vout_buffer[OUTPUT_DATA_SIZE];

	double tree0[OUTPUT_DATA_SIZE] = 0;
	double tree1[OUTPUT_DATA_SIZE] = 0;
	double tree2[OUTPUT_DATA_SIZE] = 0;

	read_1:
	for (int j = 0; j < INPUT_DATA_SIZE; j++) {
#pragma HLS loop_tripcount min=INPUT_DATA_SIZE max=INPUT_DATA_SIZE
		vin_buffer[j] = input_values[j];
	}
	
	inference_1:
	for(int j=0; j < OUTPUT_DATA_SIZE; j++){
#pragma HLS loop_tripcount min=OUTPUT_DATA_SIZE max=OUTPUT_DATA_SIZE

	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.430622011;
	}
	else{
		tree0[j] = -0.220048919;
	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree1[j] = -0.215311036;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree1[j] = 0.428571463;
	}
	else{
		tree1[j] = 0.128571421;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree1[j] = -0.128571451;
	}
	else{
		tree1[j] = 0.128571421;
	}
	

	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.85000038){
		tree1[j] = -7.66345476;
	}
	else{
		tree1[j] = -0.213812172;
	}
	

	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree2[j] = -0.219899267;
	}
	else{
		tree2[j] = 0.217241377;
	}
	

	}
	else{
		tree2[j] = 0.402985066;
	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.295082778;
	}
	else{
		tree0[j] = -0.19683747;
	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree1[j] = -0.191612214;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.287215412;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree1[j] = -0.119655393;
	}
	else{
		tree1[j] = 0.121238194;
	}
	

	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.85000038){
		tree1[j] = 0.0119826663;
	}
	else{
		tree1[j] = -0.191138521;
	}
	

	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 4.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = -0.195821807;
	}
	else{
		tree2[j] = -0.00269367103;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree2[j] = -0.107412621;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = 0.209871635;
	}
	else{
		tree2[j] = -0.0265715588;
	}
	

	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.85000038){
		tree2[j] = 0.0771064013;
	}
	else{
		tree2[j] = 0.297540128;
	}
	

	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.236306787;
	}
	else{
		tree0[j] = -0.181336597;
	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree1[j] = -0.175504029;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 2) < 5.05000019){
		
	if (*(vin_buffer + 4*j + 0) < 5.05000019){
		tree1[j] = 0.0784917325;
	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.25){
		tree1[j] = 0.0668418482;
	}
	else{
		tree1[j] = 0.241057426;
	}
	

	}
	

	}
	else{
		tree1[j] = -0.0371556394;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.85000038){
		tree1[j] = 0.0100614149;
	}
	else{
		tree1[j] = -0.174704418;
	}
	

	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 4.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = -0.180165544;
	}
	else{
		tree2[j] = 0.00726488465;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 2) < 5.05000019){
		tree2[j] = -0.0578227639;
	}
	else{
		tree2[j] = 0.122338183;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.85000038){
		tree2[j] = 0.0630181506;
	}
	else{
		tree2[j] = 0.237204403;
	}
	

	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.203852341;
	}
	else{
		tree0[j] = -0.170494914;
	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree1[j] = -0.163605615;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree1[j] = 0.204518631;
	}
	else{
		tree1[j] = 0.0464834869;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree1[j] = -0.109693311;
	}
	else{
		tree1[j] = 0.0926420242;
	}
	

	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.85000038){
		tree1[j] = 0.0090344632;
	}
	else{
		tree1[j] = -0.162477046;
	}
	

	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 4.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = -0.169104204;
	}
	else{
		tree2[j] = 0.0137579208;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 2) < 5.05000019){
		tree2[j] = -0.0452597365;
	}
	else{
		tree2[j] = 0.100356087;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.85000038){
		tree2[j] = 0.0519054718;
	}
	else{
		tree2[j] = 0.203949228;
	}
	

	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.183452412;
	}
	else{
		tree0[j] = -0.162297457;
	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree1[j] = -0.154138923;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.186947152;
	}
	else{
		tree1[j] = -0.053264387;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 5.05000019){
		
	if (*(vin_buffer + 4*j + 1) < 2.9000001){
		tree1[j] = -0.135480031;
	}
	else{
		tree1[j] = 0.0885925591;
	}
	

	}
	else{
		tree1[j] = -0.150662541;
	}
	

	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 4.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = -0.160508573;
	}
	else{
		tree2[j] = 0.0125771537;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 2) < 5.05000019){
		tree2[j] = -0.0388760455;
	}
	else{
		tree2[j] = 0.0858836025;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.85000038){
		tree2[j] = 0.042941872;
	}
	else{
		tree2[j] = 0.183017045;
	}
	

	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.169368118;
	}
	else{
		tree0[j] = -0.155699849;
	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree1[j] = -0.146013469;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.172504574;
	}
	else{
		tree1[j] = -0.0471911393;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 5.05000019){
		
	if (*(vin_buffer + 4*j + 1) < 2.9000001){
		tree1[j] = -0.126944765;
	}
	else{
		tree1[j] = 0.0799103677;
	}
	

	}
	else{
		tree1[j] = -0.141917035;
	}
	

	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 4.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = -0.153490961;
	}
	else{
		tree2[j] = 0.0134451231;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = 0.0717510283;
	}
	else{
		tree2[j] = -0.0414980128;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		
	if (*(vin_buffer + 4*j + 2) < 5.05000019){
		tree2[j] = -0.028885141;
	}
	else{
		tree2[j] = 0.0977884308;
	}
	

	}
	else{
		tree2[j] = 0.173987702;
	}
	

	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.158799544;
	}
	else{
		tree0[j] = -0.150105298;
	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree1[j] = -0.138523117;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.161982983;
	}
	else{
		tree1[j] = -0.0443760864;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 5.05000019){
		
	if (*(vin_buffer + 4*j + 1) < 2.9000001){
		tree1[j] = -0.118573882;
	}
	else{
		tree1[j] = 0.0743857473;
	}
	

	}
	else{
		tree1[j] = -0.133837625;
	}
	

	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 4.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = -0.147345766;
	}
	else{
		tree2[j] = 0.0142603237;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 5.14999962){
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		tree2[j] = -0.0415497161;
	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = 0.0351802632;
	}
	else{
		tree2[j] = 0.138523564;
	}
	

	}
	

	}
	else{
		tree2[j] = 0.163172677;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.150204912;
	}
	else{
		tree0[j] = -0.145044655;
	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree1[j] = -0.131210536;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.153308138;
	}
	else{
		tree1[j] = -0.0395669565;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 5.05000019){
		
	if (*(vin_buffer + 4*j + 1) < 2.9000001){
		tree1[j] = -0.1109901;
	}
	else{
		tree1[j] = 0.0704311654;
	}
	

	}
	else{
		tree1[j] = -0.12617521;
	}
	

	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 4.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = -0.141554654;
	}
	else{
		tree2[j] = 0.0149865942;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 5.14999962){
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		tree2[j] = -0.0383817479;
	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = 0.0241114963;
	}
	else{
		tree2[j] = 0.128226236;
	}
	

	}
	

	}
	else{
		tree2[j] = 0.153534696;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.1426671;
	}
	else{
		tree0[j] = -0.140168741;
	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree1[j] = -0.123804785;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.14580147;
	}
	else{
		tree1[j] = -0.035178721;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 3.1500001){
		
	if (*(vin_buffer + 4*j + 0) < 6.5999999){
		tree1[j] = -0.134182259;
	}
	else{
		tree1[j] = -0.0213955063;
	}
	

	}
	else{
		tree1[j] = 0.0087980805;
	}
	

	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 4.85000038){
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.139297202;
	}
	else{
		tree2[j] = 0.0532883145;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = 0.0847027004;
	}
	else{
		tree2[j] = -0.0525109619;
	}
	

	}
	else{
		tree2[j] = 0.142963231;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.13557972;
	}
	else{
		tree0[j] = -0.135064989;
	}
	

	if (*(vin_buffer + 4*j + 2) < 5.14999962){
		
	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree1[j] = -0.116191648;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		
	if (*(vin_buffer + 4*j + 1) < 2.3499999){
		tree1[j] = 0.0164910723;
	}
	else{
		tree1[j] = 0.13854973;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.9000001){
		tree1[j] = -0.102068059;
	}
	else{
		tree1[j] = 0.0555418916;
	}
	

	}
	

	}
	

	}
	else{
		tree1[j] = -0.123394012;
	}
	

	if (*(vin_buffer + 4*j + 2) < 4.85000038){
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.133229241;
	}
	else{
		tree2[j] = 0.0398604795;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = 0.0778191239;
	}
	else{
		tree2[j] = -0.052116029;
	}
	

	}
	else{
		tree2[j] = 0.136263967;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.12865451;
	}
	else{
		tree0[j] = -0.129812017;
	}
	

	if (*(vin_buffer + 4*j + 2) < 5.14999962){
		
	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree1[j] = -0.108377993;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.131557465;
	}
	else{
		tree1[j] = 0.0130662899;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.9000001){
		tree1[j] = -0.0950063542;
	}
	else{
		tree1[j] = 0.0532187186;
	}
	

	}
	

	}
	

	}
	else{
		tree1[j] = -0.116841592;
	}
	

	if (*(vin_buffer + 4*j + 2) < 4.85000038){
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.127085507;
	}
	else{
		tree2[j] = 0.0335973576;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = 0.0742606148;
	}
	else{
		tree2[j] = -0.0477290265;
	}
	

	}
	else{
		tree2[j] = 0.129317284;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.121719062;
	}
	else{
		tree0[j] = -0.12421722;
	}
	

	if (*(vin_buffer + 4*j + 2) < 5.14999962){
		
	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree1[j] = -0.100470193;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.124527253;
	}
	else{
		tree1[j] = 0.012794828;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree1[j] = 0.0182135236;
	}
	else{
		tree1[j] = -0.0351226181;
	}
	

	}
	

	}
	

	}
	else{
		tree1[j] = -0.110418819;
	}
	

	if (*(vin_buffer + 4*j + 2) < 4.85000038){
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.120433971;
	}
	else{
		tree2[j] = 0.028456239;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = 0.0697158203;
	}
	else{
		tree2[j] = -0.0468012132;
	}
	

	}
	else{
		tree2[j] = 0.122496508;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.11473041;
	}
	else{
		tree0[j] = -0.118420579;
	}
	

	if (*(vin_buffer + 4*j + 2) < 5.14999962){
		
	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree1[j] = -0.0926298425;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.117551051;
	}
	else{
		tree1[j] = 0.0125180241;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree1[j] = 0.0207842346;
	}
	else{
		tree1[j] = -0.0313819125;
	}
	

	}
	

	}
	

	}
	else{
		tree1[j] = -0.104251929;
	}
	

	if (*(vin_buffer + 4*j + 2) < 5.14999962){
		
	if (*(vin_buffer + 4*j + 1) < 3.04999995){
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree2[j] = -0.0915681124;
	}
	else{
		tree2[j] = 0.00862100534;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.85000038){
		tree2[j] = 0.110005915;
	}
	else{
		tree2[j] = 0.0243457537;
	}
	

	}
	

	}
	else{
		tree2[j] = -0.120479003;
	}
	

	}
	else{
		tree2[j] = 0.121317282;
	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.107694656;
	}
	else{
		tree0[j] = -0.112576976;
	}
	

	if (*(vin_buffer + 4*j + 2) < 5.14999962){
		
	if (*(vin_buffer + 4*j + 0) < 5.44999981){
		tree1[j] = -0.0735686794;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 1) < 2.6500001){
		tree1[j] = 0.0123189101;
	}
	else{
		tree1[j] = 0.105095081;
	}
	

	}
	else{
		tree1[j] = -0.0113838017;
	}
	

	}
	

	}
	else{
		tree1[j] = -0.0955269709;
	}
	

	if (*(vin_buffer + 4*j + 2) < 5.14999962){
		
	if (*(vin_buffer + 4*j + 1) < 3.04999995){
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 1) < 2.54999995){
		tree2[j] = 0.0497050621;
	}
	else{
		tree2[j] = -0.0900263041;
	}
	

	}
	else{
		tree2[j] = 0.100666717;
	}
	

	}
	else{
		tree2[j] = -0.112032153;
	}
	

	}
	else{
		tree2[j] = 0.112749942;
	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.101380005;
	}
	else{
		tree0[j] = -0.107117154;
	}
	

	if (*(vin_buffer + 4*j + 2) < 5.14999962){
		
	if (*(vin_buffer + 4*j + 0) < 5.44999981){
		tree1[j] = -0.0654773042;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		
	if (*(vin_buffer + 4*j + 2) < 4.64999962){
		tree1[j] = 0.071040161;
	}
	else{
		tree1[j] = -0.0316096507;
	}
	

	}
	else{
		tree1[j] = 0.119120017;
	}
	

	}
	else{
		tree1[j] = -0.0090087112;
	}
	

	}
	

	}
	else{
		tree1[j] = -0.0873806626;
	}
	

	if (*(vin_buffer + 4*j + 2) < 4.85000038){
		
	if (*(vin_buffer + 4*j + 1) < 3.04999995){
		tree2[j] = 0.0128666768;
	}
	else{
		tree2[j] = -0.121713579;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = 0.0701830015;
	}
	else{
		tree2[j] = -0.0533180647;
	}
	

	}
	else{
		tree2[j] = 0.104869373;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.095275715;
	}
	else{
		tree0[j] = -0.101790331;
	}
	

	if (*(vin_buffer + 4*j + 2) < 5.14999962){
		
	if (*(vin_buffer + 4*j + 0) < 5.44999981){
		tree1[j] = -0.0585310273;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		
	if (*(vin_buffer + 4*j + 2) < 4.64999962){
		tree1[j] = 0.0664431378;
	}
	else{
		tree1[j] = -0.0264687967;
	}
	

	}
	else{
		tree1[j] = 0.109369479;
	}
	

	}
	else{
		tree1[j] = -0.00826003402;
	}
	

	}
	

	}
	else{
		tree1[j] = -0.0823554322;
	}
	

	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		
	if (*(vin_buffer + 4*j + 1) < 3.04999995){
		
	if (*(vin_buffer + 4*j + 3) < 1.60000002){
		tree2[j] = -0.0801073164;
	}
	else{
		tree2[j] = 0.100336127;
	}
	

	}
	else{
		tree2[j] = -0.117334045;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 5.14999962){
		tree2[j] = 0.0182764474;
	}
	else{
		tree2[j] = 0.0990470797;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.0891820192;
	}
	else{
		tree0[j] = -0.0964985415;
	}
	

	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		
	if (*(vin_buffer + 4*j + 0) < 5.44999981){
		tree1[j] = -0.0522038937;
	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree1[j] = 0.0923672318;
	}
	else{
		tree1[j] = 0.0179841146;
	}
	

	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 6.05000019){
		tree1[j] = 0.00886444841;
	}
	else{
		tree1[j] = -0.0590595044;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		
	if (*(vin_buffer + 4*j + 1) < 3.04999995){
		
	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.00602423493;
	}
	else{
		tree2[j] = 0.0269548204;
	}
	

	}
	else{
		tree2[j] = -0.111514151;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 5.14999962){
		tree2[j] = 0.0184794962;
	}
	else{
		tree2[j] = 0.091575481;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.0837989375;
	}
	else{
		tree0[j] = -0.0917258486;
	}
	

	if (*(vin_buffer + 4*j + 0) < 5.44999981){
		tree1[j] = -0.0471516997;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		
	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree1[j] = 0.0831074864;
	}
	else{
		tree1[j] = 0.0149866603;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 6.05000019){
		tree1[j] = 0.00915684085;
	}
	else{
		tree1[j] = -0.0513933748;
	}
	

	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0935106575;
	}
	else{
		tree2[j] = 0.026505338;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		tree2[j] = 0.0125105949;
	}
	else{
		tree2[j] = 0.0838628411;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 2.45000005){
		tree0[j] = 0.0786677599;
	}
	else{
		tree0[j] = -0.0870034248;
	}
	

	if (*(vin_buffer + 4*j + 0) < 5.44999981){
		tree1[j] = -0.0435130596;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		
	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree1[j] = 0.07811822;
	}
	else{
		tree1[j] = 0.0101398872;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 6.05000019){
		tree1[j] = 0.0102074035;
	}
	else{
		tree1[j] = -0.0453768224;
	}
	

	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 5.14999962){
		
	if (*(vin_buffer + 4*j + 1) < 3.04999995){
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.036293719;
	}
	else{
		tree2[j] = 0.0629615188;
	}
	

	}
	else{
		tree2[j] = -0.084745571;
	}
	

	}
	else{
		tree2[j] = 0.0804405361;
	}
	

	if (*(vin_buffer + 4*j + 2) < 3.4000001){
		tree0[j] = 0.0677801669;
	}
	else{
		tree0[j] = -0.0808052272;
	}
	

	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 0) < 5.44999981){
		tree1[j] = -0.0388489813;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree1[j] = 0.00267020031;
	}
	else{
		tree1[j] = 0.0747686028;
	}
	

	}
	

	}
	else{
		tree1[j] = -0.031966351;
	}
	

	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0853333622;
	}
	else{
		tree2[j] = 0.0264386516;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 6.05000019){
		tree2[j] = 0.00412582839;
	}
	else{
		tree2[j] = 0.056749288;
	}
	

	}
	
tree0[j] = -0.0124261184;
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		
	if (*(vin_buffer + 4*j + 0) < 5.55000019){
		tree1[j] = -0.0294606779;
	}
	else{
		tree1[j] = 0.0491429046;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.00415844657;
	}
	else{
		tree1[j] = -0.03627529;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 1) < 3.1500001){
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 1) < 2.6500001){
		tree2[j] = 0.0385785699;
	}
	else{
		tree2[j] = -0.0495467223;
	}
	

	}
	else{
		tree2[j] = 0.0906612128;
	}
	

	}
	else{
		tree2[j] = -0.0596319959;
	}
	
tree0[j] = -0.0114925886;
	if (*(vin_buffer + 4*j + 2) < 5.05000019){
		
	if (*(vin_buffer + 4*j + 0) < 6.05000019){
		
	if (*(vin_buffer + 4*j + 1) < 2.6500001){
		tree1[j] = -0.0283436812;
	}
	else{
		tree1[j] = 0.00544351107;
	}
	

	}
	else{
		tree1[j] = 0.0558974072;
	}
	

	}
	else{
		tree1[j] = -0.027872134;
	}
	

	if (*(vin_buffer + 4*j + 2) < 4.85000038){
		tree2[j] = -0.0377209261;
	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree2[j] = 0.00204676948;
	}
	else{
		tree2[j] = 0.0518581234;
	}
	

	}
	
tree0[j] = -0.0100069102;
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 0) < 5.55000019){
		tree1[j] = -0.0274813566;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree1[j] = -0.00697381422;
	}
	else{
		tree1[j] = 0.0709982663;
	}
	

	}
	

	}
	else{
		tree1[j] = -0.0275159869;
	}
	

	if (*(vin_buffer + 4*j + 1) < 3.04999995){
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 1) < 2.6500001){
		tree2[j] = 0.0358652808;
	}
	else{
		tree2[j] = -0.0452733524;
	}
	

	}
	else{
		tree2[j] = 0.085109815;
	}
	

	}
	else{
		tree2[j] = -0.0506632775;
	}
	
tree0[j] = -0.0101767527;
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		
	if (*(vin_buffer + 4*j + 0) < 5.55000019){
		tree1[j] = -0.0248351488;
	}
	else{
		tree1[j] = 0.0446489118;
	}
	

	}
	else{
		tree1[j] = -0.0223798137;
	}
	

	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0780981034;
	}
	else{
		tree2[j] = 0.0204321109;
	}
	

	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree2[j] = 0.0063205366;
	}
	else{
		tree2[j] = 0.0513237901;
	}
	

	}
	
tree0[j] = -0.00972964801;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0237640496;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.0413856208;
	}
	else{
		tree1[j] = -0.0125131216;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0420993865;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = 0.0386490673;
	}
	else{
		tree2[j] = -0.0580373555;
	}
	

	}
	else{
		tree2[j] = 0.0831397399;
	}
	

	}
	
tree0[j] = -0.00935757346;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0239318404;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.0401715003;
	}
	else{
		tree1[j] = -0.0119660012;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 1) < 3.04999995){
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.00638331566;
	}
	else{
		tree2[j] = 0.0544351377;
	}
	

	}
	else{
		tree2[j] = -0.0480407886;
	}
	
tree0[j] = -0.00947500952;
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 0) < 5.55000019){
		tree1[j] = -0.0225574616;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree1[j] = -0.00992034469;
	}
	else{
		tree1[j] = 0.0643382818;
	}
	

	}
	

	}
	else{
		tree1[j] = -0.0247603245;
	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0393829606;
	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree2[j] = -0.0131064886;
	}
	else{
		tree2[j] = 0.0478994213;
	}
	

	}
	
tree0[j] = -0.00956440531;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0216520187;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 5.05000019){
		tree1[j] = 0.0336737074;
	}
	else{
		tree1[j] = -0.0184615757;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0377558023;
	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree2[j] = -0.0107561555;
	}
	else{
		tree2[j] = 0.0447877012;
	}
	

	}
	
tree0[j] = -0.00951200351;
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 0) < 5.55000019){
		tree1[j] = -0.0226187669;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree1[j] = -0.00934538059;
	}
	else{
		tree1[j] = 0.0631766766;
	}
	

	}
	

	}
	else{
		tree1[j] = -0.0235776156;
	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0349710323;
	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree2[j] = -0.00943445135;
	}
	else{
		tree2[j] = 0.0419731922;
	}
	

	}
	
tree0[j] = -0.00963145494;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0219386257;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.0400436036;
	}
	else{
		tree1[j] = -0.010547284;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 4.85000038){
		tree2[j] = -0.0311622433;
	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree2[j] = 0.00430742558;
	}
	else{
		tree2[j] = 0.0390126593;
	}
	

	}
	
tree0[j] = -0.00944014546;
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 0) < 5.55000019){
		tree1[j] = -0.0222905986;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree1[j] = -0.00871694088;
	}
	else{
		tree1[j] = 0.0624986626;
	}
	

	}
	

	}
	else{
		tree1[j] = -0.024066003;
	}
	

	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 1) < 2.6500001){
		tree2[j] = 0.035431996;
	}
	else{
		tree2[j] = -0.0542352125;
	}
	

	}
	else{
		tree2[j] = 0.0385512523;
	}
	
tree0[j] = -0.00958529674;
	if (*(vin_buffer + 4*j + 2) < 5.05000019){
		
	if (*(vin_buffer + 4*j + 0) < 5.55000019){
		tree1[j] = -0.0201040693;
	}
	else{
		tree1[j] = 0.0298720207;
	}
	

	}
	else{
		tree1[j] = -0.0225872956;
	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0355525687;
	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 6.35000038){
		tree2[j] = 0.0327143632;
	}
	else{
		tree2[j] = 0.0068394444;
	}
	

	}
	
tree0[j] = -0.00925823022;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0203516223;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.0363923647;
	}
	else{
		tree1[j] = -0.0102508049;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0325735584;
	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 6.35000038){
		tree2[j] = 0.030371923;
	}
	else{
		tree2[j] = 0.00654658442;
	}
	

	}
	
tree0[j] = -0.00937817805;
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 0) < 5.55000019){
		tree1[j] = -0.0201363452;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree1[j] = -0.00842716172;
	}
	else{
		tree1[j] = 0.0576423742;
	}
	

	}
	

	}
	else{
		tree1[j] = -0.0229928717;
	}
	

	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree2[j] = -0.0385266431;
	}
	else{
		tree2[j] = 0.00345264934;
	}
	

	}
	else{
		tree2[j] = 0.0370537788;
	}
	
tree0[j] = -0.00935130939;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0202563833;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.036704652;
	}
	else{
		tree1[j] = -0.00947705749;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0313477628;
	}
	else{
		tree2[j] = 0.0246066693;
	}
	
tree0[j] = -0.00935987197;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.020222893;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 5.05000019){
		tree1[j] = 0.0292848106;
	}
	else{
		tree1[j] = -0.0120938672;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree2[j] = -0.0358631648;
	}
	else{
		tree2[j] = 0.00291170459;
	}
	

	}
	else{
		tree2[j] = 0.0342322402;
	}
	
tree0[j] = -0.00929206517;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0198873058;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.0331506245;
	}
	else{
		tree1[j] = -0.00617244514;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 1) < 2.6500001){
		tree2[j] = 0.0379881635;
	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 6.05000019){
		tree2[j] = -0.0530413873;
	}
	else{
		tree2[j] = 0.0284742657;
	}
	

	}
	
tree0[j] = -0.00943612866;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0217943955;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.0365313999;
	}
	else{
		tree1[j] = 0.0137984073;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree2[j] = -0.0350777805;
	}
	else{
		tree2[j] = 0.00158041937;
	}
	

	}
	else{
		tree2[j] = 0.0358202979;
	}
	
tree0[j] = -0.00973614305;
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 0) < 5.55000019){
		tree1[j] = -0.0197434239;
	}
	else{
		tree1[j] = 0.0297625307;
	}
	

	}
	else{
		tree1[j] = -0.0213356595;
	}
	

	if (*(vin_buffer + 4*j + 1) < 2.6500001){
		tree2[j] = 0.0375019871;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.75){
		tree2[j] = -0.0491629876;
	}
	else{
		tree2[j] = 0.0305754356;
	}
	

	}
	
tree0[j] = -0.00925249513;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0190726798;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.0382530764;
	}
	else{
		tree1[j] = 0.0168346297;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0299499333;
	}
	else{
		tree2[j] = 0.0251847953;
	}
	
tree0[j] = -0.00978145562;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0192090292;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.0318240263;
	}
	else{
		tree1[j] = -0.00725860381;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 1) < 2.6500001){
		tree2[j] = 0.0365158953;
	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 6.05000019){
		tree2[j] = -0.0477304719;
	}
	else{
		tree2[j] = 0.0257717092;
	}
	

	}
	
tree0[j] = -0.00982088502;
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 0) < 5.64999962){
		tree1[j] = -0.0120936809;
	}
	else{
		tree1[j] = 0.0255388189;
	}
	

	}
	else{
		tree1[j] = -0.0223202147;
	}
	

	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = -0.0055405451;
	}
	else{
		tree2[j] = -0.0208273269;
	}
	

	}
	else{
		tree2[j] = 0.0343218371;
	}
	
tree0[j] = -0.00884358585;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0175539721;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.0363285281;
	}
	else{
		tree1[j] = 0.0162490308;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0278610084;
	}
	else{
		tree2[j] = 0.023961002;
	}
	
tree0[j] = -0.00935288705;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0186019074;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.0303545073;
	}
	else{
		tree1[j] = -0.0068850005;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0248004515;
	}
	else{
		tree2[j] = 0.0217417497;
	}
	
tree0[j] = -0.00934191048;
	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 0) < 5.64999962){
		tree1[j] = -0.0129501261;
	}
	else{
		tree1[j] = 0.0258134101;
	}
	

	}
	else{
		tree1[j] = -0.0211682897;
	}
	

	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = -0.00543820579;
	}
	else{
		tree2[j] = -0.0200663432;
	}
	

	}
	else{
		tree2[j] = 0.0326976553;
	}
	
tree0[j] = -0.00847498886;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0182831082;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.0306143779;
	}
	else{
		tree1[j] = -0.0072264839;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0249242466;
	}
	else{
		tree2[j] = 0.0215228237;
	}
	
tree0[j] = -0.00855832733;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0181295723;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.0287167095;
	}
	else{
		tree1[j] = -0.00476364931;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = -0.00458666543;
	}
	else{
		tree2[j] = -0.0187324639;
	}
	

	}
	else{
		tree2[j] = 0.0302378982;
	}
	
tree0[j] = -0.00833714753;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0171325151;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.0279992167;
	}
	else{
		tree1[j] = -0.00517435744;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0241098702;
	}
	else{
		tree2[j] = 0.0203580782;
	}
	
tree0[j] = -0.0084214285;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0170356985;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.0262828283;
	}
	else{
		tree1[j] = -0.0029993183;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = -0.00488631427;
	}
	else{
		tree2[j] = -0.0191714447;
	}
	

	}
	else{
		tree2[j] = 0.0304909237;
	}
	
tree0[j] = -0.00821107253;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0173017457;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.034756884;
	}
	else{
		tree1[j] = 0.0164372157;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 3) < 1.54999995){
		tree2[j] = -0.00461294781;
	}
	else{
		tree2[j] = -0.0180862546;
	}
	

	}
	else{
		tree2[j] = 0.0293703265;
	}
	
tree0[j] = -0.00839850213;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0164726749;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.0266595632;
	}
	else{
		tree1[j] = -0.00483236741;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0230573844;
	}
	else{
		tree2[j] = 0.0199955553;
	}
	
tree0[j] = -0.00846539345;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0163970813;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.0250634812;
	}
	else{
		tree1[j] = -0.00273302826;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree2[j] = -0.00381826074;
	}
	else{
		tree2[j] = -0.0196389928;
	}
	

	}
	else{
		tree2[j] = 0.0294753332;
	}
	
tree0[j] = -0.00839526579;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0162461493;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.033397872;
	}
	else{
		tree1[j] = 0.0161836371;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree2[j] = -0.00401700567;
	}
	else{
		tree2[j] = -0.0181995258;
	}
	

	}
	else{
		tree2[j] = 0.0284112077;
	}
	
tree0[j] = -0.00867087673;
	if (*(vin_buffer + 4*j + 1) < 2.6500001){
		tree1[j] = -0.0175250284;
	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 6.14999962){
		tree1[j] = 0.0204494856;
	}
	else{
		tree1[j] = -0.00680113584;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0223351717;
	}
	else{
		tree2[j] = 0.0195875671;
	}
	
tree0[j] = -0.00759580126;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0169241801;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.0248225126;
	}
	else{
		tree1[j] = -0.00244841236;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree2[j] = -0.00320100994;
	}
	else{
		tree2[j] = -0.0193602182;
	}
	

	}
	else{
		tree2[j] = 0.0283187684;
	}
	
tree0[j] = -0.00764739281;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0158337895;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.024215823;
	}
	else{
		tree1[j] = -0.00291640824;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree2[j] = -0.00345370779;
	}
	else{
		tree2[j] = -0.017929798;
	}
	

	}
	else{
		tree2[j] = 0.0273553208;
	}
	
tree0[j] = -0.00765525689;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0161320511;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.0339419357;
	}
	else{
		tree1[j] = 0.0164030753;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0224331357;
	}
	else{
		tree2[j] = 0.0189714096;
	}
	
tree0[j] = -0.00816563517;
	if (*(vin_buffer + 4*j + 1) < 2.6500001){
		tree1[j] = -0.0173255838;
	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 6.14999962){
		tree1[j] = 0.0192576181;
	}
	else{
		tree1[j] = -0.00498138554;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree2[j] = -0.00264711445;
	}
	else{
		tree2[j] = -0.0187502485;
	}
	

	}
	else{
		tree2[j] = 0.0275852196;
	}
	
tree0[j] = -0.00706445705;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0162237119;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = 0.0239160974;
	}
	else{
		tree1[j] = -0.00265015033;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.75){
		
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree2[j] = -0.00295793265;
	}
	else{
		tree2[j] = -0.0176262911;
	}
	

	}
	else{
		tree2[j] = 0.0264681;
	}
	
tree0[j] = -0.00715726614;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0156745873;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.0335215665;
	}
	else{
		tree1[j] = 0.0162082035;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0214351248;
	}
	else{
		tree2[j] = 0.0182844382;
	}
	
tree0[j] = -0.0076999166;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.016129313;
	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 6.05000019){
		tree1[j] = 0.0193039738;
	}
	else{
		tree1[j] = -0.000844640017;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree2[j] = 0.0202165227;
	}
	else{
		tree2[j] = -0.0175613221;
	}
	
tree0[j] = -0.00783255417;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0157155246;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.0307511445;
	}
	else{
		tree1[j] = 0.013607393;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0156140253;
	}
	else{
		tree2[j] = 0.0210701209;
	}
	
tree0[j] = -0.00809859112;
	if (*(vin_buffer + 4*j + 1) < 2.6500001){
		tree1[j] = -0.0174411405;
	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 6.05000019){
		tree1[j] = 0.0184153616;
	}
	else{
		tree1[j] = -0.00355607341;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0197748914;
	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 6.25){
		tree2[j] = 0.0210366603;
	}
	else{
		tree2[j] = 0.00535012595;
	}
	

	}
	
tree0[j] = -0.00723137707;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0155754443;
	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree1[j] = -0.000282198074;
	}
	else{
		tree1[j] = 0.0166785698;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0153602185;
	}
	else{
		tree2[j] = 0.0208426602;
	}
	
tree0[j] = -0.00732617965;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0147105381;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.0307812933;
	}
	else{
		tree1[j] = 0.0141519913;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0194581896;
	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 6.25){
		tree2[j] = 0.0204225499;
	}
	else{
		tree2[j] = 0.0052661649;
	}
	

	}
	
tree0[j] = -0.00782681908;
	if (*(vin_buffer + 4*j + 1) < 2.6500001){
		tree1[j] = -0.0174376741;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = -0.00150977273;
	}
	else{
		tree1[j] = 0.0194570888;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.014830797;
	}
	else{
		tree2[j] = 0.0210170243;
	}
	
tree0[j] = -0.0074843294;
	if (*(vin_buffer + 4*j + 1) < 2.6500001){
		tree1[j] = -0.0164869968;
	}
	else{
		
	if (*(vin_buffer + 4*j + 0) < 6.05000019){
		tree1[j] = 0.0167651437;
	}
	else{
		tree1[j] = -0.00312646758;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree2[j] = 0.0195656288;
	}
	else{
		tree2[j] = -0.0159193128;
	}
	
tree0[j] = -0.00655285968;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0156953912;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.0306772459;
	}
	else{
		tree1[j] = 0.0127865467;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0190778319;
	}
	else{
		tree2[j] = 0.016657263;
	}
	
tree0[j] = -0.0070435782;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.015265869;
	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree1[j] = 0.00075441238;
	}
	else{
		tree1[j] = 0.0152605278;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0155849941;
	}
	else{
		tree2[j] = 0.0210641921;
	}
	
tree0[j] = -0.00715473713;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0144732073;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.0289603379;
	}
	else{
		tree1[j] = 0.0127689736;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0141061321;
	}
	else{
		tree2[j] = 0.0197918694;
	}
	
tree0[j] = -0.00745225418;
	if (*(vin_buffer + 4*j + 1) < 2.6500001){
		tree1[j] = -0.0167825148;
	}
	else{
		
	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree1[j] = -0.0009009848;
	}
	else{
		tree1[j] = 0.0178801958;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree2[j] = 0.0190431345;
	}
	else{
		tree2[j] = -0.0151514532;
	}
	
tree0[j] = -0.00713037979;
	if (*(vin_buffer + 4*j + 3) < 1.45000005){
		tree1[j] = 0.0173721258;
	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree1[j] = -0.0270227604;
	}
	else{
		tree1[j] = 0.0124137895;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0190069489;
	}
	else{
		tree2[j] = 0.0168033279;
	}
	
tree0[j] = -0.00590636209;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0160239059;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.0288499109;
	}
	else{
		tree1[j] = 0.0116949724;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0154117132;
	}
	else{
		tree2[j] = 0.0197290592;
	}
	
tree0[j] = -0.00631126948;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0146903237;
	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree1[j] = 0.00121643487;
	}
	else{
		tree1[j] = 0.0140903294;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0141497022;
	}
	else{
		tree2[j] = 0.0189936794;
	}
	
tree0[j] = -0.00646372233;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0141440788;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.0282605458;
	}
	else{
		tree1[j] = 0.012785932;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.018801149;
	}
	else{
		tree2[j] = 0.0159239825;
	}
	
tree0[j] = -0.00691270735;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0144564901;
	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree1[j] = 0.000964503677;
	}
	else{
		tree1[j] = 0.014212654;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0138153872;
	}
	else{
		tree2[j] = 0.0189189315;
	}
	
tree0[j] = -0.0070079565;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0134642683;
	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree1[j] = 9.18672959;
	}
	else{
		tree1[j] = 0.0138099184;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.0177914537;
	}
	else{
		tree2[j] = 0.0154139483;
	}
	
tree0[j] = -0.00714263413;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0136907678;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.0263972543;
	}
	else{
		tree1[j] = 0.0120982779;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0132512199;
	}
	else{
		tree2[j] = 0.0183598492;
	}
	
tree0[j] = -0.00738467555;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0133684054;
	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree1[j] = -6.61340964;
	}
	else{
		tree1[j] = 0.0139225917;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree2[j] = 0.0174172595;
	}
	else{
		tree2[j] = -0.0137930848;
	}
	
tree0[j] = -0.00739339553;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0137658874;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.0256033745;
	}
	else{
		tree1[j] = 0.0108290166;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 0) < 5.94999981){
		tree2[j] = -0.01751546;
	}
	else{
		tree2[j] = 0.0153082563;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0128796361;
	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree1[j] = 0.00176533335;
	}
	else{
		tree1[j] = 0.0121601615;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0139219919;
	}
	else{
		tree2[j] = 0.0195092969;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0127096465;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.0240312777;
	}
	else{
		tree1[j] = 0.0110358652;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0124928216;
	}
	else{
		tree2[j] = 0.0183407106;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0114431828;
	}
	else{
		
	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree1[j] = -0.000298142142;
	}
	else{
		tree1[j] = 0.0127350697;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree2[j] = -0.0125616388;
	}
	else{
		tree2[j] = 0.0171724353;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		
	if (*(vin_buffer + 4*j + 2) < 4.85000038){
		tree1[j] = 0.0299698338;
	}
	else{
		tree1[j] = -0.0145980306;
	}
	

	}
	else{
		tree1[j] = -0.0107894456;
	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0120097874;
	}
	else{
		tree2[j] = 0.0183207784;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0122691374;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = 0.00133558048;
	}
	else{
		tree1[j] = 0.0142933894;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree2[j] = 0.0163324196;
	}
	else{
		tree2[j] = -0.0131506184;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0135137867;
	}
	else{
		tree1[j] = -0.00823191833;
	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0119348029;
	}
	else{
		tree2[j] = 0.0170012284;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.011005789;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = 0.00059482205;
	}
	else{
		tree1[j] = 0.0142794903;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree2[j] = 0.0158615597;
	}
	else{
		tree2[j] = -0.0124892779;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0135353347;
	}
	else{
		tree1[j] = -0.00792069081;
	}
	

	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree2[j] = -0.0121070305;
	}
	else{
		tree2[j] = 0.0155430175;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0127025414;
	}
	else{
		tree1[j] = -0.00705433683;
	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0113061052;
	}
	else{
		tree2[j] = 0.0161593575;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0105340928;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = 0.000365895889;
	}
	else{
		tree1[j] = 0.0146601265;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree2[j] = 0.0158712063;
	}
	else{
		tree2[j] = -0.0124820909;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0128018176;
	}
	else{
		tree1[j] = -0.00691608246;
	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0106259426;
	}
	else{
		tree2[j] = 0.0156752542;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.00944873877;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.00021602925;
	}
	else{
		tree1[j] = 0.0144590074;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree2[j] = 0.0153814591;
	}
	else{
		tree2[j] = -0.011736311;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0128630493;
	}
	else{
		tree1[j] = -0.00676393183;
	}
	

	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree2[j] = -0.0116176289;
	}
	else{
		tree2[j] = 0.0151311131;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0120970747;
	}
	else{
		tree1[j] = -0.00600560196;
	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.0101316646;
	}
	else{
		tree2[j] = 0.0150914779;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.0091198571;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.000330773415;
	}
	else{
		tree1[j] = 0.0146376276;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree2[j] = 0.0153467301;
	}
	else{
		tree2[j] = -0.0116140964;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0122227166;
	}
	else{
		tree1[j] = -0.0059719584;
	}
	

	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree2[j] = -0.0108043384;
	}
	else{
		tree2[j] = 0.0143785747;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = 0.00938121881;
	}
	else{
		tree1[j] = -0.00757900765;
	}
	

	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree2[j] = 0.0142252287;
	}
	else{
		tree2[j] = -0.0103512779;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0120470999;
	}
	else{
		tree1[j] = -0.00582764344;
	}
	

	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree2[j] = -0.00955164526;
	}
	else{
		tree2[j] = 0.0143568404;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 0) < 5.85000038){
		tree1[j] = -0.00876035076;
	}
	else{
		
	if (*(vin_buffer + 4*j + 3) < 1.6500001){
		tree1[j] = -0.000616947073;
	}
	else{
		tree1[j] = 0.0146507435;
	}
	

	}
	

	if (*(vin_buffer + 4*j + 1) < 2.8499999){
		tree2[j] = 0.0144770211;
	}
	else{
		tree2[j] = -0.0107313618;
	}
	
tree0[j] = 0;
	if (*(vin_buffer + 4*j + 1) < 2.75){
		tree1[j] = 0.0121253915;
	}
	else{
		tree1[j] = -0.00579718966;
	}
	

	if (*(vin_buffer + 4*j + 2) < 4.94999981){
		tree2[j] = -0.0102347787;
	}
	else{
		tree2[j] = 0.013704475;
	}
	

	}


	write_1:
	for (int j = 0; j < OUTPUT_DATA_SIZE; j++) {
#pragma HLS loop_tripcount min=OUTPUT_DATA_SIZE max=OUTPUT_DATA_SIZE
		output_values[j] = vout_buffer[j];
	}
}
}
