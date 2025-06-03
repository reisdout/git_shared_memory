#include "../include/input_output_configurator.h"


class CNN_ACK_RTTModel_input_output_configurator : public class_input_output_configurator
{
    public:
        CNN_ACK_RTTModel_input_output_configurator(){};
        ~CNN_ACK_RTTModel_input_output_configurator(){};
        void configure_input_output(float par_input [NUMTEST+2][DIMENSION], float par_output[NUMTEST]);

};