#include <stdio.h>
#include "eleve.h"
#include "prof.h"
#include "ecole.h"

#ifndef CLASSE_H
#define CLASSE_H
#define NOMCLASSE 5
#define NBRELEVE 25


//structure recursive pour la classe
typedef struct Classe
{
char NomClasse[NOMCLASSE];      // permet d'eviter confusion si deux classes CE1 créées (on pourra les appeler CE1-1 et CE1-2 par exemple)
char niveau [3];                // niveaux au sens strict : CP, CE1, CE2, CM1 et CM2
Prof_t Prof;                    // structure enseignant ajouté mais lors de l'affichage de la classe, on se limite à afficher nom et prénom tout simplement
int nbEleve;                    //
Eleve_t TabEleve[NBRELEVE];     //
struct Classe *suivant;         //
}Classe_t;

//fonction d'affichage de classe
void AfficherClasse(Classe_t *C,int taille);

//fonction de saisie de classe
void SaisirClasse(Classe_t **C,int taille);

#endif
