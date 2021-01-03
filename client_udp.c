
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#define MAX 20
#define PORT 9600

int main(){

	int sockfd, nBytes;
	char buffer[MAX];
	struct sockaddr_in serverAddr;
	socklen_t addr_size;

	sockfd = socket(PF_INET, SOCK_DGRAM, 0);

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

	addr_size = sizeof serverAddr;
	for(;;){
		printf("Taper le message a envoyer au serveur :\n");
		fgets(buffer,MAX+1,stdin);
		printf("Vous avez taper : %s \n",buffer);

		nBytes = strlen(buffer) + 1;

		sendto(sockfd,buffer,nBytes,0,(struct sockaddr *)&serverAddr,addr_size);
		if ((strncmp(buffer, "exit", 4)) == 0) {
				printf("Fermeture du client...\n");
				break;
			}
	}
  	return 0;
}
