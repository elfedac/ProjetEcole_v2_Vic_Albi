//#include "menu.h"
#include<stdio.h>
#include<stdlib.h>
#define CLEAR()     system("clear");


void choixMenuPrincipal();

void menuPrincipal();



int main()
{

MenuPrincipal();

}

//Les fonctions

void MenuPrincipal()
{

printf("                                                                              \n");
printf("                       @         @                                            \n");
printf("                     @             @                     #&@@@@@@@@@@@@&      \n");
printf("                   @                 @               @@         @@            \n");
printf("            ,@@@/                     @             @@&           @@          \n");
printf("        @(        .@                  @@           @@@             #@@@       \n");
printf("    ./              @*           @ @@@@@@         @@@   @           &@  %     \n");
printf("   @                            @ @@@@@@@@       %@@  #%@@           @   @    \n");
printf("  @                           *@@@@@@@@@@@      @@@ @ %@   @             @&   \n");
printf("  @                           ,@@@@@@@@@@@@   @    @@@      @               & \n");
printf("                             @@@@@@@@@@@@@@ @%   @@@@       #,      @        &\n");
printf(" @@@                         @@@@@@@@@@@@@@                  @       @      @@\n");
printf("@@@@@                        @@@@@@@@@@@@@                 .@      @  @@@   @ \n");
printf(" @@@  *@                     @@@@@@@@@@@@            @@ @@   .@@@@@           \n");
printf("             %@@@@@@@@@@@@@@. @@@@@@@@@@@@@@@@@@@@@@@                         \n");
printf("                                                                              \n");
printf("##############################################################################\n");
printf("######                                                                  ######\n");
printf("######                     1 : L'Etablissement                          ######\n");
printf("######                     2 : Les Classes                              ######\n");
printf("######                     3 : Les Eleves                               ######\n");
printf("######                     4 : Quitter                                  ######\n");
printf("######                                                                  ######\n");
printf("##############################################################################\n");

choixMenuPrincipal();
}


void MenuEtablissement()
{

printf("                                                                              \n");
printf("       ###           #######       ###      ###     #######                   \n");
printf("       ###           ########      #####    ###     ########                  \n");
printf("       ###           ###    ##     #####    ###     ###    ##                 \n");
printf("       ###           ###    ##     ###  ##  ###     ###    ##                 \n");
printf("       ###           ###    ##     ###  ##  ###     ########                  \n");
printf("       ###           ###    ##     ###    #####     ###   ###                 \n");
printf("       ######### ### ########  ### ###    ##### ### ###    ###  ###           \n");
printf("       ######### ### #######   ### ###     #### ### ###     ### ###           \n");
printf("                                                                              \n");
printf("                                                                              \n");
printf("##############################################################################\n");
printf("######                    Gestion de l'Etablissement                    ######\n");
printf("######                                                                  ######\n");
printf("######                     1 : Renseigner Etablissement                 ######\n");
printf("######                     2 : Modifier Etablissement                   ######\n");
printf("######                     3 : Afficher Etablissement                   ######\n");
printf("######                     4 : Retour Menu Principal                    ######\n");
printf("######                                                                  ######\n");
printf("##############################################################################\n");

choixMenuEtablissement();
}




void MenuClasse()
{

printf("                                                                              \n");
printf("       ###           #######       ###      ###     #######                   \n");
printf("       ###           ########      #####    ###     ########                  \n");
printf("       ###           ###    ##     #####    ###     ###    ##                 \n");
printf("       ###           ###    ##     ###  ##  ###     ###    ##                 \n");
printf("       ###           ###    ##     ###  ##  ###     ########                  \n");
printf("       ###           ###    ##     ###    #####     ###   ###                 \n");
printf("       ######### ### ########  ### ###    ##### ### ###    ###  ###           \n");
printf("       ######### ### #######   ### ###     #### ### ###     ### ###           \n");
printf("                                                                              \n");
printf("                                                                              \n");
printf("##############################################################################\n");
printf("######                       Gestion des Classes                        ######\n");
printf("######                                                                  ######\n");
printf("######                     1 : Saisir une classe                        ######\n");
printf("######                     2 : Modifier une classe                      ######\n");
printf("######                     3 : Afficher une classe                      ######\n");
printf("######                     4 : Retour Menu Principal                    ######\n");
printf("######                                                                  ######\n");
printf("##############################################################################\n");

choixMenuClasse();

}


