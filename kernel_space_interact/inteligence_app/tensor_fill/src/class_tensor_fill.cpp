#include "../include/class_tensor_fill.h"

#include <iostream>

#include "../../keras2c/keras2c/Model/include/k2c_include.h"

extern k2c_tensor myInput, myOutput;

extern float flattenedFeatures[MAX_TERMINALS][MAX_TERMINALS][NUM_FLATTENED_FEATURES];

extern float myfloatOutput[1];

extern float kerasarray_1D_ACK_RTT[2];
extern float kerasarray_1D_SND_RTT[2];
//float kerasarray_CNN_ACK_RTT[6];
extern float kerasarray_2D_ACK_RTT[6];
extern float kerasarray_2D_SND_RTT[6];


class_tensor_fill::class_tensor_fill()
{
    for (int i=0; i < MAX_TERMINALS; i++)
        for (int j=0; j < MAX_TERMINALS; j++)
        {


            for(int k=0; k<NUM_FLATTENED_FEATURES; k++)
            flattenedFeatures[i][j][k] = 0.0;
            heldFeatures[i][j] = 0;      
    

        }

}

void class_tensor_fill::fill_tensor(int parSrc, int parDest)
{

   //k2c_tensor myInput,myOutput;
   //float myfloatOutput[1] = {0};
   //float kerasarray_MLP_SND_RTT[2];
   //float kerasarray_CNN_ACK_RTT[6];
  
   /*cout << "All Flattened Features:\n";   
   std::cout <<"("; 
    for (int i=0; i < NUM_FLATTENED_FEATURES; i++)
      std::cout <<  flattenedFeatures[parSrc][parDest][i]<<", ";
   std::cout << ")\n";*/

   //float myfloatOutput[1] = {0};

   
   if (model_architeture < 0 )
   {
        std::cout << "Adjust model architerure first" << endl;
        exit(0);
   }

   if(heldFeatures[parSrc][parDest] < NUM_FLATTENED_FEATURES)
   {
        std::cout << "Not enough features" << endl;
        exit(0);
   }


   if(model_architeture == MLP_MODEL)
   {

      std::cout<< "Features MLP_ACK_SND_RTT: "<< "{" 
               << flattenedFeatures[parSrc][parDest][NUM_FLATTENED_FEATURES-3]<<", "
               <<flattenedFeatures[parSrc][parDest][NUM_FLATTENED_FEATURES-2]<< ", "
               <<flattenedFeatures[parSrc][parDest][NUM_FLATTENED_FEATURES-1] << "}\n";

      myInput.array = &flattenedFeatures[parSrc][parDest][NUM_FLATTENED_FEATURES-3];
      std::cout<< "myInpputArray" << "{" 
               << myInput.array[0]<<", "
               << myInput.array[1]<< ", "
               << myInput.array[2] << "}\n";
      myInput.ndim = 1;
      myInput.numel = 3;
      myInput.shape[0] = 3;
      myInput.shape[1] = 1;
      myInput.shape[2] = 1;  //k2c_tensor test1_dense_68_input_1_input = {&test1_dense_68_input_1_input_array[0],1,3,{3,1,1,1,1}}; 
      myInput.shape[3] = 1;
      myInput.shape[4] = 1;

      myOutput.array=myfloatOutput;
      myOutput.ndim=1;
      myOutput.numel=1;
      myOutput.shape[0]=1;
      myOutput.shape[1]=1;
      myOutput.shape[2]=1;      // k2c_tensor c_dense_70_1_test1 = {&c_dense_70_1_test1_array[0],1,1,{1,1,1,1,1}}; 
      myOutput.shape[3]=1;
      myOutput.shape[4]=1;
   }
            

   else if(model_architeture ==LSTM_MODEL)
   {
      //cout << "Entrou LSTM";
      //myPause();
      myInput.array = flattenedFeatures[parSrc][parDest];
      myInput.ndim = 2;//-------------------------------------------------------------------------------|
      myInput.numel = 9;//------------------------------------------------------------------------------|-|
                      //                                                                                | |
                      //k2c_tensor test9_lstm_24_input_1_input = {&test9_lstm_24_input_1_input_array[0],2,9,{3,3,1,1,1}}; 
                      //                     só olhar o padrão nas primeiras linhas                          | | | | |
      myInput.shape[0] = 3;//--------------------------------------------------------------------------------| | | | |
      myInput.shape[1] = 3;//----------------------------------------------------------------------------------| | | |
      myInput.shape[2] = 1;//------------------------------------------------------------------------------------| | |
      myInput.shape[3] = 1;//--------------------------------------------------------------------------------------| |
      myInput.shape[4] = 1;//----------------------------------------------------------------------------------------|


      myOutput.array=myfloatOutput;
      myOutput.ndim=1;//-------------------------------------------------------------------------------|
      myOutput.numel=1;//------------------------------------------------------------------------------|-|
                                      //k2c_tensor c_client_0_13_test1 = {&c_client_0_13_test1_array[0],1,1,{1,1,1,1,1}}; 
      myOutput.shape[0]=1;//                                                                                | | | | |
      myOutput.shape[1]=1;//--------------------------------------------------------------------------------| | | | |
      myOutput.shape[2]=1;//------------------------------------------------------------------------------------| | |
      myOutput.shape[3]=1;//--------------------------------------------------------------------------------------| |
      myOutput.shape[4]=1;//----------------------------------------------------------------------------------------|

   }

   else if (model_architeture ==CNN_MODEL)
   {
      //cout << "Entrou CNN";
      //myPause();

      myInput.array = flattenedFeatures[parSrc][parDest];
      myInput.ndim = 3;
      myInput.numel = 9;
      myInput.shape[0] = 3;
      myInput.shape[1] = 3;
      myInput.shape[2] = 1;
      myInput.shape[3] = 1;
      myInput.shape[4] = 1;


      
      myOutput.array=myfloatOutput;
      myOutput.ndim=1;
      myOutput.numel=1;
      myOutput.shape[0]=1;
      myOutput.shape[1]=1;
      myOutput.shape[2]=1;
      myOutput.shape[3]=1;
      myOutput.shape[4]=1;


   }
   else if (model_architeture == MLP_ACK_RTT)
   {
      kerasarray_1D_ACK_RTT[0] = flattenedFeatures[parSrc][parDest][NUM_FLATTENED_FEATURES-3];
      kerasarray_1D_ACK_RTT[1] = flattenedFeatures[parSrc][parDest][NUM_FLATTENED_FEATURES-1];
      std::cout<< "Features MLP_ACK_RTT: "<< "{" << kerasarray_1D_ACK_RTT[0]<<","<<kerasarray_1D_ACK_RTT[1]<<"}\n";
      myInput.array = kerasarray_1D_ACK_RTT;
      std::cout<< "myInpputArray" << "{" << myInput.array[0]<<","<<myInput.array[1]<<"}\n";
      //myPause();
      myInput.ndim = 1;
      myInput.numel = 2;
      myInput.shape[0] = 2;
      myInput.shape[1] = 1;
      myInput.shape[2] = 1;  //k2c_tensor test1_dense_8_input_input = {&test1_dense_8_input_input_array[0],1,2,{2,1,1,1,1}};; 
      myInput.shape[3] = 1;
      myInput.shape[4] = 1;



      myOutput.array=myfloatOutput;
      myOutput.ndim=1;
      myOutput.numel=1;
      myOutput.shape[0]=1;
      myOutput.shape[1]=1;
      myOutput.shape[2]=1;      //k2c_tensor c_dense_11_test1 = {&c_dense_11_test1_array[0],1,1,{1,1,1,1,1}}; ; 

      myOutput.shape[3]=1;
      myOutput.shape[4]=1;




   }

   else if (model_architeture == MLP_SND_RTT)
   {
      kerasarray_1D_SND_RTT[0] = flattenedFeatures[parSrc][parDest][NUM_FLATTENED_FEATURES-2];
      kerasarray_1D_SND_RTT[1] = flattenedFeatures[parSrc][parDest][NUM_FLATTENED_FEATURES-1];
      std::cout<< "Fatures MLP_SND_RTT" << "{" << kerasarray_1D_SND_RTT[0]<<","<<kerasarray_1D_SND_RTT[1]<<"}\n";
      myInput.array = kerasarray_1D_SND_RTT;
      std::cout<< "myInpputArray" << "{" << myInput.array[0]<<","<<myInput.array[1]<<"}\n";
      //myPause();
      myInput.ndim = 1;
      myInput.numel = 2;
      myInput.shape[0] = 2;
      myInput.shape[1] = 1;
      myInput.shape[2] = 1;  //k2c_tensor test1_dense_8_input_input = {&test1_dense_8_input_input_array[0],1,2,{2,1,1,1,1}};; 
      myInput.shape[3] = 1;
      myInput.shape[4] = 1;



      myOutput.array=myfloatOutput;
      myOutput.ndim=1;
      myOutput.numel=1;
      myOutput.shape[0]=1;
      myOutput.shape[1]=1;
      myOutput.shape[2]=1;      //k2c_tensor c_dense_11_test1 = {&c_dense_11_test1_array[0],1,1,{1,1,1,1,1}}; ; 

      myOutput.shape[3]=1;
      myOutput.shape[4]=1;




   }

   else if (model_architeture == CNN_ACK_RTT || model_architeture == LSTM_ACK_RTT)
   {
      //kerasarray_CNN_ACK_RTT
      kerasarray_2D_ACK_RTT[0] = flattenedFeatures[parSrc][parDest][FEATURES_DIMENSION*0];
      kerasarray_2D_ACK_RTT[1] = flattenedFeatures[parSrc][parDest][FEATURES_DIMENSION*0+2];
      kerasarray_2D_ACK_RTT[2] = flattenedFeatures[parSrc][parDest][FEATURES_DIMENSION*1];
      kerasarray_2D_ACK_RTT[3] = flattenedFeatures[parSrc][parDest][FEATURES_DIMENSION*1+2];
      kerasarray_2D_ACK_RTT[4] = flattenedFeatures[parSrc][parDest][FEATURES_DIMENSION*2];
      kerasarray_2D_ACK_RTT[5] = flattenedFeatures[parSrc][parDest][FEATURES_DIMENSION*2+2];

      if(!parSrc)
      {
        std::cout << "Entrada CNN_ACK_RTT:\n";
        std::cout << "{" << kerasarray_2D_ACK_RTT[0]<<","
        <<kerasarray_2D_ACK_RTT[1] << ","
        <<kerasarray_2D_ACK_RTT[2]<<","
        <<kerasarray_2D_ACK_RTT[3]<<","
        <<kerasarray_2D_ACK_RTT[4]<<","
        <<kerasarray_2D_ACK_RTT[5]<<"}\n";
        //cin.ignore();
      }
      

      myInput.array = kerasarray_2D_ACK_RTT;
      if(!parSrc)
      {
        std::cout << "myInputArray:\n";
        std::cout << "{" << myInput.array[0]<<","
        <<myInput.array[1] << ","
        <<myInput.array[2]<<","
        <<myInput.array[3]<<","
        <<myInput.array[4]<<","
        <<myInput.array[5]<<"}\n";
        //myPause();
      }

      myInput.ndim = 3;
      myInput.numel = 6;
      myInput.shape[0] = 3;
      myInput.shape[1] = 2;
      myInput.shape[2] = 1;  ////3,6,{3,2,1,1,1} 
      myInput.shape[3] = 1;
      myInput.shape[4] = 1;



      myOutput.array=myfloatOutput;
      myOutput.ndim=1;
      myOutput.numel=1;
      myOutput.shape[0]=1;
      myOutput.shape[1]=1;
      myOutput.shape[2]=1;      ////,1,1,{1,1,1,1,1} 

      myOutput.shape[3]=1;
      myOutput.shape[4]=1;




   }

   else if (model_architeture == CNN_SND_RTT || model_architeture == LSTM_SND_RTT)
   {
      //kerasarray_CNN_ACK_RTT
      kerasarray_2D_SND_RTT[0] = flattenedFeatures[parSrc][parDest][FEATURES_DIMENSION*0+1];
      kerasarray_2D_SND_RTT[1] = flattenedFeatures[parSrc][parDest][FEATURES_DIMENSION*0+2];
      kerasarray_2D_SND_RTT[2] = flattenedFeatures[parSrc][parDest][FEATURES_DIMENSION*1+1];
      kerasarray_2D_SND_RTT[3] = flattenedFeatures[parSrc][parDest][FEATURES_DIMENSION*1+2];
      kerasarray_2D_SND_RTT[4] = flattenedFeatures[parSrc][parDest][FEATURES_DIMENSION*2+1];
      kerasarray_2D_SND_RTT[5] = flattenedFeatures[parSrc][parDest][FEATURES_DIMENSION*2+2];

      if(!parSrc)
      {
        std::cout << "Entrada CNN_SND_RTT:\n";
        std::cout << "{" << kerasarray_2D_SND_RTT[0]<<","
        <<kerasarray_2D_SND_RTT[1] << ","
        <<kerasarray_2D_SND_RTT[2]<<","
        <<kerasarray_2D_SND_RTT[3]<<","
        <<kerasarray_2D_SND_RTT[4]<<","
        <<kerasarray_2D_SND_RTT[5]<<"}\n";
        //myPause();
      }

      myInput.array = kerasarray_2D_SND_RTT;
      if(!parSrc)
      {
        std::cout << "myInputArray:\n";
        std::cout << "{" << myInput.array[0]<<","
        <<myInput.array[1] << ","
        <<myInput.array[2]<<","
        <<myInput.array[3]<<","
        <<myInput.array[4]<<","
        <<myInput.array[5]<<"}\n";
        //myPause();
      }

      myInput.ndim = 3;
      myInput.numel = 6;
      myInput.shape[0] = 3;
      myInput.shape[1] = 2;
      myInput.shape[2] = 1;  ////3,6,{3,2,1,1,1} 
      myInput.shape[3] = 1;
      myInput.shape[4] = 1;



      myOutput.array=myfloatOutput;
      myOutput.ndim=1;
      myOutput.numel=1;
      myOutput.shape[0]=1;
      myOutput.shape[1]=1;
      myOutput.shape[2]=1;      ////,1,1,{1,1,1,1,1} 

      myOutput.shape[3]=1;
      myOutput.shape[4]=1;


   }

  //std::cout << "experiment_round: " << experiment_round << "\n";
  //myPause();

 
}


