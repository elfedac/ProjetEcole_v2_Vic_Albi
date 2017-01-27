@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@                                    @@
@@       Saisie/Affichage Ecole       @@
@@                                    @@
@@        par Manuel  + groupe        @@
@@         pour optimisation          @@
@@                                    @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "adresse.h"


#ifndef ECOLE_H
#define ECOLE_H

#define NOMMAX 30
#define PRENOMMAX 20
#define NOMMAXECOLE 50
#define LIGNE 600
#define RUEMAX 60
#define VILLEMAX 30
#define TELMAX 15
#define MAILMAX 50
#define CLEAR()     system("clear");



//structure pour l'Ecole
typedef struct Ecole
{
char nomEcole[NOMMAXECOLE];         //
char nomDirecteur [NOMMAX];         //
char prenomDirecteur[PRENOMMAX];    //
//Adresse_t AdresseDirecteur;       //Non utilisé pour l'instant
Adresse_t AdresseEcole;           //
int nbclasse;                       //
struct Classe *tete;                //
}Ecole_t;




//Fonction Affichage Ecole
void AfficherEcole(const char *nom_fichier, Ecole_t *Ec)


//Fonction Saisie Ecole
void SaisirEcole();


#endif // ECOLE_H
