
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define NOMMAX 30
#define PRENOMMAX 20
#define NOMMAXECOLE 50
#define NOMCLASSE 5
#define NBRELEVE 25
#define LIGNE 600
#define RUEMAX 60
#define VILLEMAX 30
#define TELMAX 15
#define MAILMAX 50
#define CLEAR()     system("clear");


//structure de l'eleve
typedef struct Eleve
{
    char nomEleve[NOMMAX];          //
    char prenomEleve [PRENOMMAX];   //
    char sexe;                      // F pour fille, G pour garçon
    int age;
    int redoublant;
    struct tm DateNaissance;
    //Parent_t Pere;                // En option...
    //Parent_t Mere;                //      |
    //Bulletin_t BulletinEleve;     // non utilisé

}Eleve_t;


//Recursive structure classroom
typedef struct Classe
{
char NomClasse[NOMCLASSE];      // for tcheck class they have same level
char niveau [3];                // level of class : CP, CE1, CE2, CM1 et CM2
//Prof_t Prof;                    // Teacher structure added but in class display, it's limited to display lastname and firstname
int nbEleve;                    //
Eleve_t TabEleve[NBRELEVE];     //
struct Classe *suivant;         //
}Classe_t;




//Les structures
void SaisirDate(Eleve_t *E);

void AfficherEleve(Eleve_t E);

void AffecterEleve(Eleve_t E, Classe_t **ClasseAffectation, char Niveau);

void SaisirEleve(Eleve_t *E);

void AfficherClasse(Classe_t *C);

void InitialiserClasse(Classe_t **C);

void AjouterClasse(Classe_t **C);

void PermuterEleve(int nbeleve);

void ModifierEleve(Classe_t *C);


//test main a supprimer
int main()
{

    //VARIABLES
    int i=0;
    char Niveau[5]={0};

	Eleve_t EleveTemp={0};

	Classe_t ClasseTemp={0};

    //InitialiserClasse(&ClasseTemp);

}


/* Student birthday input function */
void SaisirDate(Eleve_t *E)
{
    //Initialisation student birthday time structure
    memset(&E->DateNaissance, 0 , sizeof (E->DateNaissance));

    //Localtime recovery
    time_t aujourdhui=time(NULL);

    time_t birthday; //Student birthday converted to POSIX

    //Student birthday input
    printf ("\nSaisissez la date de naissance de l'élève (JJ/MM/AAAA): ");
	scanf ("%d/%d/%d",	&E->DateNaissance.tm_mday, &E->DateNaissance.tm_mon, &E->DateNaissance.tm_year);
    getchar();

	// Time structure month and year modified before POSIX conversion
	E->DateNaissance.tm_mon-=1;
    E->DateNaissance.tm_year-=1900;

    //Student birthday converted in seconds
    birthday=mktime(&E->DateNaissance);

    //Age is a double type variable, created & initialised to save student age through a calculation...
    double Age=difftime(aujourdhui, birthday)/(365.25*24*3600); //because of Leap year, a year is 365,25 days, a day is 24 hours & 1 hour is 3600 seconds
    E->age=Age;

}


/*Display Student features*/
void AfficherEleve(Eleve_t E)
{
    CLEAR();

    //Title display
    printf("**********\tCaracteristisques de l'eleve\t**********\n\n");

    //Display last name, first name & age
    printf("\nNom de l'eleve : %s\nPrenom de l'eleve : %s\nAge : %d ans\n",
            E.nomEleve, E.prenomEleve, E.age);

    //Student Sex verification to display the true information
    if (E.sexe=='M')
        {
        printf("\nSexe : Masculin\n");
        }
    else
        {
        printf("\nSexe : Féminin\n");
        }

  	printf ("\nDate de naissance : %02d/%02d/%d\n", E.DateNaissance.tm_mday, 1 + E.DateNaissance.tm_mon, 1900 + E.DateNaissance.tm_year);

  	//Student school year repeat verification to display the true information
    if (E.redoublant==1)
        {
        printf("\nEleve redoublant\n");
        }
    else
        {
        printf("\nEleve non redoublant\n");
        }

}


