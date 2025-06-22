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

void LSTM_SND_RTTModel::keras2c_model_Round_POC_500Mbps(const k2c_tensor* input_layer_20_input, k2c_tensor* keras_tensor_9_output) 
{ 
    cout << "LSTM_SND_RTT_model_Round_POC_500Mbps" <<  endl;
    
    float lstm_16_output_array[9] = {0}; 
    k2c_tensor lstm_16_output = {&lstm_16_output_array[0],2,9,{3,3,1,1,1}}; 
    float lstm_16_fwork[24] = {0}; 
    int lstm_16_go_backwards = 0;
    int lstm_16_return_sequences = 1;
    float lstm_16_state[6] = {0}; 
    float lstm_16_kernel_array[24] = {
    +3.51797009e+00f,+2.42944384e+00f,+4.81234264e+00f,+6.99497890e+00f,+6.79666996e+00f,
    +6.17935419e+00f,+3.85947734e-01f,+6.97372377e-01f,-1.43208134e+00f,+5.60146570e-02f,
    +1.14936292e-01f,-1.69317758e+00f,-6.83875661e-03f,-2.92458129e-03f,+8.34293896e-04f,
    -6.04459703e-01f,+6.99246347e-01f,+5.52345812e-01f,+1.97130024e+00f,+2.92877531e+00f,
    +4.16312027e+00f,+7.12225389e+00f,+6.42976713e+00f,+6.04324055e+00f,}; 
    k2c_tensor lstm_16_kernel = {&lstm_16_kernel_array[0],2,24,{8,3,1,1,1}}; 
    float lstm_16_recurrent_kernel_array[36] = {
    -3.09510469e+00f,-2.24019766e+00f,-1.97526550e+00f,+2.24138474e+00f,+2.66182256e+00f,
    +1.08914661e+00f,+1.50231290e+00f,+1.17203021e+00f,+9.37788963e-01f,+8.69489670e-01f,
    +1.21888447e+00f,-4.84133363e-01f,-1.16318440e+00f,-1.70977366e+00f,-6.45761788e-01f,
    -9.76698935e-01f,-1.26825559e+00f,+4.86190349e-01f,-5.70140839e-01f,+7.13437259e-01f,
    -2.15567172e-01f,-3.73653978e-01f,-3.41506094e-01f,+4.18556809e-01f,+8.01191211e-01f,
    -1.85693607e-01f,-1.00829554e+00f,-1.37027574e+00f,-2.94965386e+00f,-1.11239254e+00f,
    +1.09895682e+00f,+2.44631314e+00f,+8.26746106e-01f,+1.56413186e+00f,+1.98934531e+00f,
    -1.15253776e-01f,}; 
    k2c_tensor lstm_16_recurrent_kernel = {&lstm_16_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
    float lstm_16_bias_array[12] = {
    +7.05634928e+00f,+6.24171543e+00f,+6.27383471e+00f,+3.55926394e-01f,+7.75596857e-01f,
    -5.82518399e-01f,+4.96605039e-01f,-5.72730720e-01f,-4.55665290e-01f,+6.60834217e+00f,
    +6.62528610e+00f,+6.30871964e+00f,}; 
    k2c_tensor lstm_16_bias = {&lstm_16_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

    
    float lstm_17_output_array[3] = {0}; 
    k2c_tensor lstm_17_output = {&lstm_17_output_array[0],1,3,{3,1,1,1,1}}; 
    float lstm_17_fwork[24] = {0}; 
    int lstm_17_go_backwards = 0;
    int lstm_17_return_sequences = 0;
    float lstm_17_state[6] = {0}; 
    float lstm_17_kernel_array[36] = {
    -5.90381670e+00f,-5.09853458e+00f,-2.75383925e+00f,+5.84485435e+00f,+4.65688896e+00f,
    +2.83087420e+00f,+6.28363895e+00f,+4.99991035e+00f,+1.93374896e+00f,+2.54515219e+00f,
    -5.89988679e-02f,-7.35075235e+00f,-3.49840426e+00f,-1.08753288e+00f,+7.00112200e+00f,
    -2.31618881e+00f,-4.29418743e-01f,+6.62042952e+00f,-7.35705614e+00f,+6.40765619e+00f,
    -1.24809551e+01f,+6.20422268e+00f,-5.36818552e+00f,+1.09647779e+01f,+7.46752691e+00f,
    -6.70902109e+00f,+1.29886036e+01f,-2.23861647e+00f,-3.47183442e+00f,+2.77485639e-01f,
    +1.23603237e+00f,+3.36042595e+00f,+1.94887012e-01f,+1.87014914e+00f,+3.22867751e+00f,
    -1.45812595e+00f,}; 
    k2c_tensor lstm_17_kernel = {&lstm_17_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
    float lstm_17_recurrent_kernel_array[36] = {
    -1.86343777e+00f,-2.07801247e+00f,-2.33149290e-01f,+2.34408140e+00f,+2.08078527e+00f,
    -4.61358994e-01f,+2.19420409e+00f,+7.87464917e-01f,+3.86692715e+00f,-1.38453233e+00f,
    -1.40587902e+00f,-6.83241904e-01f,+8.57607603e-01f,+2.79960692e-01f,+4.13054228e-01f,
    +8.71111453e-01f,+6.39154375e-01f,+6.75225496e-01f,-9.69131663e-02f,-5.94725907e-01f,
    +1.14215839e+00f,+6.96890414e-01f,-6.44460022e-01f,+3.87448221e-01f,+5.96262991e-01f,
    -1.19603544e-01f,-2.99311817e-01f,+5.08779585e-01f,-4.06049728e-01f,-2.87625027e+00f,
    -8.85906518e-01f,-1.26155221e+00f,+2.88789821e+00f,+3.61459303e+00f,+2.89223027e+00f,
    +3.15371066e-01f,}; 
    k2c_tensor lstm_17_recurrent_kernel = {&lstm_17_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
    float lstm_17_bias_array[12] = {
    +4.11726427e+00f,+4.04672194e+00f,+4.67363119e+00f,-4.73175317e-01f,-1.06989467e+00f,
    -1.03268099e+00f,+2.04380564e-02f,-4.84832621e-04f,-1.74085405e-02f,+3.14148951e+00f,
    +3.40092540e+00f,+4.00524235e+00f,}; 
    k2c_tensor lstm_17_bias = {&lstm_17_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

    
    float client_0_output_array[1] = {0}; 
    k2c_tensor client_0_output = {&client_0_output_array[0],1,1,{1,1,1,1,1}}; 
    float client_0_kernel_array[3] = {
    +4.82219505e+00f,-5.05173588e+00f,+3.25590730e+00f,}; 
    k2c_tensor client_0_kernel = {&client_0_kernel_array[0],2,3,{3,1,1,1,1}}; 
    float client_0_bias_array[1] = {
    +1.82394877e-01f,}; 
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
    k2c_dense(keras_tensor_9_output,&dropout_17_output,&client_0_kernel, 
        &client_0_bias,k2c_sigmoid,client_0_fwork); 

 } 

void LSTM_SND_RTTModel::keras2c_model_Round_POC_10Mbps(const k2c_tensor* input_layer_20_input, k2c_tensor* keras_tensor_17_output) 
{ 
    cout << "LSTM_SND_RTT_keras2c_model_Round_POC_10Mbps"<< endl;
    float lstm_16_output_array[9] = {0}; 
    k2c_tensor lstm_16_output = {&lstm_16_output_array[0],2,9,{3,3,1,1,1}}; 
    float lstm_16_fwork[24] = {0}; 
    int lstm_16_go_backwards = 0;
    int lstm_16_return_sequences = 1;
    float lstm_16_state[6] = {0}; 
    float lstm_16_kernel_array[24] = {
    +5.50971556e+00f,+4.43224859e+00f,-8.57102394e-01f,-1.88694513e+00f,+1.15836990e+00f,
    -2.62977839e-01f,+1.06971431e+00f,-1.17301178e+00f,+6.59855223e+00f,-2.08892894e+00f,
    -2.90138793e+00f,+1.97849181e-02f,+1.71555486e-02f,+9.96484905e-02f,+1.09450483e+00f,
    -1.07248485e+00f,+1.16266203e+00f,-2.36311525e-01f,+3.28915071e+00f,+4.02335882e+00f,
    -1.54147029e+00f,+2.56744456e+00f,+1.96602738e+00f,-2.65394360e-01f,}; 
    k2c_tensor lstm_16_kernel = {&lstm_16_kernel_array[0],2,24,{8,3,1,1,1}}; 
    float lstm_16_recurrent_kernel_array[36] = {
    +4.19922781e+00f,+1.98076713e+00f,+3.13825011e+00f,-3.95345521e+00f,-2.93605638e+00f,
    -2.86018324e+00f,+5.32222271e+00f,+5.95015097e+00f,+1.16205081e-01f,+6.06640458e-01f,
    +8.52962434e-01f,+9.18745995e-01f,-2.71735549e-01f,-6.96990252e-01f,-6.86983228e-01f,
    +9.27468598e-01f,+7.31192827e-01f,+2.98935741e-01f,-2.40523160e-01f,-1.34386614e-01f,
    +1.61764228e+00f,+4.80964303e-01f,-8.66892815e-01f,-2.19009471e+00f,-2.36721620e-01f,
    +3.59665453e-01f,+7.14467645e-01f,+2.07677245e-01f,+3.00926059e-01f,+2.08550906e+00f,
    +1.55381292e-01f,-6.34320438e-01f,-1.50234020e+00f,+8.11575508e+00f,+6.41650963e+00f,
    +1.12552130e+00f,}; 
    k2c_tensor lstm_16_recurrent_kernel = {&lstm_16_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
    float lstm_16_bias_array[12] = {
    +9.72813070e-01f,+2.70042491e+00f,+3.76362085e-01f,+1.90778002e-01f,+6.20424271e-01f,
    +1.24009311e+00f,+5.08129239e-01f,-5.78076482e-01f,+1.48244545e-01f,+3.89894724e+00f,
    +3.19623351e+00f,+8.55948448e-01f,}; 
    k2c_tensor lstm_16_bias = {&lstm_16_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

    
    float lstm_17_output_array[3] = {0}; 
    k2c_tensor lstm_17_output = {&lstm_17_output_array[0],1,3,{3,1,1,1,1}}; 
    float lstm_17_fwork[24] = {0}; 
    int lstm_17_go_backwards = 0;
    int lstm_17_return_sequences = 0;
    float lstm_17_state[6] = {0}; 
    float lstm_17_kernel_array[36] = {
    +2.41266155e+00f,+1.97720051e+00f,+2.04914880e+00f,-1.42938054e+00f,-1.43261516e+00f,
    -1.54476500e+00f,+3.61863685e+00f,+2.85711217e+00f,+3.56492472e+00f,+5.97512722e+00f,
    +4.56788301e+00f,+5.85940886e+00f,-6.01470041e+00f,-5.10139418e+00f,-5.64613962e+00f,
    -7.09405601e-01f,-3.51024240e-01f,-9.75116670e-01f,-3.76679468e+00f,+4.48169184e+00f,
    -3.38510919e+00f,+2.64767623e+00f,-4.38996601e+00f,+2.39740968e+00f,-2.26481050e-01f,
    +1.06845841e-01f,-2.80554980e-01f,-7.20491111e-01f,-1.40629637e+00f,-2.68048108e-01f,
    +1.11227763e+00f,+1.21922386e+00f,+3.63907486e-01f,+2.57720804e+00f,+1.59300244e+00f,
    +3.37004256e+00f,}; 
    k2c_tensor lstm_17_kernel = {&lstm_17_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
    float lstm_17_recurrent_kernel_array[36] = {
    -3.60505909e-01f,-8.59651446e-01f,-3.44865829e-01f,+1.81082022e+00f,+1.34218407e+00f,
    +1.28573525e+00f,+1.97400898e-01f,-7.25035965e-01f,+2.22369842e-02f,+5.70136189e-01f,
    +5.38291097e-01f,+3.93508039e-02f,-1.23136610e-01f,-4.25332725e-01f,+3.77495140e-02f,
    +6.36516631e-01f,+6.20173633e-01f,+7.66317368e-01f,-2.18638480e-01f,-8.74824598e-02f,
    +4.38231975e-01f,+6.65699720e-01f,-6.24477208e-01f,+7.64024854e-01f,+6.99396789e-01f,
    -4.94859070e-01f,+2.03165174e-01f,-9.64903474e-01f,-2.16070104e+00f,-5.83227158e-01f,
    +1.72260344e+00f,+1.73270738e+00f,+6.13411427e-01f,-7.90157199e-01f,-1.16697454e+00f,
    -6.55768752e-01f,}; 
    k2c_tensor lstm_17_recurrent_kernel = {&lstm_17_recurrent_kernel_array[0],2,36,{12, 3, 1, 1, 1}}; 
    float lstm_17_bias_array[12] = {
    +1.77334309e+00f,+2.65790462e+00f,+1.72275877e+00f,+9.59335148e-01f,+3.71138424e-01f,
    +8.05762470e-01f,+2.98794601e-02f,+1.80105101e-02f,+4.24791165e-02f,+2.72425008e+00f,
    +2.53807783e+00f,+2.82442975e+00f,}; 
    k2c_tensor lstm_17_bias = {&lstm_17_bias_array[0],1,12,{12, 1, 1, 1, 1}}; 

    
    float client_0_output_array[1] = {0}; 
    k2c_tensor client_0_output = {&client_0_output_array[0],1,1,{1,1,1,1,1}}; 
    float client_0_kernel_array[3] = {
    +6.15082026e+00f,-5.81693983e+00f,+6.21325827e+00f,}; 
    k2c_tensor client_0_kernel = {&client_0_kernel_array[0],2,3,{3,1,1,1,1}}; 
    float client_0_bias_array[1] = {
    +2.70633489e-01f,}; 
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
    k2c_dense(keras_tensor_17_output,&dropout_17_output,&client_0_kernel, 
        &client_0_bias,k2c_sigmoid,client_0_fwork); 

 } 


void LSTM_SND_RTTModel::keras2c_model_initialize() { 
    
    cout << "Iniciando Modelo LSTM_SND_RTT" << endl;

} 




void LSTM_SND_RTTModel::keras2c_model_terminate() { 
    
    cout << "Terminando Modelo LSTM_SND_RTT" << endl;

} 

