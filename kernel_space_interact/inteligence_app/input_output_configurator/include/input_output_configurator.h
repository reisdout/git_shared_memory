#pragma once

#include <string.h> 
#include <iostream>

#include "../../defines/defines.h"

using namespace std;


class class_input_output_configurator{


    public:
        class_input_output_configurator(){}; 
        virtual ~class_input_output_configurator(){};
        virtual void configure_input_output(float par_input [NUM_INPUT_TEST2D][DIMENSION], float par_output[NUMTEST])=0;
};