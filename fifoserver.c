#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>


#define PIPE "fifo1"
int main()
{
  FILE *fp;
  char readBuffer[80];
  
  // create a fifo if it doesn't no exist
  umask(0);
  mknod(PIPE, S_IFIFO|0666, 0);
  
  while(1)
  {
    fp = fopen(PIPE, "r");
    fgets(readBuffer, 80, fp);
    printf("Received : %s\n", readBuffer);
    fclose(fp);
  }
  
  return 0;
}