//*****************************************************************//
//***           Folder eleve.c and eleve.h                     ***//
//***              by Adrien et Lenny                          ***//
//*****************************************************************//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOMCLASSE 6
#define NBRELEVE 3
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
typedef struct prof
{
char nomProf[NOMMAX];           //
char prenomProf[PRENOMMAX];     //
//Adresse_t AdresseProf;          //
}Prof_t;
typedef struct Classe
{
char NomClasse[NOMCLASSE];      // for tcheck class they have same level
char niveau [3];                // level of class : CP, CE1, CE2, CM1 et CM2
Prof_t Prof;                   // Teacher structure added but in class display, it's limited to display lastname and firstname
int nbEleve;                    //
Eleve_t TabEleve[NBRELEVE];     //
struct Classe *suivant;         //
}Classe_t;

void SaisirEleve(Eleve_t *E)
{

    printf("*****\tSaisie des caracteristisques de l'eleve\t*****\n\n");

    //Last name student input
    printf("\nSaisissez le nom de l'eleve: ");
    fgets(E->nomEleve,NOMMAX,stdin);
    E->nomEleve[strlen(E->nomEleve)-1]='\0';


    //Fist name student input
    printf("\nSaisissez le prenom de l'eleve: ");
    fgets(E->prenomEleve,PRENOMMAX,stdin);
     E->prenomEleve[strlen(E->prenomEleve)-1]='\0';

    //Gender student input
    printf("\nSaisissez le Sexe de l'eleve (F / M): ");
    scanf("%c",&E->sexe);
    getchar();

    //Gender student input check
    while((E->sexe!='F') && (E->sexe!='M'))
	{
		//CLEAR(); //if wrong input, system console screen cleared before displaying new choice
		printf("\nJe n'ai pas compris...\nVeuillez re-saisir le sexe (F / M): ");
		scanf("%c",&E->sexe);
		getchar();
	}

    //Student school year repeat input
    printf("\nL'élève est-il redoublant?\n(1 si redoublant/ 0 si non redoublant): ");
    scanf("%d",&E->redoublant);
    getchar();

    //Check Student school year repeat input
    while((E->redoublant!=1) && (E->redoublant!=0))
	{
		//CLEAR(); //if wrong input, system console screen cleared before displaying new choice
		printf("\nJe n'ai pas compris...\nL'élève est-il redoublant ? (1 pour redoublant/ 0 pour non redoublant): ");
		scanf("%d",&E->redoublant);
    }

    //Input student birthday function call
    //SaisirDate(E);
}
/*void SaisirDate(Eleve_t *Y)
{
    //Initialisation student birthday time structure
//    memset(&Y->DateNaissance, 0 , sizeof (Y->DateNaissance));

    //Localtime recovery
//    time_t aujourdhui=time(NULL);

//  time_t birthday; //Student birthday converted to POSIX

    //Student birthday input
    //printf ("\nSaisissez la date de naissance de l'élève (JJ/MM/AAAA): ");
	//scanf ("%d/%d/%d",	&Y->DateNaissance.tm_mday, &Y->DateNaissance.tm_mon, &Y->DateNaissance.tm_year);

	// Time structure month and year modified before POSIX conversion
	//Y->DateNaissance.tm_mon-=1;
    //Y->DateNaissance.tm_year-=1900;

    //Student birthday converted in seconds
    //birthday=mktime(&Y->DateNaissance);

    //Age is a double type variable, created & initialised to save student age through a calculation...
    //double Age=difftime(aujourdhui, birthday)/(365.25*24*3600); //because of Leap year, a year is 365,25 days, a day is 24 hours & 1 hour is 3600 seconds
   // Y->age=Age;

}*/
void SaisirClasse(Classe_t *C,int taille)
{
	int i=0;
	printf("Nom et prenom du professeur: \n");
	scanf("%s %s", C->Prof.nomProf,C->Prof.prenomProf);
	printf("Nom de la classe: \n");
	scanf("%s", C->NomClasse);

    printf("Niveau de la classe: \n");
	scanf("%s",C->niveau);
	getchar();
	C->nbEleve=0;
	for(i=0;i<taille;i++)
	{
		SaisirEleve(&C->TabEleve[i]);
		C->nbEleve=C->nbEleve+1;
	}
}


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
void EnregistrerSauvegardeClasse(Classe_t *C,FILE *ptr_sauvegarde)
{

	printf("Je suis dans la fonction EnregistrerSauvegardeClasse()");
	char milieu[50];
	char debut[50]={"fichier_sauvegarde"};
	char fin[50]={".txt"};
	Classe_t *courant=C;
	//FILE *ptr_sauvegarde=NULL;

// une fois qu'on a le premier niveau(CP), il faudra parcourir toute la classe, pour enregistrer ses données y compris le tableau des élèves, dans le fichier de sauvegare
// qui lui correspond (fichier_sauvegardeCP.txt)
// ensuite on passera au niveau au-dessus, tant que C.niveau est différent de NULL
	do // utilisation d'une bouche "do...while" afin que la dernière classe soit traitée car je pense que ce ne serait pas le cas avec juste un "while". A VERIFIER!!!
	{
		strcpy(milieu, courant->niveau);
		printf("Le milieu est: %s\n",milieu);
		strcat(debut, milieu);
		strcat(debut, fin);
		printf("Le nom du fichier de sauvegarde est: %s",debut);// printf de contrôle à enlever plus tard
		ptr_sauvegarde = fopen(debut,"w");

		if(!ptr_sauvegarde) // si l'ouverture se passe mal
		{
        perror("erreur ouverture du fichier");
		exit(EXIT_FAILURE);
		}



		fprintf(ptr_sauvegarde, "%s;%s;%s;%s;\n", courant->NomClasse, courant->Prof.nomProf,courant->Prof.prenomProf, courant->niveau);

// ensuite, une fois qu'on a enregistré les trois premières données de la classe, dont le niveau (qui est unique!)on se trouvera dans une boucle for() pour parcourir
// le tableau des élèves, et les ajouter au fichier_sauvegarde. Voir si c'est juste pour enregistrer la date de naissance.
		int i=0;
		for (i=0;i<courant->nbEleve;i++)
		{
			fprintf(ptr_sauvegarde, "%s;%s;%c;\n", courant->TabEleve[i].nomEleve, courant->TabEleve[i].prenomEleve, courant->TabEleve[i].sexe);
		}
		fclose(ptr_sauvegarde); // on ferme le fichier ouvert puisqu'on va en ouvrir un nouveau avec un autre nom
		courant=courant->suivant;//on passera ensuite à la classe de niveau suivant, tant que C.suivant n'est pas NULL
		}while(courant!=NULL);
}
//This function is used to create classrooms


main()
{
	Classe_t Tete;

	SaisirClasse(&Tete,3);
	printf("Je suis entre les deux fonctions!!");
	FILE *f;
    EnregistrerSauvegardeClasse(&Tete,f);

	//CreationClasse(&Tete);
	//AfficherClasse(Tete);
}
