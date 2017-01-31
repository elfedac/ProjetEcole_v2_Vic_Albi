#include "classe.h"
#include "ecole.h"
#include "eleve.h"
#include "menu.h"
#include "adresse.h"

int Authentification()
{
	char utilisateur[20];                       //to store the username just entered
	char motDePasse[10];                        //to store the password just entered
	int  tentative=0;                           //to count how many wrong entries were input
	char ligneLueDansFichierSecret[300];        //to store what was returned by the fgets() function
	char *champ;                                //a pointer upon the "champ" variable, of char type
	char tab[NBUTILISATEURS][25];               //pour stocker les paires nom d'utilisateur/mot de passe lues dans "fichier_secret.txt"/to save the pairs username/password readen from the "fichier_secret.txt" file
	int i=0;
	int j=0;

	FILE *ptr_fichierSecret;                    // initializing an object of the type FILE with a pointer on it

    do                                      // this do-while loop will be repeated 3 times if the entries are wrong
    {
		printf("Entrez votre nom d'utilisateur fourni: ");
		scanf("%s",utilisateur);
		printf("Entrez votre mot de passe fourni: ");
		scanf("%s",motDePasse);

		ptr_fichierSecret = fopen("fichier_secret.txt", "r"); // opening of "ficher_secret.txt" on "read" mode

		if(!ptr_fichierSecret)                              // in case the opening went wrong a message is sent
		{
			perror("erreur ouverture du fichier");
			exit(EXIT_FAILURE);
		}

		fgets(ligneLueDansFichierSecret, 200, ptr_fichierSecret); //to read the one and sole line, as each username and password are following themselves, just seperated with a semicolon.
		fclose(ptr_fichierSecret);                          // we close the file which was opened earlier

		champ=strtok(ligneLueDansFichierSecret, ";");       // we "slice" the line until the firs semicolon

		while(champ != NULL) 
		{                           // and we go on "slicing" the line until we get "NULL". Each slice is put into the 2D char array named "tab"
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
				return 0;
            }
            else
            {
                i++;
            }
        }
        tentative ++;                               // is incremented by 1 for each wrong user'input
        printf("Acces non autorise!\n");
    }while(tentative<NBTENTATIVEMAX);
    return 1;
}

main()
{
	Ecole_t Ec;
	Eleve_t E;
	
	if(Authentification()==0)
	{
		CreationClasse(&Ec.Tete);
		MenuPrincipal(&Ec);
	}
	else
	{
		AuRevoir();
	}
		
	
