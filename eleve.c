#include "eleve.h" //header eleve.h file called


/* Student birthday input function */
void SaisirDate(Eleve_t *Y)
{
    //Initialisation student birthday time structure
    memset(&Y->DateNaissance, 0 , sizeof (Y->DateNaissance));

    //Localtime recovery
    time_t aujourdhui=time(NULL);

    time_t birthday; //Student birthday converted to POSIX

    //Student birthday input
    printf ("\nSaisissez la date de naissance de l'élève (JJ/MM/AAAA): ");
	scanf ("%d/%d/%d",	&Y->DateNaissance.tm_mday, &Y->DateNaissance.tm_mon, &Y->DateNaissance.tm_year);

	// Time structure month and year modified before POSIX conversion
	Y->DateNaissance.tm_mon-=1;
    Y->DateNaissance.tm_year-=1900;

    //Student birthday converted in seconds
    birthday=mktime(&Y->DateNaissance);

    //Age is a double type variable, created & initialised to save student age through a calculation...
    double Age=difftime(aujourdhui, birthday)/(365.25*24*3600); //because of Leap year, a year is 365,25 days, a day is 24 hours & 1 hour is 3600 seconds
    Y->age=Age;

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

  	printf ("\nDate de naissance : %d/%02d/%d\n", E.DateNaissance.tm_mday, 1 + E.DateNaissance.tm_mon, 1900 + E.DateNaissance.tm_year);

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

    //Fist name student input
    printf("\nSaisissez le prenom de l'eleve: ");
    fgets(E->prenomEleve,PRENOMMAX,stdin);

    //Gender student input
    printf("\nSaisissez le Sexe de l'eleve (F / M): ");
    scanf("%c",&E->sexe);
    getchar();

    //Gender student input check
    while((E->sexe!='F') && (E->sexe!='M'))
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

    //Input student birthday function call
    SaisirDate(E);
}



int main()
{

    // *** VARIABLES ***

	Eleve_t  Elvin={0};



	// affiche la date du jour
    //AfficherDatejour(date_jour );

	// Affichage naissance d'un élève (plusieurs formats)
	//AfficherDate(Elvin) ;

	// saisir la date de naissence d'un élève
    //AfficherDate(Elvin);
    SaisirEleve(&Elvin);
    AfficherEleve(Elvin);


}

