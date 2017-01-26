#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NBUTILISATEURS 3
#define NBTENTATIVEMAX 3
#define CLEAR()     system("clear");

int main()
{
char utilisateur[20];                       //pour stocker le nom de l'utilisateur qui est saisi
char motDePasse[10];                        //pour stocker le mot de passe qui est saisi
int  tentative=0;                            //pour comptabiliser les tentatives de saisie de mot de passe
char ligneLueDansFichierSecret[300];        //pour stocker ce qui est retourné par la fonction fgets()
char *champ;                                //un pointeur vers la variable "champ", de type char
char tab[NBUTILISATEURS][25];                   // pour stocker les paires nom d'utilisateur/mot de passe lues dans "fichier_secret.txt"
int i=0;
int j=0;

FILE *ptr_fichierSecret;                    // création d'un pointeur FILE

    do
    {
    printf("Entrez votre nom d'utilisateur fourni: ");
    scanf("%s",utilisateur);
    printf("Entrez votre mot de passe fourni: ");
    scanf("%s",motDePasse);
    
    ptr_fichierSecret = fopen("fichier_secret.txt", "r"); // ouverture du fichier secret en mode "read"

    if(!ptr_fichierSecret)                              // si l'ouverture se passe mal
    {
        perror("erreur ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    
    fgets(ligneLueDansFichierSecret, 200, ptr_fichierSecret); // lire la seule et unique ligne car les noms d'utilisateur et mot de passe se suivent avec ";" entre chague

    fclose(ptr_fichierSecret);
    printf("Ligne lue: %s",ligneLueDansFichierSecret);

    champ=strtok(ligneLueDansFichierSecret, ";");
    
    while(champ != NULL)
    {
    strcpy(tab[j],champ);
    
    printf("%s\n",tab[j]);
    champ=strtok(NULL, ";");
    j++;
    }
		for (i=0;i<NBUTILISATEURS*2;i++)
        {
            if ((strcmp(tab[i],utilisateur)==0) && (strcmp(tab[i+1],motDePasse)==0))  
            {
                printf("Acces autorise\n");
                tentative = NBTENTATIVEMAX;
                //Menu(Ec);
            }
            else //il n'y avait pas d'accolades dans la version originale, mais je pense que c'est mieux!!
            {
                i++;
            } 
        }
        tentative ++;
        printf("Acces non autorise!\n");
    }while(tentative<NBTENTATIVEMAX);

 return(0);
 }
