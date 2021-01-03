#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 20
#define PORT 9600
#define SA struct sockaddr


void fils(int sockfd){
	char buffer[MAX];
	int n;

	for (;;) {
    	memset(&buffer, '\0', MAX);
		read(sockfd, buffer, sizeof(buffer));
		printf("Du client : %s\t Au client : ", buffer);
    	memset(&buffer, '\0', MAX);
    	n = 0;
    	while ((buffer[n++] = getchar()) != '\n') ;
		write(sockfd, buffer, sizeof(buffer));
		if (strncmp("exit", buffer, 4) == 0) {
			printf("Fermeture du serveur...\n");
			break;
		}
	}
}

int main(){
	int sockfd, connection, len;
	struct sockaddr_in serverAddr, clientAddr;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

  	if (sockfd == -1) {
		printf("Echec de la creation du socket...\n");
		exit(0);
  	}
	else
		printf("Succes de la creation du socket..\n");
	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(PORT);
  	if ((bind(sockfd, (SA*)&serverAddr, sizeof(serverAddr))) != 0) {
		printf("Echec du bind du socket...\n");
		exit(0);
	}
	else
		printf("Succes du bind du socket..\n");
  	bind(sockfd, (SA*)&serverAddr, sizeof(serverAddr));
	if ((listen(sockfd, 5)) != 0) {
		printf("Listen a echoue...\n");
		exit(0);
	}
	else
		printf("Le serveur est en listen..\n");
	len = sizeof(clientAddr);

	connection = accept(sockfd, (SA*)&clientAddr, &len);
	if (connection < 0) {
		printf("Le serveur n'a pas accept le client...\n");
		exit(0);
	}
	else
		printf("Le serveur acccept le client...\n");

	fils(connection);
	close(sockfd);
  return 0;
}
