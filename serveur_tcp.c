/*
* Code du serveur
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>


#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

/* Port local du serveur */
#define PORT 9600


int main(int argc, char *argv[])
{

  SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
  /*if(sock == INVALID_SOCKET)
  {
      perror("socket()");
      exit(errno);
  }*/
  SOCKADDR_IN sin = { 0 };

  sin.sin_addr.s_addr = htonl(INADDR_ANY); /* nous sommes un serveur, nous acceptons n'importe quelle adresse */

  sin.sin_family = AF_INET;

  sin.sin_port = htons(PORT);

  //if(
  bind (sock, (SOCKADDR *) &sin, sizeof sin);
  /*== SOCKET_ERROR)
  {
      perror("bind()");
      exit(errno);
  }*/

  //if(
  listen(sock, 5); //== SOCKET_ERROR)
  /*{
      perror("listen()");
      exit(errno);
  }*/


  SOCKADDR_IN csin = { 0 };
  SOCKET csock;

  int sinsize = sizeof csin;

  csock = accept(sock, (SOCKADDR *)&csin, &sinsize);

  /*if(csock == INVALID_SOCKET)
  {
      perror("accept()");
      exit(errno);
  }
  */
  closesocket(sock);
  closesocket(csock);


  return 0;
}
