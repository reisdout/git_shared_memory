#include <chrono>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <thread>
#include <mutex>
#include <atomic>


//pcap

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <./libpcap/pcap/pcap.h>

#include <math.h>

#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netinet/ip_icmp.h>

#include "./tensor_fill/include/class_tensor_fill.h"

#include "./input_output_configurator/include/input_output_configurator.h"

#include "./input_output_configurator/include/MLP_Model_input_output_configurator.h"
#include "./input_output_configurator/include/MLP_ACK_RTT_input_output_configurator.h"
#include "./input_output_configurator/include/MLP_SND_RTT_input_output_configurator.h"

#include "./input_output_configurator/include/LSTM_Model_input_output_configurator.h"
#include "./input_output_configurator/include/LSTM_ACK_RTT_input_output_configurator.h"
#include "./input_output_configurator/include/LSTM_SND_RTT_input_output_configurator.h"

#include "./input_output_configurator/include/CNN_Model_input_output_configurator.h"
#include "./input_output_configurator/include/CNN_ACK_RTT_input_output_configurator.h"
#include "./input_output_configurator/include/CNN_SND_RTT_input_output_configurator.h"


#include "./keras2c/keras2c/MLP_3000_epocas/keras2c_model_MLP.h"
#include "./keras2c/keras2c/LSTM_3000_epocas/keras2c_model_LSTM.h"
#include "./keras2c/keras2c/CNN_3000_epocas/keras2c_model_CNN.h"

#include "./keras2c/keras2c/MLP_3000_epocas_ACK_RTT/keras2c_model_MLP_ACK_RTT.h"
#include "./keras2c/keras2c/LSTM_3000_epocas_ACK_RTT/keras2c_model_LSTM_ACK_RTT.h"
#include "./keras2c/keras2c/CNN_3000_epocas_ACK_RTT/keras2c_model_CNN_ACK_RTT.h" 


#include "./keras2c/keras2c/MLP_3000_epocas_SND_RTT/keras2c_model_MLP_SND_RTT.h"
#include "./keras2c/keras2c/LSTM_3000_epocas_SND_RTT/keras2c_model_LSTM_SND_RTT.h"
#include "./keras2c/keras2c/CNN_3000_epocas_SND_RTT/keras2c_model_CNN_SND_RTT.h"

#include "./keras2c/keras2c/Model/Model.h"
#include "mrs_utils.h"
#include "shm.h"

using namespace std;
using namespace std::chrono;
std::mutex mtx;

pcap_t* handle;
int linkhdrlen;
int packets;

k2c_tensor myInput,myOutput;

bool first_ack_process = false;

uint64_t marcaTempoChegadaAckAnterior = 0;
long double intervalFromPreviousAck = 0.0;

uint64_t marcaTempoAnterior = 0;

long double intervalbetweenTS = 0.0;


uint64_t virtual_clock_origin = 1746929140609; //1746891186990;



bool virtual_clock_origin_set = false;
uint64_t num_ack_received = 0;
int64_t num_features_inserted = 0;
long double ack_ewma = 0.0;
long double ack_normalize = 0.0;
long double send_ewma = 0.0;
long double send_normalize = 0.0;
long double rtt = 0.0;
long double rtt_normalize=0.0;
long double expWeightExpon = 0.8;
long double cut_feature = 1.0;

int experiment_round = 8;

float flattenedFeatures[MAX_TERMINALS][MAX_TERMINALS][NUM_FLATTENED_FEATURES];

float myfloatOutput[1] = {0};

float kerasarray_1D_ACK_RTT[2];
float kerasarray_1D_SND_RTT[2];
//float kerasarray_CNN_ACK_RTT[6];
float kerasarray_2D_ACK_RTT[6];
float kerasarray_2D_SND_RTT[6];


//string str_model_file = "/proc/icc_vegas_driver";

//string tshark_memory = "/tmp/ramdisk/tshark/temp.txt";

//ofstream myfile;

//ofstream tshark_file;

//void write_to_drive(string par_string)
//{
    //cout << "Atualizando CC level para " << par_string <<  "em ack " << num_ack_received << endl;
    //myfile << par_string;
    //cout << "CC atualizado em ACK " << num_ack_received << endl;
//}


/*
Algumas vezes o compilador se perde no
polimorfismo. Por isso fique de olho nas
assinaturas(cout na primeira linha) dos 
metodos concredos. Se isso acontecer,
apagre a pasta build e de um novo build.

*/


Model *ptModel=0;

int prevision = 0;
int last_prevision = 0;

uint64_t seq_prevision_high = 0;


/////////////////////////Shared Memory///////////////////////////////////////////


#define MAX_ARG_LEN 30


char read_buf[UV_READ_BUF_SIZE]  = {0};
shm_mem_t   *shm_base                   = NULL;
int         shm_fd                      = -1;
size_t      mem_size                    = sizeof(shm_mem_t);
uint64_t    prod_seq                    = 0;



/*
Producer functions
*/
static void
prod_cleanup()
{
    close(shm_base->event_fd);
    /* remove the mapped memory segment from the address space of the process */
    if (munmap(shm_base, mem_size) == -1) {
        printf("prod: Unmap failed: %s\n", strerror(errno));
        exit(1);
    }

    /* close the shared memory segment as if it was a file */
    if (close(shm_fd) == -1) {
        printf("prod: Close failed: %s\n", strerror(errno));
        exit(1);
    }

}

