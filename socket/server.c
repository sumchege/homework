#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

#define MAXSIZE 512
#define PORT 8888

int main()
{
  int sockfd, len, nBytes;
  struct sockaddr_in serverAddr, clientAddr;
  char recvbuf[MAXSIZE], sendbuf[MAXSIZE];
  
  // create a socket
  
  if((sockfd = socket(AF_INET, SOCK_DGRAM, 0))<0)
  {
    perror("udp socket");
  }
  
  // configure server address
  // zero out the address
  memset((char *) &serverAddr, 0, sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;	// internet address sin_family
  serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);	// Any incoming interface
  serverAddr.sin_port = htons(PORT); // local port
  
  // bind server
  if(bind(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1)
  {
    perror("binding");
  }
  
  while(1)
  {
    // transactions
    printf("Waiting connections...\n");
    fflush(stdout);
    
    // try to receive data - > blocking call 
    if((nBytes = recvfrom(sockfd, recvbuf, MAXSIZE, 0, (struct sockaddr*)&clientAddr, &len)) < 0)
    {
      perror("receiving");
    }
    
    // print details of clientAddr and data received
    printf("Received packet from: %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
    printf("Data: %s\n", recvbuf);
    
    
    // now try replying
    if(sendto(sockfd, recvbuf, nBytes, 0, (struct sockaddr *)&clientAddr, len) < 0)
    {
      perror("sending");
    }
    
  }
  
  
  close(sockfd);
  return 0;
}