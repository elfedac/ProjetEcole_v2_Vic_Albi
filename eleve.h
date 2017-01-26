#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#ifndef ELEVE_H
#define ELEVE_H

#define NOMMAX 30
#define PRENOMMAX 20



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


/* AFFICHE LA DATE DE NAISSENCE D'UN ELEVE + SON AGE */
void AfficherDate(Eleve_t y);

/* SAISIE LA DATE DE NAISSENCE D'UN ELEVE */
void SaisirDate(Eleve_t *y);

/* AFFICHE UN ELEVE */
void AfficherEleve(Eleve_t E);

/* SAISIE UN ELELVE */
void SaisirEleve(Eleve_t *E);

#endif // ELEVE_H