static void
prod_write_header(shm_mem_t *buf)
{
    int     event_fd;
    pid_t   pid;

    pid = getpid();
    event_fd = eventfd(0, EFD_CLOEXEC);
    printf("Started eventfd for notification with fd %d\n", event_fd);
    if (event_fd < 0 || pid < 0) {
        exit(1);
    }
    buf->prod_pid = pid;
    buf->event_fd = event_fd;
    atomic_store(&buf->prod_seq, 0);
    atomic_store(&buf->cons_seq, 0);
    printf("Write SHM Header: PID: %d eventfd: %d\n", pid, event_fd);
}

static void
prod_write_data(shm_mem_t *buf, uint64_t data)
{
    uint64_t    cons_seq;

    cons_seq = atomic_load(&buf->cons_seq);
    if (cons_seq > prod_seq) {
        //error;
    }
    if((prod_seq - cons_seq)  >= BUF_COUNT) {
        printf("Slow consumer, buffer full\n");
        return;
    }
    buf->data[prod_seq%BUF_COUNT] = data;
    prod_seq++;
    atomic_store(&buf->prod_seq, prod_seq);
    printf("Write Data: %lu\n", data);
    eventfd_write(buf->event_fd, prod_seq);
    
}

static void
uv_buf_alloc(uv_handle_t *handle, size_t size, uv_buf_t *buf)
{
    buf->base = read_buf;
    buf->len = UV_READ_BUF_SIZE;
}

void
on_stdin_read(uv_stream_t *stream, ssize_t nread, const uv_buf_t *buf)
{
    if (nread >= 0) {
        if (buf->base[0] == 'q') {
            prod_cleanup();
            exit(1);
        }
        int num = atoi(buf->base);
        if (num != 0 || buf->base[0] == '0') {
            prod_write_data(shm_base, num);
            //printf("You entered: %d\n", num);
        } else {
            printf("Invalid input. Please enter an integer.\n");
        }
    } else {
        printf("Exiting program.\n");
        uv_stop(uv_default_loop());
    }
}


//////////////////////////////////////////////////////////////////////////





class_tensor_fill *pt_tensor_fill = new class_tensor_fill();


bool check_bidimensional_model(int par_model_architecture)
{
    if(par_model_architecture == LSTM_MODEL   ||
       par_model_architecture == LSTM_ACK_RTT ||
       par_model_architecture == LSTM_SND_RTT ||
       par_model_architecture == CNN_MODEL    ||
       par_model_architecture == CNN_ACK_RTT  ||
       par_model_architecture == CNN_SND_RTT)
       return true;
    
    return false;
}


bool check_big_error(float par_keras_prevision, float par_keras2c_prevision, int par_input_position)
{
    //char c;
    bool big_error = false;
    bool all_prints = false;
    //if(fabs(keras_output[i] - myOutput.array[0]) >= 0.0001)
    float error = par_keras_prevision - par_keras2c_prevision;
    cout << "Keras: " << par_keras_prevision << endl;
    cout << "Keras2c: " << par_keras2c_prevision << endl;
    cout << "The error was: " << fixed << setprecision(8) << error << endl;
    if(//par_input_position == 109  || //linha 108 / 324
        //par_input_position == 110 || //linha 188
        //par_input_position == 111 || //linha 189
        //par_input_position == 251 || //linha 250
        //par_input_position == 270 || //linha 269
        all_prints)
        cin.ignore();
    if(fabs(error) > 0.0001)
    {
       std::cout << "Big error to " << par_input_position << " output";
       big_error = true;
       cin.ignore();
    }

    return big_error;

}


int make_prevision(int par_experiment_round)
{


 if(!ptModel)
 {
    cout << "Abstract Model" << endl;
    exit(0);
 }

 pt_tensor_fill->fill_tensor(0,0); //preenche os tensors do keras


 if(par_experiment_round == ROUND_0000001)
 {
    std::cout << "Round0000001\n";
    ptModel->keras2c_model_Round0000001(&myInput,&myOutput);
 }

  else if(par_experiment_round == ROUND_0000002)
  {
    std::cout << "Round0000002\n";
    ptModel->keras2c_model_Round0000002(&myInput,&myOutput);
  }

  else if (par_experiment_round == ROUND_0000001_10MBPS){
    ptModel->keras2c_model_Round0000001_10Mbps(&myInput,&myOutput);
    //myPause();
  
  }

  else if(par_experiment_round == ROUND_0000002_100MBPS)
  {
    ptModel->keras2c_model_Round0000002_100Mbps(&myInput,&myOutput);
  }

  else if(par_experiment_round == ROUND_0000003_500MBPS)
  {
    ptModel->keras2c_model_Round0000003_500Mbps(&myInput,&myOutput);
  }

  else if(par_experiment_round == ROUND_0000004_1000MBPS)
  {
    ptModel->keras2c_model_Round0000004_1000Mbps(&myInput,&myOutput);
  }

  else if(par_experiment_round == ROUND_REC_100MBPS)
  {
    ptModel->keras2c_model_Round_REC_100Mbps(&myInput,&myOutput);
  }

  else if(par_experiment_round == ROUND_POC_0000001_10MBPS)
  {
    ptModel->keras2c_model_Round_POC_10Mbps(&myInput,&myOutput);
  }

  else if(par_experiment_round == ROUND_POC_0000002_100MBPS)
  {
     ptModel->keras2c_model_Round_POC_100Mbps(&myInput,&myOutput);
  }

  else if(par_experiment_round == ROUND_POC_0000003_300MBPS)
  {
    ptModel->keras2c_model_Round_POC_300Mbps(&myInput,&myOutput);

  }

  else if(par_experiment_round == ROUND_POC_0000004_500MBPS)
  {
    ptModel->keras2c_model_Round_POC_500Mbps(&myInput,&myOutput);
  }


  else if(par_experiment_round == ROUND_COMPLXETY_TIME)
    ptModel->keras2c_model_Round_COMPLEXITY(&myInput,&myOutput);
  
  else //default
    ptModel->keras2c_model(&myInput,&myOutput);

  std::cout <<"Resposta Modelo: " << myOutput.array[0]<<"\n";
  if(myOutput.array[0] <= 0.5 )
    return 1;
         
  return 2;

}


