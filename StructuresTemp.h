#define NOMMAX 30
#define PRENOMMAX 20
#define NOMMAXECOLE 50
#define NOMCLASSE 5
#define RUEMAX 60
#define VILLEMAX 30
#define MAILMAX 50
#define NBRENOTESMAX 10
#define COMMENTMAX 300
#define NBREMATIERE 4       //de base : Maths, Français, Hist-Geo, Anglais. Ajout de matière possible facilement

//Les structures

//structure matière                 //Non utilisé - mais utile pour la suite
typedef struct matiere              //ça fait partie de la gestion Ecole/Classes
char nomMatiere [NOMMAX];           //nom de la matière à renseigner
int TabNotes [NBRENOTESMAX];        //saisie des notes
char comment_matiere [COMMENTMAX];  //commentaires du prof
int moyenne;                        //moyenne des notes
}Matiere_t;


//structure pedagogique             //Non utilisé---Pas obligatoire mais utile pour la suite
typedef struct bulletin             //ça fait partie de la gestion Ecole/Classes
{                                   //
char bulletin [20];                 //pour préciser si c'est le bulletin 1er trimestre, etc
Matiere_t TabMatiere[NBREMATIERE];  //Recapitualtif des notes trimestrielles
int nbre_absences;                  //pour gérer l'absentéisme...
int nbre_retards;                   //les retards,
int nbre_avert_discipline;          //et les avertissements disciplinaires
char comment_pedago;                //commentaires conseil des classes/trimestre
}Bulletin_t;



//structure adresse
typedef struct Adresse
{
char rue [MAXRUE];          //
int CodePostal;             //
char Ville[VILLEMAX];       //
char TelMaison [TELMAX];    //
char TelMobile [TELMAX];    //
char Mail[MAILMAX];         // Pas obligé d'utiliser le mail
}Adresse_t;

//structure parent
typedef struct Parent
{
char nomParent [NOMMAX];        //
char prenomParent [PRENOMMAX];  //
char Profession [NOMMAX];       //          |
Adresse_t AdresseParent;        //
}Parent_t;


//structure de l'eleve
typedef struct Eleve
{
char nomEleve [NOMMAX];         //
char prenomEleve [PRENOMMAX];   //
char sexe;                      // F pour fille, G pour garçon
struct tm DateNaissance;        //
int age;                        //
Parent_t Pere;                  //
Parent_t Mere;                  //
Bulletin_t BulletinEleve;       // En option - non utilisé
int redoublant;                 //
}Eleve_t;


//structure pour l'enseignant
typedef struct prof
{
char nomProf[NOMMAX];           //
char prenomProf[PRENOMMAX];     //
Adresse_t AdresseProf;          //
}Prof_t;                        //



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



//structure pour l'Ecole
typedef struct Ecole
{
char nomEcole[NOMMAXECOLE];     //
char nomDirecteur [NOMMAX];     //
char prenomDirecteur[PRENOMMAX];//
Adresse_t AdresseDirecteur;     //
Adresse_t AdresseEcole;         //
int nbclasse;                   //
struct Classe *tete;            //
}



