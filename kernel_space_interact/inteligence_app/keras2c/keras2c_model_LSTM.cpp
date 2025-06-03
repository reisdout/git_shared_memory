#include <math.h> 
#include <string.h> 
#include <iostream>
#include "./keras2c/Model/include/k2c_include.h" 
#include "./keras2c/Model/include/k2c_tensor_include.h" 
#include "./keras2c/LSTM_3000_epocas/keras2c_model_LSTM.h"

 
 using namespace std;


void LSTMModel::keras2c_model(const k2c_tensor* lstm_24_input_1_input, k2c_tensor* client_0_13_output) 
{ 
		/*

		float lstm_24_output_array[9] = {0}; 
		k2c_tensor lstm_24_1_output = {&lstm_24_output_array[0],2,9,{3,3,1,1,1}}; 
		float lstm_24_fwork[24] = {0}; 
		int lstm_24_go_backwards = 0;
		int lstm_24_return_sequences = 1;
		float lstm_24_state[6] = {0}; 
		float lstm_24_kernel_array[36] = {
		+6.65799737e-01f,+1.50157297e+00f,+4.06030750e+00f,-6.47513986e-01f,+1.33494186e+00f,
		+4.44655085e+00f,+2.05832624e+00f,+1.59611249e+00f,+2.25419617e+00f,-2.95792967e-01f,
		+2.53720939e-01f,+4.02951300e-01f,-2.91545272e-01f,+8.24735940e-01f,+9.38223824e-02f,
		+8.82028416e-03f,+6.85749710e-01f,-7.13573337e-01f,-9.95516926e-02f,-3.33011532e+00f,
		-1.16874032e-01f,+3.29514965e-02f,-1.25136268e+00f,+2.98025198e-02f,+9.65796053e-01f,
		-9.41047192e-01f,+8.25686753e-01f,-5.31542158e+00f,+3.02041709e-01f,+5.06732321e+00f,
		-2.62783790e+00f,+4.46585603e-02f,+2.47677898e+00f,+1.26810288e+00f,+1.04488289e+00f,
		+2.58962131e+00f,}; 
		k2c_tensor lstm_24_kernel = {&lstm_24_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
		float lstm_24_recurrent_kernel_array[36] = {
		+1.96960521e+00f,+1.64175808e+00f,+2.75920153e+00f,-8.82189941e+00f,-6.19097710e-01f,
		-8.90906811e+00f,+5.16270876e-01f,+5.34702480e-01f,+1.94431758e+00f,-3.11937541e-01f,
		+1.41555238e+00f,-1.48578668e+00f,+1.14860523e+00f,-7.41930664e-01f,+9.76558402e-02f,
		-5.79043090e-01f,+1.99073642e-01f,-3.05554897e-01f,-1.02687024e-01f,-2.13730955e+00f,
		-2.65853014e-02f,+3.55196834e-01f,+1.23844457e+00f,+3.33002567e-01f,-1.16666958e-01f,
		+1.21076323e-01f,-3.75683904e-01f,+2.71782488e-01f,+5.30053854e-01f,+3.02667427e+00f,
		-7.17021823e-01f,-1.11884415e+00f,-7.14225721e+00f,+1.55547354e-02f,-1.00918347e-02f,
		+5.91783345e-01f,}; 
		k2c_tensor lstm_24_recurrent_kernel = {&lstm_24_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
		float lstm_24_bias_array[12] = {
		+1.41935158e+00f,+1.36830413e+00f,+2.25607133e+00f,-2.78940916e-01f,+1.68839455e+00f,
		+3.55071723e-01f,-5.48472106e-01f,-4.42936152e-01f,-4.30338115e-01f,+9.50440288e-01f,
		+1.08839166e+00f,+2.83765531e+00f,}; 
		k2c_tensor lstm_24_bias = {&lstm_24_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

		
		float lstm_25_output_array[2] = {0}; 
		k2c_tensor lstm_25_1_output = {&lstm_25_output_array[0],1,2,{2,1,1,1,1}}; 
		float lstm_25_fwork[16] = {0}; 
		int lstm_25_go_backwards = 0;
		int lstm_25_return_sequences = 0;
		float lstm_25_state[4] = {0}; 
		float lstm_25_kernel_array[24] = {
		-1.67313838e+00f,+1.15210843e+00f,-8.89813483e-01f,-3.09778333e+00f,-2.74562073e+00f,
		-5.17053008e-01f,+1.97810829e+00f,+4.12558556e+00f,+4.15888429e-02f,-1.37617597e-02f,
		-2.79069734e+00f,+1.76597166e+00f,-9.05368805e+00f,+8.30631733e+00f,+5.06540528e-03f,
		+3.31808534e-03f,-3.45221162e+00f,+2.64517283e+00f,-2.55304217e-01f,+2.60019803e+00f,
		-1.83134007e+00f,-3.16676331e+00f,-1.84225750e+00f,+9.70886648e-01f,}; 
		k2c_tensor lstm_25_kernel = {&lstm_25_kernel_array[0],2,24,{12, 2, 1, 1, 1}}; 
		float lstm_25_recurrent_kernel_array[16] = {
		-1.85857987e+00f,-9.70237970e-01f,+2.91057229e+00f,+2.51203108e+00f,-1.28049493e-01f,
		+2.53143311e-01f,-9.22986746e-01f,-1.05562377e+00f,-3.01007986e-01f,-1.32479385e-01f,
		+4.16269712e-02f,-4.88986641e-01f,-2.58337712e+00f,-8.55689049e-01f,+3.08314013e+00f,
		+2.60398126e+00f,}; 
		k2c_tensor lstm_25_recurrent_kernel = {&lstm_25_recurrent_kernel_array[0],2,16,{8,2,1,1,1}}; 
		float lstm_25_bias_array[8] = {
		+2.98111320e+00f,+4.81175041e+00f,-3.95189255e-01f,-3.93679775e-02f,+1.48573490e-02f,
		-1.44399107e-02f,+3.61033511e+00f,+4.20342970e+00f,}; 
		k2c_tensor lstm_25_bias = {&lstm_25_bias_array[0],1,8,{8,1,1,1,1}}; 

		
		float client_0_kernel_array[2] = {
		-7.83691978e+00f,+8.29816055e+00f,}; 
		k2c_tensor client_0_kernel = {&client_0_kernel_array[0],2,2,{2,1,1,1,1}}; 
		float client_0_bias_array[1] = {
		-6.51536584e-02f,}; 
		k2c_tensor client_0_bias = {&client_0_bias_array[0],1,1,{1,1,1,1,1}}; 
		float client_0_fwork[4] = {0}; 

		
		k2c_lstm(&lstm_24_1_output,lstm_24_input_1_input,lstm_24_state,&lstm_24_kernel, 
			&lstm_24_recurrent_kernel,&lstm_24_bias,lstm_24_fwork, 
			lstm_24_go_backwards,lstm_24_return_sequences, 
			k2c_sigmoid,k2c_tanh); 
		k2c_tensor dropout_24_1_output; 
		dropout_24_1_output.ndim = lstm_24_1_output.ndim; // copy data into output struct 
		dropout_24_1_output.numel = lstm_24_1_output.numel; 
		memcpy(dropout_24_1_output.shape,lstm_24_1_output.shape,K2C_MAX_NDIM*sizeof(size_t));  
		dropout_24_1_output.array = &lstm_24_1_output.array[0]; // rename for clarity 
		k2c_lstm(&lstm_25_1_output,&dropout_24_1_output,lstm_25_state,&lstm_25_kernel, 
			&lstm_25_recurrent_kernel,&lstm_25_bias,lstm_25_fwork, 
			lstm_25_go_backwards,lstm_25_return_sequences, 
			k2c_sigmoid,k2c_tanh); 
		k2c_tensor dropout_25_1_output; 
		dropout_25_1_output.ndim = lstm_25_1_output.ndim; // copy data into output struct 
		dropout_25_1_output.numel = lstm_25_1_output.numel; 
		memcpy(dropout_25_1_output.shape,lstm_25_1_output.shape,K2C_MAX_NDIM*sizeof(size_t));  
		dropout_25_1_output.array = &lstm_25_1_output.array[0]; // rename for clarity 
		k2c_dense(client_0_13_output,&dropout_25_1_output,&client_0_kernel, 
			&client_0_bias,k2c_sigmoid,client_0_fwork); 

	*/

 } 