std::string get_model_name_str(int par_model)
{
  if(par_model == MLP_MODEL)
    return "MLP\u2081\u2082\u2083";

  else if (par_model == LSTM_MODEL)
    return "LSTM\u2081\u2082\u2083";

  else if (par_model == CNN_MODEL)
    return "CNN\u2081\u2082\u2083";

  else if (par_model == MLP_ACK_RTT)
    return "MLP\u2081\u2083";

  else if (par_model == LSTM_ACK_RTT)
    return "LSTM\u2081\u2083";
  
  else if (par_model == CNN_ACK_RTT)
    return  "CNN\u2081\u2083";

  else if (par_model == MLP_SND_RTT)
    return "MLP\u2082\u2083";

  else if (par_model == LSTM_SND_RTT)
    return "LSTM\u2082\u2083";

  else if (par_model == CNN_SND_RTT)
    return "CNN\u2082\u2083";




  else
      return "TEST_MODEL";

}



double get_model_time_response(int par_experiment_round)
{
    
    double dt;
    


    if(par_experiment_round == ROUND_COMPLXETY_TIME)
    {
        auto start_time = high_resolution_clock::now();

        for(int n =0; n < NUMTEST; n++)
            ptModel->keras2c_model_Round_COMPLEXITY(&myInput,&myOutput);

        auto end_time = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end_time - start_time);

        dt =  duration.count()/2000;
    
    }

    else
    {
        cout << "Invalid Round" << endl;
        exit(0);
    }

    cout << "Model dt computed!!" << endl;
    cin.ignore();

    return dt;

}







pcap_t* create_pcap_handle(char* device, char* filter)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = NULL;
    pcap_if_t* devices = NULL;
    struct bpf_program bpf;
    bpf_u_int32 netmask;
    bpf_u_int32 srcip;

    // If no network interface (device) is specfied, get the first one.
    if (!*device) {
    	if (pcap_findalldevs(&devices, errbuf)) {
            fprintf(stderr, "pcap_findalldevs(): %s\n", errbuf);
            return NULL;
        }
        strcpy(device, devices[0].name);
    }

    // Get network device source IP address and netmask.
    if (pcap_lookupnet(device, &srcip, &netmask, errbuf) == PCAP_ERROR) {
        fprintf(stderr, "pcap_lookupnet: %s\n", errbuf);
        return NULL;
    }

    // Open the device for live capture.
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "pcap_open_live(): %s\n", errbuf);
        return NULL;
    }

    // Convert the packet filter epxression into a packet filter binary.
    if (pcap_compile(handle, &bpf, filter, 1, netmask) == PCAP_ERROR) {
        fprintf(stderr, "pcap_compile(): %s\n", pcap_geterr(handle));
        return NULL;
    }

    // Bind the packet filter to the libpcap handle.    
    if (pcap_setfilter(handle, &bpf) == PCAP_ERROR) {
        fprintf(stderr, "pcap_setfilter(): %s\n", pcap_geterr(handle));
        return NULL;
    }

    return handle;
}

void get_link_header_len(pcap_t* handle)
{
    int linktype;
 
    // Determine the datalink layer type.
    if ((linktype = pcap_datalink(handle)) == PCAP_ERROR) {
        printf("pcap_datalink(): %s\n", pcap_geterr(handle));
        return;
    }
 
    // Set the datalink layer header size.
    switch (linktype)
    {
    case DLT_NULL:
        linkhdrlen = 4;
        break;
 
    case DLT_EN10MB:
        linkhdrlen = 14;
        break;
 
    case DLT_SLIP:
    case DLT_PPP:
        linkhdrlen = 24;
        break;
 
    default:
        printf("Unsupported datalink (%d)\n", linktype);
        linkhdrlen = 0;
    }
}


void set_pt_model(int par_model_architecture)
{

    if(par_model_architecture == MLP_MODEL)
    {

        ptModel =  new MLPModel();
    }

    else if(par_model_architecture == MLP_ACK_RTT)
    {
        ptModel = new MLP_ACK_RTTModel();
    }

    else if(par_model_architecture == MLP_SND_RTT)
    {
        ptModel = new MLP_SND_RTTModel();
    }

    else if(par_model_architecture == LSTM_MODEL)
    {
        ptModel =  new LSTMModel();

    }

    else if(par_model_architecture == LSTM_ACK_RTT)
    {
        ptModel = new LSTM_ACK_RTTModel();
    }

    else if(par_model_architecture == LSTM_SND_RTT)
    {
        ptModel = new LSTM_SND_RTTModel();
    }

    else if(par_model_architecture == CNN_MODEL)
    {
        ptModel = new CNNModel();

    }

    else if(par_model_architecture == CNN_ACK_RTT)
    {
        ptModel = new CNN_ACK_RTTModel();
    }

    else if(par_model_architecture == CNN_SND_RTT)
    {
        ptModel = new CNN_SND_RTTModel();

    }

    else
    {
        cout << "Invalid model architecture" << endl;
        exit(0);
    }


}


