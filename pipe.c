
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
  int fd[2], nbytes;
  pid_t child_pid;
  
  char string[] = "Hello, world!\n";
  char readBuffer[80];
  
  // Make pipe
  pipe(fd);
  
  // fork chid
  if((child_pid= fork()) == -1)
  {
    perror("Fork");
    exit(1);
  }
  
  // Make decision of data flow direction
  
  if(child_pid == 0)
  {
    // Child process closes up input side of the pipe
    close(fd[0]);
    
    // send string through pipe 
    write(fd[1], string, sizeof(string)+1);
    exit(0);
  }
  else
  {
    // Parent closes the output side of the pipe
    close(fd[1]);
    
    //read from pipe
    nbytes = read(fd[0], readBuffer, sizeof(readBuffer));
    printf("Received: %s", readBuffer);
    
  }
  
  return 0;
}
