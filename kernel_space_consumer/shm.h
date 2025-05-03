//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <unistd.h>
//#include <string.h>
//#include <fcntl.h>
#include <linux/shm.h>
#include <linux/stat.h>
#include <linux/mman.h>
#include <linux/types.h>
#include <linux/eventfd.h>
//#include <linux/syscall.h>
//#include <errno.h>
//#include <stdint.h>
//#include <linux/atmioc.h>
#include <linux/user_events.h>


#define BUF_COUNT        128
#define UV_READ_BUF_SIZE 64 
#define SHARED_MEM_PATH "/shm_example"

typedef struct shm_mem_ {
    uint32_t                prod_pid;
    uint32_t                event_fd;
    atomic_uint_fast64_t    prod_seq;
    atomic_uint_fast64_t    cons_seq;
    uint64_t                data[BUF_COUNT];
} shm_mem_t;