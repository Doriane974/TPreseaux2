#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#define MAX 20
#define PORT 9600
#define SA struct sockaddr

void chat(int sockfd)
{
	char buffer[MAX];
	int n;
	for (;;) {
		//bzero(buffer, sizeof(buffer));
    memset(&buffer, '\0', MAX);
		printf("Entrer le message a envoyer : ");
		n = 0;
		while ((buffer[n++] = getchar()) != '\n')
			;
		write(sockfd, buffer, sizeof(buffer));
		//bzero(buffer, sizeof(buffer));
    memset(&buffer, '\0', MAX);
		read(sockfd, buffer, sizeof(buffer));
		printf("You received : %s", buffer);
		if ((strncmp(buffer, "exit", 4)) == 0) {
			printf("Client Exit...\n");
			break;
		}
	}
}

int main()
{
	int sockfd, connection;
	struct sockaddr_in serverAddr, clientAddr;

	// socket create and varification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");
	//bzero(&serverAddr, sizeof(serverAddr));
  memset(&serverAddr, '\0', sizeof(serverAddr));

	// assign IP, PORT
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddr.sin_port = htons(PORT);

	// connect the client socket to server socket
	if (connect(sockfd, (SA*)&serverAddr, sizeof(serverAddr)) != 0) {
		printf("connection with the server failed...\n");
		exit(0);
	}
	else
		printf("connected to the server..\n");

	// function for chat
  chat(sockfd);

	// close the socket
	close(sockfd);
}
