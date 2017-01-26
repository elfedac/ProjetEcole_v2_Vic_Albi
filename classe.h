#include <stdio.h>
#include "eleve.h"
#include "prof.h"
#include "ecole.h"

#ifndef CLASSE_H
#define CLASSE_H
#define NOMCLASSE 5
#define NBRELEVE 25


//Recursive structure classroom
typedef struct Classe
{
char NomClasse[NOMCLASSE];      // for tcheck class they have same level
char niveau [3];                // level of class : CP, CE1, CE2, CM1 et CM2
Prof_t Prof;                    // Teacher structure added but in class display, it's limited to display lastname and firstname
int nbEleve;                    // 
Eleve_t TabEleve[NBRELEVE];     //
struct Classe *suivant;         //
}Classe_t;

//Classroom display function
void AfficherClasse(Classe_t *C,int taille);

//Classroom input function 
void SaisirClasse(Classe_t **C,int taille);

#endif
