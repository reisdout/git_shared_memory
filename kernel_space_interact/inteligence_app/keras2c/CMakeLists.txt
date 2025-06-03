cmake_minimum_required(VERSION 3.10.0)
project(poc_keras2c VERSION 2.8.0)

set(ProjectType STATIC) #pode ser SHARED ou STATIC. Essa variavel sera passada
                        #no add_library para dizer se dinamica (shared/.so) 
                        #ou estática (.a)


set(KERAS_DIR "./keras2c")


include_directories(${KERAS_DIR}/CNN_3000_epocas
${KERAS_DIR}/CNN_3000_epocas_ACK_RTT
${KERAS_DIR}/CNN_3000_epocas_SND_RTT
${KERAS_DIR}/LSTM_3000_epocas
${KERAS_DIR}/LSTM_3000_epocas_ACK_RTT
${KERAS_DIR}/LSTM_3000_epocas_SND_RTT
${KERAS_DIR}/MLP_3000_epocas
${KERAS_DIR}/MLP_3000_epocas_ACK_RTT
${KERAS_DIR}/MLP_3000_epocas_SND_RTT
${KERAS_DIR}/Model
${KERAS_DIR}/Model/include
${CMAKE_SOURCE_DIR}/defines) #evita ter que dar o caminho dos .h nos includes



add_library(${PROJECT_NAME} ${ProjectType} ./k2c_activations.cpp
./k2c_embedding_layers.cpp
./k2c_normalization_layers.cpp
./keras2c_model_CNN_ACK_RTT.cpp
./keras2c_model_LSTM_ACK_RTT.cpp
./keras2c_model_MLP_ACK_RTT.cpp
./k2c_convolution_layers.cpp
./k2c_helper_functions.cpp
./k2c_pooling_layers.cpp
./keras2c_model_CNN.cpp
./keras2c_model_LSTM.cpp
./keras2c_model_MLP.cpp
./k2c_core_layers.cpp
./k2c_merge_layers.cpp
./k2c_recurrent_layers.cpp
./keras2c_model_CNN_SND_RTT.cpp
./keras2c_model_LSTM_SND_RTT.cpp
./keras2c_model_MLP_SND_RTT.cpp) #cria a lib


target_include_directories(${PROJECT_NAME} PRIVATE ${KERAS_DIR} 
                                                   ${KERAS_DIR}/CNN_3000_epocas 
                                                   ${KERAS_DIR}/CNN_3000_epocas_ACK_RTT 
                                                   ${KERAS_DIR}/CNN_3000_epocas_SND_RTT 
                                                   ${KERAS_DIR}/LSTM_3000_epocas 
                                                   ${KERAS_DIR}/LSTM_3000_epocas_ACK_RTT 
                                                   ${KERAS_DIR}/LSTM_3000_epocas_SND_RTT 
                                                   ${KERAS_DIR}/MLP_3000_epocas 
                                                   ${KERAS_DIR}/MLP_3000_epocas_ACK_RTT 
                                                   ${KERAS_DIR}/MLP_3000_epocas_SND_RTT 
                                                   ${KERAS_DIR}/Model
                                                   ${KERAS_DIR}/Model/include
)