#include "adresse.h"



//Fonction d'affichage Adresse
void AfficherAdresse(Adresse_t A)
{
printf ("Adresse...\nRue: %s\nCode Postal %d\nVille: %s\n", A.rue, A.CodePostal, A.Ville);
printf ("Telephone fixe: %s\nTelephone mobile: %s\nAdresse mail: %s", A.TelMaison, A.TelMobile, A.Mail);

}


//Fonction Saisie Adresse
void SaisirAdresse(Adresse_t *A)
{
    printf("\nSaisir la rue : ");
    fgets(A->rue, RUEMAX, stdin);
    A->rue[strlen(A->rue)-1]='\0'; // on supprime le '\n' généré par fgets

    printf("\nSaisir le code postal de la commune : ");
    scanf("%d", &A->CodePostal);
    getchar();

    printf("\nSaisir la ville : ");
    fgets(A->Ville, VILLEMAX, stdin);
    A->Ville[strlen(A->Ville)-1]='\0'; // on supprime le '\n' généré par fgets

    printf("\nSaisir numero de telephone fixe:");
    fgets(A->TelMaison, TELMAX, stdin);
    A->TelMaison[strlen(A->TelMaison)-1]='\0'; // on supprime le '\n' généré par fgets

    printf("\nSaisir numero de telephone mobile:");
    fgets(A->TelMobile, TELMAX, stdin);
    A->TelMobile[strlen(A->TelMobile)-1]='\0'; // on supprime le '\n' généré par fgets

    printf("\nSaisir adresse mail : ");
    fgets(A->Mail, MAILMAX, stdin);
    A->Mail[strlen(A->Mail)-1]='\0'; // on supprime le '\n' généré par fgets

}
