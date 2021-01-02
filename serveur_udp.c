#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <ctype.h>
#define MAX 20
#define PORT 9600

int main(){
  int sockfd, nBytes;
  char buffer[MAX];
  struct sockaddr_in serverAddr, clientAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size, client_addr_size;
  int i;

  sockfd = socket(PF_INET, SOCK_DGRAM, 0);

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(PORT);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  bind(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  addr_size = sizeof serverStorage;

  for(;;){
    nBytes = recvfrom(sockfd,buffer,MAX,0,(struct sockaddr *)&serverStorage, &addr_size);
    if ((strncmp(buffer, "exit", 4)) == 0) {
			printf("Client Exit...\n");
			break;
		}
    printf("Received from client: %s\n",buffer);
  }
  return 0;
}
