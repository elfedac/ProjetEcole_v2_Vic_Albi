/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@                                    @@
@@       Saisie/Affichage Adresse     @@
@@                                    @@
@@        par Manuel  + groupe        @@
@@         pour optimisation          @@
@@                                    @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef ADRESSE_H
#define ADRESSE_H

#define NOMMAX 30
#define PRENOMMAX 20
#define RUEMAX 60
#define VILLEMAX 30
#define MAILMAX 50
#define TELMAX 14

//structure adresse
typedef struct Adresse
{
char rue [RUEMAX];          //
int CodePostal;             //
char Ville[VILLEMAX];       //
char TelMaison[TELMAX];     //
char TelMobile[TELMAX];     //
char Mail[MAILMAX];         //
}Adresse_t;


// Les fonctions
void AfficherAdresse(Adresse_t A);

void SaisirAdresse(Adresse_t *A);

#endif
