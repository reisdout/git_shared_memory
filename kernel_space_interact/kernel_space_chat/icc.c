#include <linux/init.h>
#include <linux/module.h> 	     /* Needed by all modules */
#include <linux/proc_fs.h>


MODULE_AUTHOR("KINGSDOCT");         /* Who wrote this module? */
MODULE_DESCRIPTION("Preparing to inteligent CC");    /* What does this module do ?*/
MODULE_LICENSE("GPL");

static struct proc_dir_entry *icc_proc_entry;




/*ssize_t	(*proc_write)(struct file *, 
                      const char __user *, 
                      size_t, 
                      loff_t *);

*/


static ssize_t icc_write (struct file * file_pointer, 
                          const char* user_space_buffer, 
                          size_t count, 
                          loff_t* offset)
{


    printk("icc write \n");    
    
    char cc_level[2];
    
    int write_res;

    write_res = copy_from_user(cc_level,user_space_buffer,2);

    cc_level[1] = '\0';
    
    int len = strlen(cc_level);

    if(len > 1)//just one char
    {
        printk("Too much for me\n");
        return 0;
    }

    printk("cc_level: %s", cc_level);

    int value = cc_level[0]  - 'A' + 1;
    printk("cc_level: %d\n", value);


    return len;
    


}





/*ssize_t	(*proc_read)(struct file *, 
                     char __user *, 
                     size_t, loff_t *);
*/

static ssize_t icc_read(struct file * file_pointer, 
                     char* user_space_buffer, 
                     size_t count, 
                     loff_t* offset) //pode ser a posicao do proximo byte a
                                     // ser lido do buffer em trans
                                     //ferencia para o user space
                                     //se o buffer e msg, pe,
                                     //msg[*offset] aponta para
                                     //o 1o byte nao transtrerido
                                     //para o user space...    
{
    printk("icc read \n");
    size_t len;
    int read_result;

    char icc_ack[] = "A\n";
    len = strlen(icc_ack);
    
    //if(*offset >= len)
        //return 0; //faz o cat parar.


    read_result = copy_to_user(user_space_buffer,icc_ack,len);

    *offset += len;
    

    return len; // deve-se retornar o numero de bytes que se pasa para
                // o user space.    

}

struct proc_ops icc_proc_ops = {

    .proc_read = icc_read,
    .proc_write = icc_write

};


/* This function shall be invoked as soon as this LKM is loaded.
 * Note the function prototype */
static int inteligent_cc_init(void){

    printk("icc_module_init: entry\n");
    icc_proc_entry = proc_create("icc_driver", //cria /proc/icc_driver
                                 0, 
                                 NULL, 
                                 &icc_proc_ops); //veja linha 28


    if(! icc_proc_entry)
    {
        printk("icc module initialization eror\n");
        return -1;
    }


    /*
     * A non 0 return means init_module failed; module can't be loaded.
     */
    printk("icc_module_init: exit\n");
    return 0;
}


/* Visit my Webiste : https://csepracticals.wixsite.com/csepracticals
 * for other courses for free or on discounted price. Take a look !! */



/* This function shall be invoked as soon as this LKM is unloaded.
 * Note the function prototype */
static void inteligent_cc_exit(void){

    printk("icc_module_exit: entry\n"); //para apagar /proc/icc_driver

    proc_remove(icc_proc_entry);

    printk("icc_module_exit: exit\n");

}




/* Tell the kernel which are init and cleanup functions for
 * this module. If you do not do this registration, kernel would
 * try to use 'init_module' and 'cleanup_module' instead */
module_init(inteligent_cc_init);
module_exit(inteligent_cc_exit);