/*Student features input*/
void SaisirEleve(Eleve_t *E)
{
    int i;

    printf("*****\tSaisie des caracteristisques de l'eleve\t*****\n\n");

    //Last name student input
    printf("\nSaisissez le nom de l'eleve: ");
    fgets(E->nomEleve,NOMMAX,stdin);
    E->nomEleve[strlen(E->nomEleve)-1]='\0';

    //uppercase the student last name
    for(i=0; i<strlen(E->nomEleve); i++)
        {
            E->nomEleve[i]=toupper(E->nomEleve[i]);
        }

    //Fist name student input
    printf("\nSaisissez le prenom de l'eleve: ");
    fgets(E->prenomEleve,PRENOMMAX,stdin);
    E->prenomEleve[strlen(E->prenomEleve)-1]='\0';

    //lowercase the student first name
    for (i=0; i<strlen(E->prenomEleve); i++)
        {
            E->prenomEleve[i]=tolower(E->prenomEleve[i]);
        }

    //Input student birthday function call
    SaisirDate(E);

    //Gender student input
    printf("\nSaisissez le Sexe de l'eleve (F / M): ");
    scanf("%c",&E->sexe);
    getchar();

    //Gender student input check
    while((E->sexe!='F') && (E->sexe!='f') && (E->sexe!='M') && (E->sexe!='m'))
	{
		CLEAR(); //if wrong input, system console screen cleared before displaying new choice
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
		CLEAR(); //if wrong input, system console screen cleared before displaying new choice
		printf("\nJe n'ai pas compris...\nL'élève est-il redoublant ? (1 pour redoublant/ 0 pour non redoublant): ");
		scanf("%d",&E->redoublant);
    }

    FILE *ptr_fichierEleve; // création d'un pointeur FILE

    ptr_fichierEleve = fopen("fichier_eleveTest.csv", "a+");      // ouverture du fichier secret en mode "écriture fin de fichier"

        if(!ptr_fichierEleve)                                        // si l'ouverture se passe mal
        {
            perror("erreur ouverture du fichier");                   //Affichage du message d'erreur
            exit(EXIT_FAILURE);                                      //Sortie du programme
        }
        else
        {

            // écriture des caractéristiques de l'établissement dans un fichier csv compatible LibreOffice/Microsoft Office
            fprintf(ptr_fichierEleve, "%s;%s;%c;%d/%d/%d;%d;%d;\n", E->nomEleve, E->prenomEleve, E->sexe, E->DateNaissance.tm_mday, E->DateNaissance.tm_mon+1,
                                                                                  E->DateNaissance.tm_year+1900, E->age, E->redoublant);

        }

fclose(ptr_fichierEleve);                                   // fermeture du fichier .csv

}



//Fonction pour déterminer dans quelle classe inscrire l'eleve
void TrouverNiveau (Eleve_t E, char *Niveau[5])
{

    if (((E.age==6) && (E.redoublant==0)) || ((E.age==7) && (E.redoublant==1)))
    {
        //
        Niveau[5]="CP";
    }

    if (((E.age==7) && (E.redoublant==0)) || ((E.age==8) && (E.redoublant==1)))
    {
        //
        Niveau[5]="CE1";
    }

    if (((E.age==8) && (E.redoublant==0)) || ((E.age==9) && (E.redoublant==1)))
    {
        //
        Niveau[5]="CE2";
    }

    if (((E.age==9) && (E.redoublant==0)) || ((E.age==10) && (E.redoublant==1)))
    {
        //
        Niveau[5]="CM1";
    }

    if (((E.age==10) && (E.redoublant==0)) || ((E.age==11) && (E.redoublant==1)))
    {
        //
        Niveau[5]="CM2";
    }

}


