/*
* Code du client
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>


#define SIZE 100
#define PORT 9600
#define h_addr h_addr_list[0] /* pour compatibité */


void afficheMessage(char buffer[]){
  int i = 0;
  // On enlève le retour chariot
  printf("Vous avez envoye le message :\n");
  while(i<20){
    printf("%c", buffer[i] );
    i++;
  }
  printf("\n");
}

void lecture_au_clavier(char* buffer[]){
  //char message[20];
  char flag = 's';
  int i = 0;
  while (flag != '\n'){
    flag = getchar();
    *buffer[i] = flag;
    i++;
  }
}

int main (int argc, char *argv[])
{



/*
* Variables du client
*
* Déclarer ici les variables suivantes :
* - sockfd le descripteur de socket
* - structure d’adresse du serveur
* - pointeur vers la structure descriptive de machine (hostent)
* - zone de mémoire destinée à accueillir la chaîne
* entrée au clavier
* - taille de la chaîne à envoyer
*/
  int sockfd; //le descripteur de socket
  int taille;
  struct sockaddr_in serverAddr; // structure d'addresse du serveur
  struct hostent* hostInfo; // pointeur vers la structure descriptive de la machine
  char buffer[1024]; // zone de memoire destinee a acceuillir la chaine
  int size = 20; // taille de la chaine a envoyer


/*
* Code du client
*
* - Ouvrir le socket du client
* - Récupérer l’adresse IP du serveur à partir de son nom
* donné en ligne de commande
* - Remplir la structure d’adresse du serveur
* - Lire une ligne de l’entrée standard
* - Envoyer la chaîne lue au serveur
*/
  const char *hostname = "localhost"; // le nom du host n'est pas correct - réparé
  sockfd = socket(PF_INET, SOCK_DGRAM, 0); //Ouvrir le socket du client
  hostInfo = gethostbyname(hostname); // Récupérer l’adresse IP du serveur à partir de son nom donné en ligne de commande

  // remplir la structure d'addressse de serveur
  serverAddr.sin_addr =  *(struct in_addr *)(hostInfo -> h_addr); // hostInfo est le pointeur nul, ca nous fait une segmentation fault.
  serverAddr.sin_port = htons(9600);
  serverAddr.sin_family = AF_INET;



  //bind(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)); //au pire on peut l'enlever
  //lire une ligne de l'entrée standard
  printf("Que voulez vous envoyer ?\n");

  //fgets(&buffer, 1024,stdin);
  printf("sockfd = %d\n", sockfd );
  *buffer = lecture_au_clavier();
  printf("apres read\n");
  //envloyer la chaine lu au serveur
  sendto(sockfd, buffer, 20, 0, (struct sockaddr *)&serverAddr, hostInfo -> h_length );
  //printf(" Vous avez envoye \n" );
  afficheMessage(buffer);

  printf("aaaa\n");
  close(sockfd);
  printf("bbb\n");

return 0;
}



// Si on a un probleme plus tard, on peut essayer de changer les 20 par des 1024
