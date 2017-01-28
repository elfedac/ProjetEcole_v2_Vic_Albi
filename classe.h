#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eleve.h"
#include "ecole.h"
#include "adresse.h"

#define NOMCLASSE 5
#define NBRELEVE 25
#define NOMMAX 25
#define PRENOMMAX 25

//structure pour l'enseignant
typedef struct prof
{
char nomProf[NOMMAX];           //
char prenomProf[PRENOMMAX];     //
Adresse_t AdresseProf;          //
}Prof_t; 

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
void AfficherClasse(Classe_t *C);

//Initialisation 5 first classroom
void CreationClasse(Classe_t **C);

//Classroom input function
void AjouterClasse(Classe_t **C);
 
//
void ModifierEleve(Classe_t *C)

//Input classroom function
void SaisirClasse(Classe_t *C) 

#endif
