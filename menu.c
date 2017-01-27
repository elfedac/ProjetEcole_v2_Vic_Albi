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


void menuPrincipal()
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


