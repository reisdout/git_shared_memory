#pragma once 
#include "../Model/include/k2c_tensor_include.h"
#include "../Model/Model.h" 

class LSTM_SND_RTTModel : public Model{
public:
LSTM_SND_RTTModel(){};
~LSTM_SND_RTTModel(){};
void keras2c_model(const k2c_tensor* conv2d_2_input_1_input, k2c_tensor* dense_5_1_output){return;};
void keras2c_model_Round0000001(const k2c_tensor* , k2c_tensor*){return;};
void keras2c_model_Round0000002(const k2c_tensor* , k2c_tensor* ){return;};
void keras2c_model_Round0000001_10Mbps(const k2c_tensor* , k2c_tensor* ){return;};
void keras2c_model_Round0000002_100Mbps(const k2c_tensor* , k2c_tensor*){return;};
void keras2c_model_Round0000003_500Mbps(const k2c_tensor* , k2c_tensor*){return;};
void keras2c_model_Round0000004_1000Mbps(const k2c_tensor* , k2c_tensor*){return;};
void keras2c_model_Round_REC_100Mbps(const k2c_tensor* , k2c_tensor*){return;};
void keras2c_model_Round_COMPLEXITY(const k2c_tensor* , k2c_tensor*);

void keras2c_model_initialize(); 
void keras2c_model_terminate(); 
};
