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

struct in_addr {
u_long s_addr;
};

struct sockaddr_in {
u_short sin_family; /* famille d’adresse : AF_INET */
u_short sin_port; /* numéro de port */
struct in_addr sin_addr; /* adresse IP */
char sin_zero[8]; /* inutilisé */
};



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
