#include "../include/input_output_configurator.h"


class MLP_SND_RTTModel_input_output_configurator : public class_input_output_configurator
{
    public:
        MLP_SND_RTTModel_input_output_configurator(){};
        ~MLP_SND_RTTModel_input_output_configurator(){};
        void configure_input_output(float par_input [NUMTEST+2][DIMENSION], float par_output[NUMTEST]);

};