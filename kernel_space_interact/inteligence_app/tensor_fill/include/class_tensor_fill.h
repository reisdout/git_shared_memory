#pragma once

#include <cstdint>
#include "../../keras2c/keras2c/Model/include/k2c_include.h"
#include "../../defines/defines.h"
using namespace std;

#define MAX_TERMINALS 80





class class_tensor_fill{


    public:
        class_tensor_fill(); 
        virtual ~class_tensor_fill();       
        void fill_tensor(int parSrc, int parDest);

        void show_flattened_features(int par_src, int par_dest);

        bool update_features(int parSrc, int parDest,float parAck_ewma, float parSend_ewma,float parRtt_ratio);

        //float* get_flattened_flow_featutes(int par_src, int par_dest){return flattenedFeatures[par_src][par_dest];};

        float get_ack_normalize(){return ack_normalize;};
        //int get_experiment_round(){return experiment_round;};
        float get_rtt_min_normalize(){return rtt_min_normalize;};
        float get_rtt_ratio_normalize(){return rtt_ratio_normalize;};
        float get_send_normalize(){return send_normalize;};

        void set_ack_normalize(float par_ack_normalize){ack_normalize = par_ack_normalize;};
        //void set_experiment_round(int par_experiment_round){experiment_round = par_experiment_round;};
        void set_model_architeture(int par_model_architeture){model_architeture = par_model_architeture;};
        void set_rtt_min_normalize(float par_rtt_min_normalize){rtt_min_normalize = par_rtt_min_normalize;};
        void set_rtt_ratio_normalize(float par_rtt_ratio_normalize){rtt_ratio_normalize = rtt_ratio_normalize;};
        void set_send_normalize(float par_send_normalize){send_normalize = par_send_normalize;};


    private:
        float ack_normalize = 1.0;
        //int experiment_round = -1;
        //float flattenedFeatures[MAX_TERMINALS][MAX_TERMINALS][NUM_FLATTENED_FEATURES];
        int heldFeatures[MAX_TERMINALS][MAX_TERMINALS];
        float rtt_min_normalize = 1.0;
        int model_architeture = -1;
        float rtt_ratio_normalize = 1.0;     
        float send_normalize = 1.0;




};