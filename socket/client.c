#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

#define MAXSIZE 512
#define PORT 8888
#define ADDR "127.0.0.1"

int main()
{
  int sockfd, len, ret, numbytes;
  struct sockaddr_in tAddr, clientAddr;
  char recvbuf[MAXSIZE], sendbuf[MAXSIZE];
  
  // create a socket
  if((sockfd = socket(AF_INET, SOCK_DGRAM, 0))<0)
  {
    perror("udp socket");
  }
  
  // configure address
  //zero out the struct
  memset((char *) &tAddr, 0, sizeof(tAddr));
  
  tAddr.sin_family = AF_INET;	// internet address sin_family
  tAddr.sin_port = htons(PORT); // local port
  
  if(inet_aton(ADDR, &tAddr.sin_addr) == 0)
  {
    perror("inet_aton");
    exit(1);
  }
  
  len = sizeof(tAddr);

  
  while(1)
  {
    // transactions
    printf("Enter message: ");
    gets(sendbuf);
    
    if(sendto(sockfd, sendbuf, strlen(sendbuf) , 0 , (struct sockaddr *) &tAddr, len)==-1)
    {
      perror("sendingto");
    }
    
  }
  
  close(sockfd);
  return 0;
}