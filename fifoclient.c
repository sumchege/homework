#include <stdio.h>
#include <stdlib.h>

#define PIPE "fifo1"

int main(int argc, char *argv[])
{
  FILE *fp;
  
  if(argc != 2){
    printf("Usage fifoclient [string]\n");
    exit(1);
  }
  
  if((fp = fopen(PIPE, "w")) == NULL)
  {
    perror("fopen");
    exit(1);
  }
  
  fputs(argv[1], fp);
  fclose(fp);
  return 0;
}