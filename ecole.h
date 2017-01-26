


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef ECOLE_H
#define ECOLE_H

#define NOMMAX 30
#define PRENOMMAX 20
#define NOMMAXECOLE 50
#define NOMCLASSE 5
#define RUEMAX 60
#define VILLEMAX 30
#define MAILMAX 50
#define CLEAR()     system("clear");



//structure pour l'Ecole
typedef struct Ecole
{
char nomEcole[NOMMAXECOLE];     //
char nomDirecteur [NOMMAX];     //
char prenomDirecteur[PRENOMMAX];//
//Adresse_t AdresseDirecteur;     //
//Adresse_t AdresseEcole;         //
int nbclasse;                   //
struct Classe *tete;            //
}Ecole_t;




//Fonction Affichage Ecole
void AfficherEcole(Ecole_t);


//Fonction Saisie Ecole
void SaisirEcole();


#endif // ECOLE_H
