#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 80
#define PORT 9600
#define SA struct sockaddr


// Function designed for chat between client and server.
void func(int sockfd)
{
	char buffer[MAX];
	int n;
	// infinite loop for chat
	for (;;) {
		bzero(buffer, MAX);

		// read the message from client and copy it in buffer
		read(sockfd, buffer, sizeof(buffer));
		// print buffer which contains the client contents
		printf("From client: %s\t To client : ", buffer);
		bzero(buffer, MAX);
		n = 0;
		// copy server message in the buffer
		while ((buffer[n++] = getchar()) != '\n')
			;

		// and send that buffer to client
		write(sockfd, buffer, sizeof(buffer));

		// if msg contains "Exit" then server exit and chat ended.
		if (strncmp("exit", buffer, 4) == 0) {
			printf("Server Exit...\n");
			break;
		}
	}
}

// Driver function
int main()
{
	int sockfd, connection, len;
	struct sockaddr_in serverAddr, clientAddr;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	/*
  if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
  */
	//else
	//	printf("Socket successfully created..\n");
	memset(&serverAddr, '\0', sizeof(serverAddr)); // avant ici bzero(éserveraddr, sizeog(serveraddr))
//  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
	// assign IP, PORT
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
	/*if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");*/
  bind(sockfd, (SA*)&serverAddr, sizeof(serverAddr));
	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
	else
		printf("Server listening..\n");
	len = sizeof(clientAddr);

	// Accept the data packet from client and verification
	connection = accept(sockfd, (SA*)&clientAddr, &len);
	if (connection < 0) {
		printf("server acccept failed...\n");
		exit(0);
	}
	else
		printf("server acccept the client...\n");

	// Function for chatting between client and server
	func(connection);

	// After chatting close the socket
	close(sockfd);
}