void MenuEleve()
{

printf("                                                                              \n");
printf("       ###           #######       ###      ###     #######                   \n");
printf("       ###           ########      #####    ###     ########                  \n");
printf("       ###           ###    ##     #####    ###     ###    ##                 \n");
printf("       ###           ###    ##     ###  ##  ###     ###    ##                 \n");
printf("       ###           ###    ##     ###  ##  ###     ########                  \n");
printf("       ###           ###    ##     ###    #####     ###   ###                 \n");
printf("       ######### ### ########  ### ###    ##### ### ###    ###  ###           \n");
printf("       ######### ### #######   ### ###     #### ### ###     ### ###           \n");
printf("                                                                              \n");
printf("                                                                              \n");
printf("##############################################################################\n");
printf("######                       Gestion des Eleves                         ######\n");
printf("######                                                                  ######\n");
printf("######                     1 : Saisir un Eleve                          ######\n");
printf("######                     2 : Modifier un Eleve                        ######\n");
printf("######                     3 : Permuter un Eleve                        ######\n");
printf("######                     4 : Supprimer un Eleve                       ######\n");
printf("######                     5 : Afficher un Eleve                        ######\n");
printf("######                     6 : Retour Menu Principal                    ######\n");
printf("######                                                                  ######\n");
printf("##############################################################################\n");

ChoixMenuEleve();
}



choixMenuPrincipal()
{
int choix=0;

printf("\nMerci de saisir votre choix svp: ");
scanf("%d", &choix);
getchar();


while (((selection < 1) && (selection >4))
switch (choix)
	{
		case 1:
                CLEAR();
                MenuEtablissement();
                break;

		case 2:
                CLEAR();
                MenuClasse();
                break;

		case 3:
                CLEAR();
                MenuEleve();
                break;

        case 4:
                CLEAR();
                MenuPrincipal()

		default :
                printf("Mauvaise saisie, recommencez...");
                MenuPrincipal();
	}

}


choixMenuEtablissement()
{
int choix=0;

printf("\nMerci de saisir votre choix svp: ");
scanf("%d", &choix);
getchar();

while (((selection < 1) && (selection >4))
switch (choix)
	{
		case 1:
                SaisirEcole(Ecole_t *Ec)
                break;

		case 2:
                SaisirEcole(Ecole_t *Ec)
                break;

		case 3:
                AfficherEcole(Ecole_t Ec)
                break;

        case 4 :
                CLEAR();
                MenuPrincipal();

		default :
                printf("Mauvaise saisie, recommencez...");
                MenuPrincipal();
	}

}


choixMenuClasse()
{
int choix=0;

printf("\nMerci de saisir votre choix svp: ");
scanf("%d", &choix);
getchar();

while (((selection < 1) && (selection >4))
switch (choix)
	{
		case 1:

                break;

		case 2:

                break;

		case 3:

                break;

        case 4 :
                CLEAR();
                MenuPrincipal();

		default :
                printf("Mauvaise saisie, recommencez...");
                MenuPrincipal();
	}

}


ChoixMenuEleve()
{
int choix=0;

printf("\nMerci de saisir votre choix svp: ");
scanf("%d", &choix);
getchar();

while (((selection < 1) && (selection >6))
switch (choix)
	{
		case 1:

                break;

		case 2:

                break;

		case 3:

                break;

        case 4:

                break;

        case 5:

                break;

        case 6 :
                CLEAR();
                MenuPrincipal();

		default :
                printf("Mauvaise saisie, recommencez...");
                MenuPrincipal();
	}
}
