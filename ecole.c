
#include "ecole.h"



//Fonction Affichage Ecole
void AfficherEcole(Ecole_t Ec)
{

    printf("********** Etablissement %s **********", Ec.nomEcole);

    printf("\n\n\n");

    printf("Directeur(trice): %s %s\n", Ec.nomDirecteur, Ec.prenomDirecteur);

    printf("L'etablissement compte %d classe\n\n", Ec.nbclasse);

}


//Fonction Saisie Ecole
void SaisirEcole(Ecole_t &Ec)
{
    printf("********** Saisie des informations Etablissement **********\n\n\n");

    printf("Saisir le nom de l'etablissement: ");
    fgets(Ec->nomEcole, NOMMAXECOLE, stdin);

    printf("\nSaisir le nom du Directeur(trice): ");
    fgets(Ec->nomDirecteur, NOMMAX, stdin);

    printf("\nSaisir le prenom du Directeur(trice): ");
    fgets(Ec->prenomDirecteur, PRENOMMAX, stdin);


}
