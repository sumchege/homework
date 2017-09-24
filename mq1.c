
/*
 * This program sends a message to the queue
 */

#include <stdio.h>
#include <string.h>
#include <mqueue.h>

#define QUEUE_NAME "/fifoq1"
#define PRIORITY 1
#define SIZE 256

int main(int argc, char *argv[]){
  mqd_t ds;
  char *text = argv[1];
  struct mq_attr queue_attr;
  
  /*
   * Attributes for queue can only be created during creation
   */
  
  queue_attr.mq_maxmsg = 10;
  queue_attr.mq_msgsize = SIZE;
  
   /*
   * Create a new MQ and and open it for sending and receiving. Queue file permisionsset for RW for owner
   * and nothing for other groups
   */
   
   if((ds = mq_open(QUEUE_NAME,O_CREAT | O_RDWR, 0600, &queue_attr)) == (mqd_t)-1)
   {
     perror("Creating queue error");
     return -1;
   }
   
   /*
    * Send a message with priority 1
    */
   
   if(mq_send(ds, text, strlen(text), PRIORITY) == -1)
   {
     perror("Sending message error");
     return -1;
   }
   
   // Close Queue
   
   if(mq_close(ds) == -1)
   {
     perror("Closing queue error");
   }
  return 0;
}