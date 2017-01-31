//#include "menu.h"
#include<stdio.h>
#include<stdlib.h>
#define CLEAR()     system("clear");


void choixMenuPrincipal();

void menuPrincipal();



int main()
{

menuPrincipal();

}


void choixMenuPrincipal()
{
int choix=0;
printf("\n\t\t\tVotre choix svp: ");

scanf("%d", &choix);
getchar();

switch (choix)
    {
        case 1:
            //MenuEtablissement();
            break;
        case 2:
            //MenuClasse();
            break;
        case 3:
            //MenuEleve();
            printf("Choix 3");
            break;
        case 4:
            CLEAR();
            printf("\n\t\tAu revoir et à bientôt...");
            break;
        default:
            CLEAR();
            printf("\n\t\tChoix invalide...");
            menuPrincipal();
    }while ((choix < 1) && (choix >4));

}


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
printf("
printf("                                                                              \n");
printf("      ###           #######       ###      ###     #######                    \n");
printf("      ###           ########      #####    ###     ########                   \n");
printf("      ###           ###    ##     #####    ###     ###    ##                  \n");
printf("      ###           ###    ##     ###  ##  ###     ###    ##                  \n");
printf("      ###           ###    ##     ###  ##  ###     ########                   \n");
printf("      ###           ###    ##     ###    #####     ###   ###                  \n");
printf("      ######### ### ########  ### ###    ##### ### ###    ###  ###            \n");
printf("      ######### ### #######   ### ###     #### ### ###     ### ###            \n");
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

switch (choix)
	{
		case 1:
                SaisirEcole(Ecole_t *Ec)
                break;

		case 2:

                break;

		case 3:

                break;

		default :
                    printf("Mauvaise saisie, recommencez\n");
                    CLEAR();
                    MenuPrincipal();

	}


}


choixMenuEtablissement()
{

}


choixMenuClasse()
{

}


ChoixMenuEleve()
{

}
