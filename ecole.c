#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "ecole.h"


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


//Fonction Affichage Ecole depuis un fichier .csv qui se nomme ici "fichier_ecole.csv"
void AfficherEcole(const char *nom_fichier, Ecole_t *Ec)
{

    //Déclaration des variables pour récupérer les informations sauvegardées dans le fichier .csv
    char ligne[LIGNE];    //chaîne temporaire contenant les lignes du fichier (une a une)
    char *champ;        //


    FILE *ptr_fichierEcole; // création d'un pointeur FILE

    ptr_fichierEcole=fopen("nom_fichier", "r"); // ouverture du fichier en lecture

    if(!ptr_fichierEcole) // si l'ouverture se passe mal
    {
        perror("erreur ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    else
    {

        fgets(ligne, LIGNE, ptr_fichierEcole);  // lecture ligne

        champ=strtok(ligne, ";");               // mettre dans champ les éléments de ligne jusqu'au prochain ';'
        strcpy(Ec->nomEcole, champ);            // copie champ dans le nom de l'etablissement


        champ=strtok(NULL, ";");                // mettre dans champ les éléments de ligne jusqu'au prochain ';'
        strcpy(Ec->nomDirecteur, champ);        // copie champ dans le nom du directeur(trice)

        champ=strtok(NULL, ";");                // mettre dans champ les éléments de ligne jusqu'au prochain ';'
        strcpy(Ec->prenomDirecteur, champ);     // copie champ dans le prenom du directeur(trice)

        champ=strtok(NULL, ";");                // mettre dans champ les éléments de ligne jusqu'au prochain ';'
        Ec->nbclasse=atoi(champ);               // on convertit le champ en un entier pour le nombre de classes

        champ=strtok(NULL, ";");
        strcpy(Ec->AdresseEcole.rue, champ);

        champ=strtok(NULL, ";");
        Ec->AdresseEcole.CodePostal=atoi(champ);

        champ=strtok(NULL, ";");
        strcpy(Ec->AdresseEcole.Ville, champ);

        champ=strtok(NULL, ";");
        strcpy(Ec->AdresseEcole.TelMaison, champ);

        champ=strtok(NULL, ";");
        strcpy(Ec->AdresseEcole.TelMobile, champ);

        champ=strtok(NULL, ";");
        strcpy(Ec->AdresseEcole.Mail, champ);
               
    }

fclose(ptr_fichierEcole);                        // fermeture du fichier .csv
    
//Instructions d'affichage des caractéristiques de l'Etablissement

printf("\tNom de l'Etablissement : %s\n", Ec->nomEcole);
printf("\tDirecteur de l'Etablissement: %s %s\n", Ec->nomDirecteur, Ec->prenomDirecteur);
printf("\t\n------ Adresse ------");
printf("\n\tRue: %s", Ec->AdresseEcole.rue);
printf("\n\tCode Postal et Commune: %d %s", Ec->AdresseEcole.CodePostal, Ec->AdresseEcole.Ville);
printf("\n\tTelephone Fixe: %s\n", Ec->AdresseEcole.TelMaison);
printf("\tTelephone Mobile: %s\n", Ec->AdresseEcole.TelMobile);
printf("\tAdresse mail: %s", Ec->AdresseEcole.Mail);
printf("\n\tNombre de classes: %s", Ec->nbclasse);
}


//Fonction Saisie Ecole
void SaisirEcole(Ecole_t *Ec)
{
    printf("********** Saisie des informations Etablissement **********\n\n\n");

    printf("Saisir le nom de l'etablissement: ");
    fgets(Ec->nomEcole, NOMMAXECOLE, stdin);
    Ec->nomEcole[strlen(Ec->nomEcole)-1]='\0';              // on supprime le '\n' généré par fgets

    printf("\nSaisir le nom du Directeur(trice): ");
    fgets(Ec->nomDirecteur, NOMMAX, stdin);
    Ec->nomDirecteur[strlen(Ec->nomDirecteur)-1]='\0';      // on supprime le '\n' généré par fgets

    printf("\nSaisir le prenom du Directeur(trice): ");
    fgets(Ec->prenomDirecteur, PRENOMMAX, stdin);
    Ec->prenomDirecteur[strlen(Ec->prenomDirecteur)-1]='\0';// on supprime le '\n' généré par fgets

    SaisirAdresse(&Ec->AdresseEcole);

    FILE *ptr_fichierEcole; // création d'un pointeur FILE

    ptr_fichierEcole = fopen("fichier_ecole.csv", "w");     // ouverture du fichier secret en mode "écriture"

    if(!ptr_fichierEcole)                                   // si l'ouverture se passe mal
    {
        perror("erreur ouverture du fichier");              //Affichage du message d'erreur
        exit(EXIT_FAILURE);                                 //Sortie du programme
    }
    else
    {
        // écriture des caractéristiques de l'établissement dans un fichier csv compatible LibreOffice/Microsoft Office
        fprintf(ptr_fichierEcole, "%s;%s;%s;%d;", Ec->nomEcole, Ec->nomDirecteur, Ec->prenomDirecteur, Ec->nbclasse);

        fprintf(ptr_fichierEcole, "%s ; %d ; %s ; %s ; %s ; %s", Ec->AdresseEcole.rue, Ec->AdresseEcole.CodePostal, Ec->AdresseEcole.Ville, Ec->AdresseEcole.TelMaison,
                                                                 Ec->AdresseEcole.TelMobile, Ec->AdresseEcole.Mail);
    }

fclose(ptr_fichierEcole);                                   // fermeture du fichier .csv
}
