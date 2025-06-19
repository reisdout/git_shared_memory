//#include <string>
//#include <iostream>
//#include <iomanip>
//#include <fstream>
#include <unistd.h>
//#include <atomic>
#include "shm.h"
//using namespace std;

uint64_t updated_congestion_level = 0;
uint64_t old_congestion_level = 0;


void write_to_cc_kernel(uint64_t par_congestion_level)
{
        char str_model_file[] = "/proc/icc_vegas_driver";
        char line[2];
        FILE* myfile;
        myfile = fopen(str_model_file,"w");        //ofstream myfile (str_model_file.c_str());
        if (myfile)//(myfile.is_open())
        {
            if(par_congestion_level == 1)
                fputs("A",myfile);//myfile << "A";
            else
                fputs("B",myfile);//myfile << "B";
            fclose(myfile);//myfile.close();
        }
        else 
            printf("Can not open drive file to write\n");//cout << "Unable to open file\n";


}


/////Shared Memory//////////////////



char        read_buf[UV_READ_BUF_SIZE]  = {0};
shm_mem_t   *shm_base                   = NULL;
int         shm_fd                      = -1;
size_t      mem_size                    = sizeof(shm_mem_t);
uint64_t    cons_seq                    = 0;


static void
cons_cleanup()
{
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
cons_read_data(shm_mem_t *buf)
{
    uint64_t    prod_seq;
    uint64_t    data;

    prod_seq = atomic_load(&buf->prod_seq);
    if (cons_seq >= prod_seq) {
        printf("No data to read");
        return;
    }
    data = buf->data[cons_seq%BUF_COUNT];
    cons_seq++;
    atomic_store(&buf->cons_seq, cons_seq);
    int value = data;
    //printf("Read Data : %lu\n", data);
    updated_congestion_level = data;
    if(old_congestion_level != updated_congestion_level)
    {
        write_to_cc_kernel(updated_congestion_level);
        old_congestion_level = updated_congestion_level;
    }
    //printf("Read value : %d\n", value);
    
    if(value < 0)
    {
        cons_cleanup();
        exit(1);

    }
    if(cons_seq < prod_seq) {
        return cons_read_data(buf);
    }


}


void eventfd_cb(uv_poll_t* handle, int status, int events)
{
    if (status < 0) {
        // Handle error
        return;
    }

    if (events & UV_READABLE) {
        // Read the value of the eventfd
        uint64_t value;
        ssize_t n = read(handle->io_watcher.fd, &value, sizeof(value));
        if (n < 0) {
            return;
        }
        if (n == 0) {
            exit(1);
            return;
        }
        cons_read_data(shm_base);
    }
}

bool
cons_start_eventfd_notification(shm_mem_t *shm_base)
{
    int     pidfd;
    int     event_fd;

    if(shm_base->prod_pid == 0 || shm_base->event_fd ==0) {
        printf("Publisher has not written  shm header\n");
        return false;
    }
    pidfd = syscall(SYS_pidfd_open, shm_base->prod_pid, 0);
    event_fd = syscall(SYS_pidfd_getfd, pidfd, shm_base->event_fd, 0);

    uv_loop_t* loop = uv_default_loop();

    // Create the uv_poll_t object
    uv_poll_t eventfd_poll;
    uv_poll_init(loop, &eventfd_poll, event_fd);

    // Start polling for events
    uv_poll_start(&eventfd_poll, UV_READABLE, eventfd_cb);
    printf("Started eventfd notification callback on prod fd: %d copy fd:%d\n",
           shm_base->event_fd, event_fd);
    uv_run(loop, UV_RUN_DEFAULT);
    return true;
}

////////////////////////////////////////



int sqrt_aprox( int x)
 {
    int lower_limit = 1;
    int upper_limit = 1;
    //bool upper_limit_done = false;

    for(int i=1; i < x; i++)
    {
        if(i*i >= x)
        {
            upper_limit = i;
            break;
        }
        lower_limit = i;
    }

    //cout << "lower_limit: " << lower_limit << endl;

    //cout << "upper_limit: " << upper_limit << endl;

    if((x-lower_limit*lower_limit) < (upper_limit*upper_limit-x))
    {
        //cout << "returning " << lower_limit << endl;
        return lower_limit;
    }
    //cout << "returning " << upper_limit << endl;
    return upper_limit;

 
}



int main(int argc, char* argv[])
{
    printf("Making the difference!\n");

    char str_model_file[] = "/proc/icc_vegas_driver";

    if (argc < 2)
    {
        printf("Consumer or Prodicer?\n");
        return 0;
    }

    if(!strcmp(argv[1],"consumer"))
    {
        
        printf ("consuming from kernel!\n");
        char line[2];
        //ifstream myfile (str_model_file.c_str());
        FILE* myfile;
        myfile = fopen(str_model_file,"r");
        if (myfile)        
        {
          
            //myfile >> line;
            if(fgets(line,sizeof(line),myfile))
            {
                int value = 'B' - line[0]; 
                printf("read: %c", line[0]); //cout << value << endl;
                fclose(myfile);//myfile.close();
            }
        }
      
        else 
            printf("Canot oppen drive file");//cout << "Unable to open file\n"; 
      

    }

    else if (!strcmp(argv[1], "producer"))//(string(argv[1]) == string("producer"))
    {
        printf("Producing to kernel\n");//cout << "Producing to kernel!" << endl;
        if(!strcmp(argv[2],"1"))
            write_to_cc_kernel(1);
        else
            write_to_cc_kernel(2);
    }
    /*    
    else if (string(argv[1]) == string("sqrt"))
    {

        int cwnd_sqrt = sqrt_aprox(stoi(string(argv[2])));
        int new_SegCwnd = cwnd_sqrt*sqrt_aprox(cwnd_sqrt);
        cout <<  new_SegCwnd << endl;

    }

    else if (string(argv[1]) == string("pipe"))
    {
        char current_congestion = '$';
        char old_congestion = '$';
        while(true)
        {
        
            std::ifstream congest_file("/tmp/ramdisk/tshark/temp.txt", std::ios::binary|std::ios::in);

            if(!congest_file.is_open())
            {
                std::cerr << "Error opening congestion file"<< endl;
                return 1;
            }
            congest_file.seekg(0,std::ios::end);
            long file_size = congest_file.tellg();
            if(!file_size)
            {
                std::cout << "File is empty" << endl;
                continue;
            }

            congest_file.seekg(-1,std::ios::end);
            congest_file.get(current_congestion);
            if(current_congestion != old_congestion)
            {
                std::cout << "new congestion" << current_congestion << endl;
                old_congestion = current_congestion;
            }

            congest_file.close();
        }

    }
    */
    else if (!strcmp(argv[1],"shared_memory"))
    {

        shm_fd = shm_open(SHARED_MEM_PATH, O_RDWR, 0666);
        if (shm_fd == -1) {
            printf("prod: Shared memory failed: %s\n", strerror(errno));
            exit(1);
        }

        /* configure the size of the shared memory segment */
        ftruncate(shm_fd, mem_size);

        /* map the shared memory segment to the address space of the process */
        shm_base = mmap(0, mem_size, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
        if (shm_base == MAP_FAILED) {
            close(shm_fd);
            printf("prod: Map failed: %s\n", strerror(errno));
            // close and shm_unlink?
            exit(1);
        }
        printf("Connected to shared memory: %s\n", SHARED_MEM_PATH);

        cons_start_eventfd_notification(shm_base);


    }

    
    else
    {
        printf("undefined mode\n");//cout << "Unusual type!" << endl;
    }

    return 0;
}