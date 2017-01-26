#include "eleve.h"


/* SAISIE LA DATE DE NAISSANCE D'UN ELEVE */
void SaisirDate(Eleve_t *Y)
{
    //Initialisation de la structure temps DateNaissance Eleve
    memset(&Y->DateNaissance, 0 , sizeof (Y->DateNaissance));

    //déclaration et récupération du temps écoulé depuis le 01/01/1970 et la date du jour
    time_t aujourdhui=time(NULL);

    time_t birthday; // date de naissance eleve qui sera convertie à la norme POSIX

    printf ("\nSaisissez l'age de l'élève au format (JJ/MM/AAAA) : ");
	scanf ("%d/%d/%d",	&Y->DateNaissance.tm_mday, &Y->DateNaissance.tm_mon, &Y->DateNaissance.tm_year);

	// Opérer aux modifications nécessaires avant la tranformation POSIX
	// En transférant dans une nouvelle variable, les éléments modifiés
    Y->DateNaissance.tm_mon-=1;
    Y->DateNaissance.tm_year-=1900;

    birthday=mktime(&Y->DateNaissance);

    //Déclaration + initialisation du double Age pour le calcul
    //du temps écoulé entre Date Naissance et date du jour (le mktime convertit DateNaissance en secondes)
    double Age=difftime(aujourdhui, birthday)/(365.25*24*3600);
    Y->age=Age;

}


/*AFFICHE UN ELEVE*/
void AfficherEleve(Eleve_t E)
{
    printf("\nNom de l'eleve : %s\nPrenom de l'eleve :%s\nAge : %d",
            E.nomEleve, E.prenomEleve, E.age);

    if (E.sexe=='M')
        {
        printf("\nSexe : Masculin");
        }
    else
        {
        printf("\nSexe : Féminin");
        }


  	printf ("\nDate de naissance : %d/%d/%d\n", E.DateNaissance.tm_mday, 1 + E.DateNaissance.tm_mon, E.DateNaissance.tm_year);

    if (E.redoublant==1)
        {
        printf("\nEleve redoublant");
        }
    else
        {
        printf("\nEleve non redoublant\n");
        }

}


/*SAISIE UN ELEVE */
void SaisirEleve(Eleve_t *E)
{
    printf("\nSaisissez le nom de l'eleve : ");
    fgets(E->nomEleve,NOMMAX,stdin);

    printf("Saisissez le prenom de l'eleve : ");
    fgets(E->prenomEleve,PRENOMMAX,stdin);

    printf("Saisissez le Sexe de l'eleve (F / M) : ");
    scanf("%c",&E->sexe);
    printf("%c", E->sexe);


    /*while(E->sexe!='F' || E->sexe!='M')
	{
		printf("\nJe n'ai pas compris, veuillez re-saisir le sexe (F / M): ");
		scanf("%c",&E->sexe);
		getchar();
	}*/

    printf("L'élève est-il redoublant ? (1 pour redoublant/ 0 pour non redoublant): ");
    scanf("%d",&E->redoublant);

    /*
    while(E->redoublant!=1 || E->redoublant!=0)
	{
		printf("\nJe n'ai pas compris...\nL'élève est-il redoublant ? (1 pour redoublant/ 0 pour non redoublant): ");
		scanf("%c",&E->sexe);
		getchar();
	} Ne fonctionne pas
    */

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

