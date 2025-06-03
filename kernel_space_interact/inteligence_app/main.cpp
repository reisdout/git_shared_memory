#include <chrono>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

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

using namespace std;
using namespace std::chrono;

pcap_t* handle;
int linkhdrlen;
int packets;

k2c_tensor myInput,myOutput;

float flattenedFeatures[MAX_TERMINALS][MAX_TERMINALS][NUM_FLATTENED_FEATURES];

float myfloatOutput[1] = {0};

float kerasarray_1D_ACK_RTT[2];
float kerasarray_1D_SND_RTT[2];
//float kerasarray_CNN_ACK_RTT[6];
float kerasarray_2D_ACK_RTT[6];
float kerasarray_2D_SND_RTT[6];



Model *ptModel;


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

void packet_handler(u_char *user, const struct pcap_pkthdr *packethdr, const u_char *packetptr)
{
    //k2c_tensor myInput,myOutput;
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


    //nao se pode inicializar cariaveis dentro dos cases do switch
    // ver https://stackoverflow.com/questions/11578936/getting-a-bunch-of-crosses-initialization-error

    uint8_t *p;
    uint8_t *end;
    uint32_t ecr;

    switch (iphdr->ip_p)
    {
    case IPPROTO_TCP:
        printf("arrival (sec): %ld\n", packethdr->ts.tv_sec); //aqui um e o complemento do outro. sec e a parte inteira e
        printf("arrival (usec): %ld\n", packethdr->ts.tv_usec);//usec e a parte fracionaria em micro-segundos(usec)
        tcphdr = (struct tcphdr*)packetptr;
        printf("TCP  %s:%d -> %s:%d\n", srcip, ntohs(tcphdr->th_sport),
               dstip, ntohs(tcphdr->th_dport));
        printf("%s\n", iphdrInfo);
        printf("%c%c%c%c%c%c Seq: 0x%x Ack: 0x%x Win: 0x%x TcpLen: %d\n",
               (tcphdr->th_flags & TH_URG ? 'U' : '*'),
               (tcphdr->th_flags & TH_ACK ? 'A' : '*'),
               (tcphdr->th_flags & TH_PUSH ? 'P' : '*'),
               (tcphdr->th_flags & TH_RST ? 'R' : '*'),
               (tcphdr->th_flags & TH_SYN ? 'S' : '*'),
               (tcphdr->th_flags & TH_SYN ? 'F' : '*'),
               ntohl(tcphdr->th_seq), ntohl(tcphdr->th_ack),
               ntohs(tcphdr->th_win), 4*tcphdr->th_off);

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
                printf("No-op option with no length. Going ahead\n.");
                continue;
            }
            uint8_t size = *p++; //passa o tamanho
            if (kind == 8) {
                ecr = ntohl(*(uint32_t *)(p+4)); //p+4 pois e o segundo grupo de 4 bytes
            }
            p += (size - 2);
        }
        
        printf("ecr: %u\n", ecr);
        //Ja estamos pegando a chegada do pacote e a ecr
        //falta so capturar o pacote SYN para sincronizar o relogio e, com isso, calcular o RTT

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


int main(int argc, char *argv[])
{
    
    /*char device[256];
    char filter[256]; 
    int count = 0;
    int opt;

    *device = 0;
    *filter = 0;

    // Get the command line options, if any
    while ((opt = getopt(argc, argv, "hi:n:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            printf("usage: %s [-h] [-i interface] [-n count] [BPF expression]\n", argv[0]);
            exit(0);
            break;
        case 'i':
            strcpy(device, optarg);
            break;
        case 'n':
            count = atoi(optarg);
            break;
        }
    }

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

    stop_capture(0);*/


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

    int model_architeture;

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






}