void AffecterEleve(Eleve_t E, Classe_t **ClasseAffectation, char Niveau)
{
            //Création d'un pointeur + positionnement en tête de liste
            Classe_t *debut=*ClasseAffectation;

            //Si liste des classes non vide et niveau classe différent de Niveau, on parcours la liste des classes
            while((debut!=NULL) && strcmp(debut->niveau, "Niveau")!=0)
                {
                    //On se positionne sur la classe suivante
                    debut=debut->suivant;
                }

            //Soit la classe a été trouvé, soit on s'arrete en fin de liste
            if ((debut!=NULL) && strcmp(debut->niveau, "Niveau")==0)
            {
                //on vérifie le nombre d'élèves déjà inscrits dans la classe en affectant la valeur à i
                int i=debut->nbEleve;

                //Si classe pleine, il faudra appeler la fonction créer classe pour creer nouvelle classe

                //si aucun élève inscrit, on remplit la première case du tableau de structures eleves...
                if (i==0)
                {
                    //...champ par champ
                    strcpy(debut->TabEleve[i].nomEleve, E.nomEleve);
                    strcpy(debut->TabEleve[i].prenomEleve, E.prenomEleve);
                    strcpy(&debut->TabEleve[i].sexe, &E.sexe);
                    debut->TabEleve[i].age=E.age;
                    debut->TabEleve[i].redoublant=E.redoublant;
                    debut->TabEleve[i].DateNaissance.tm_mday=E.DateNaissance.tm_mday;
                    debut->TabEleve[i].DateNaissance.tm_mon=E.DateNaissance.tm_mon;
                    debut->TabEleve[i].DateNaissance.tm_year=E.DateNaissance.tm_year;

                    debut->nbEleve++;
                }
                else
                {
                    strcpy(debut->TabEleve[i+1].nomEleve, E.nomEleve);
                    strcpy(debut->TabEleve[i+1].prenomEleve, E.prenomEleve);
                    strcpy(&debut->TabEleve[i+1].sexe, &E.sexe);
                    debut->TabEleve[i+1].age=E.age;
                    debut->TabEleve[i+1].redoublant=E.redoublant;
                    debut->TabEleve[i+1].DateNaissance.tm_mday=E.DateNaissance.tm_mday;
                    debut->TabEleve[i+1].DateNaissance.tm_mon=E.DateNaissance.tm_mon;
                    debut->TabEleve[i+1].DateNaissance.tm_year=E.DateNaissance.tm_year;

                    debut->nbEleve++;

                } while (i<NBRELEVE);

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
	printf("Nom de la classe:\t%s\nNiveau:\t%s\n",C->NomClasse, C->niveau);
	//printf("Liste des eleves:\n");
	/*for (i=0;i<NBRELEVE;i++)
	{
		AfficherEleve(C->TabEleve[i]);
	}*/
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
    getchar();
    while(courant!= NULL && strcmp (courant->niveau, nouvelle->niveau)!= 0)
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

//Initialisation 5 classes de base
void InitialiserClasse(Classe_t **C)
{
	int i;
	const char *TabNomClasse[]={"CP-1","CE1-1","CE2-1","CM1-1","CM2-1"};
	const char *TabNiveauClasse[]={"CP","CE1","CE2","CM1","CM2"};

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

			if (tete==NULL)
			{
				printf("classe %s créée\n",nouvelleClasse->niveau);
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
            printf("Classe %s créée\n",nouvelleClasse->niveau);
            }
        }
    }
}


