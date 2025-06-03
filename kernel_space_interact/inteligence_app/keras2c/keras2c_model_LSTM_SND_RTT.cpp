#include <math.h> 
#include <string.h> 
#include <iostream>
#include "./keras2c/Model/include/k2c_include.h" 
#include "./keras2c/Model/include/k2c_tensor_include.h" 
#include "./keras2c/LSTM_3000_epocas_SND_RTT/keras2c_model_LSTM_SND_RTT.h"


 using namespace std;



void LSTM_SND_RTTModel::keras2c_model_Round_COMPLEXITY(const k2c_tensor* input_layer_20_input, k2c_tensor* keras_tensor_84_output) 
{ 

    cout << "LSTM_SND_RTT_Model_Round_COMPLEXITY\n";

    float lstm_16_output_array[9] = {0}; 
    k2c_tensor lstm_16_output = {&lstm_16_output_array[0],2,9,{3,3,1,1,1}}; 
    float lstm_16_fwork[24] = {0}; 
    int lstm_16_go_backwards = 0;
    int lstm_16_return_sequences = 1;
    float lstm_16_state[6] = {0}; 
    float lstm_16_kernel_array[24] = {
    -2.83429456e+00f,-2.36564326e+00f,-4.76955175e+00f,+2.26405764e+00f,+6.67365938e-02f,
    +1.63842782e-01f,+3.02804971e+00f,-8.21811795e-01f,+1.37775671e+00f,-9.61929083e-01f,
    -3.58152604e+00f,+8.49115133e-01f,+1.12754703e-01f,+7.02642053e-02f,-6.53320104e-02f,
    -8.10579538e-01f,-7.97291636e-01f,+7.05790043e-01f,-2.32874346e+00f,-2.76475239e+00f,
    +3.28617960e-01f,+3.23715115e+00f,+1.08376779e-01f,+5.46014786e+00f,}; 
    k2c_tensor lstm_16_kernel = {&lstm_16_kernel_array[0],2,24,{8,3,1,1,1}}; 
    float lstm_16_recurrent_kernel_array[36] = {
    -4.70741558e+00f,-3.51762581e+00f,-3.91662455e+00f,-4.40729237e+00f,-8.52326632e-01f,
    -8.41781199e-01f,+6.10229683e+00f,+7.63590991e-01f,+5.28380346e+00f,-1.46918952e-01f,
    +2.48412895e+00f,+6.68021962e-02f,+1.65884233e+00f,+3.74042869e+00f,+4.08886623e+00f,
    +2.30360761e-01f,-4.91334295e+00f,-4.06727552e+00f,-5.30043483e-01f,-4.72887456e-01f,
    +3.21054459e-01f,-6.42421544e-01f,-5.58129430e-01f,+7.86864161e-01f,-7.36046135e-01f,
    -9.40367997e-01f,+1.68940470e-01f,-5.17142105e+00f,-4.07684898e+00f,-2.84394360e+00f,
    -3.74881601e+00f,-1.38005197e+00f,+7.94046819e-01f,+4.38781261e+00f,+1.39894235e+00f,
    +5.68128705e-01f,}; 
    k2c_tensor lstm_16_recurrent_kernel = {&lstm_16_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
    float lstm_16_bias_array[12] = {
    +2.22212720e+00f,+2.02256751e+00f,+1.17828190e+00f,-3.79776210e-01f,-1.39151204e+00f,
    +5.05395949e-01f,+5.70355177e-01f,+5.58608472e-01f,-4.93449241e-01f,+2.13893175e+00f,
    +1.80039251e+00f,+5.11796761e+00f,}; 
    k2c_tensor lstm_16_bias = {&lstm_16_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

    
    float lstm_17_output_array[3] = {0}; 
    k2c_tensor lstm_17_output = {&lstm_17_output_array[0],1,3,{3,1,1,1,1}}; 
    float lstm_17_fwork[24] = {0}; 
    int lstm_17_go_backwards = 0;
    int lstm_17_return_sequences = 0;
    float lstm_17_state[6] = {0}; 
    float lstm_17_kernel_array[36] = {
    -3.09073257e+00f,-2.98786926e+00f,-2.65158486e+00f,+1.35182202e+00f,+1.64321792e+00f,
    +1.23976135e+00f,+8.38585973e-01f,+1.16779470e+00f,+2.22798371e+00f,-5.42056751e+00f,
    -1.09403765e+00f,-4.18283749e+00f,-1.12396717e+00f,+1.64594817e+00f,-1.85973227e+00f,
    +3.41618276e+00f,-1.17329288e+00f,+3.84095669e+00f,+2.41067982e+00f,-2.19711018e+00f,
    -1.95279634e+00f,+4.18279505e+00f,-3.66065764e+00f,-3.40887451e+00f,-7.92373896e+00f,
    +6.20313025e+00f,+4.92967510e+00f,-2.26268387e+00f,-4.25714159e+00f,-3.01349831e+00f,
    +1.84705043e+00f,+1.57651925e+00f,+1.28940761e+00f,+2.25088120e+00f,+1.21955502e+00f,
    +2.88165927e+00f,}; 
    k2c_tensor lstm_17_kernel = {&lstm_17_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
    float lstm_17_recurrent_kernel_array[36] = {
    -1.43766928e+00f,-1.26205134e+00f,-1.40392411e+00f,-1.95968974e+00f,-1.38573492e+00f,
    -1.06750405e+00f,+8.39995146e-01f,+5.66899002e-01f,+8.70249927e-01f,-1.19914114e-01f,
    +6.02797121e-02f,+3.10220033e-01f,-1.26550448e+00f,+5.24434865e-01f,-1.60500515e+00f,
    -1.49340641e+00f,-2.28987408e+00f,-7.53644645e-01f,-4.79725748e-01f,+8.87301490e-02f,
    +1.93469703e-01f,+3.33644748e-01f,-8.39583635e-01f,-1.62326589e-01f,-5.96441090e-01f,
    +9.57053065e-01f,+2.27456704e-01f,-1.86545920e+00f,-7.63053894e-01f,-1.52925730e+00f,
    -1.99176669e+00f,-1.02569735e+00f,-6.58568799e-01f,+6.55922592e-01f,+1.53553307e-01f,
    +8.62324476e-01f,}; 
    k2c_tensor lstm_17_recurrent_kernel = {&lstm_17_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
    float lstm_17_bias_array[12] = {
    +4.88585758e+00f,+4.74060965e+00f,+2.66363597e+00f,+1.44636643e+00f,+1.96598977e-01f,
    +1.50961292e+00f,-1.45219788e-02f,+1.48303644e-03f,-3.75727611e-03f,+5.48911381e+00f,
    +5.48792219e+00f,+2.84871769e+00f,}; 
    k2c_tensor lstm_17_bias = {&lstm_17_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

    
    float client_0_output_array[1] = {0}; 
    k2c_tensor client_0_output = {&client_0_output_array[0],1,1,{1,1,1,1,1}}; 
    float client_0_kernel_array[3] = {
    -9.20232296e+00f,+9.99227715e+00f,+1.01320095e+01f,}; 
    k2c_tensor client_0_kernel = {&client_0_kernel_array[0],2,3,{3,1,1,1,1}}; 
    float client_0_bias_array[1] = {
    -1.16217263e-01f,}; 
    k2c_tensor client_0_bias = {&client_0_bias_array[0],1,1,{1,1,1,1,1}}; 
    float client_0_fwork[6] = {0}; 

    
    k2c_lstm(&lstm_16_output,input_layer_20_input,lstm_16_state,&lstm_16_kernel, 
        &lstm_16_recurrent_kernel,&lstm_16_bias,lstm_16_fwork, 
        lstm_16_go_backwards,lstm_16_return_sequences, 
        k2c_sigmoid,k2c_tanh); 
    k2c_tensor dropout_16_output; 
    dropout_16_output.ndim = lstm_16_output.ndim; // copy data into output struct 
    dropout_16_output.numel = lstm_16_output.numel; 
    memcpy(dropout_16_output.shape,lstm_16_output.shape,K2C_MAX_NDIM*sizeof(size_t));  
    dropout_16_output.array = &lstm_16_output.array[0]; // rename for clarity 
    k2c_lstm(&lstm_17_output,&dropout_16_output,lstm_17_state,&lstm_17_kernel, 
        &lstm_17_recurrent_kernel,&lstm_17_bias,lstm_17_fwork, 
        lstm_17_go_backwards,lstm_17_return_sequences, 
        k2c_sigmoid,k2c_tanh); 
    k2c_tensor dropout_17_output; 
    dropout_17_output.ndim = lstm_17_output.ndim; // copy data into output struct 
    dropout_17_output.numel = lstm_17_output.numel; 
    memcpy(dropout_17_output.shape,lstm_17_output.shape,K2C_MAX_NDIM*sizeof(size_t));  
    dropout_17_output.array = &lstm_17_output.array[0]; // rename for clarity 
    k2c_dense(keras_tensor_84_output,&dropout_17_output,&client_0_kernel, 
        &client_0_bias,k2c_sigmoid,client_0_fwork); 

 } 



void LSTM_SND_RTTModel::keras2c_model_initialize() { 
    
    cout << "Iniciando Modelo LSTM_SND_RTT" << endl;

} 




void LSTM_SND_RTTModel::keras2c_model_terminate() { 
    
    cout << "Terminando Modelo LSTM_SND_RTT" << endl;

} 

