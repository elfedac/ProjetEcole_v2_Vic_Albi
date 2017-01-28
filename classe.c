//*****************************************************************//
//***           Folder eleve.c and eleve.h                     ***//
//***              by Adrien et Lenny                          ***//
//*****************************************************************//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOMCLASSE 5
#define NBRELEVE 25
#define NOMMAX 25
#define PRENOMMAX 25

#include "classe.h"

//Classroom display function
void AfficherClasse(Classe_t *C)
{
	char choix[5];
	int i;
	Classe_t *niveau=C;
	printf("Quelle classe voulez vous afficher?");
	scanf("%s",choix);
	//We use "while" function for select next class
	while(strcmp(choix,C->NomClasse)!=0)
	{
		C=C->suivant;//we select next class
	}
	printf("Nom de la classe:\t%s\nProfesseur:\t%s %s\nNiveau:\t%s\n",C->NomClasse,C->Prof.nomProf,C->Prof.prenomProf,C->niveau);
	printf("Liste des eleves:\n");
	for (i=0;i<NBRELEVE;i++)
	{
		AfficherEleve(C->TabEleve[i]);
	}
}

void CreationClasse(Classe_t **C)
{
	int i;
	char TabNomClasse[5][5]={"CP-1","CE1-1","CE2-1","CM1-1","CM2-1"};
	char TabNiveauClasse[5][5]={"CP","CE1","CE2","CM1","CM2"};
		for(i=0;i<5;i++)
	{
		Classe_t *tete=*C;
		Classe_t *nouvelleClasse;
		nouvelleClasse= (Classe_t *) malloc( sizeof (Classe_t));
		if (nouvelleClasse ==NULL)
		{ 
			perror("desole, plus de place\n");
			return;
		}
		else
		{ 
			strcpy(nouvelleClasse->NomClasse,TabNomClasse[i]);
			strcpy(nouvelleClasse->niveau,TabNiveauClasse[i]);
			nouvelleClasse->suivant=NULL;

			if ( tete==NULL)
			{ 
				printf("classe de %s est créer\n",nouvelleClasse->niveau);
				*C=nouvelleClasse;
			}
			else
			{
				// on parcours l'ecole a la recherche de la derniere classe
				while (tete->suivant !=NULL)
                {
                    // on passe a la classe suivante
                    tete=tete->suivant;
                }

             // la derniere classe de l'ecole pointe vers la nouvelle classe
             tete->suivant=nouvelleClasse;
             printf("classe de %s est créer\n",nouvelleClasse->niveau);
          }
        }
     }
}
		


//Classroom input function
void AjouterClasse(Classe_t **C)              
{
	Classe_t *courant = *C; 
    Classe_t *avant = NULL;    
    Classe_t *nouvelle;        
    
    nouvelle = (Classe_t*)malloc(sizeof(Classe_t)); // initialisation de nouveau
    if(nouvelle==NULL) // si l'allocation se passe mal
    {
        perror("Allocation failed :");
        return;
    }
    printf("saisir le nom et le niveau de la classe (separer par un espace):\n");
    scanf("%s %s",nouvelle->NomClasse,nouvelle->niveau);
    while(courant != NULL && strcmp (courant->niveau, nouvelle->niveau) != 0)
    {
		avant = courant;            // le courant devient précédent
        courant = courant->suivant;// l'élément suivant de la liste devient le courant
    }
    nouvelle->suivant = courant;
    // si courant n'est pas le premier élément de la liste
    if(avant != NULL)
        avant->suivant = nouvelle; // affecter nouveau derrière l'élément précédent courant
    else
        *C = nouvelle; // sinon affecter nouveau en tête de liste
}

void ModifierEleve(Classe_t *C)
{
	int choix;
	char temp[25];
	char nomModif[25];
	char prenomModif[25];
	int verif=0;
	int i;
	Classe_t *tete=C;
	printf("Saisir le nom et le prenom de l'eleve a modifier:\n");
	scanf("%s %s",nomModif,prenomModif);
	do
	{
		for(i=0;i<NBRELEVE;i++)
		{
			if((strcmp(nomModif,C->TabEleve[i].nomEleve)==0) && (strcmp(prenomModif,C->TabEleve[i].prenomEleve)==0))
			{
				printf("Eleve trouvé dans le classe %s\n",C->NomClasse);
				printf("que voulez-vous modifier?\n");
				printf("1-Nom\n2-Prenom\n3-Age\n4-Sexe");
				scanf("%d",&choix);
				switch (choix)
				{
					case 1:
						printf("Saisir nouveau nom:\n");
						scanf("%s",temp);
						strcpy(C->TabEleve[i].nomEleve,temp);
						printf("nouveau nom: %s\n",C->TabEleve[i].nomEleve);
						break;
					case 2:
						printf("Saisir nouveau prenom:\n");
						scanf("%s",temp);
						strcpy(C->TabEleve[i].prenomEleve,temp);
						printf("nouveau prenom: %s\n",C->TabEleve[i].prenomEleve);
						break;
					case 3:
						SaisirDate(&C->TabEleve[i])
						break;
					case 4:
						printf("Saisir nouveau sexe:\n");
						scanf("%c",temp);
						strcpy(C->TabEleve[i].sexe,temp);
						printf("nouveau sexe: %c\n",C->TabEleve[i].nomEleve);
						break;
				}
				verif=1;
				break;
			}
			else
				C=C->suivant;
		}
	}while(verif!=1);
}


