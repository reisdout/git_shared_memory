// SPDX-License-Identifier: GPL-2.0-only
/*
 * TCP Vegas congestion control
 *
 * This is based on the congestion detection/avoidance scheme described in
 *    Lawrence S. Brakmo and Larry L. Peterson.
 *    "TCP Vegas: End to end congestion avoidance on a global internet."
 *    IEEE Journal on Selected Areas in Communication, 13(8):1465--1480,
 *    October 1995. Available from:
 *	ftp://ftp.cs.arizona.edu/xkernel/Papers/jsac.ps
 *
 * See http://www.cs.arizona.edu/xkernel/ for their implementation.
 * The main aspects that distinguish this implementation from the
 * Arizona Vegas implementation are:
 *   o We do not change the loss detection or recovery mechanisms of
 *     Linux in any way. Linux already recovers from losses quite well,
 *     using fine-grained timers, NewReno, and FACK.
 *   o To avoid the performance penalty imposed by increasing cwnd
 *     only every-other RTT during slow start, we increase during
 *     every RTT during slow start, just like Reno.
 *   o Largely to allow continuous cwnd growth during slow start,
 *     we use the rate at which ACKs come back as the "actual"
 *     rate, rather than the rate at which data is sent.
 *   o To speed convergence to the right rate, we set the cwnd
 *     to achieve the right ("actual") rate when we exit slow start.
 *   o To filter out the noise caused by delayed ACKs, we use the
 *     minimum RTT sample observed during the last RTT to calculate
 *     the actual rate.
 *   o When the sender re-starts from idle, it waits until it has
 *     received ACKs for an entire flight of new data before making
 *     a cwnd adjustment decision. The original Vegas implementation
 *     assumed senders never went idle.
 */

 #include <linux/mm.h>
 #include <linux/module.h>
 #include <linux/skbuff.h>
 #include <linux/inet_diag.h>
 #include <linux/proc_fs.h>
 
 #include <net/tcp.h>
 
 #include "tcp_vegas.h"
 
 static int alpha = 2;
 static int beta  = 4;
 static int gamma = 1;

 /***********************MRS******************************/
 static bool intelligent = false;
 static int mrs_network_state = 1;
 static u64  new_SegCwnd = 1.0;
 //static u32 fake_cwnd = 1;
 /*
 Esta funcao aproxima a sqrt
 */
 static int sqrt_aprox( int x)
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

    if((x-lower_limit*lower_limit) < (upper_limit*upper_limit-x))
        return lower_limit;
    
    return upper_limit;

 
}
/*
static void i_cong_avoid(int cwnd)
{
    if(intelligent)
    {
        printk("Working with cwnd = %d\n", cwnd);
        u32 segCwnd = cwnd;

        if (mrs_network_state == 2 || segCwnd == 1)// fsegCwnd == 1 indica redução por timeout
        {
            printk("Seting cwnd with network stare equal to 2? %d\n", mrs_network_state);
            //Este calculo utiliza a ideia de que a raiz quarta do cubo
            //e igual a raiz(x)*raiz(raiz(x)), fazendo aproximacoes por
            //inteiros da raiz
            int cwnd_sqrt = sqrt_aprox(segCwnd);
            new_SegCwnd = cwnd_sqrt*sqrt_aprox(cwnd_sqrt); //float_SegCwnd*(1.0/std::pow(segCwnd,0.25));

            u32 segCwndAnt = segCwnd;        

            if(new_SegCwnd > 10) //a ideia é sempre ter 9 para preencher a matriz 3X3
            {
                u32 oldSegCwnd = segCwnd;//Não pode usar segCwndAnt, pois essa é a nossa janela anterior. A segCwnd é do vegas e foi mudada por timeout, sendo dessincronizada da segCwndAnt
                segCwnd = new_SegCwnd;
                if(oldSegCwnd  > 1) //É um decremento efetivo, pois se foi por time_out (segCwnd == 1) a coisa acaba incrementando.
                printk("--DECREMENTOU de %d para %d\n", segCwndAnt, segCwnd);
                else
                printk("--INCREMENTOU de %d para %d\n",oldSegCwnd, segCwnd);

            
            }
            else
            {
                segCwnd = 10;
                printk("==JANELA MINIMA foi de %d para %d\n", segCwndAnt, segCwnd);
            }  
            //printf("--DECREMENTOU Fluxo %d, foi de %d para %d\n",flow_id, segCwndAnt, segCwnd);
            //getchar();
            //tcp_snd_cwnd_set(tp, segCwnd + 1);//tcb->m_cWnd = segCwnd * tcb->m_segmentSize;
            //tcb->m_ssThresh = GetSsThresh (tcb, 0);
            printk("Updated cwnd = %d \n", segCwnd+1);
      }
      else if (mrs_network_state == 1)
      {
        printk("Seting cwnd with network stare equal to 1? %d\n", mrs_network_state);
      
        if(segCwnd >= 10 || segCwnd <= 2)
          new_SegCwnd = (segCwnd + 4);
        
        else
          new_SegCwnd = segCwnd*segCwnd;//(float)std::pow(float_SegCwnd,2.0);
        
        printk("new_SegCwnd: %d\n",new_SegCwnd);
        u32 segCwndAnt = segCwnd;
        if(new_SegCwnd > 10)
          segCwnd = new_SegCwnd +1; //(uint32_t)(float_SegCwnd) +1;
        else
          segCwnd = 10;
        printk("++INCREMENTOU, foi de %d para %d\n",segCwndAnt,segCwnd);
        //getchar();
        //tcp_snd_cwnd_set(tp, segCwnd);//tcb->m_cWnd = segCwnd * tcb->m_segmentSize;
      }
      //tcb->m_ssThresh = std::max (tcb->m_ssThresh, 3 * tcb->m_cWnd / 4);
      return;
    }

    printk("Not intelligent CC\n");

    

}

*/

 
 module_param(alpha, int, 0644);
 MODULE_PARM_DESC(alpha, "lower bound of packets in network");
 module_param(beta, int, 0644);
 MODULE_PARM_DESC(beta, "upper bound of packets in network");
 module_param(gamma, int, 0644);
 MODULE_PARM_DESC(gamma, "limit on increase (scale by 2)");
 
 /* There are several situations when we must "re-start" Vegas:
  *
  *  o when a connection is established
  *  o after an RTO
  *  o after fast recovery
  *  o when we send a packet and there is no outstanding
  *    unacknowledged data (restarting an idle connection)
  *
  * In these circumstances we cannot do a Vegas calculation at the
  * end of the first RTT, because any calculation we do is using
  * stale info -- both the saved cwnd and congestion feedback are
  * stale.
  *
  * Instead we must wait until the completion of an RTT during
  * which we actually receive ACKs.
  */
 static void vegas_enable(struct sock *sk)
 {
     const struct tcp_sock *tp = tcp_sk(sk);
     struct vegas *vegas = inet_csk_ca(sk);
 
     /* Begin taking Vegas samples next time we send something. */
     vegas->doing_vegas_now = 1;
 
     /* Set the beginning of the next send window. */
     vegas->beg_snd_nxt = tp->snd_nxt;
 
     vegas->cntRTT = 0;
     vegas->minRTT = 0x7fffffff;
 }
 
 /* Stop taking Vegas samples for now. */
 static inline void vegas_disable(struct sock *sk)
 {
     struct vegas *vegas = inet_csk_ca(sk);
 
     vegas->doing_vegas_now = 0;
 }
 
 void tcp_vegas_init(struct sock *sk)
 {
     struct vegas *vegas = inet_csk_ca(sk);
 
     vegas->baseRTT = 0x7fffffff;
     vegas_enable(sk);
 }
 EXPORT_SYMBOL_GPL(tcp_vegas_init);
 
 /* Do RTT sampling needed for Vegas.
  * Basically we:
  *   o min-filter RTT samples from within an RTT to get the current
  *     propagation delay + queuing delay (we are min-filtering to try to
  *     avoid the effects of delayed ACKs)
  *   o min-filter RTT samples from a much longer window (forever for now)
  *     to find the propagation delay (baseRTT)
  */
 void tcp_vegas_pkts_acked(struct sock *sk, const struct ack_sample *sample)
 {
     struct vegas *vegas = inet_csk_ca(sk);
     u32 vrtt;
 
     if (sample->rtt_us < 0)
         return;
 
     /* Never allow zero rtt or baseRTT */
     vrtt = sample->rtt_us + 1;
 
     /* Filter to find propagation delay: */
     if (vrtt < vegas->baseRTT)
         vegas->baseRTT = vrtt;
 
     /* Find the min RTT during the last RTT to find
      * the current prop. delay + queuing delay:
      */
     vegas->minRTT = min(vegas->minRTT, vrtt);
     vegas->cntRTT++;
 }
 EXPORT_SYMBOL_GPL(tcp_vegas_pkts_acked);
 
 void tcp_vegas_state(struct sock *sk, u8 ca_state)
 {
     if (ca_state == TCP_CA_Open)
         vegas_enable(sk);
     else
         vegas_disable(sk);
 }
 EXPORT_SYMBOL_GPL(tcp_vegas_state);
 
 /*
  * If the connection is idle and we are restarting,
  * then we don't want to do any Vegas calculations
  * until we get fresh RTT samples.  So when we
  * restart, we reset our Vegas state to a clean
  * slate. After we get acks for this flight of
  * packets, _then_ we can make Vegas calculations
  * again.
  */
 void tcp_vegas_cwnd_event(struct sock *sk, enum tcp_ca_event event)
 {
     if (event == CA_EVENT_CWND_RESTART ||
         event == CA_EVENT_TX_START)
         tcp_vegas_init(sk);
 }
 EXPORT_SYMBOL_GPL(tcp_vegas_cwnd_event);
 
 static inline u32 tcp_vegas_ssthresh(struct tcp_sock *tp)
 {
     return  min(tp->snd_ssthresh, tcp_snd_cwnd(tp));
 }



 
 static void tcp_vegas_cong_avoid(struct sock *sk, u32 ack, u32 acked)
 {
     
    printk("intelligent cc: updating cwnd\n");
    
    struct tcp_sock *tp = tcp_sk(sk);
     struct vegas *vegas = inet_csk_ca(sk);
 
     if (!vegas->doing_vegas_now) {
         tcp_reno_cong_avoid(sk, ack, acked);
         return;
     }

	 if(!intelligent)
	 {
 
			if (after(ack, vegas->beg_snd_nxt)) {
				/* Do the Vegas once-per-RTT cwnd adjustment. */
		
				/* Save the extent of the current window so we can use this
				* at the end of the next RTT.
				*/
				vegas->beg_snd_nxt  = tp->snd_nxt;
		
				/* We do the Vegas calculations only if we got enough RTT
				* samples that we can be reasonably sure that we got
				* at least one RTT sample that wasn't from a delayed ACK.
				* If we only had 2 samples total,
				* then that means we're getting only 1 ACK per RTT, which
				* means they're almost certainly delayed ACKs.
				* If  we have 3 samples, we should be OK.
				*/
		
				if (vegas->cntRTT <= 2) {
					/* We don't have enough RTT samples to do the Vegas
					* calculation, so we'll behave like Reno.
					*/
					tcp_reno_cong_avoid(sk, ack, acked);
				} else {
					u32 rtt, diff;
					u64 target_cwnd;
		
					/* We have enough RTT samples, so, using the Vegas
					* algorithm, we determine if we should increase or
					* decrease cwnd, and by how much.
					*/
		
					/* Pluck out the RTT we are using for the Vegas
					* calculations. This is the min RTT seen during the
					* last RTT. Taking the min filters out the effects
					* of delayed ACKs, at the cost of noticing congestion
					* a bit later.
					*/
					rtt = vegas->minRTT;
		
					/* Calculate the cwnd we should have, if we weren't
					* going too fast.
					*
					* This is:
					*     (actual rate in segments) * baseRTT
					*/
					target_cwnd = (u64)tcp_snd_cwnd(tp) * vegas->baseRTT;
					do_div(target_cwnd, rtt);
		
					/* Calculate the difference between the window we had,
					* and the window we would like to have. This quantity
					* is the "Diff" from the Arizona Vegas papers.
					*/
					diff = tcp_snd_cwnd(tp) * (rtt-vegas->baseRTT) / vegas->baseRTT;
		
					if (diff > gamma && tcp_in_slow_start(tp)) {
						/* Going too fast. Time to slow down
						* and switch to congestion avoidance.
						*/
		
						/* Set cwnd to match the actual rate
						* exactly:
						*   cwnd = (actual rate) * baseRTT
						* Then we add 1 because the integer
						* truncation robs us of full link
						* utilization.
						*/
						tcp_snd_cwnd_set(tp, min(tcp_snd_cwnd(tp),
									(u32)target_cwnd + 1));
						tp->snd_ssthresh = tcp_vegas_ssthresh(tp);
		
					} else if (tcp_in_slow_start(tp)) {
						/* Slow start.  */
						tcp_slow_start(tp, acked);
					} else {
						/* Congestion avoidance. */
		
						/* Figure out where we would like cwnd
						* to be.
						*/
						if (diff > beta) {
							/* The old window was too fast, so
							* we slow down.
							*/
							tcp_snd_cwnd_set(tp, tcp_snd_cwnd(tp) - 1);
							tp->snd_ssthresh
								= tcp_vegas_ssthresh(tp);
						} else if (diff < alpha) {
							/* We don't have enough extra packets
							* in the network, so speed up.
							*/
							tcp_snd_cwnd_set(tp, tcp_snd_cwnd(tp) + 1);
						} else {
							/* Sending just as fast as we
							* should be.
							*/
						}
					}
		
					if (tcp_snd_cwnd(tp) < 2)
						tcp_snd_cwnd_set(tp, 2);
					else if (tcp_snd_cwnd(tp) > tp->snd_cwnd_clamp)
						tcp_snd_cwnd_set(tp, tp->snd_cwnd_clamp);
		
					tp->snd_ssthresh = tcp_current_ssthresh(sk);
				}
		
				/* Wipe the slate clean for the next RTT. */
				vegas->cntRTT = 0;
				vegas->minRTT = 0x7fffffff;
			}
			/* Use normal slow start */
			else if (tcp_in_slow_start(tp))
				tcp_slow_start(tp, acked);
	 }
	else
	{
	    printk("Operating in inteligent mode (ver 2.0) \n");

        printk("Vega++ with ntworkstate: %d\n", mrs_network_state);
        //printk("tcb->m_segmentSize: %d\n", tcb->m_segmentSize);

        u64 segCwnd = tcp_snd_cwnd(tp);

        if (mrs_network_state == 2 || segCwnd == 1)// fsegCwnd == 1 indica redução por timeout
        {
            printk("Seting cwnd with network stare equal to 2? %d\n", mrs_network_state);
            //Este calculo utiliza a ideia de que a raiz quarta do cubo
            //e igual a raiz(x)*raiz(raiz(x)), fazendo aproximacoes por
            //inteiros da raiz
            int cwnd_sqrt = sqrt_aprox(segCwnd);
            new_SegCwnd = (u64)cwnd_sqrt*sqrt_aprox(cwnd_sqrt); //float_SegCwnd*(1.0/std::pow(segCwnd,0.25));

            u64 segCwndAnt = segCwnd;        

            if(new_SegCwnd > 10) //a ideia é sempre ter 9 para preencher a matriz 3X3
            {
                u64 oldSegCwnd = segCwnd;//Não pode usar segCwndAnt, pois essa é a nossa janela anterior. A segCwnd é do vegas e foi mudada por timeout, sendo dessincronizada da segCwndAnt
                segCwnd = new_SegCwnd;
                if(oldSegCwnd  > 1) //É um decremento efetivo, pois se foi por time_out (segCwnd == 1) a coisa acaba incrementando.
                printk("--DECREMENTOU de %llu para %llu\n", segCwndAnt, segCwnd);
                else
                printk("--INCREMENTOU de %llu para %llu\n",oldSegCwnd, segCwnd);

            
            }
            else
            {
                segCwnd = 10;
                printk("==JANELA MINIMA foi de %llu para %llu\n", segCwndAnt, segCwnd);
            }  
            //printf("--DECREMENTOU Fluxo %d, foi de %d para %d\n",flow_id, segCwndAnt, segCwnd);
            //getchar();
            tcp_snd_cwnd_set(tp, segCwnd + 1);//tcb->m_cWnd = segCwnd * tcb->m_segmentSize;
            //tcb->m_ssThresh = GetSsThresh (tcb, 0);
            printk("Updated cwnd = %llu \n", segCwnd+1);
      }
      else if (mrs_network_state == 1)
      {
        printk("Seting cwnd with network stare equal to 1? %d\n", mrs_network_state);
      
        if(segCwnd >= 10 || segCwnd <= 2)
          new_SegCwnd = (segCwnd + 4*acked); //4*acked, pois aumenta 4 para cada ack
        
        else
          new_SegCwnd = segCwnd*segCwnd;//(float)std::pow(float_SegCwnd,2.0);
        
        printk("new_SegCwnd: %llu\n",new_SegCwnd);
        u64 segCwndAnt = segCwnd;
        if(new_SegCwnd > 10)
          segCwnd = new_SegCwnd +1; //(uint32_t)(float_SegCwnd) +1;
        else
          segCwnd = 10;
        printk("++INCREMENTOU, foi de %llu para %llu\n",segCwndAnt,segCwnd);
        //getchar();
        tcp_snd_cwnd_set(tp, segCwnd);//tcb->m_cWnd = segCwnd * tcb->m_segmentSize;
      }
      //tcb->m_ssThresh = std::max (tcb->m_ssThresh, 3 * tcb->m_cWnd / 4);


	}
 }
 
 /* Extract info for Tcp socket info provided via netlink. */
 size_t tcp_vegas_get_info(struct sock *sk, u32 ext, int *attr,
               union tcp_cc_info *info)
 {
     const struct vegas *ca = inet_csk_ca(sk);
 
     if (ext & (1 << (INET_DIAG_VEGASINFO - 1))) {
         info->vegas.tcpv_enabled = ca->doing_vegas_now;
         info->vegas.tcpv_rttcnt = ca->cntRTT;
         info->vegas.tcpv_rtt = ca->baseRTT;
         info->vegas.tcpv_minrtt = ca->minRTT;
 
         *attr = INET_DIAG_VEGASINFO;
         return sizeof(struct tcpvegas_info);
     }
     return 0;
 }
 EXPORT_SYMBOL_GPL(tcp_vegas_get_info);
 
 static struct tcp_congestion_ops tcp_vegas __read_mostly = {
     .init		= tcp_vegas_init,
     .ssthresh	= tcp_reno_ssthresh,
     .undo_cwnd	= tcp_reno_undo_cwnd,
     .cong_avoid	= tcp_vegas_cong_avoid,
     .pkts_acked	= tcp_vegas_pkts_acked,
     .set_state	= tcp_vegas_state,
     .cwnd_event	= tcp_vegas_cwnd_event,
     .get_info	= tcp_vegas_get_info,
 
     .owner		= THIS_MODULE,
     .name		= "vegas",
 };
 
 
 //MRS_INIT
 
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
 
 
     printk("icc_vegas write \n");
	 
	 printk("enabling intelligence\n");

	 intelligent = true;
     
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
 
     printk("cc_level: %s\n", cc_level);
 
     int value = cc_level[0]  - 'A' + 1;
     printk("cc_level: %d\n", value);

     mrs_network_state = value;

     //fake_cwnd++;

     //i_cong_avoid(fake_cwnd);
 
 
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
     printk("icc_vegas read \n");
     size_t len;
     int read_result;
 
     char icc_ack[] = "A\n";
     len = strlen(icc_ack);
     
     //if(*offset >= len)
         //return 0; //faz o cat parar.
 
 
     read_result = copy_to_user(user_space_buffer,icc_ack,len);
 
     *offset += len;
     
 
     return len; // deve-se retornar o numero de bytes que se passa para
                 // o user space.    
 
 }
 
 struct proc_ops icc_proc_ops = {
 
     .proc_read = icc_read,
     .proc_write = icc_write
 
 };
 
 
 //MRS_END
 
 
 
 
 
 
 
 
 
 static int __init tcp_vegas_register(void)
 {
     BUILD_BUG_ON(sizeof(struct vegas) > ICSK_CA_PRIV_SIZE);
     tcp_register_congestion_control(&tcp_vegas);
 
     printk("icc_vegas_module_init: entry\n");
	 intelligent = false;
     icc_proc_entry = proc_create("icc_vegas_driver", //cria /proc/icc_driver
                                  0, 
                                  NULL, 
                                  &icc_proc_ops); //veja linha 28
 
 
     if(! icc_proc_entry)
     {
         printk("icc_vegas module initialization eror\n");
         return -1;
     }
 
 
     /*
      * A non 0 return means init_module failed; module can't be loaded.
      */
     printk("icc_module_init: exit\n");
 
 
     return 0;
 }
 
 static void __exit tcp_vegas_unregister(void)
 {
     tcp_unregister_congestion_control(&tcp_vegas);
 
     printk("icc_vegas_module_exit: entry\n"); //para apagar /proc/icc_driver
 
     proc_remove(icc_proc_entry);
 
     printk("icc_vegas_module_exit: exit\n");
 
 
 }
 
 module_init(tcp_vegas_register);
 module_exit(tcp_vegas_unregister);
 
 MODULE_AUTHOR("Stephen Hemminger");
 MODULE_LICENSE("GPL");
 MODULE_DESCRIPTION("INTELIGENT TCP Vegas");