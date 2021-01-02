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


void fils(int sockfd)
{
	char buffer[MAX];
	int n;

	for (;;) {
    memset(&buffer, '\0', MAX);
		read(sockfd, buffer, sizeof(buffer));
		printf("From client: %s\t To client : ", buffer);
    memset(&buffer, '\0', MAX);
		n = 0;
		while ((getchar() != '\n') || (n<20) ){
      buffer[n] = getchar();
      n++;
    }
		write(sockfd, buffer, sizeof(buffer));
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
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
  }
	else
		printf("Socket successfully created..\n");
	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(PORT);
  if ((bind(sockfd, (SA*)&serverAddr, sizeof(serverAddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully binded..\n");
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
	fils(connection);

	// After chatting close the socket
	close(sockfd);
}
