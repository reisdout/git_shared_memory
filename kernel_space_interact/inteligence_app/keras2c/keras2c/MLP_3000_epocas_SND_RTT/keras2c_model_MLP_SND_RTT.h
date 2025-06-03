#pragma once 

#include "../Model/include/k2c_tensor_include.h"
#include "../Model/Model.h" 

class MLP_SND_RTTModel : public Model
{
    public:
        MLP_SND_RTTModel(){};
        ~MLP_SND_RTTModel(){}
        void keras2c_model(const k2c_tensor* dense_8_input_input, k2c_tensor* dense_11_output); 
        void keras2c_model_Round0000001(const k2c_tensor* , k2c_tensor* );
        void keras2c_model_Round0000002(const k2c_tensor* , k2c_tensor* );
        void keras2c_model_Round0000001_10Mbps(const k2c_tensor* , k2c_tensor*){return;};
        void keras2c_model_Round0000002_100Mbps(const k2c_tensor* , k2c_tensor*){return;};
        void keras2c_model_Round0000003_500Mbps(const k2c_tensor* , k2c_tensor*){return;};
        void keras2c_model_Round0000004_1000Mbps(const k2c_tensor* , k2c_tensor*){return;};        
        void keras2c_model_Round_REC_100Mbps(const k2c_tensor* , k2c_tensor*);
        void keras2c_model_Round_COMPLEXITY(const k2c_tensor* , k2c_tensor*);
        void keras2c_model_initialize(); 
        void keras2c_model_terminate(); 
};