void set_virtual_clock_origin(uint64_t par_1970_ts, uint64_t par_virtual_clock_ts)
{

    bool force_print_set_virtual_clock_origin = true;
/*

Observe a tabela abaixo. O cálculo do RTT é feito considerando o primeiro pacote
SYN. No caso considerado, a primeira coluna traz a marca de tempo desde 01/01/1970
(1741093101433) e a marca de temp TS (1773487458), que é a obtida no relógio virtual.
Podemos considerar que essas marcas de tempo caem em pontos iguais no eixo do tempo, mas 
têm valor distintos por estarem sendo contadas de origens diferentes. Ou seja, o 
"eixo dos tempos virtuais" foi transladado. Daí para se obter a origem do tempo virtual
em relação à 01/01/70, basta subtrair  1741093101433 de 1773487458 e encontraremos
o ponto Ov(Origem virtual), a partir do qual 1741093101433 tem valor 1773487458. Depois
sempre que quisermos achar o valor do virtual em relação a 01/01/1970, basta somarmos
Ov. 
Esse processo foi feito com os acks de um experimento, cujos valores estão
tabulados abaixo. Veja que o valor do RTT é exatamente o esperado para um
delay de 40s, adotado no enlace do experimento.



TS SYN 1       Origem Virtual Clock(Ov)	    ack_arr	   ecr	       RTT
1741093101433	   1739319613975	1741093101534	1773487517	42
1773487458	   1739319613975	1741093101534	1773487517	42
	           1739319613975	1741093101534	1773487517	42
	           1739319613975	1741093101534	1773487517	42
	           1739319613975	1741093103472	1773489451	46


*/

    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "Seting Virtual colck origin" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;

    //bool force_print_set_virtual_clock_origin=false;

    class_mrs_debug::print<uint64_t>("par_1970_ts: ", par_1970_ts, force_print_set_virtual_clock_origin); 
    class_mrs_debug::print<uint64_t>("par_virtual_clock_ts: ", par_virtual_clock_ts, force_print_set_virtual_clock_origin); 


    //tem que dividir por 1000 o desde de 1970, pois o dump traz em microssegundos e o virtual
    //é milissegundos.
    
    virtual_clock_origin = (par_1970_ts/1000) - par_virtual_clock_ts;
    virtual_clock_origin_set = true;

    class_mrs_debug::print<uint64_t>("virtual_clock_origin: ", virtual_clock_origin,force_print_set_virtual_clock_origin); 

}




void calculate_ack_ewma(uint64_t par_ack_arrival_time)
{

    bool force_print_calculate_ack_ewma = true;
   
    if(first_ack_process)    
    {

        long double ack_arrival_micro = par_ack_arrival_time/1000;
        long double marcaTempoChegadaAckAnterior_micro = marcaTempoChegadaAckAnterior/1000;
        long double delta_t = ack_arrival_micro - marcaTempoChegadaAckAnterior_micro;
        intervalFromPreviousAck = delta_t;
        ack_ewma = ((1.0-expWeightExpon )*ack_ewma) + (expWeightExpon *intervalFromPreviousAck);
        //cout << "ack_ewma: " << ack_ewma<< "; "<<"Dt: " <<intervalFromPreviousAck <<  endl;
        class_mrs_debug::print<long double>("ack_ewma: ", ack_ewma,force_print_calculate_ack_ewma);
    }
    
    
    marcaTempoChegadaAckAnterior = par_ack_arrival_time;
}


void calculate_send_ewma(uint64_t  par_eco_reply)
{
    bool  force_print_calculate_send_ewma = true;
    uint64_t delta_t = 0;

    class_mrs_debug::print<uint64_t>("par_eco_reply: ", par_eco_reply,force_print_calculate_send_ewma);
    
    if(first_ack_process)
    {
        if(par_eco_reply > marcaTempoAnterior)//pior que acontece....
            delta_t = par_eco_reply - marcaTempoAnterior; //duration_cast<microseconds>(marcaTempoAtual - marcaTempoAnterior);
        intervalbetweenTS = (long double) delta_t; //(float) delta_t.count();
        send_ewma = ((1.0-expWeightExpon )*send_ewma + (expWeightExpon*intervalbetweenTS));
        cout << "send_ewma: " << send_ewma<< "; "<<"Dt: " << intervalbetweenTS <<  endl;
        class_mrs_debug::print<long double>("send_ewma: ", send_ewma,force_print_calculate_send_ewma);

    }

 
    marcaTempoAnterior = par_eco_reply;

}

void calculate_rtt(uint64_t  par_ack_arrival_time, uint64_t par_packet_eco_reply)
{
    
    bool force_prinnt_calculate_rtt = true;
    
    long double ack_arrival_mili_sec = static_cast<long double>(par_ack_arrival_time/1000.0);

    
    class_mrs_debug::print<long double>("ack_arrival_mili_sec: ", ack_arrival_mili_sec,force_prinnt_calculate_rtt);

    class_mrs_debug::print<long double>("virtual_clock_origin: ", virtual_clock_origin ,force_prinnt_calculate_rtt );

    class_mrs_debug::print<long double>("par_packet_eco_reply: ", par_packet_eco_reply ,force_prinnt_calculate_rtt );
    
    long double ecr_from_1970 =  static_cast<long double>(virtual_clock_origin + par_packet_eco_reply);

    class_mrs_debug::print<long double>("ecr_from_1970: ", ecr_from_1970, force_prinnt_calculate_rtt);
    
    rtt = (ack_arrival_mili_sec - ecr_from_1970);  //(double)pre_rtt.count();
    rtt = rtt*1000; // microsseconds
    
    class_mrs_debug::print<float>("rtt in calculate_rtt: ", rtt,force_prinnt_calculate_rtt);
}




