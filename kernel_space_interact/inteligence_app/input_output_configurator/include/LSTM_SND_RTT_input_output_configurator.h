#include "../include/input_output_configurator.h"


class LSTM_SND_RTTModel_input_output_configurator : public class_input_output_configurator
{
    public:
        LSTM_SND_RTTModel_input_output_configurator(){};
        ~LSTM_SND_RTTModel_input_output_configurator(){};
        void configure_input_output(float par_input [NUMTEST+2][DIMENSION], float par_output[NUMTEST]);

};