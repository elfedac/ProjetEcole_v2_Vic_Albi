//*****************************************************************//
//***           eleve.c and eleve.h files                       ***//
//***              by Adrien et Lenny                           ***//
//*****************************************************************//

#include <stdio.h>
#include <stdlib.h>

#include "classe.h"

// This function displays the classrooms on the screen
void AfficherClasse(Classe_t *C,int taille)
{
	char choix[3];
	int i;
	Classe_t *niveau=C;
	printf("Quelle classe voulez vous afficher?");
	scanf("%s",choix);
	//We use a "while" function to select next classroom
	while(C->niveau!=choix)
	{
		C=C->suivant;//we select the next classroom
	}
	printf("Nom de la classe:\t%s\nProfesseur:\t%s %s\n",C.NomClasse,C.Prof.nomProf,C.Prof.prenomProf);
	printf("Liste des eleves:\n");
	for (i=0;i<taille;i++)
	{
		AfficherEleve(C.TabEleve[i]);
	}
}

//This function is used to create classrooms
void SaisirClasse(Classe_t *C,int taille)
{
	int i=0;
	printf("Nom et prenom du professeur: \n");
	scanf("%s %s", C->Prof.nomProf,C->Prof.prenomProf);
	printf("Nom de la classe: \n");
	scanf("%s", C->NomClasse);

	for(i=0;i<taille;i++)
	{
		SaisirEleve(&C->TabEleve[i]);
	}
}


