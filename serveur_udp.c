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
/* Port local du serveur */
#define PORT 9600

/*typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;
*/
/*
struct in_addr {
u_long s_addr;
};

struct sockaddr_in {
u_short sin_family; /* famille d’adresse : AF_INET *
u_short sin_port; /* numéro de port *
struct in_addr sin_addr; /* adresse IP *
char sin_zero[8]; /* inutilisé *
};
*/


int main(int argc, char *argv[])
  {
  /*
  * Variables du serveur
  *
  * Déclarer ici les variables suivantes :
  * - sockfd le descripteur de socket
  * - structure d’adresse locale du serveur
  * - structure d’adresse du client
  * - taille de l’adresse du client
  */
  int sockfd; // le descripteur de socket
  struct sockaddr_in serverAddr, clientAddr; // strucutre d'adresse locale du serveur et du client
  char buffer[1024];
  socklen_t addr_size, client_addr_size; // Taille de l'adresse du client
  int i;

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
  while (1) {
  /*
  * Code de l’éintrieur de la boucle
  */
  }
  return 0;
}