void class_tensor_fill::show_flattened_features(int par_src, int par_dest)
{
    for (int i = 0; i <  heldFeatures[par_src][par_dest]; i++)
        cout << flattenedFeatures[par_src][par_dest][i] << ", ";
    
    cout << endl;

}


bool class_tensor_fill::update_features(int parSrc, int parDest,float parAck_ewma, float parSend_ewma,float parRtt_ratio)
{



    /*******Round 0************
    float ack_normalize = 63.4010;
    float send_normalize = 63.591;
    float rtt_min_normalize = 421.0;
    float rtt_ratio_normalize =  1.1734;
    */

   /*******Round 1***********
    float ack_normalize = 67.016;
    float send_normalize = 68.975;
    float rtt_min_normalize = 421.0;
    float rtt_ratio_normalize =  1.19;

    ack_ewma: 40.4084
    send_ewma: 41.6424
    rtt_min: 421.0
    rtt_ratio: 1.1258907363420427

  */

     /*******Round 2*************
    float ack_normalize = 69.8943;
    float send_normalize = 70.2878;
    float rtt_min_normalize = 421.0;
    float rtt_ratio_normalize =  1.195;
    float cut_feature = 1.5;
  */
    /*****Round0000001_10Mbps***************************/


  //cout << "Normalizadores\n"; 
  //cout << ack_normalize <<", " <<send_normalize <<", " << rtt_min_normalize << ", " <<rtt_ratio_normalize <<"\n";
  //myPause();

    //if(parAck_ewma > cut_feature*ack_normalize || parSend_ewma > cut_feature*send_normalize || (parRtt_ratio/rtt_min_normalize) > cut_feature*rtt_ratio_normalize)
    //{
      //cout <<"cwnd fora do modelo\n";
      //return false; //Evita inserir
    //}
    

   /*
    
    float ack_normalize = 2.0*63.9942;
    float send_normalize = 2.0*63.4432;
    float rtt_min_normalize = 2.0*422.0;
    float rtt_ratio_normalize =  2.0*1.1848;
    */
    

    /*
    cout << "Eis as" <<heldFeatures << "features planificadas na entrada:\n";
    for(int i = 0; i < heldFeatures; i++)
      cout << flattenedFeatures[parSrc][parDest][i] <<"\n";
    */
    
    //std::cout << "(" << parSrc<<", "<< parDest<<", "<< heldFeatures[parSrc][parDest]<<")";
    //myPause();

    if(heldFeatures[parSrc][parDest] < NUM_FLATTENED_FEATURES)
    {
      flattenedFeatures[parSrc][parDest][heldFeatures[parSrc][parDest]] = (parAck_ewma/ack_normalize);
      heldFeatures[parSrc][parDest]++;
      flattenedFeatures[parSrc][parDest][heldFeatures[parSrc][parDest]] = (parSend_ewma/send_normalize);
      heldFeatures[parSrc][parDest]++;
      flattenedFeatures[parSrc][parDest][heldFeatures[parSrc][parDest]] =(parRtt_ratio/(rtt_min_normalize*rtt_ratio_normalize));
      heldFeatures[parSrc][parDest]++;
    }
    else//Já com 9; é só shiftar
    {
      for(int i=3; i<NUM_FLATTENED_FEATURES; i++)
        flattenedFeatures[parSrc][parDest][i-3] = flattenedFeatures[parSrc][parDest][i];
      flattenedFeatures[parSrc][parDest][NUM_FLATTENED_FEATURES-3] = parAck_ewma/ack_normalize;
      flattenedFeatures[parSrc][parDest][NUM_FLATTENED_FEATURES-2] = parSend_ewma/send_normalize;
      flattenedFeatures[parSrc][parDest][NUM_FLATTENED_FEATURES-1] =parRtt_ratio/(rtt_min_normalize*rtt_ratio_normalize);

    }
    /*
    cout << "Eis as " <<heldFeatures << " features planificadas na Saída:\n";
    for(int i = 0; i < heldFeatures; i++)
      cout << flattenedFeatures[parSrc][parDest][i] <<"\n";
    myPause();
    */

   return true;

}


class_tensor_fill::~class_tensor_fill()
{

}