#pragma once 

#include "../Model/include/k2c_tensor_include.h"
#include "../Model/Model.h" 

class MLPModel : public Model
{
    public:
        MLPModel(){};
        ~MLPModel(){}
        void keras2c_model(const k2c_tensor* dense_68_input_1_input, k2c_tensor* dense_70_1_output);
        void keras2c_model_Round0000001(const k2c_tensor* , k2c_tensor* ){return;};
        void keras2c_model_Round0000002(const k2c_tensor* , k2c_tensor* ){return;};
        void keras2c_model_Round0000001_10Mbps(const k2c_tensor* , k2c_tensor*);
        void keras2c_model_Round0000002_100Mbps(const k2c_tensor* , k2c_tensor*){return;};
        void keras2c_model_Round0000003_500Mbps(const k2c_tensor* , k2c_tensor*){return;};
        void keras2c_model_Round0000004_1000Mbps(const k2c_tensor* , k2c_tensor*){return;};
        void keras2c_model_Round_REC_100Mbps(const k2c_tensor* , k2c_tensor*);
        void keras2c_model_Round_COMPLEXITY(const k2c_tensor* , k2c_tensor*);
        void keras2c_model_initialize(); 
        void keras2c_model_terminate(); 
};