void feature_handler(uint64_t par_ack_arrival_time, uint64_t par_packet_eco_reply)
{

       
        if(!virtual_clock_origin_set)
        {
            cout << "No Virtual clock origin" << endl;
            return;
        }

        uint64_t sh_mem_data;

        //if(num_ack_received < NUM_FLATTENED_FEATURES+3)
        num_ack_received++;

        calculate_ack_ewma(par_ack_arrival_time);
        calculate_send_ewma(par_packet_eco_reply);
        calculate_rtt(par_ack_arrival_time,par_packet_eco_reply);

        if(first_ack_process)
        {
            
            if(intervalFromPreviousAck < cut_feature*ack_normalize && intervalbetweenTS < cut_feature*send_normalize)
            {
                              
                cout << "updating features with (" << ack_ewma << ", "<< send_ewma <<", "<< rtt << ")" << endl;
                cout << "normalized (" << (float)(ack_ewma/ack_normalize) << ", "
                << (float)(send_ewma/send_normalize) <<", "
                << (float)(rtt/rtt_normalize) << ")" << endl;
                pt_tensor_fill->update_features(0,0,(float)(ack_ewma/ack_normalize),(float)(send_ewma/send_normalize),(float)(rtt/rtt_normalize));
                num_features_inserted++;
                //cin.ignore();
                if(num_features_inserted >= NUM_FLATTENED_FEATURES)
                {
                    //mtx.lock();
                    prevision = make_prevision(experiment_round);
                    //mtx.unlock();

                    if(prevision != last_prevision)
                    {
                    
                        if(prevision == 1)
                        {
                            
                            sh_mem_data = 1;
                            prod_write_data(shm_base, sh_mem_data);
                            //printf("You entered: %d\n", num);
                            //tshark_file << "A";
                            seq_prevision_high = 0;
                            last_prevision = prevision;
                        }
                            
                            
                        
                        else
                        {
                            seq_prevision_high++;
                        
                            if(seq_prevision_high >=3)
                            {
                                sh_mem_data = 2;
                                prod_write_data(shm_base, sh_mem_data);
                                last_prevision = prevision;
                                //tshark_file << "B";
                            }
                            else
                                last_prevision = 1; //se manteve em 1
                            
                        }
                        
                    }
                    
                   
                        
                            
                    cout << "@@@@@@@@@@@Model Prevision: " << prevision << endl;
                    cout << "@@@@@@@@@@@seq_prevision_high: " << seq_prevision_high << endl;
                }

            }    
 
 

        }

        first_ack_process = true;


}


