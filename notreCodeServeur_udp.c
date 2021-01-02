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

typedef enum { FALSE, TRUE} bool;

//Port local du serveur
#define PORT 9600

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;

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
/*
bool readclose(char buffer[]){

  if(buffer[0]=='c' || buffer[0]=='C' ){
    if(buffer[1] == 'l' || buffer[0]=='L'){
      if(buffer[2] == 'o' || buffer[0]=='O'){
        if(buffer[3] == 's' || buffer[0]=='S'){
          if(buffer[4] == 'e' || buffer[0]=='E'){
            return TRUE;
          }
        }
      }
    }
    return FALSE;
  }
}

void afficheMessage(char buffer[]){
  int i = 0;
  // On enlève le retour chariot
  printf("Vous avez recu le message :\n");
  while(buffer[i] != '$'){
    printf("%c", buffer[i] );;
    i++;
  }
  printf("\n");
}

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
  struct sockaddr_in serverAddr, clientAddr; // structure d'adresse locale du serveur et du client
  struct sockaddr_storage serverStorage;
  char buffer[1024];
  socklen_t addr_size, client_addr_size; // Taille de l'adresse du client
  int i;
  int nBytes;
  /* Code du serveur
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
  serverAddr.sin_family = PF_INET;
  serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); // inet_adress cause le probleme
  //serverAddr.sin_addr =  *(struct in_addr *)(hostInfo -> h_addr);
  serverAddr.sin_port = htons(9600);
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero); // memset met le premier octet du 3eme argument
                                                                // le premier argument pointe ; on remplace dans le
                                                                //3 eme le truc indidu& par le premier dans le 2eme
                                                                /*1 : pointeur vers bloc de mémoire a remplir.
                                                                2 : valeur a mettre ds le bloc de mémoire, entier
                                                                3: nombre d'octet a mettre a la valeut.*/


  //bind(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr));


  //* Boucle générale du serveur (infinie)
  //*
  int j = 0;
  while (i<20) {
  j++;
  printf("dans la boucle\n");
  nBytes = recvfrom( sockfd, &buffer, 1024, 0, (struct sockaddr *)&clientAddr, &client_addr_size); // client addr size cause le probleme
  //int recvfrom(int sockfd, char *buf, int len, int flags, struct sockaddr *from, int *fromlen);
  //int sendto(int sockfd, char *buf, int len, int flags, struct sockaddr *to, int tolen);
  //sendto(sockfd, buffer, 20, 0, (struct sockaddr *)&serverAddr, hostInfo -> h_length );
  printf("Vous avez recu :\n");
  printf("%d\n", nBytes );
  read(sockfd, &buffer, 20);
  //afficheMessage(buffer);
  printf("Que voulez vous repondre?\n");
  nBytes = write(sockfd, buffer,1024 );
  sendto(sockfd,buffer,nBytes,0,(struct sockaddr *)&serverStorage,addr_size);
  /*int sendto(int sockfd, char *buf, int len, int flags, struct sockaddr *to, int tolen);*/
  /*
  * Code de l’éintrieur de la boucle
  */
  }

  close(sockfd);
  return 0;

}
