//*****************************************************************
//***           Fichiers eleve.c et eleve.h                     ***
//***              par Elvin et Manuel                          ***
//*****************************************************************

#include "eleve.h" //header eleve.h file called


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
    birthday=mktime(&Y->DateNaissance);

    //Age is a double type variable, created & initialised to save student age through a calculation...
    double Age=difftime(aujourdhui, birthday)/(365.25*24*3600); //because of Leap year, a year is 365,25 days, a day is 24 hours & 1 hour is 3600 seconds
    E->age=Age;

}


/*Display Student features*/
void AfficherEleve(Eleve_t E)
{
    CLEAR();

    //Title display
    printf("**********\tCaracteristisques de l'eleve\t**********\n");

    //Display last name, first name & age
    printf("\nNom de l'eleve : %s\nPrenom de l'eleve : %s\nAge : %d ans\n",
    E.nomEleve, E.prenomEleve, E.age);

   //Student Sex verification to display the true information
    if ((E.sexe=='M') || (E.sexe=='m'))
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

    printf("*****\tSaisie des caracteristisques de l'eleve\t*****\n\n");

    //Last name student input
    printf("\nSaisissez le nom de l'eleve: ");
    fgets(E->nomEleve,NOMMAX,stdin);
    E->nomEleve[strlen(E->nomEleve)-1]='\0';          //'\n' removal from string nomEleve

    //uppercase the last name student
    for(i=0; i<strlen(E->nomEleve); i++)
    {
    	E->nomEleve[i]=toupper(E->nomEleve[i]);
    }
	
    //Fist name student input
    printf("\nSaisissez le prenom de l'eleve: ");
    fgets(E->prenomEleve,PRENOMMAX,stdin);
    E->prenomEleve[strlen(E->prenomEleve)-1]='\0';    //'\n' removal from string prenomEleve

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
    getchar();      //Returns the next character from the standard input (stdin)

    //Gender student input check
    while((E->sexe!='F') && (E->sexe!='f') && (E->sexe!='M') && (E->sexe!='m'))
	{
		CLEAR(); //if wrong input, system console screen cleared before displaying new choice
		printf("\nJe n'ai pas compris...\nVeuillez re-saisir le sexe (F / M): ");
		scanf("%c",&E->sexe);
		getchar();      //Returns the next character from the standard input (stdin)
	}

    //Student school year repeat input
    printf("\nL'élève est-il redoublant?\n(1 si redoublant/ 0 si non redoublant): ");
    scanf("%d",&E->redoublant);
    getchar();          //Returns the next character from the standard input (stdin).

    //Check Student school year repeat input
    while((E->redoublant!=1) && (E->redoublant!=0))
	{
		CLEAR(); //if wrong input, system console screen cleared before displaying new choice
		printf("\nJe n'ai pas compris...\nL'élève est-il redoublant ? (1 pour redoublant/ 0 pour non redoublant): ");
		scanf("%d",&E->redoublant);
    }
}


//Find Academic level according Student age & year repeat
void TrouverNiveau (Eleve_t E, char *Niveau)
{

    if (((E.age==6) && (E.redoublant==0)) || ((E.age==7) && (E.redoublant==1)))
    {
        strcpy(Niveau, "CP");
    }

    if (((E.age==7) && (E.redoublant==0)) || ((E.age==8) && (E.redoublant==1)))
    {
        strcpy(Niveau, "CE1");
    }

    if (((E.age==8) && (E.redoublant==0)) || ((E.age==9) && (E.redoublant==1)))
    {
        strcpy(Niveau, "CE2");
    }

    if (((E.age==9) && (E.redoublant==0)) || ((E.age==10) && (E.redoublant==1)))
    {
        strcpy(Niveau, "CM1");
    }

    if (((E.age==10) && (E.redoublant==0)) || ((E.age==11) && (E.redoublant==1)))
    {
        strcpy(Niveau, "CM2");
    }

}


//Class Student Assignment according to academic level
int AffecterEleve(Eleve_t E, Classe_t *ClasseAffectation, const char *Niveau)
{
    //Création d'un pointeur + positionnement en tête de liste
    Classe_t *debut=ClasseAffectation;

    //Looking for the right class according to his level
    while((debut!=NULL) && (strcmp(debut->niveau, Niveau)!=0))

    {
        //go to next Class
        debut=debut->suivant;
    }
    if(debut->nbEleve==NBRELEVE) //Class is full
    {
        debut=debut->suivant;
    }

    //Students number affected to integer 'i'
    int i=debut->nbEleve;

	//printf("\nVérification nombre eleves dans la classe...%d\n", i); //petite balise test

    //Condition vérifiant que la classe de niveau recherché 'suivante' n'est pas pleine
	if((i<NBRELEVE) && (strcmp(debut->niveau,Niveau)==0))
	{
        //Student characteristics copy to Class
		strcpy(debut->TabEleve[i].nomEleve, E.nomEleve);
		strcpy(debut->TabEleve[i].prenomEleve, E.prenomEleve);
		strcpy(&debut->TabEleve[i].sexe, &E.sexe);
		debut->TabEleve[i].age=E.age;
		debut->TabEleve[i].redoublant=E.redoublant;
		debut->TabEleve[i].DateNaissance.tm_mday=E.DateNaissance.tm_mday;
		debut->TabEleve[i].DateNaissance.tm_mon=E.DateNaissance.tm_mon;
		debut->TabEleve[i].DateNaissance.tm_year=E.DateNaissance.tm_year;

        //Number of students raised by one
		debut->nbEleve++;
		return 0;
    }
	else
	{
		return 1;
	}

}