void packet_handler(u_char *user, const struct pcap_pkthdr *packethdr, const u_char *packetptr)
{
    //k2c_tensor myInput,myOutput;
    float force_print_packet_handler = true;
    struct ip* iphdr;
    struct icmp* icmphdr;
    struct tcphdr* tcphdr;
    struct udphdr* udphdr;
    char iphdrInfo[256];
    char srcip[256];
    char dstip[256];
   
 

    // Skip the datalink layer header and get the IP header fields.
    packetptr += linkhdrlen;
    iphdr = (struct ip*)packetptr;
    strcpy(srcip, inet_ntoa(iphdr->ip_src));
    strcpy(dstip, inet_ntoa(iphdr->ip_dst));
    sprintf(iphdrInfo, "ID:%d TOS:0x%x, TTL:%d IpLen:%d DgLen:%d",
            ntohs(iphdr->ip_id), iphdr->ip_tos, iphdr->ip_ttl,
            4*iphdr->ip_hl, ntohs(iphdr->ip_len));
 
    // Advance to the transport layer header then parse and display
    // the fields based on the type of hearder: tcp, udp or icmp.
    packetptr += 4*iphdr->ip_hl;


    //nao se pode inicializar variaveis dentro dos cases do switch
    // ver https://stackoverflow.com/questions/11578936/getting-a-bunch-of-crosses-initialization-error

    uint8_t *p;
    uint8_t *end;
    uint32_t ecr;
    uint32_t my_time_stamp;
    uint64_t time_arrival;
    std::thread mythread;

    switch (iphdr->ip_p)
    {
    case IPPROTO_TCP:

        printf("arrival (sec): %ld\n", packethdr->ts.tv_sec); //aqui um e o complemento do outro. sec e a parte inteira e
        printf("arrival (usec): %ld\n", packethdr->ts.tv_usec);//usec e a parte fracionaria em micro-segundos(usec)
        time_arrival = uint64_t(packethdr->ts.tv_sec*1000000 + packethdr->ts.tv_usec);
        tcphdr = (struct tcphdr*)packetptr;
        

        //printf("TCP  %s:%d -> %s:%d\n", srcip, ntohs(tcphdr->th_sport),
               //dstip, ntohs(tcphdr->th_dport));
        //printf("%s\n", iphdrInfo);
        //printf("%c%c%c%c%c%c Seq: 0x%x Ack: 0x%x Win: 0x%x TcpLen: %d\n",
               //(tcphdr->th_flags & TH_URG ? 'U' : '*'),
               //(tcphdr->th_flags & TH_ACK ? 'A' : '*'),
               //(tcphdr->th_flags & TH_PUSH ? 'P' : '*'),
               //(tcphdr->th_flags & TH_RST ? 'R' : '*'),
               //(tcphdr->th_flags & TH_SYN ? 'S' : '*'),
               //(tcphdr->th_flags & TH_SYN ? 'F' : '*'),
               //ntohl(tcphdr->th_seq), ntohl(tcphdr->th_ack),
               //ntohs(tcphdr->th_win), 4*tcphdr->th_off);

        packets += 1;
        //Buscando as opcoes ver:
        //https://www.rfc-editor.org/rfc/rfc7323.html
        //https://stackoverflow.com/questions/42750552/read-tcp-options-fields


        p = (uint8_t *)packetptr + 20; // or sizeof (struct tcphdr)
        end = (uint8_t *)packetptr + 4*tcphdr->th_off;
        ecr = 0; 
    

        while (p < end) {
            uint8_t kind = *p++;//pega o tipo
            if (kind == 0) {
                printf("No options\n");
                break;
            }
            if (kind == 1) {
                printf("No-op option with no length. Going ahead.\n");
                continue;
            }
            uint8_t size = *p++; //passa o tamanho
            if (kind == 8) {
                my_time_stamp = ntohl(*(uint32_t *)(p));
                ecr = ntohl(*(uint32_t *)(p+4)); //p+4 pois e o segundo grupo de 4 bytes
            }
            p += (size - 2);
        }
        
        //printf("ecr: %u\n", ecr);
        //Ja estamos pegando a chegada do pacote e a ecr
        //falta so capturar o pacote SYN para sincronizar o relogio e, com isso, calcular o RTT

        if(tcphdr->th_flags & TH_SYN && string(srcip) == "10.0.0.3")//acertar a origem do relogio virtual so no primeiro SYN
        {
            if (!virtual_clock_origin_set)
            {
                class_mrs_debug::print<char>("calling set_virtual_clock_origin", '\n',force_print_packet_handler);
                set_virtual_clock_origin(time_arrival, my_time_stamp);                              
            }
            else
                cout << "SYN afther virtual clock origin set" << endl;
            printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n"); 
            break;

        }
        //Os dois if abaixo garantem  que e ACK do primeiro fluxo
        if(string(srcip) != "10.0.1.3" ||  ntohs(tcphdr->th_sport) != 5002) //so aceita de 10.0.1.3
        {
            cout << "Ignored source " <<  string(srcip) <<":" << ntohs(tcphdr->th_sport) << endl;
            printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");
            break;
        }

        if(string(srcip) == "10.0.1.3" && !tcphdr->th_flags & TH_ACK)
        {
            cout << "No ACK packet came from 10.0.1.3" << endl;
            printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");
            break;
        }


        printf("%lu  %s-> %s %c%c%c%c%c%c, TSval:%u ecr: %u\n",             
        time_arrival, 
        srcip,
        dstip,
        (tcphdr->th_flags & TH_URG ? 'U' : '*'),
        (tcphdr->th_flags & TH_ACK ? 'A' : '*'),
        (tcphdr->th_flags & TH_PUSH ? 'P' : '*'),
        (tcphdr->th_flags & TH_RST ? 'R' : '*'),
        (tcphdr->th_flags & TH_SYN ? 'S' : '*'),
        (tcphdr->th_flags & TH_SYN ? 'F' : '*'),
        my_time_stamp,
        ecr);

        feature_handler(time_arrival,ecr);

        printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");
        break;
 
    case IPPROTO_UDP:
        udphdr = (struct udphdr*)packetptr;
        printf("UDP  %s:%d -> %s:%d\n", srcip, ntohs(udphdr->uh_sport),
               dstip, ntohs(udphdr->uh_dport));
        printf("%s\n", iphdrInfo);
	    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");
        packets += 1;
        break;
 
    case IPPROTO_ICMP:
        icmphdr = (struct icmp*)packetptr;
        printf("ICMP %s -> %s\n", srcip, dstip);
        printf("%s\n", iphdrInfo);
        printf("Type:%d Code:%d ID:%d Seq:%d\n", icmphdr->icmp_type, icmphdr->icmp_code,
               ntohs(icmphdr->icmp_hun.ih_idseq.icd_id), ntohs(icmphdr->icmp_hun.ih_idseq.icd_seq));
	    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");
        packets += 1;
        break;
    }
}

void stop_capture(int signo)
{
    struct pcap_stat stats;
 
    if (pcap_stats(handle, &stats) >= 0) {
        printf("\n%d packets captured\n", packets);
        printf("%d packets received by filter\n", stats.ps_recv); 
        printf("%d packets dropped\n\n", stats.ps_drop);
    }
    pcap_close(handle);
    exit(0);
}

/*
int start_pcap_looping(int par_count=0)
{
    if (pcap_loop(handle, par_count, packet_handler, (u_char*)NULL) == PCAP_ERROR) {
        fprintf(stderr, "pcap_loop failed: %s\n", pcap_geterr(handle));
        return -1;
    }

    stop_capture(0);
    return 0;

}
*/

