#pragma once

#include "./include/k2c_include.h" 

/*Observe que para cada experimento a uma determinada taxa de gargalo
temos um método virtual. Esses métodos serão efetivamente concretizados
(implementados por meio do código obtido pelo Keras2c) nas classes correspondentes
aos modelos que se destacaram. Por exemplo, para Round0000002 a 100Mbps os modelos 
MLP13 e CNN23 se destacaram; assim, nas classes MLP_ACK_RTT e CNN_SND_RTT o método
keras2c_model_Round0000002_100Mbps será concretizado com o código keras2c correspondente, 
com os modelos MLP13 e CNN23 respectivamente exportados pelos keras2c. Nos demais só 
teremos um return. 
 taxa de gargalo */

class Model {

public:
    Model(){};
    virtual ~Model(){};
    // pure virtual functions
    virtual void keras2c_model(const k2c_tensor* dense_68_input_1_input, k2c_tensor* dense_70_1_output)=0;
    virtual void keras2c_model_Round0000001(const k2c_tensor* , k2c_tensor*)=0;
    virtual void keras2c_model_Round0000002(const k2c_tensor* , k2c_tensor*)=0;
    virtual void keras2c_model_Round0000001_10Mbps(const k2c_tensor* , k2c_tensor*)=0;
    virtual void keras2c_model_Round0000002_100Mbps(const k2c_tensor* , k2c_tensor*)=0;
    virtual void keras2c_model_Round0000003_500Mbps(const k2c_tensor* , k2c_tensor*)=0;
    virtual void keras2c_model_Round0000004_1000Mbps(const k2c_tensor* , k2c_tensor*)=0;
    virtual void keras2c_model_Round_REC_100Mbps(const k2c_tensor* , k2c_tensor*)=0;
    virtual void keras2c_model_Round_COMPLEXITY(const k2c_tensor* , k2c_tensor*)=0;    
    virtual void keras2c_model_initialize()=0; 
    virtual void keras2c_model_terminate()=0; 

};
 