/*
void LSTMModel::keras2c_model_Round0000001_10Mbps(const k2c_tensor* lstm_4_input_1_input, k2c_tensor* client_0_1_output) { 

cout << "LSTMModel:: keras2c_model_Round0000001_10Mbps\n"; 

float lstm_4_output_array[9] = {0}; 
k2c_tensor lstm_4_output = {&lstm_4_output_array[0],2,9,{3,3,1,1,1}}; 
float lstm_4_fwork[24] = {0}; 
int lstm_4_go_backwards = 0;
int lstm_4_return_sequences = 1;
float lstm_4_state[6] = {0}; 
float lstm_4_kernel_array[36] = {
+1.46098566e+00f,+1.01678357e-01f,+3.70802999e+00f,+2.22893023e+00f,+1.06229436e+00f,
+3.39547205e+00f,+2.20098567e+00f,+2.87351155e+00f,+1.66636407e+00f,+5.43084383e-01f,
+7.42601335e-01f,+5.14583886e-01f,+9.34801698e-01f,+6.65910065e-01f,+4.35755938e-01f,
+1.26701796e+00f,+6.87833548e-01f,+3.57216410e-02f,-3.56222957e-01f,+2.60954797e-01f,
+4.57526445e-02f,+1.18590578e-01f,-6.44191802e-02f,+2.59577245e-01f,+9.35257614e-01f,
-7.77356505e-01f,-1.23096454e+00f,+7.62999356e-01f,-4.27149743e-01f,+5.80510712e+00f,
+1.09305811e+00f,-1.68272838e-01f,+5.54520082e+00f,+3.15564799e+00f,+4.31358194e+00f,
+3.58050495e-01f,}; 
k2c_tensor lstm_4_kernel = {&lstm_4_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
float lstm_4_recurrent_kernel_array[36] = {
+2.99016166e+00f,+3.11746931e+00f,+3.08320785e+00f,-3.00520420e+00f,-2.97596955e+00f,
-3.82591987e+00f,-2.50693011e+00f,-2.97290277e+00f,-2.11283636e+00f,+3.85276694e-03f,
-1.46578938e-01f,+1.46218970e-01f,-2.00154036e-01f,+1.17429674e-01f,-7.21600294e-01f,
+1.97606161e-01f,-4.71240312e-01f,+3.24997634e-01f,+3.09032828e-01f,+3.47681910e-01f,
+4.89887804e-01f,-1.89190693e-02f,+4.30195481e-01f,+7.54906703e-03f,+9.58851039e-01f,
-5.77725887e-01f,-5.21830261e-01f,+1.84941816e+00f,+1.13404047e+00f,+1.87021470e+00f,
-2.01023197e+00f,-6.85997009e-01f,-1.95738447e+00f,-1.21331263e+00f,-1.19627881e+00f,
+1.57154903e-01f,}; 
k2c_tensor lstm_4_recurrent_kernel = {&lstm_4_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
float lstm_4_bias_array[12] = {
+1.63576007e+00f,+1.47938538e+00f,+1.98653245e+00f,-9.53280330e-02f,+7.81444311e-02f,
+6.50430739e-01f,-3.69433492e-01f,+3.07627678e-01f,+4.88918900e-01f,+2.34492445e+00f,
+1.54319501e+00f,+6.82997346e-01f,}; 
k2c_tensor lstm_4_bias = {&lstm_4_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

 
float lstm_5_output_array[3] = {0}; 
k2c_tensor lstm_5_output = {&lstm_5_output_array[0],1,3,{3,1,1,1,1}}; 
float lstm_5_fwork[24] = {0}; 
int lstm_5_go_backwards = 0;
int lstm_5_return_sequences = 0;
float lstm_5_state[6] = {0}; 
float lstm_5_kernel_array[36] = {
+1.95149505e+00f,+2.25674224e+00f,+4.05497313e+00f,-2.25928545e+00f,-2.57602000e+00f,
-3.85789323e+00f,-1.30381429e+00f,-1.24399185e+00f,-2.69524193e+00f,+2.98805141e+00f,
+5.42472172e+00f,+2.95734978e+00f,-2.73136568e+00f,-5.45198202e+00f,-2.82308769e+00f,
-2.40995288e+00f,-4.68685532e+00f,-2.12910962e+00f,-3.65487766e+00f,-2.62294602e+00f,
-2.58046317e+00f,+4.21241903e+00f,+3.08625937e+00f,+2.95457745e+00f,+2.93724132e+00f,
+1.91035819e+00f,+2.11307406e+00f,+7.62907088e-01f,+1.95109022e+00f,+1.64302504e+00f,
-9.40926254e-01f,-2.05249596e+00f,-2.16167998e+00f,-4.42051530e-01f,-7.49143660e-02f,
-5.54789245e-01f,}; 
k2c_tensor lstm_5_kernel = {&lstm_5_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
float lstm_5_recurrent_kernel_array[36] = {
-9.35142711e-02f,+3.10839683e-01f,+1.92576572e-01f,-4.53013405e-02f,+2.83633739e-01f,
+1.72602922e-01f,-2.00213686e-01f,-6.87036440e-02f,+2.25685965e-02f,+6.00737743e-02f,
+6.00146949e-01f,+8.30464780e-01f,+5.29664934e-01f,+7.22639441e-01f,+5.21084845e-01f,
+2.40155384e-01f,+6.18453562e-01f,+3.98836344e-01f,+2.34050378e-01f,+6.61246598e-01f,
+2.60985970e-01f,-1.79906055e-01f,-2.57936269e-01f,+3.99173439e-01f,-4.38095510e-01f,
-9.80784833e-01f,-1.31259358e+00f,-5.06260097e-01f,-1.56995565e-01f,+6.60930395e-01f,
-2.92484939e-01f,+7.53284276e-01f,+1.05730808e+00f,-1.69906139e+00f,-6.57192349e-01f,
+6.27361536e-01f,}; 
k2c_tensor lstm_5_recurrent_kernel = {&lstm_5_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
float lstm_5_bias_array[12] = {
+1.65709758e+00f,+1.35117280e+00f,+2.34992051e+00f,-2.86095262e-01f,+6.70524895e-01f,
+8.79207492e-01f,-2.15983968e-02f,-7.11816177e-02f,-5.95134348e-02f,+3.98638034e+00f,
+7.47091818e+00f,+4.41429329e+00f,}; 
k2c_tensor lstm_5_bias = {&lstm_5_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

 
float client_0_kernel_array[3] = {
-1.13051720e+01f,-1.28088522e+01f,-1.42298574e+01f,}; 
k2c_tensor client_0_kernel = {&client_0_kernel_array[0],2,3,{3,1,1,1,1}}; 
float client_0_bias_array[1] = {
-5.39587028e-02f,}; 
k2c_tensor client_0_bias = {&client_0_bias_array[0],1,1,{1,1,1,1,1}}; 
float client_0_fwork[6] = {0}; 

 
k2c_lstm(&lstm_4_output,lstm_4_input_1_input,lstm_4_state,&lstm_4_kernel, 
	&lstm_4_recurrent_kernel,&lstm_4_bias,lstm_4_fwork, 
	lstm_4_go_backwards,lstm_4_return_sequences, 
	k2c_sigmoid,k2c_tanh); 
k2c_tensor dropout_4_1_output; 
dropout_4_1_output.ndim = lstm_4_output.ndim; // copy data into output struct 
dropout_4_1_output.numel = lstm_4_output.numel; 
memcpy(dropout_4_1_output.shape,lstm_4_output.shape,K2C_MAX_NDIM*sizeof(size_t));  
dropout_4_1_output.array = &lstm_4_output.array[0]; // rename for clarity 
k2c_lstm(&lstm_5_output,&dropout_4_1_output,lstm_5_state,&lstm_5_kernel, 
	&lstm_5_recurrent_kernel,&lstm_5_bias,lstm_5_fwork, 
	lstm_5_go_backwards,lstm_5_return_sequences, 
	k2c_sigmoid,k2c_tanh); 
k2c_tensor dropout_5_1_output; 
dropout_5_1_output.ndim = lstm_5_output.ndim; // copy data into output struct 
dropout_5_1_output.numel = lstm_5_output.numel; 
memcpy(dropout_5_1_output.shape,lstm_5_output.shape,K2C_MAX_NDIM*sizeof(size_t));  
dropout_5_1_output.array = &lstm_5_output.array[0]; // rename for clarity 
k2c_dense(client_0_1_output,&dropout_5_1_output,&client_0_kernel, 
	&client_0_bias,k2c_sigmoid,client_0_fwork); 

return;
 } 
*/



