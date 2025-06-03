#include <math.h> 
 #include <string.h> 
#include "./include/k2c_include.h" 
#include "./include/k2c_tensor_include.h" 

 


void keras2c_model(k2c_tensor* input_layer_14_input, k2c_tensor* keras_tensor_9_output) { 

float lstm_4_output_array[9] = {0}; 
k2c_tensor lstm_4_output = {&lstm_4_output_array[0],2,9,{3,3,1,1,1}}; 
float lstm_4_fwork[24] = {0}; 
int lstm_4_go_backwards = 0;
int lstm_4_return_sequences = 1;
float lstm_4_state[6] = {0}; 
float lstm_4_kernel_array[36] = {
+6.26344025e-01f,-1.24438619e-02f,+3.72678971e+00f,+1.71739906e-02f,-9.73474205e-01f,
-1.55617356e-01f,+3.94752812e+00f,+2.01828033e-02f,+2.58481407e+00f,-2.81640053e-01f,
-1.50236499e+00f,+2.25488737e-01f,+7.42030561e-01f,+1.08482087e+00f,+2.18746290e-01f,
-1.17205143e-01f,-7.59309053e-01f,-5.61166465e-01f,+5.22937626e-03f,-5.38607463e-02f,
-1.42481383e-02f,-5.08888904e-03f,+3.84837180e-01f,+1.22036468e-02f,-5.44427633e-01f,
-1.74684748e-02f,+7.82000601e-01f,+2.95255756e+00f,-3.62395972e-01f,+3.76376629e+00f,
+1.08311021e+00f,-6.42889738e-01f,+1.00326121e+00f,+5.04379320e+00f,+4.53020960e-01f,
+3.52178693e+00f,}; 
k2c_tensor lstm_4_kernel = {&lstm_4_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
float lstm_4_recurrent_kernel_array[36] = {
-5.35943806e-01f,-1.41293609e+00f,+1.64069009e+00f,+1.28048353e+01f,+1.32802892e+00f,
+9.42353344e+00f,+2.92530924e-01f,+2.00835228e+00f,-2.07941413e+00f,+1.97058335e-01f,
-3.13308883e+00f,+1.68956503e-01f,+1.28625047e+00f,-2.74922997e-01f,+8.50317836e-01f,
-3.68647039e-01f,+3.05599475e+00f,-1.04042664e-02f,-3.62872869e-01f,-4.61312485e+00f,
+4.52021323e-02f,+4.13194448e-02f,+1.58246517e-01f,-5.46521097e-02f,+3.01871687e-01f,
+3.98379040e+00f,-6.95209920e-01f,-1.72947598e+00f,-1.79033113e+00f,+9.78877604e-01f,
+1.17351313e+01f,+2.41981953e-01f,+8.83425045e+00f,+4.55522209e-01f,+1.58668280e+00f,
-1.76663363e+00f,}; 
k2c_tensor lstm_4_recurrent_kernel = {&lstm_4_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
float lstm_4_bias_array[12] = {
+3.48037481e+00f,+6.35662317e-01f,+2.41774321e+00f,-5.66279255e-02f,+9.24214065e-01f,
-5.16413487e-02f,+4.43428487e-01f,+7.07755089e-02f,-6.38228476e-01f,+4.48667002e+00f,
+7.16091454e-01f,+2.93961167e+00f,}; 
k2c_tensor lstm_4_bias = {&lstm_4_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

 
float lstm_5_output_array[3] = {0}; 
k2c_tensor lstm_5_output = {&lstm_5_output_array[0],1,3,{3,1,1,1,1}}; 
float lstm_5_fwork[24] = {0}; 
int lstm_5_go_backwards = 0;
int lstm_5_return_sequences = 0;
float lstm_5_state[6] = {0}; 
float lstm_5_kernel_array[36] = {
-5.87904811e-01f,-2.47342229e+00f,-2.59709430e+00f,+3.32401127e-01f,+2.88114858e+00f,
+2.88981986e+00f,+7.18808353e-01f,+3.32628489e+00f,+2.63147521e+00f,-7.45133066e+00f,
-9.21892762e-01f,+1.58530295e+00f,-2.74454880e+00f,-7.77547061e-01f,-1.28738022e+00f,
+7.25429249e+00f,+4.83630836e-01f,-1.42526257e+00f,+1.87428341e+01f,-7.49566269e+00f,
+9.29388618e+00f,-4.21896905e-01f,+9.41563919e-02f,-1.95053518e-01f,-1.45315552e+01f,
+5.25974655e+00f,-6.48208618e+00f,+8.05236459e-01f,-1.70329022e+00f,+1.78384328e+00f,
+1.70621133e+00f,+1.84039748e+00f,+1.88536692e+00f,+4.99415351e-03f,+2.68756247e+00f,
-1.12649822e+00f,}; 
k2c_tensor lstm_5_kernel = {&lstm_5_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
float lstm_5_recurrent_kernel_array[36] = {
-3.69587064e-01f,-1.09338653e+00f,-8.75187159e-01f,-2.62776518e+00f,-2.61575222e+00f,
-1.91897857e+00f,+3.63366795e+00f,+3.15784168e+00f,+2.77007866e+00f,+6.12147339e-02f,
-1.38074517e+00f,-1.02924681e+00f,+3.38286847e-01f,-1.31542933e+00f,-1.83202100e+00f,
+9.04512107e-02f,+1.43581367e+00f,+1.55339587e+00f,-4.34649765e-01f,-2.14606628e-01f,
+3.02800596e-01f,-4.69742939e-02f,-8.76509428e-01f,+6.70597553e-01f,+1.39352405e+00f,
-4.45158362e-01f,+3.41173299e-02f,-2.08087039e+00f,-4.33456469e+00f,-3.68462753e+00f,
+6.11095846e-01f,+7.00954944e-02f,+7.38115489e-01f,+2.56410092e-01f,+1.47657692e+00f,
-7.66926646e-01f,}; 
k2c_tensor lstm_5_recurrent_kernel = {&lstm_5_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
float lstm_5_bias_array[12] = {
+3.11287284e+00f,+3.94647932e+00f,+3.93219805e+00f,-1.75503731e+00f,-1.92142054e-01f,
+4.62724000e-01f,+3.97814848e-02f,-8.18677060e-03f,+3.77276866e-03f,+3.17771935e+00f,
+3.27345705e+00f,+2.45958352e+00f,}; 
k2c_tensor lstm_5_bias = {&lstm_5_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

 
float client_0_output_array[1] = {0}; 
k2c_tensor client_0_output = {&client_0_output_array[0],1,1,{1,1,1,1,1}}; 
float client_0_kernel_array[3] = {
-3.56668067e+00f,+6.49346924e+00f,-5.83301353e+00f,}; 
k2c_tensor client_0_kernel = {&client_0_kernel_array[0],2,3,{3,1,1,1,1}}; 
float client_0_bias_array[1] = {
+1.90527812e-01f,}; 
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
k2c_dense(&client_0_output,&dropout_5_output,&client_0_kernel, 
	&client_0_bias,k2c_sigmoid,client_0_fwork); 

 } 

void keras2c_model_initialize() { 

} 

void keras2c_model_terminate() { 

} 

