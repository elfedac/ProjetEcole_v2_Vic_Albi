

#include "ecole.h"


//Fonction Affichage Ecole depuis un fichier .csv qui se nomme ici "fichier_ecole.csv"
void AfficherEcole(const char *nom_fichier, Ecole_t *Ec)
{

    //Déclaration des variables pour récupérer les informations sauvegardées dans le fichier .csv
    char ligne[LIGNE];    //chaîne temporaire contenant les lignes du fichier (une a une)
    char *champ;        //


    FILE *ptr_fichierEcole; // création d'un pointeur FILE

    ptr_fichierEcole = fopen(nom_fichier, "r"); // ouverture du fichier en lecture

    if(!ptr_fichier) // si l'ouverture se passe mal
    {
        perror("erreur ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    else
    {
        fgets(ligne, LIGNE, ptr_fichierEcole); // lecture ligne

        champ=strtok(ligne, ";"); // mettre dans champ les éléments de ligne jusqu'au prochain ';'
        strcpy(Ec->nomEcole, champ); // copier champ dans le nom de l'etablissement


        champ=strtok(NULL, ";");// mettre dans champ les éléments de ligne jusqu'au prochain ';'
        strcpy(Ec->nomDirecteur, champ); // copier champ dans le nom du directeur(trice)

        champ=strtok(NULL, ";");// mettre dans champ les éléments de ligne jusqu'au prochain ';'
        strcpy(Ec->prenomDirecteur, champ); // copier champ dans le prenom du directeur(trice)

        champ=strtok(NULL, ";");// mettre dans champ les éléments de ligne jusqu'au prochain ';'
        Ec->nbclasse=atoi(champ); // on convertit le champ en un entier pour le nombre de classes

    }

fclose(ptr_fichierEcole); // fermeture du fichier .csv

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


    FILE *ptr_fichierEcole; // création d'un pointeur FILE

    ptr_fichierEcole = fopen("fichier_ecole.csv", "w"); // ouverture du fichier secret en mode "écriture"

    if(!ptr_fichierEcole)                               // si l'ouverture se passe mal
    {
        perror("erreur ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    else
    {
        // écriture des caractéristiques de l'établissement dans un fichier csv compatible LibreOffice/Microsoft Office
        fprintf(ptr_fichierEcole, "%s ; %s ; %s ; %d ; ", Ec->nomEcole, Ec->nomDirecteur, Ec->prenomDirecteur, Ec->nbclasse);
    }

fclose(ptr_fichierEcole); // fermeture du fichier .csv
}
