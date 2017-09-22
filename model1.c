#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>

/*
 * Desired queue attributes
 */

#define PERM 0660
#define MAX_MSGS 10
#define MAX_MSGSZ 256
#define MAX_BUFFERSZ MAX_MSGSZ + 10

int main(int argc, char **argv)
{
  
  if(argc != 2)
  {
    
    printf("Usage : taskmodel2 <K>");
  }
  printf("%s", argv[2]);
  int count = 0;
  int prio;
  
  // Queue descriptors
  mqd_t qchannel;
  
  // queue attributes
  struct mq_attr attr;
  attr.mq_flags = 0;
  attr.mq_maxmsg = MAX_MSGS;
  attr.mq_msgsize = MAX_MSGSZ;
  attr.mq_curmsgs = 0;
  
  // Send MAX_BUFFERSZ
  char buffer[MAX_BUFFERSZ];
  
  if((qchannel = mq_open("/fifo1", O_CREAT | O_RDWR, 0600,&attr)) == -1)
  {
    perror("Creating queue.");
    return -1;
  }
  
  while(1)
  {
    // Read a value from queue and multiply with K
    
    if(mq_receive(qchannel, buffer, MAX_BUFFERSZ, &prio) == -1){
      perror("Receiving");
      return -1;
    }
    count = *((int*)buffer);
    int dsp = count * 10;
    printf("Got: %d\n", dsp);
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
