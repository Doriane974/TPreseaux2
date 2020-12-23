/*
* Code du client
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define SIZE 100
#define PORT 9600





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

  sockfd = socket(PF_INET, SOCK_DGRAM, 0); //Ouvrir le socket du client
  hostInfo = gethostbyname(hostInfo -> h_name); // Récupérer l’adresse IP du serveur à partir de son nom donné en ligne de commande


  serverAddr.sin_addr = hostInfo->h_addr; /* l'adresse se trouve dans le champ h_addr de la structure hostinfo */
  serverAddr.sin_port = htons(9600);
  serverAddr.sin_family = AF_INET;


return 0;
}
