#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mqueue.h>

/*
 * Desired queue attributes
 */

#define PERM 0660
#define MAX_MSGS 10
#define MAX_MSGSZ 256
#define MAX_BUFFERSZ MAX_MSGSZ + 10

int main()
{
  int count = 0;
  
  // Queue descriptors
  mqd_t qchannel;
  
  // queue attributes
  struct mq_attr attr;
  attr.mq_flags = 0;
  attr.mq_maxmsg = MAX_MSGS;
  attr.mq_msgsize = MAX_MSGSZ;
  attr.mq_curmsgs = 0;
  
  // Send MAX_BUFFERSZ
  // char buffer[MAX_BUFFERSZ];
  
  if((qchannel = mq_open("/fifo1", O_CREAT | O_RDWR, 0600, &attr)) == -1)
  {
    perror("Creating queue.");
    return -1;
  }
  
  while(1)
  {
    // generate a random number and send through channel to the other process
    usleep(100000);
    
    if(count > 100)
      count = 0;
    if(mq_send(qchannel, (char *) &count, sizeof(count), 1) == -1){
      perror("Sending");
      return -1;
    }
    printf("sent: %d\n", count);
    count++;
  }
  
  
  if (mq_close(qchannel) == -1)
  {
    perror("Closing queue error");
  }
  
  // unlink the Queue
  if(mq_unlink("fifo1") == -1){
    perror("Removing Q error");
  }
  
  return 0;
}