int main(int argc, char *argv[])
{
    //codigos pcap baseados em https://vichargrave.github.io/programming/develop-a-packet-sniffer-with-libpcap/
    int model_architeture = -1;
    char device[256];
    char filter[256]; 
    int count = 0;
    int opt;
    int rate;
    uint64_t congestion_level_change = 0;
    uint64_t A_kernel_update = 0;
    uint64_t B_kernel_update = 0;
 
    *device = 0;
    *filter = 0;
    //comando a ser dados sudo ./inteligence_app -i enp4s0 tcp[tcpflags] == tcp-ack or tcp[tcpflags] == tcp-syn
    // Get the command line options, if any

    

    while ((opt = getopt(argc, argv, "hi:n:m:b:r:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            printf("usage: %s [-h] [-i interface] [-n count] [-m model] [-b bottleneck] [-r round] [BPF expression]\n", argv[0]);
            exit(0);
            break;
        case 'i':
            strcpy(device, optarg);
            break;
        case 'n':
            count = atoi(optarg);
            break;        

        case 'm':
            model_architeture = atoi(optarg);
            pt_tensor_fill->set_model_architeture(model_architeture);
            set_pt_model(model_architeture);
            cout << "CC assisted by " << get_model_name_str(model_architeture) << endl; 
            break;
        
        case 'b':
            rate = atoi(optarg);
            cout << "rate: " << rate << endl;
            
            if(rate == 10)
            {
                ack_normalize = 273.018;
                send_normalize = 271.082;
                rtt_normalize = 14.679*43000; //Lembre-se que e RTT ratio. Assim, considerando 43000 o RTT maximo
            }

            else if (rate == 100)
            {
                ack_normalize = 33.173;
                send_normalize = 33.013;
                rtt_normalize = 2.963*43000;

            }

            else if (rate == 300)
            {
               ack_normalize = 9.187;
                send_normalize = 9.601;
                rtt_normalize = 1.54*43000;
            }
            

            else if(rate == 500)
            {
                ack_normalize = 5.66;
                send_normalize = 5.73;
                rtt_normalize = 1.351*43000;
            } 
            
            break;

        
        case 'r':
            experiment_round = atoi(optarg);
            cout << "experiment_round: " << experiment_round << endl;
            break;


        }

    }


    shm_fd = shm_open(SHARED_MEM_PATH, O_RDWR | O_CREAT, 0644);
    if (shm_fd == -1) {
        printf("prod: Shared memory failed: %s\n", strerror(errno));
        exit(1);
    }
    /* configure the size of the shared memory segment */
    ftruncate(shm_fd, mem_size);

    /* map the shared memory segment to the address space of the process */
    shm_base = (shm_mem_*) mmap(0, mem_size, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (shm_base == MAP_FAILED) {
        close(shm_fd);
        printf("prod: Map failed: %s\n", strerror(errno));
        // close and shm_unlink?
        exit(1);
    }
    printf("Started SHM producer: %s\n", SHARED_MEM_PATH);
    prod_write_header(shm_base);




    // Get the packet capture filter expression, if any.
    for (int i = optind; i < argc; i++) {
        strcat(filter, argv[i]);
        strcat(filter, " ");
    }

    signal(SIGINT, stop_capture);
    signal(SIGTERM, stop_capture);
    signal(SIGQUIT, stop_capture);
    
    // Create packet capture handle.
    handle = create_pcap_handle(device, filter);
    if (handle == NULL) {
        return -1;
    }

    // Get the type of link layer.
    get_link_header_len(handle);
    if (linkhdrlen == 0) {
        return -1;
    }

    // Start the packet capture with a set count or continually if the count is 0.
    if (pcap_loop(handle, count, packet_handler, (u_char*)NULL) == PCAP_ERROR) {
        fprintf(stderr, "pcap_loop failed: %s\n", pcap_geterr(handle));
        return -1;
    }
    //std::thread t1 (start_pcap_looping,count);
    //t1.detach();

    /*
    bool force_print_main_while = true;
    
    while(true)    
    {
        
        if(last_prevision == prevision)
        {
            //cout << "@@@@@@@@@@@@No change in prevision" << endl;
            continue;
        }
        congestion_level_change++;
        
        class_mrs_debug::print<int>("last_prevision: ", last_prevision,true);
        class_mrs_debug::print<int>("prevision: ",prevision,true);

        cout << "@@@@@@@@@@@Updating Network State...." << endl;
        if(prevision == 1) 
        {      
           //rite_to_drive("A");
           A_kernel_update++;
           class_mrs_debug::print<uint64_t>("Updating kernel with A: ", A_kernel_update,force_print_main_while);
        }
        else
        {
            //write_to_drive("B");
            B_kernel_update++;
            class_mrs_debug::print<uint64_t>("Updating kernel with B: ",B_kernel_update,force_print_main_while);
        }

        //last_prevision = prevision;

        class_mrs_debug::print<uint64_t>("congestion_level_changes", congestion_level_change,force_print_main_while);
        class_mrs_debug::print<uint64_t>("congestion_level_changes A + B: ", B_kernel_update + A_kernel_update,force_print_main_while);
     
        //usleep(100000);
        //cin.ignore();
    }

    t1.join();
    */

    stop_capture(0); 
    //myfile.close();
    delete ptModel;
    delete pt_tensor_fill;


    /*

    class_tensor_fill *tensor_fill;

    class_input_output_configurator *pt_input_output_configurator;

    std::ofstream file;


    //O numero de testes é definido pelos  numelo de outputs dento do array keras_output. Mas os modelos 2D (CNN e LSTM)
    //precisam de dois vetores iniciais para irem formando as matrizes de entrada 3X3
    //por isso + 2 na linha da variavel float input. Daí quando for modelo 1D, deve-se pegar dois iniciais, sem 
    // correspondente no output, que serão desprezados no for dos testes
    //LEMBRE-SE:
    //Quando for modelo unidimensional (MLP) deve-se buscar duas linhas a mais de inputs em
    //relação aos outputs, pois,nesse caso, as primeiras duas entras seão desprezadas

    float input[NUMTEST +2][DIMENSION];

    //float input_1D[NUMTEST][DIMENSION];

    float keras_output[NUMTEST];

    int model_list[] = {MLP_MODEL, MLP_ACK_RTT, MLP_SND_RTT, LSTM_MODEL, LSTM_ACK_RTT, LSTM_SND_RTT, CNN_MODEL, CNN_ACK_RTT, CNN_SND_RTT};

    

    double dt; //guarda a media dos tempos de resposta. 

    for (int model = 0; model < NUM_MODELS; model++)
    {

        model_architeture = model_list[model]; //LSTM_MODEL;
        tensor_fill = new class_tensor_fill();

        tensor_fill->set_model_architeture(model_architeture);

        if(model_architeture == MLP_MODEL)
        {

            ptModel =  new MLPModel();
            pt_input_output_configurator = new MLP_Model_input_output_configurator();

        }

        else if(model_architeture == MLP_ACK_RTT)
        {
            ptModel = new MLP_ACK_RTTModel();
            pt_input_output_configurator = new MLP_ACK_RTTModel_input_output_configurator();
        }

        else if(model_architeture == MLP_SND_RTT)
        {
            ptModel = new MLP_SND_RTTModel();
            pt_input_output_configurator = new MLP_SND_RTTModel_input_output_configurator();
        }

        else if(model_architeture == LSTM_MODEL)
        {
            ptModel =  new LSTMModel();
            pt_input_output_configurator = new LSTM_Model_input_output_configurator();
        }

        else if(model_architeture == LSTM_ACK_RTT)
        {
            ptModel = new LSTM_ACK_RTTModel();
            pt_input_output_configurator = new LSTM_ACK_RTTModel_input_output_configurator();
        }

        else if(model_architeture == LSTM_SND_RTT)
        {
            ptModel = new LSTM_SND_RTTModel();
            pt_input_output_configurator = new LSTM_SND_RTTModel_input_output_configurator();
        }

        else if(model_architeture == CNN_MODEL)
        {
            ptModel = new CNNModel();
            pt_input_output_configurator = new CNN_Model_input_output_configurator();
        }

        else if(model_architeture == CNN_ACK_RTT)
        {
            ptModel = new CNN_ACK_RTTModel();
            pt_input_output_configurator = new CNN_ACK_RTTModel_input_output_configurator();
        }

        else if(model_architeture == CNN_SND_RTT)
        {
            ptModel = new CNN_SND_RTTModel();
            pt_input_output_configurator = new CNN_SND_RTTModel_input_output_configurator();
        }

        else
        {
            cout << "Invalid model architecture" << endl;
            exit(0);
        }


        pt_input_output_configurator->configure_input_output(input, keras_output);
        file.open("./models_response_time.csv", std::ios::out | std::ios::app);
        if(file.fail())
        {
            cout << "Can not open file to save model response time" << endl;
            exit(0);
        }

        //if(model_architeture == MLP_MODEL)
            //file << "Model,"<<"Response Time" << endl;

        //auto start_time = high_resolution_clock::now();
        for(int i = 0; i < NUMTEST + 2; i++)
        {
            //Modelos com vetores de 3 dimensoes (ACK,SND,RTT)
            if(model_architeture == MLP_MODEL || model_architeture == CNN_MODEL || model_architeture == LSTM_MODEL)
                tensor_fill->update_features(0,0,input[i][0],input[i][1],input[i][2]);
            
            //Modelos com vetores de duas dimensoes (ACK, RTT)
            else if (model_architeture == MLP_ACK_RTT || model_architeture == CNN_ACK_RTT || model_architeture == LSTM_ACK_RTT)
            {  //Nesse caso, so preenche a primeira  e a terceira e ultima posições  do vetor de feature (ACK,SND,RTT)
                tensor_fill->update_features(0,0,input[i][0],0,input[i][2]);
            }
            //Modelos com vetores de duas dimensoes (SND, RTT)
            else if (model_architeture ==  MLP_SND_RTT || model_architeture == CNN_SND_RTT || model_architeture == LSTM_SND_RTT)
            { ///Nesse caso, so preenche a segunda e a terceira e ultima posicoes do vetor de features (ACK,SND, RTT)
                tensor_fill->update_features(0,0,0,input[i][1],input[i][2]);
            }
            else
            {
                cout << "Invalid model architecture" << endl;
                exit(0);
            }

            //Veja que aqui, no cados dos modelos bidiemensionais 
            //os dois primeiros vetores de input sao desprezados.
            if(i >= (FEATURES_DIMENSION -1))
            {
                tensor_fill->show_flattened_features(0,0);
                tensor_fill->fill_tensor(0,0);
                if (i == FEATURES_DIMENSION -1)
                    dt = get_model_time_response(ROUND_COMPLXETY_TIME);
                int class_prevision = make_prevision(ROUND_COMPLXETY_TIME);
                check_big_error(keras_output[i-2], myOutput.array[0],i);
                //if(class_prevision > 1)
                    //cin.ignore();
            }


        }

        

        file << get_model_name_str(model_architeture)<<","<< fixed << setprecision(3) << dt << endl;

        file.close();




        delete ptModel;
        delete tensor_fill;
        delete pt_input_output_configurator;
    }


*/



}