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


//#error not defined for this platform

//#endif
/* Port local du serveur */
#define PORT 9600
int main(int argc, char *argv[])
{

  SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
  /*if(sock == INVALID_SOCKET)
  {
      perror("socket()");
      exit(errno);
  }
  */
  struct hostent *hostinfo = NULL;
  SOCKADDR_IN sin = { 0 }; /* initialise la structure avec des 0 */
  const char *hostname = "localhost";

  hostinfo = gethostbyname(hostname); /* on récupère les informations de l'hôte auquel on veut se connecter */
  /*if (hostinfo == NULL) /* l'hôte n'existe pas
  {
      fprintf (stderr, "Unknown host %s.\n", hostname);
      exit(EXIT_FAILURE);
  }*/

  sin.sin_addr = *(IN_ADDR *) hostinfo->h_addr; /* l'adresse se trouve dans le champ h_addr de la structure hostinfo */
  sin.sin_port = htons(PORT); /* on utilise htons pour le port */
  sin.sin_family = AF_INET;

  //if(
  connect(sock,(SOCKADDR *) &sin, sizeof(SOCKADDR));// == SOCKET_ERROR)
/*  {
      perror("connect()");
      exit(errno);
  }*/

  char buffer[1024];
  //if(
  send(sock, buffer, strlen(buffer), 0);// < 0)
  /*{
      perror("send()");
      exit(errno);
  }*/

  int n = 0;

  //if((
  n = recv(sock, buffer, sizeof buffer - 1, 0);//) < 0)
  /*{
      perror("recv()");
      exit(errno);
  }*/

  buffer[n] = '\0';

  closesocket(sock);
  /*
  * Variables du serveur
  *
  * Déclarer ici les variables suivantes :
  * - sockfd le descripteur de socket
  * - structure d’adresse locale du serveur
  * - structure d’adresse du client
  * - taille de l’adresse du client
  */
  /*
  * Code du serveur
  *
  * - Ouvrir le socket du serveur
  * - Remplir la structure d’adresse locale du serveur :
  * - la famille d’adresse
  * - l’adresse IP
  * - le port
  * - Spécifier l’adresse locale du socket du serveur
  */
  /*
  * Boucle générale du serveur (infinie)
  */
  //while (1) {
    /*
    * Code de l’interieur de la boucle
    *///}
  return 0;
}
