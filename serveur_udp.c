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
#include <sys/uio.h>
#include <sys/uio.h>

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

  // ouverture du socket du serveur
  sockfd = socket(PF_INET, SOCK_DGRAM, 0);

  //Remplissage de la structure d'adresse locale du serveur :
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // inet_adress cause le probleme
  //serverAddr.sin_addr =  *(struct in_addr *)(hostInfo -> h_addr);
  serverAddr.sin_port = htons(9600);
/*  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero); // memset met le premier octet du 3eme argument
                                                                // le premier argument pointe ; on remplace dans le
                                                                //3 eme le truc indidu& par le premier dans le 2eme
                                                                /*1 : pointeur vers bloc de mémoire a remplir.
                                                                2 : valeur a mettre ds le bloc de mémoire, entier
                                                                3: nombre d'octet a mettre a la valeut.*/


  bind(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  /*
  * Boucle générale du serveur (infinie)
  */

  while (1) {

  recvfrom( sockfd, buffer, 1024, 0, (struct sockaddr *)&clientAddr, client_addr_size); // des warnings ici
  //int recvfrom(int sockfd, char *buf, int len, int flags, struct sockaddr *from, int *fromlen);
  //int sendto(int sockfd, char *buf, int len, int flags, struct sockaddr *to, int tolen);
  write(sockfd, buffer,1024 );

  /*
  * Code de l’éintrieur de la boucle
  */
  }

  close(sockfd);
  return 0;
}