//Fonction qui affecte des élèves dans Classe à partir d'un fichier .csv qui se nomme ici "fichier_eleve_cole.csv"
void RemplirClasse(Classe_t *Classe)
{

    //Déclaration des variables pour récupérer les informations sauvegardées dans le fichier .csv
    char ligne[LIGNE];    //chaîne temporaire contenant les lignes du fichier (une a une)
    char *champ;          //
    int i=0;

    FILE *ptr_fichierEleveClasse; // création d'un pointeur FILE

    ptr_fichierEleveClasse=fopen("RemplirClasse.csv", "r"); // ouverture du fichier en lecture

    if(!ptr_fichierEleveClasse) // si l'ouverture se passe mal
    {
        perror("erreur ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (i=0; i<10; i++)
        {

        fgets(ligne, LIGNE, ptr_fichierEleveClasse);      // lecture ligne

        champ=strtok(ligne, ";");                         // mettre dans champ les éléments de ligne jusqu'au prochain ';'
        strcpy(Classe->TabEleve[i].nomEleve, champ);      // copie champ dans le nom de l'eleve

        champ=strtok(NULL, ";");                          // mettre dans champ les éléments de ligne jusqu'au prochain ';'
        strcpy(Classe->TabEleve[i].prenomEleve, champ);   // copie champ dans le prenom de l'eleve

        champ=strtok(NULL, ";");                          // mettre dans champ les éléments de ligne jusqu'au prochain ';'
        Classe->TabEleve[i].sexe=atoi(champ);                   // copie champ dans le genre de l'eleve

        champ=strtok(NULL, ";");                                //
        Classe->TabEleve[i].DateNaissance.tm_mday=atoi(champ);  //

        champ=strtok(NULL, ";");                                //
        Classe->TabEleve[i].DateNaissance.tm_mon=atoi(champ);   //

        champ=strtok(NULL, ";");                                //
        Classe->TabEleve[i].DateNaissance.tm_year=atoi(champ);  //

        champ=strtok(NULL, ";");
        Classe->TabEleve[i].age=atoi(champ);

        champ=strtok(NULL, ";");
        Classe->TabEleve[i].redoublant=atoi(champ);

        }
    }

fclose(ptr_fichierEleveClasse);                        // fermeture du fichier .csv

}



/*  fonction auxiliaire permuter deux éléments du tableau */
void TrierEleve(int nbeleve) //Tri par permutation
{
    //déclaration d'une structure eleve tampon
    Eleve_t EleveTemp;

    //création deux boucles de compteur
    int i,j;

	for (i=0; i<nbeleve-1; i++)
		for(j=i; j<nbeleve; j++)
		{
		    if (strcmp(TabEleve[i].nom, TabEleve[j].nom)>0)
            {
                //stockage de tous les champs dans la structure Eleve tampon
                strcpy(EleveTemp.nomEleve, debut.TabEleve[i].nomEleve);
                strcpy(EleveTemp.prenomEleve, debut.TabEleve[i].prenomEleve);
                strcpy(EleveTemp.sexe, debut.TabEleve[i].sexe);
                EleveTemp.DateNaissance.tm_mday=debut.TabEleve[i].DateNaissance.tm_mday;
                EleveTemp.DateNaissance.tm_mon=debut.TabEleve[i].DateNaissance.tm_mon;
                EleveTemp.DateNaissance.tm_year=debut.TabEleve[i].DateNaissance.tm_year;
                EleveTemp.age=debut.TabEleve[i].age;
                EleveTemp.redoublant=debut.TabEleve[i].redoublant;

                //Copie de la structure Eleve TabEleve[j] vers la structure Eleve de TabEleve[i]
                strcpy(debut.TabEleve[i].nomEleve, debut.TabEleve[j].nomEleve);
                strcpy(debut.TabEleve[i].prenomEleve, debut.TabEleve[j].prenomEleve);
                strcpy(debut.TabEleve[i].sexe, debut.TabEleve[j].sexe);
                debut.TabEleve[i].DateNaissance.tm_mday=debut.TabEleve[j].DateNaissance.tm_mday;
                debut.TabEleve[i].DateNaissance.tm_mon=debut.TabEleve[j].DateNaissance.tm_mon;
                debut.TabEleve[i].DateNaissance.tm_year=debut.TabEleve[j].DateNaissance.tm_year;
                debut.TabEleve[i].age=debut.TabEleve[j].age;
                debut.TabEleve[i].redoublant=debut.TabEleve[j].redoublant;

                //Copie de la structure Eleve Tampon vers la structure Eleve TabEleve[j]
                strcpy(debut.TabEleve[j].nomEleve, EleveTemp.nomEleve);
                strcpy(debut.TabEleve[j].prenomEleve, EleveTemp.prenomEleve);
                strcpy(debut.TabEleve[j].sexe, EleveTemp.sexe);
                debut.TabEleve[j].DateNaissance.tm_mday=EleveTemp.DateNaissance.tm_mday;
                debut.TabEleve[j].DateNaissance.tm_mon=EleveTemp.DateNaissance.tm_mon;
                debut.TabEleve[j].DateNaissance.tm_year=EleveTemp.DateNaissance.tm_year;
                debut.TabEleve[j].age=EleveTemp.age;
                debut.TabEleve[j].redoublant=EleveTemp.redoublant;
            }

}



//Fonction modifier Eleve
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
