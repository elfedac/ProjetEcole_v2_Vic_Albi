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
	char choix[6];
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

void SaisirClasse(Classe_t *C)             
{
	char choix[6];
	char fini[3]={"non"};
	int i=0;
	Classe_t *tete=C;
	printf("Quelle classe voulez vous saisir?");
	scanf("%s",choix);
	getchar();
	//We use "while" function for select next class
	while(strcmp(choix,C->NomClasse)!=0)
	{
		C=C->suivant;//we select next class
	}
	do
	{
		printf("Nom et prenom du professeur: \n");
		scanf("%s %s", C->Prof.nomProf,C->Prof.prenomProf);
		printf("Nom de la classe: \n");
		scanf("%s", C->NomClasse);
		printf("Niveau de la classe:\n");
		scanf("%s",C->niveau);
		getchar();

		for(i=0;i<NBRELEVE;i++)
		{
			SaisirEleve(&C->TabEleve[i]);
		}
	}while(fini=="oui");
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
			nouvelleClasse->nbEleve=0;
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
    SaisirClasse(&C);
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

/*  fonction auxiliaire permuter deux éléments du tableau (Manuel)*/
void TrierEleve(Classe_t *Classe, int nbeleve) //Tri par permutation
{
    //déclaration d'une structure eleve tampon
    Eleve_t EleveTemp;

    //création deux boucles de compteur
    int i,j;

	for (i=0; i<Classe->nbEleve-1; i++)
		for(j=i; j<Classe->nbEleve; j++)
		{
		    if (strcmp(TabEleve[i].nom, TabEleve[j].nom)>0)
            {
                //stockage de tous les champs dans la structure Eleve tampon
                strcpy(EleveTemp.nomEleve, Classe.TabEleve[i].nomEleve);
                strcpy(EleveTemp.prenomEleve, Classe.TabEleve[i].prenomEleve);
                strcpy(EleveTemp.sexe, Classe.TabEleve[i].sexe);
                EleveTemp.DateNaissance.tm_mday=Classe.TabEleve[i].DateNaissance.tm_mday;
                EleveTemp.DateNaissance.tm_mon=Classe.TabEleve[i].DateNaissance.tm_mon;
                EleveTemp.DateNaissance.tm_year=Classe.TabEleve[i].DateNaissance.tm_year;
                EleveTemp.age=Classe.TabEleve[i].age;
                EleveTemp.redoublant=Classe.TabEleve[i].redoublant;

                //Copie de la structure Eleve TabEleve[j] vers la structure Eleve de TabEleve[i]
                strcpy(Classe.TabEleve[i].nomEleve, Classe.TabEleve[j].nomEleve);
                strcpy(Classe.TabEleve[i].prenomEleve, Classe.TabEleve[j].prenomEleve);
                strcpy(Classe.TabEleve[i].sexe, Classe.TabEleve[j].sexe);
                Classe.TabEleve[i].DateNaissance.tm_mday=Classe.TabEleve[j].DateNaissance.tm_mday;
                Classe.TabEleve[i].DateNaissance.tm_mon=Classe.TabEleve[j].DateNaissance.tm_mon;
                Classe.TabEleve[i].DateNaissance.tm_year=Classe.TabEleve[j].DateNaissance.tm_year;
                Classe.TabEleve[i].age=Classe.TabEleve[j].age;
                Classe.TabEleve[i].redoublant=Classe.TabEleve[j].redoublant;

                //Copie de la structure Eleve Tampon vers la structure Eleve TabEleve[j]
                strcpy(Classe.TabEleve[j].nomEleve, EleveTemp.nomEleve);
                strcpy(Classe.TabEleve[j].prenomEleve, EleveTemp.prenomEleve);
                strcpy(Classe.TabEleve[j].sexe, EleveTemp.sexe);
                Classe.TabEleve[j].DateNaissance.tm_mday=EleveTemp.DateNaissance.tm_mday;
                Classe.TabEleve[j].DateNaissance.tm_mon=EleveTemp.DateNaissance.tm_mon;
                Classe.TabEleve[j].DateNaissance.tm_year=EleveTemp.DateNaissance.tm_year;
                Classe.TabEleve[j].age=EleveTemp.age;
                Classe.TabEleve[j].redoublant=EleveTemp.redoublant;
            }

}


void ModifierEleve(Classe_t *C)
{
	int choix;
	char choixModif;
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
				AfficherEleve(C->TabEleve[i]);
				printf("Souhaitez vous modifier l'eleve? o/n\t");
				scanf("%c",&choixModif);
				if((choixModif=='o') && (choixModif=='O')) 
				{
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
			}
			else
				C=C->suivant;
		}
	}while(verif!=1);
}

void SupprimerEleve(Classe_t *C)
{
	int choix;
	char temp[25];
	char nomSuppr[25];
	char prenomSuppr[25];
	int verif=0;
	int i;
	Classe_t *tete=C;
	printf("Saisir le nom et le prenom de l'eleve a supprimer:\n");
	scanf("%s %s",nomSuppr,prenomSuppr);
	do
	{
		for(i=0;i<NBRELEVE;i++)
		{
			if((strcmp(nomSuppr,C->TabEleve[i].nomEleve)==0) && (strcmp(prenomSuppr,C->TabEleve[i].prenomEleve)==0))
			{
				printf("Eleve trouvé dans le classe %s\n",C->NomClasse);
				for(i=0;i<C.nbEleve;i++)
				{
					strcpy(C->TabEleve[i].prenomEleve,C->TabEleve[i+1].prenomEleve);
					strcpy(C->TabEleve[i].nomEleve,C->TabEleve[i+1].nomEleve);
					strcpy(C->TabEleve[i].sexe,C->TabEleve[i+1].sexe);
					C->TabEleve[i].redoublant=C->TabEleve[i+1].redoublant
					C->TabEleve[i].DateNaissance.tm_mday=C->TabEleve[i+1].DateNaissance.tm_mday;
					C->TabEleve[i].DateNaissance.tm_mon=C->TabEleve[i+1].DateNaissance.tm_mon;
					C->TabEleve[i].DateNaissance.tm_year=C->TabEleve[i+1].DateNaissance.tm_year;
					
				}
				verif=1;
				break;
			}
			else
				C=C->suivant;
		}
	}while(verif!=1);
	C->nbEleve=C->nbEleve-1;
}

