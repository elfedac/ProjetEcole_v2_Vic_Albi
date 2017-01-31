#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include<time.h>
#include "classe.h"
#include "ecole.h"
#include "menu.h"
#include "adresse.h"

#ifndef ELEVE_H
#define ELEVE_H

#define NOMMAX 30
#define PRENOMMAX 20
#define CLEAR()     system("clear");

//structure de l'eleve
typedef struct Eleve
{
    char nomEleve[NOMMAX];          //
    char prenomEleve [PRENOMMAX];   //
    char sexe;                      // F pour fille, G pour garçon
    int age;
    int redoublant;
    struct tm DateNaissance;
    //Parent_t Pere;                // En option...
    //Parent_t Mere;                //      |
    //Bulletin_t BulletinEleve;     // non utilisé

}Eleve_t;


//Display Student birthday & age
void AfficherDate(Eleve_t y);

//Student birthday imput
void SaisirDate(Eleve_t *y);

//Display student informations
void AfficherEleve(Eleve_t E);

//Student imput
void SaisirEleve(Eleve_t *E);

//Find Student Academic level
void TrouverNiveau (Eleve_t E, char *Niveau);

//Class Student Assignment
int AffecterEleve(Eleve_t E, Classe_t *ClasseAffectation, const char *Niveau);

#endif // ELEVE_H
