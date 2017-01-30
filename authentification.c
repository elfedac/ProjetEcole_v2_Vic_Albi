#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NBUTILISATEURS 3
#define NBTENTATIVEMAX 3
#define CLEAR() system("clear");

int main()
{
char utilisateur[20];                       //to store the username just entered
char motDePasse[10];                        //to store the password just entered
int  tentative=0;                           //to count how many wrong entries were input
char ligneLueDansFichierSecret[300];        //to store what was returned by the fgets() function
char *champ;                                //a pointer to the "champ" variable, of char type
char tab[NBUTILISATEURS][25];               //to store the username/password pairs readen from the "fichier_secret.txt" file (hiden file)
int i=0;
int j=0;

FILE *ptr_fichierSecret;                    // initializing an object type FILE with a pointer to it

    do                                      // this do-while loop will be repeated 3 times if the entries are wrong
    {
    printf("Entrez votre nom d'utilisateur fourni: ");
    scanf("%s",utilisateur);
    printf("Entrez votre mot de passe fourni: ");
    scanf("%s",motDePasse);

    ptr_fichierSecret = fopen("fichier_secret.txt", "r"); // opening of "fichier_secret.txt" on "read" mode

    if(!ptr_fichierSecret)                              // in case the opening would fail, a message is sent
    {
        perror("erreur ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    fgets(ligneLueDansFichierSecret, 200, ptr_fichierSecret); //to read the one and sole line, as each username and password are following themselves, just seperated with a semicolon.
    fclose(ptr_fichierSecret);                          // we close the file opened earlier

    champ=strtok(ligneLueDansFichierSecret, ";");       // we "slice" the line until the first semicolon

    while(champ != NULL)                            // and we go on "slicing" until we get "NULL". Each slice is put into the 2D char array named "tab"
    strcpy(tab[j],champ);
    champ=strtok(NULL, ";");
    j++;
    }
		for (i=0;i<NBUTILISATEURS*2;i++)            // the username/password pairs being in the array, whe check if they match the entries
        {                                           // if so, the acces is granted and the main menu is displayed on the screen
            if ((strcmp(tab[i],utilisateur)==0) && (strcmp(tab[i+1],motDePasse)==0))
            {
                printf("Acces autorise\n");
                tentative = NBTENTATIVEMAX;
                //Menu(Ec);                         // used to go to the menu
            }
            else
            {
                i++;
            }
        }
        tentative ++;                               // is incremented by 1 for each wrong user's input
        printf("Acces non autorise!\n");
    }while(tentative<NBTENTATIVEMAX);
 return(0);
 }
