#include <stdio.h>
#include <stdlib.h>

#include "classe.h"

//fonction pour Afficher la classe
void AfficherClasse(Classe_t *C,int taille)
{
	char choix[3];
	int i;
	Classe_t *niveau=C;
	printf("Quelle classe voulez vous afficher?");
	scanf("%s",choix);
	//on boucle pour selectionner la bonne classe
	while(C->niveau!=choix)
	{
		C=C->suivant;//on passe a la classe suivante
	}
	printf("Nom de la classe:\t%s\nProfesseur:\t%s %s\n",C.NomClasse,C.Prof.nomProf,C.Prof.prenomProf);
	printf("Liste des eleves:\n");
	for (i=0;i<taille;i++)
	{
		AfficherEleve(C.TabEleve[i]);
	}
}

//fonction de saisie de la classe
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


