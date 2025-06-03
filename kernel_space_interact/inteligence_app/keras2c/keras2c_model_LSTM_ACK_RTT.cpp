#include <math.h> 
#include <string.h> 
#include <iostream>
#include "./keras2c/Model/include/k2c_include.h" 
#include "./keras2c/Model/include/k2c_tensor_include.h" 
#include "./keras2c/LSTM_3000_epocas_ACK_RTT/keras2c_model_LSTM_ACK_RTT.h"


 using namespace std;



void LSTM_ACK_RTTModel::keras2c_model_Round0000003_500Mbps(const k2c_tensor* lstm_10_input_input, k2c_tensor* client_0_output) { 

cout <<"LSTM_ACK_RTTModel Round0000003_500Mbps\n";

float lstm_10_output_array[9] = {0}; 
k2c_tensor lstm_10_output = {&lstm_10_output_array[0],2,9,{3,3,1,1,1}}; 
float lstm_10_fwork[24] = {0}; 
int lstm_10_go_backwards = 0;
int lstm_10_return_sequences = 1;
float lstm_10_state[6] = {0}; 
float lstm_10_kernel_array[24] = {
-6.34261036e+00f,+9.95271111e+00f,-7.50060701e+00f,+1.87215722e+00f,+1.88815117e+00f,
-3.53301287e-01f,-1.60672474e+00f,+1.22258425e-01f,-2.48552036e+00f,-8.29111695e-01f,
-5.64553976e-01f,-6.16913915e-01f,-4.71716374e-03f,-2.03264970e-03f,-3.24426627e+00f,
-4.82909650e-01f,-6.91734195e-01f,+2.15531304e-01f,-1.99678254e+00f,+1.02073278e+01f,
-5.99384785e+00f,+5.76242113e+00f,+3.75361300e+00f,-2.33368799e-01f,}; 
k2c_tensor lstm_10_kernel = {&lstm_10_kernel_array[0],2,24,{8,3,1,1,1}}; 
float lstm_10_recurrent_kernel_array[36] = {
-3.01131749e+00f,-2.08150887e+00f,+9.34175670e-01f,-2.64283967e+00f,-2.01516581e+00f,
+7.66515553e-01f,+1.27584791e+00f,+6.99787951e+00f,+3.78737497e+00f,+1.86767113e+00f,
-2.42398477e+00f,+2.76217961e+00f,-3.83559370e+00f,+4.50370264e+00f,+8.76892626e-01f,
-8.46489966e-01f,-2.57062006e+00f,+3.77383828e+00f,-3.42506468e-01f,-2.06401125e-02f,
+3.35023212e+00f,+1.93272103e-02f,-4.71561909e-01f,+1.08501935e+00f,+4.38426733e-02f,
+4.98887263e-02f,+1.22739720e+00f,+1.84646189e+00f,-2.73758268e+00f,+2.48387265e+00f,
+3.99183422e-01f,-1.37186557e-01f,+1.92441642e+00f,+3.04487586e+00f,+6.23723555e+00f,
+4.47424555e+00f,}; 
k2c_tensor lstm_10_recurrent_kernel = {&lstm_10_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
float lstm_10_bias_array[12] = {
+2.32679796e+00f,+1.50054312e+00f,+2.12743416e-01f,-3.55272532e-01f,+1.81213304e-01f,
+6.44900560e-01f,+3.58326674e-01f,+5.12185216e-01f,-1.84619725e-02f,+5.55242920e+00f,
+3.08085895e+00f,+6.36217058e-01f,}; 
k2c_tensor lstm_10_bias = {&lstm_10_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

 
float lstm_11_output_array[3] = {0}; 
k2c_tensor lstm_11_output = {&lstm_11_output_array[0],1,3,{3,1,1,1,1}}; 
float lstm_11_fwork[24] = {0}; 
int lstm_11_go_backwards = 0;
int lstm_11_return_sequences = 0;
float lstm_11_state[6] = {0}; 
float lstm_11_kernel_array[36] = {
+1.63310790e+00f,+4.41877985e+00f,-5.49842536e-01f,+6.48064804e+00f,+4.60031271e+00f,
+4.19864178e+00f,+3.59393239e+00f,+3.27032113e+00f,+5.23263836e+00f,-4.89996880e-01f,
+1.30239189e+00f,-3.72617126e-01f,-9.67902780e-01f,+2.18239880e+00f,-3.96708727e+00f,
+3.25582719e+00f,-6.54910088e-01f,-4.48728144e-01f,+8.60295105e+00f,+6.72098017e+00f,
+5.44184113e+00f,+5.66870356e+00f,+5.11331129e+00f,+4.15239859e+00f,+6.61686897e-01f,
+2.77927518e-01f,+3.76098394e-01f,+2.36229920e+00f,+2.07463908e+00f,+3.18075204e+00f,
+6.19874716e+00f,+2.29731250e+00f,+4.87829018e+00f,-6.29331231e-01f,+2.51461387e+00f,
+3.53457904e+00f,}; 
k2c_tensor lstm_11_kernel = {&lstm_11_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
float lstm_11_recurrent_kernel_array[36] = {
+4.13233578e-01f,-1.04866683e+00f,-9.88724113e-01f,+1.31391680e+00f,-3.34605098e-01f,
-1.57429621e-01f,-6.47889435e-01f,-1.85856366e+00f,-2.44248366e+00f,+2.09833407e+00f,
+4.94263321e-01f,+8.14814925e-01f,+2.60593939e+00f,-3.15226793e-01f,+1.52138138e+00f,
+2.25994706e+00f,+5.31340778e-01f,+7.76310265e-01f,-2.52915055e-01f,+3.22074085e-01f,
+1.73207238e-01f,-9.30860698e-01f,-1.38177598e+00f,-9.74517226e-01f,+5.97787201e-01f,
+7.25545883e-01f,+2.53394693e-01f,-2.22878385e+00f,-1.20608890e-02f,+2.40585303e+00f,
-2.27425313e+00f,-1.07938670e-01f,+3.47289872e+00f,-4.35169315e+00f,-7.94811368e-01f,
+6.82853103e-01f,}; 
k2c_tensor lstm_11_recurrent_kernel = {&lstm_11_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
float lstm_11_bias_array[12] = {
+3.54093456e+00f,+3.17012811e+00f,+2.70102310e+00f,+2.30266094e+00f,+2.29269654e-01f,
+2.02336788e+00f,-1.29854251e-02f,-6.32054964e-03f,-1.18458355e-02f,+2.43587399e+00f,
+3.90641260e+00f,+3.53459430e+00f,}; 
k2c_tensor lstm_11_bias = {&lstm_11_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

 
float client_0_kernel_array[3] = {
-5.27961159e+00f,-5.62408733e+00f,-6.19533825e+00f,}; 
k2c_tensor client_0_kernel = {&client_0_kernel_array[0],2,3,{3,1,1,1,1}}; 
float client_0_bias_array[1] = {
+6.55532768e-03f,}; 
k2c_tensor client_0_bias = {&client_0_bias_array[0],1,1,{1,1,1,1,1}}; 
float client_0_fwork[6] = {0}; 

 
k2c_lstm(&lstm_10_output,lstm_10_input_input,lstm_10_state,&lstm_10_kernel, 
	&lstm_10_recurrent_kernel,&lstm_10_bias,lstm_10_fwork, 
	lstm_10_go_backwards,lstm_10_return_sequences, 
	k2c_sigmoid,k2c_tanh); 
k2c_tensor dropout_10_output; 
dropout_10_output.ndim = lstm_10_output.ndim; // copy data into output struct 
dropout_10_output.numel = lstm_10_output.numel; 
memcpy(dropout_10_output.shape,lstm_10_output.shape,K2C_MAX_NDIM*sizeof(size_t));  
dropout_10_output.array = &lstm_10_output.array[0]; // rename for clarity 
k2c_lstm(&lstm_11_output,&dropout_10_output,lstm_11_state,&lstm_11_kernel, 
	&lstm_11_recurrent_kernel,&lstm_11_bias,lstm_11_fwork, 
	lstm_11_go_backwards,lstm_11_return_sequences, 
	k2c_sigmoid,k2c_tanh); 
k2c_tensor dropout_11_output; 
dropout_11_output.ndim = lstm_11_output.ndim; // copy data into output struct 
dropout_11_output.numel = lstm_11_output.numel; 
memcpy(dropout_11_output.shape,lstm_11_output.shape,K2C_MAX_NDIM*sizeof(size_t));  
dropout_11_output.array = &lstm_11_output.array[0]; // rename for clarity 
k2c_dense(client_0_output,&dropout_11_output,&client_0_kernel, 
	&client_0_bias,k2c_sigmoid,client_0_fwork); 

 } 





void  LSTM_ACK_RTTModel::keras2c_model_Round0000004_1000Mbps(const k2c_tensor* lstm_10_input_input, k2c_tensor* client_0_output) { 

cout <<"LSTM_ACK_RTTModel Round0000004_1000Mbps\n";

float lstm_10_output_array[9] = {0}; 
k2c_tensor lstm_10_output = {&lstm_10_output_array[0],2,9,{3,3,1,1,1}}; 
float lstm_10_fwork[24] = {0}; 
int lstm_10_go_backwards = 0;
int lstm_10_return_sequences = 1;
float lstm_10_state[6] = {0}; 
float lstm_10_kernel_array[24] = {
-4.58835304e-01f,-1.92137516e+00f,+3.76712143e-01f,-7.62376606e-01f,+1.62304783e+00f,
+9.77895439e-01f,-3.09255749e-01f,-9.83882666e-01f,-7.27517605e-01f,-4.47735697e-01f,
-4.25846845e-01f,+8.06870282e-01f,-1.56585991e-01f,-2.60856226e-02f,+2.97135599e-02f,
-7.48766184e-01f,-6.41079128e-01f,+6.81787431e-01f,+3.98775935e-01f,-2.42363334e+00f,
+4.37640399e-01f,-6.49224743e-02f,+2.24250579e+00f,+3.44336653e+00f,}; 
k2c_tensor lstm_10_kernel = {&lstm_10_kernel_array[0],2,24,{8,3,1,1,1}}; 
float lstm_10_recurrent_kernel_array[36] = {
+2.99832404e-01f,-2.64140153e+00f,-5.52453470e+00f,+2.36111954e-01f,-2.00655508e+00f,
-4.70920849e+00f,-2.56857842e-01f,+1.91785634e+00f,+7.42478371e+00f,-2.82758057e-01f,
+7.82690108e-01f,+8.14563394e-01f,+9.67602730e-02f,+2.39981651e+00f,+8.01026285e-01f,
-2.03033134e-01f,-1.10042417e+00f,-9.52107668e-01f,+7.48809159e-01f,-5.46467245e-01f,
+7.34478593e-01f,+3.12578343e-02f,-7.03737557e-01f,+5.02701819e-01f,-1.03372538e+00f,
-3.65031689e-01f,-2.00597525e-01f,-4.18250114e-01f,-2.38359976e+00f,-1.61041677e+00f,
+3.78682911e-01f,-4.27280277e-01f,-4.65952730e+00f,+5.34790218e-01f,+9.91690755e-01f,
+4.92879200e+00f,}; 
k2c_tensor lstm_10_recurrent_kernel = {&lstm_10_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
float lstm_10_bias_array[12] = {
+2.18351185e-02f,+1.77278841e+00f,+8.85789931e-01f,+9.71974313e-01f,+4.08071429e-02f,
+2.05943197e-01f,-4.05206472e-01f,+3.74047518e-01f,-3.56972069e-01f,+8.94126818e-02f,
+1.45866120e+00f,+2.17911911e+00f,}; 
k2c_tensor lstm_10_bias = {&lstm_10_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

 
float lstm_11_output_array[3] = {0}; 
k2c_tensor lstm_11_output = {&lstm_11_output_array[0],1,3,{3,1,1,1,1}}; 
float lstm_11_fwork[24] = {0}; 
int lstm_11_go_backwards = 0;
int lstm_11_return_sequences = 0;
float lstm_11_state[6] = {0}; 
float lstm_11_kernel_array[36] = {
-2.17884183e+00f,-2.67063975e+00f,+1.06131852e-01f,+1.81842721e+00f,+5.76730631e-02f,
-9.81437862e-01f,+1.57033670e+00f,+1.40363073e+00f,-1.08003902e+00f,+7.76838064e-02f,
-4.36531641e-02f,+5.59321225e-01f,-1.57387662e+00f,-2.49402881e+00f,-2.45749637e-01f,
+2.57436681e+00f,+3.20960569e+00f,-2.28030157e+00f,-1.21011743e-02f,+5.06047672e-03f,
+7.83067882e-01f,-3.11536789e+00f,-3.42360950e+00f,+5.72234094e-01f,+2.76705217e+00f,
+3.29157495e+00f,-2.25757305e-02f,-3.03955698e+00f,-2.43630362e+00f,+2.52955943e-01f,
+6.04218483e-01f,-1.56916809e+00f,-8.23996663e-01f,+3.01287365e+00f,+2.34837532e+00f,
-2.34122133e+00f,}; 
k2c_tensor lstm_11_kernel = {&lstm_11_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
float lstm_11_recurrent_kernel_array[36] = {
+2.74899626e+00f,+2.12671900e+00f,+3.34469318e-01f,+3.26940155e+00f,+1.87248790e+00f,
-3.55759621e-01f,-3.05363750e+00f,-5.37006950e+00f,+2.24067315e-01f,-5.97732842e-01f,
-6.37648761e-01f,-9.59692240e-01f,-3.96414816e-01f,-4.48197052e-02f,-2.64850527e-01f,
+8.63375902e-01f,+1.30892754e+00f,-6.36192337e-02f,+1.90504298e-01f,+1.34032974e-02f,
+1.86145620e-03f,-5.53784788e-01f,-4.11106408e-01f,-5.64048171e-01f,+4.48967703e-02f,
-6.57213330e-02f,+2.64546961e-01f,+1.46950769e+00f,+1.14971459e+00f,+1.99135505e-02f,
+1.76932597e+00f,+1.15936387e+00f,+2.43609920e-01f,-3.04787564e+00f,-3.61908889e+00f,
+1.33306449e-02f,}; 
k2c_tensor lstm_11_recurrent_kernel = {&lstm_11_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
float lstm_11_bias_array[12] = {
+2.15905190e+00f,+2.31817794e+00f,+4.43168432e-01f,+4.70193118e-01f,+1.96409181e-01f,
+1.11992526e+00f,-4.24306793e-03f,-2.70357542e-02f,-8.56143892e-01f,+3.06367588e+00f,
+2.60075402e+00f,+3.79219919e-01f,}; 
k2c_tensor lstm_11_bias = {&lstm_11_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

 
float client_0_kernel_array[3] = {
+9.99200821e+00f,+8.67287064e+00f,+2.23074555e-02f,}; 
k2c_tensor client_0_kernel = {&client_0_kernel_array[0],2,3,{3,1,1,1,1}}; 
float client_0_bias_array[1] = {
-2.21988391e-02f,}; 
k2c_tensor client_0_bias = {&client_0_bias_array[0],1,1,{1,1,1,1,1}}; 
float client_0_fwork[6] = {0}; 

 
k2c_lstm(&lstm_10_output,lstm_10_input_input,lstm_10_state,&lstm_10_kernel, 
	&lstm_10_recurrent_kernel,&lstm_10_bias,lstm_10_fwork, 
	lstm_10_go_backwards,lstm_10_return_sequences, 
	k2c_sigmoid,k2c_tanh); 
k2c_tensor dropout_10_output; 
dropout_10_output.ndim = lstm_10_output.ndim; // copy data into output struct 
dropout_10_output.numel = lstm_10_output.numel; 
memcpy(dropout_10_output.shape,lstm_10_output.shape,K2C_MAX_NDIM*sizeof(size_t));  
dropout_10_output.array = &lstm_10_output.array[0]; // rename for clarity 
k2c_lstm(&lstm_11_output,&dropout_10_output,lstm_11_state,&lstm_11_kernel, 
	&lstm_11_recurrent_kernel,&lstm_11_bias,lstm_11_fwork, 
	lstm_11_go_backwards,lstm_11_return_sequences, 
	k2c_sigmoid,k2c_tanh); 
k2c_tensor dropout_11_output; 
dropout_11_output.ndim = lstm_11_output.ndim; // copy data into output struct 
dropout_11_output.numel = lstm_11_output.numel; 
memcpy(dropout_11_output.shape,lstm_11_output.shape,K2C_MAX_NDIM*sizeof(size_t));  
dropout_11_output.array = &lstm_11_output.array[0]; // rename for clarity 
k2c_dense(client_0_output,&dropout_11_output,&client_0_kernel, 
	&client_0_bias,k2c_sigmoid,client_0_fwork); 

 } 


 void LSTM_ACK_RTTModel::keras2c_model_Round_COMPLEXITY(const k2c_tensor* input_layer_17_input, k2c_tensor* keras_tensor_74_output) 
 { 

	cout << "LSTM_ACK_RTT_Model_Round_COMPLEXITY\n";

	float lstm_10_output_array[9] = {0}; 
	k2c_tensor lstm_10_output = {&lstm_10_output_array[0],2,9,{3,3,1,1,1}}; 
	float lstm_10_fwork[24] = {0}; 
	int lstm_10_go_backwards = 0;
	int lstm_10_return_sequences = 1;
	float lstm_10_state[6] = {0}; 
	float lstm_10_kernel_array[24] = {
	-1.80802476e+00f,-3.50052190e+00f,-3.36128807e+00f,+3.05798721e+00f,+9.16732103e-02f,
	-1.57919109e-01f,+1.58375049e+00f,+2.35380650e+00f,+2.24113989e+00f,+4.65664357e-01f,
	-1.80242360e-01f,+7.94004649e-02f,+7.01361075e-02f,+7.12739453e-02f,-6.30569756e-02f,
	-7.29318619e-01f,-6.66601956e-01f,+6.76471651e-01f,-2.50723809e-01f,-6.69146627e-02f,
	+4.62939292e-01f,+3.22988605e+00f,+5.39090395e+00f,+3.50907159e+00f,}; 
	k2c_tensor lstm_10_kernel = {&lstm_10_kernel_array[0],2,24,{8,3,1,1,1}}; 
	float lstm_10_recurrent_kernel_array[36] = {
	-4.31302404e+00f,-6.05029583e+00f,-5.60542965e+00f,-5.05749178e+00f,-5.02776384e+00f,
	-4.21240520e+00f,+4.06352186e+00f,+3.86840701e+00f,+4.06498718e+00f,-1.37891138e+00f,
	+1.56165659e+00f,+1.48245394e+00f,-1.44654876e-02f,+1.73446536e+00f,+1.11965585e+00f,
	+1.12078226e+00f,-3.70892525e-01f,-1.24547207e+00f,-1.17106736e+00f,-5.84727585e-01f,
	+8.69931340e-01f,-1.27778634e-01f,-4.42171603e-01f,+3.89744610e-01f,-8.48741353e-01f,
	-4.35269594e-01f,+4.75479275e-01f,-4.00634527e+00f,-2.86890912e+00f,-4.86640120e+00f,
	-4.61210346e+00f,-2.50669694e+00f,-2.48980165e+00f,+3.95116377e+00f,+2.30197072e+00f,
	+6.91234648e-01f,}; 
	k2c_tensor lstm_10_recurrent_kernel = {&lstm_10_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
	float lstm_10_bias_array[12] = {
	+2.97629189e+00f,+1.28239965e+00f,+9.50464845e-01f,-7.09067881e-01f,+3.25298935e-01f,
	+1.28791428e+00f,+5.24250329e-01f,+4.62014675e-01f,-4.76838559e-01f,+3.38795877e+00f,
	+4.96919298e+00f,+3.64105153e+00f,}; 
	k2c_tensor lstm_10_bias = {&lstm_10_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

	
	float lstm_11_output_array[3] = {0}; 
	k2c_tensor lstm_11_output = {&lstm_11_output_array[0],1,3,{3,1,1,1,1}}; 
	float lstm_11_fwork[24] = {0}; 
	int lstm_11_go_backwards = 0;
	int lstm_11_return_sequences = 0;
	float lstm_11_state[6] = {0}; 
	float lstm_11_kernel_array[36] = {
	-1.79734099e+00f,+1.50827968e+00f,+4.81387258e-01f,-2.99161601e+00f,-4.93847728e-01f,
	-1.30259967e+00f,+5.41871214e+00f,+2.20811009e+00f,+2.87108469e+00f,-6.35167360e+00f,
	-4.24789524e+00f,-4.09597635e+00f,-5.42289305e+00f,-3.54176497e+00f,-2.96741629e+00f,
	+6.03953457e+00f,+4.38903475e+00f,+4.10989571e+00f,-2.38468242e+00f,+2.23889303e+00f,
	-2.03806067e+00f,-5.74834633e+00f,+5.48798800e+00f,-5.13053322e+00f,+6.23333311e+00f,
	-6.40175343e+00f,+5.89616251e+00f,-1.59750783e+00f,-5.66950679e-01f,-9.90734175e-02f,
	-2.24063134e+00f,-9.01340842e-01f,-1.23322570e+00f,+2.76165366e+00f,+2.01605701e+00f,
	+1.46404743e+00f,}; 
	k2c_tensor lstm_11_kernel = {&lstm_11_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
	float lstm_11_recurrent_kernel_array[36] = {
	+1.89717460e+00f,+1.36896074e+00f,+9.54452336e-01f,+1.17927814e+00f,+6.66080654e-01f,
	+3.49338472e-01f,-7.48874724e-01f,-7.93996811e-01f,-5.63740075e-01f,-4.04630341e-02f,
	-2.25237697e-01f,+3.70026641e-02f,+1.43089926e+00f,+1.25462198e+00f,+1.19724858e+00f,
	-1.35627413e+00f,-1.35314536e+00f,-1.24881482e+00f,-2.69176841e-01f,+8.63964111e-02f,
	+1.19756490e-01f,+1.43970177e-01f,-3.57818097e-01f,+3.26766521e-01f,+4.07117680e-02f,
	-5.30003645e-02f,-1.47383690e-01f,+1.12381673e+00f,+8.64658296e-01f,+1.35690701e+00f,
	+1.66307434e-01f,+4.59001303e-01f,+4.64678317e-01f,-8.80589366e-01f,-5.55128634e-01f,
	+5.32111049e-01f,}; 
	k2c_tensor lstm_11_recurrent_kernel = {&lstm_11_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
	float lstm_11_bias_array[12] = {
	+4.55830050e+00f,+4.41169882e+00f,+4.25517273e+00f,+2.21687102e+00f,+2.20017242e+00f,
	+1.88446689e+00f,-1.38241623e-03f,+6.72521186e-04f,-2.22758902e-03f,+7.00973558e+00f,
	+5.87618208e+00f,+5.35815525e+00f,}; 
	k2c_tensor lstm_11_bias = {&lstm_11_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

	
	float client_0_output_array[1] = {0}; 
	k2c_tensor client_0_output = {&client_0_output_array[0],1,1,{1,1,1,1,1}}; 
	float client_0_kernel_array[3] = {
	+8.72080421e+00f,-9.36427689e+00f,+9.68266678e+00f,}; 
	k2c_tensor client_0_kernel = {&client_0_kernel_array[0],2,3,{3,1,1,1,1}}; 
	float client_0_bias_array[1] = {
	-1.30522698e-01f,}; 
	k2c_tensor client_0_bias = {&client_0_bias_array[0],1,1,{1,1,1,1,1}}; 
	float client_0_fwork[6] = {0}; 

	
	k2c_lstm(&lstm_10_output,input_layer_17_input,lstm_10_state,&lstm_10_kernel, 
		&lstm_10_recurrent_kernel,&lstm_10_bias,lstm_10_fwork, 
		lstm_10_go_backwards,lstm_10_return_sequences, 
		k2c_sigmoid,k2c_tanh); 
	k2c_tensor dropout_10_output; 
	dropout_10_output.ndim = lstm_10_output.ndim; // copy data into output struct 
	dropout_10_output.numel = lstm_10_output.numel; 
	memcpy(dropout_10_output.shape,lstm_10_output.shape,K2C_MAX_NDIM*sizeof(size_t));  
	dropout_10_output.array = &lstm_10_output.array[0]; // rename for clarity 
	k2c_lstm(&lstm_11_output,&dropout_10_output,lstm_11_state,&lstm_11_kernel, 
		&lstm_11_recurrent_kernel,&lstm_11_bias,lstm_11_fwork, 
		lstm_11_go_backwards,lstm_11_return_sequences, 
		k2c_sigmoid,k2c_tanh); 
	k2c_tensor dropout_11_output; 
	dropout_11_output.ndim = lstm_11_output.ndim; // copy data into output struct 
	dropout_11_output.numel = lstm_11_output.numel; 
	memcpy(dropout_11_output.shape,lstm_11_output.shape,K2C_MAX_NDIM*sizeof(size_t));  
	dropout_11_output.array = &lstm_11_output.array[0]; // rename for clarity 
	k2c_dense(keras_tensor_74_output,&dropout_11_output,&client_0_kernel, 
		&client_0_bias,k2c_sigmoid,client_0_fwork); 

 } 



void LSTM_ACK_RTTModel::keras2c_model_initialize() { 
    
    cout << "Iniciando Modelo LSTM_ACK_RTT" << endl;

} 




void LSTM_ACK_RTTModel::keras2c_model_terminate() { 
    
    cout << "Terminando Modelo LSTM_ACK_RTT" << endl;

} 

