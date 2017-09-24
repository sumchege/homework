
/*
 * This program sends a message to the queue
 */

#include <stdio.h>
#include <string.h>
#include <mqueue.h>

#define QUEUE_NAME "/fifoq1"
#define PRIORITY 1
#define SIZE 256

int main()
{
  mqd_t ds;
  char new_text[SIZE];
  struct mq_attr attr, old_attr;
  int prio;
  
  /*
   * Open q for sending and receiving. No blocking when receiving a message (O_NONBLOCK)
   * 
   */
  if((ds = mq_open(QUEUE_NAME, O_RDWR | O_NONBLOCK, 0600, NULL)) == (mqd_t)-1)
  {
    perror("Creating queue error");
    return -1;
  }
  
  /*
   * Change to blocking receive to demonstrate mq_setattr, mq_getattr. 
   * NOTE: mq_setattr cannot be used to change values of mq params such as mq_msgsize, mq_maxmsg etc. It can 
   * only be used to change mq_flags of mq_attr struct
   */
  
  attr.mq_flags = 0; /* set !O_NONBLOCK*/
  if(mq_setattr(ds, &attr, NULL)){
    perror("mq_setattr error");
    return -1;
  }
  
  /*we check that O-O_NONBLOCK is not set, the function populates mq params in the old_attr struct
   * 
   */
  
  if(mq_getattr(ds, &old_attr))
  {
    perror("mq_getattr error");
    return -1;
  }
  
  if(!(old_attr.mq_flags & O_NONBLOCK))
  {
    printf("O_NONBLOCK not set\n");
  }
  
  /*
   * receive the message from queue, this is a blocking call
   * 
   */
  
  if(mq_receive(ds, new_text, SIZE, &prio) == -1)
  {
    perror("cannot receive");
    return -1;
  }
  printf("Message: %s, prio = %d\n", new_text, prio);
  
  // Close Queue
  if (mq_close(ds) == -1)
  {
    perror("Closing queue error");
  }
  
  // unlink the Queue
  if(mq_unlink(QUEUE_NAME) == -1){
    perror("Removing Q error");
  }
  return 0;
}