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

//#include "classe.h"
//Recursive structure classroom

//structure de l'eleve
typedef struct Eleve
{
    char nomEleve[NOMMAX];          //
    char prenomEleve [PRENOMMAX];   //
    char sexe;                      // F pour fille, G pour garçon
    int age;
    int redoublant;
    //struct tm DateNaissance;
    //Parent_t Pere;                // En option...
    //Parent_t Mere;                //      |
    //Bulletin_t BulletinEleve;     // non utilisé

}Eleve_t;

typedef struct Classe
{
char NomClasse[NOMCLASSE];      // for tcheck class they have same level
char niveau [3];                // level of class : CP, CE1, CE2, CM1 et CM2
//Prof_t Prof; 
char prof[25];                   // Teacher structure added but in class display, it's limited to display lastname and firstname
int nbEleve;                    // 
Eleve_t TabEleve[NBRELEVE];     //
struct Classe *suivant;         //
}Classe_t;




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
	printf("Nom de la classe:\t%s\nProfesseur:\t%s\nNiveau:\t%s\n",C->NomClasse,C->prof,C->niveau);
	//printf("Liste des eleves:\n");
	/*for (i=0;i<NBRELEVE;i++)
	{
		AfficherEleve(C->TabEleve[i]);
	}*/
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
        perror("pas possible");
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
				printf("1-Nom\n2-Prenom\n");
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
				}
				verif=1;
				break;
			}
			else
				C=C->suivant;
		}
	}while(verif!=1);
}
	
main()
{
	Classe_t *Tete=NULL;
	CreationClasse(&Tete);
	AfficherClasse(Tete);
}		
	
	
	
	
	
	
	
	
	
	
	


