cmake_minimum_required(VERSION 3.10.0)
project(inteligence_app VERSION 0.1.0 LANGUAGES C CXX)


set(OSBitness 32)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBitness 64)
endif()


set (FullOutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}${OSBitness}/${CMAKE_BUILD_TYPE}")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static libs") #static libs
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}") #shared libs
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}") #executable files

include_directories(. ./libpcap/pcap
                    ./keras2c/keras2c
                    ./keras2c/keras2c/CNN_3000_epocas
                    ./keras2c/keras2c/CNN_3000_epocas_ACK_RTT
                    ./keras2c/keras2c/CNN_3000_epocas_SND_RTT
                    ./keras2c/keras2c/LSTM_3000_epocas
                    ./keras2c/keras2c/LSTM_3000_epocas_ACK_RTT
                    ./keras2c/keras2c/LSTM_3000_epocas_SND_RTT
                    ./keras2c/keras2c/MLP_3000_epocas
                    ./keras2c/keras2c/MLP_3000_epocas_ACK_RTT
                    ./keras2c/keras2c/MLP_3000_epocas_SND_RTT
                    ./keras2c/keras2c/Model
                    ./keras2c/keras2c/Model/include
                    ./tensor_fill/include
                    ./input_output_configurator/include
                    ./defines)

#link_directories(${CMAKE_SOURCE_DIR}/lib)


find_library(PCAP_LIB NAMES pcap PATHS ${CMAKE_SOURCE_DIR}/libpcap)

find_library(POC_KERASC NAMES poc_keras2c PATHS ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})

add_subdirectory(keras2c)

add_executable(inteligence_app main.cpp 
               ./tensor_fill/src/class_tensor_fill.cpp 
               ./input_output_configurator/src/input_output_configurator.cpp
               ./input_output_configurator/src/MLP_Model_input_output_configurator.cpp
               ./input_output_configurator/src/MLP_ACK_RTT_input_output_configurator.cpp
               ./input_output_configurator/src/MLP_SND_RTT_input_output_configurator.cpp
               ./input_output_configurator/src/LSTM_Model_input_output_configurator.cpp
               ./input_output_configurator/src/LSTM_ACK_RTT_input_output_configurator.cpp
               ./input_output_configurator/src/LSTM_SND_RTT_input_output_configurator.cpp
               ./input_output_configurator/src/CNN_Model_input_output_configurator.cpp
               ./input_output_configurator/src/CNN_ACK_RTT_input_output_configurator.cpp
               ./input_output_configurator/src/CNN_SND_RTT_input_output_configurator.cpp)

target_link_libraries(${PROJECT_NAME} 
                      ${PCAP_LIB} 
                      ${POC_KERASC})