void LSTMModel::keras2c_model_Round_COMPLEXITY(const k2c_tensor* input_layer_14_input, k2c_tensor* keras_tensor_9_output) 
{ 

		cout << "LSTM_ACK_SND_RTT_Model_Round_COMPLEXITY\n";
		float lstm_4_output_array[9] = {0}; 
		k2c_tensor lstm_4_output = {&lstm_4_output_array[0],2,9,{3,3,1,1,1}}; 
		float lstm_4_fwork[24] = {0}; 
		int lstm_4_go_backwards = 0;
		int lstm_4_return_sequences = 1;
		float lstm_4_state[6] = {0}; 
		float lstm_4_kernel_array[36] = {
		-1.72308356e-01f,-2.52803469e+00f,-2.48543048e+00f,+8.08681369e-01f,-2.70675921e+00f,
		-2.69753718e+00f,+1.68915308e+00f,+1.99233279e-01f,-1.66525945e-01f,+1.49272192e+00f,
		+1.07308221e+00f,+4.10574436e-01f,+1.74748290e+00f,-1.59481078e-01f,+1.60732403e-01f,
		+1.64694524e+00f,-3.57734531e-01f,-5.55269778e-01f,-5.54913655e-02f,-1.70440033e-01f,
		-8.72301459e-02f,+1.74223855e-01f,+9.48851183e-02f,+2.01210100e-02f,-7.18187213e-01f,
		+7.08987594e-01f,+6.49968982e-01f,+2.85301059e-01f,+9.08041239e-01f,-7.10121095e-01f,
		+1.24317431e+00f,+3.38047117e-01f,+5.38460433e-01f,+1.94086790e+00f,+3.11157298e+00f,
		+2.80327225e+00f,}; 
		k2c_tensor lstm_4_kernel = {&lstm_4_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
		float lstm_4_recurrent_kernel_array[36] = {
		-2.11409640e+00f,-5.29808474e+00f,-5.32010698e+00f,+1.06047726e+00f,+2.47532654e+00f,
		+2.28919196e+00f,+1.06036437e+00f,+8.76592934e-01f,+6.42183423e-01f,+8.61032903e-01f,
		-5.54148138e-01f,-8.91310573e-01f,+3.18146467e+00f,-1.23698926e+00f,-1.84803152e+00f,
		+2.89466548e+00f,-1.06890845e+00f,-1.52570009e+00f,+9.65495646e-01f,+9.16059092e-02f,
		+8.93483981e-02f,-1.90928411e+00f,-2.46908799e-01f,-3.72954786e-01f,-1.47548187e+00f,
		-3.19921196e-01f,-1.42720789e-01f,-1.14642560e+00f,-5.03837585e+00f,-5.52361393e+00f,
		+1.74110365e+00f,-5.89192629e-01f,-2.83510834e-01f,+1.63915026e+00f,-1.21176493e+00f,
		-6.16545200e-01f,}; 
		k2c_tensor lstm_4_recurrent_kernel = {&lstm_4_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
		float lstm_4_bias_array[12] = {
		+6.07016385e-01f,+6.63496137e-01f,+9.30869222e-01f,+1.66923797e+00f,+1.28704263e-02f,
		+3.43618035e-01f,+3.83221239e-01f,-4.78799760e-01f,-4.40143883e-01f,+5.23177803e-01f,
		+3.16988873e+00f,+3.52584720e+00f,}; 
		k2c_tensor lstm_4_bias = {&lstm_4_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

		
		float lstm_5_output_array[3] = {0}; 
		k2c_tensor lstm_5_output = {&lstm_5_output_array[0],1,3,{3,1,1,1,1}}; 
		float lstm_5_fwork[24] = {0}; 
		int lstm_5_go_backwards = 0;
		int lstm_5_return_sequences = 0;
		float lstm_5_state[6] = {0}; 
		float lstm_5_kernel_array[36] = {
		-3.04261780e+00f,-4.05297136e+00f,-3.22936821e+00f,+1.14521825e+00f,+2.02391768e+00f,
		+2.12291050e+00f,+1.00776553e+00f,+1.24754691e+00f,+1.97425854e+00f,+2.96259969e-01f,
		+2.24483013e-01f,+1.76015958e-01f,+3.90642071e+00f,+3.45722151e+00f,+2.19204545e+00f,
		+4.00131655e+00f,+3.74191642e+00f,+2.72604680e+00f,+1.08237691e-01f,+8.23922157e-02f,
		+5.64997457e-02f,-5.71110964e+00f,-6.74801493e+00f,-6.63102818e+00f,-6.05510712e+00f,
		-6.93862534e+00f,-6.74117661e+00f,-3.22733569e+00f,-2.16695094e+00f,-3.50133944e+00f,
		+1.66987896e+00f,+3.29560447e+00f,+1.99924111e+00f,+7.30778694e-01f,+2.82902241e+00f,
		+1.62268031e+00f,}; 
		k2c_tensor lstm_5_kernel = {&lstm_5_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
		float lstm_5_recurrent_kernel_array[36] = {
		+6.68296456e-01f,+9.02438581e-01f,+9.57632542e-01f,-9.76805985e-01f,-2.54817575e-01f,
		+3.40312161e-02f,+2.77733833e-01f,+4.17584091e-01f,+7.29729712e-01f,+1.09619796e+00f,
		+1.59934521e+00f,+1.58424544e+00f,+1.04473376e+00f,+5.16263247e-01f,+7.07584023e-01f,
		+1.54453039e+00f,+1.20698345e+00f,+8.65187645e-01f,+1.32974431e-01f,+1.15992926e-01f,
		+4.52566981e-01f,+2.05680460e-01f,+4.07968611e-02f,-4.71309006e-01f,-3.69675338e-01f,
		-2.82472193e-01f,-5.09276800e-02f,-5.23549259e-01f,+2.94474632e-01f,+6.90127611e-01f,
		-6.32021904e-01f,-7.79739678e-01f,-5.17971098e-01f,-2.72958934e-01f,+3.58778775e-01f,
		+9.68013182e-02f,}; 
		k2c_tensor lstm_5_recurrent_kernel = {&lstm_5_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
		float lstm_5_bias_array[12] = {
		+4.21019697e+00f,+3.73109269e+00f,+4.01968670e+00f,+2.11882377e+00f,+2.04667068e+00f,
		+1.83665860e+00f,+3.38193141e-02f,+3.00786365e-02f,+2.47620679e-02f,+4.56627274e+00f,
		+5.10650587e+00f,+5.23888254e+00f,}; 
		k2c_tensor lstm_5_bias = {&lstm_5_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

		
		float client_0_output_array[1] = {0}; 
		k2c_tensor client_0_output = {&client_0_output_array[0],1,1,{1,1,1,1,1}}; 
		float client_0_kernel_array[3] = {
		-8.88045692e+00f,-8.63310051e+00f,-8.79765892e+00f,}; 
		k2c_tensor client_0_kernel = {&client_0_kernel_array[0],2,3,{3,1,1,1,1}}; 
		float client_0_bias_array[1] = {
		-1.10497877e-01f,}; 
		k2c_tensor client_0_bias = {&client_0_bias_array[0],1,1,{1,1,1,1,1}}; 
		float client_0_fwork[6] = {0}; 

		
		k2c_lstm(&lstm_4_output,input_layer_14_input,lstm_4_state,&lstm_4_kernel, 
			&lstm_4_recurrent_kernel,&lstm_4_bias,lstm_4_fwork, 
			lstm_4_go_backwards,lstm_4_return_sequences, 
			k2c_sigmoid,k2c_tanh); 
		k2c_tensor dropout_4_output; 
		dropout_4_output.ndim = lstm_4_output.ndim; // copy data into output struct 
		dropout_4_output.numel = lstm_4_output.numel; 
		memcpy(dropout_4_output.shape,lstm_4_output.shape,K2C_MAX_NDIM*sizeof(size_t));  
		dropout_4_output.array = &lstm_4_output.array[0]; // rename for clarity 
		k2c_lstm(&lstm_5_output,&dropout_4_output,lstm_5_state,&lstm_5_kernel, 
			&lstm_5_recurrent_kernel,&lstm_5_bias,lstm_5_fwork, 
			lstm_5_go_backwards,lstm_5_return_sequences, 
			k2c_sigmoid,k2c_tanh); 
		k2c_tensor dropout_5_output; 
		dropout_5_output.ndim = lstm_5_output.ndim; // copy data into output struct 
		dropout_5_output.numel = lstm_5_output.numel; 
		memcpy(dropout_5_output.shape,lstm_5_output.shape,K2C_MAX_NDIM*sizeof(size_t));  
		dropout_5_output.array = &lstm_5_output.array[0]; // rename for clarity 
		k2c_dense(keras_tensor_9_output,&dropout_5_output,&client_0_kernel, 
			&client_0_bias,k2c_sigmoid,client_0_fwork);
} 



void LSTMModel::keras2c_model_initialize() { 

	cout << "Inicializando modelo LSTM" << endl;

} 

void LSTMModel::keras2c_model_terminate() { 

	cout << "Finalizando modelo LSTM" << endl;

} 

