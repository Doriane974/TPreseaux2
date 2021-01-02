
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(){
  int sockfd, nBytes;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  sockfd = socket(PF_INET, SOCK_DGRAM, 0);

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(9600);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  /*Initialize size variable to be used later on*/
  addr_size = sizeof serverAddr;
  int j = 0;
  while(j<20){
    printf("Type a sentence to send to server:\n");
    fgets(buffer,21,stdin);

    printf("You typed: %s \n",buffer);

    nBytes = strlen(buffer) + 1;

    /*Send message to server*/
    sendto(sockfd,buffer,nBytes,0,(struct sockaddr *)&serverAddr,addr_size);


  }

  return 0;
}
