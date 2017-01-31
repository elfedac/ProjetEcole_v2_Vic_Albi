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
printf("######                     2 : Ajouter une classe                       ######\n");
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


AuRevoir()
{

printf("                                 .:AMMO:                                    ");
printf("                        .:AMMMMMHIIIHMMM.                                   ");
printf("              ....   .AMMMMMMMMMMMHHHMHHMMMML:AMF"                          ");
printf("            .:MMMMMLAMMMMMMMHMMMMMMHHIHHIIIHMMMML.                          ");
printf("                 "WMMMMMMMMMMMMMMMMMMH:::::HMMMMMMHII:.                     ");
printf("            .AMMMMMMMHHHMMMMMMMMMMHHHHHMMMMMMMMMAMMMHHHHL.                  ");
printf("          .MMMMMMMMMMHHMMMMMMMMHHHHMMMMMMMMMMMMMHTWMHHHHHML                 ");
printf("         .MMMMMMMMMMMMMMMMMMMHHHHHHHHHMHMMHHHHIII:::HMHHHHMM.               ");
printf("         .MMMMMMMMMMMMMMMMMMMMMMHHHHHHMHHHHHHIIIIIIIIHMHHHHHM.              ");
printf("         MMMMMMMMMMMMMMMMMHHMMHHHHHIIIHHH::IIHHII:::::IHHHHHHHL             ");
printf("         "MMMMMMMMMMMMMMMMHIIIHMMMMHHIIHHLI::IIHHHHIIIHHHHHHHHML            ");
printf("          .MMMMMMMMMMMMMM"WMMMHHHMMMMMMMMMMMLHHHMMMMMMHHHHHHHHHHH           ");
printf("         .MMMMMMMMMMMWWMW   ""YYHMMMMMMMMMMMMF""HMMMMMMMMMHHHHHHHH.         ");
printf("        .MMMMMMMMMM W" V                         W"WMMMMMHHHHHHHHHH         ");
printf("       "MMMMMMMMMM".                                 "WHHHMH"HHHHHHL        ");
printf("       MMMMMMMMMMF  .                                         IHHHHH.       ");
printf("       MMMMMMMMMM .                                  .        HHHHHHH       ");
printf("       MMMMMMMMMF. .                               .  .       HHHHHHH.      ");
printf("       MMMMMMMMM .     ,AWMMMMML.              ..    .  .     HHHHHHH.      ");
printf("     :MMMMMMMMM".  .  F"'    'WM:.         ,::HMMA, .  .      HHHHMMM       ");
printf("     :MMMMMMMMF.  . ."         WH..      AMM"'     "  .  .    HHHMMMM       ");
printf("      MMMMMMMM . .     ,;AAAHHWL"..     .:'                   HHHHHHH       ");
printf("      MMMMMMM:. . .   -MK"OTO L :I..    ...:HMA-.             "HHHHHH       ");
printf(" ,:IIIILTMMMMI::.      L,,,,.  ::I..    .. K"OTO"ML           'HHHHHH       ");
printf(" LHT::LIIIIMMI::. .      '""'.IHH:..    .. :.,,,,           '  HMMMH: HLI'  ");
printf(" ILTT::"IIITMII::.  .         .IIII.     . '""""             ' MMMFT:::.    ");
printf(" HML:::WMIINMHI:::.. .          .:I.     .   . .  .        '  .M"'.....I.   ");
printf(" "HWHINWI:.'.HHII::..          .HHI     .II.    .  .      . . :M.',, ..I:   ");
printf(" "MLI"ML': :HHII::...        MMHHL     :::::  . :..      .'.'.'HHTML.II:    ");
printf("   "MMLIHHWL:IHHII::....:I:" :MHHWHI:...:W,,"  '':::.      ..'  ":.HH:II:   ");
printf("     "MMMHITIIHHH:::::IWF"    """T99"'  '""    '.':II:..'.'..'  I'.HHIHI'   ");
printf("       YMMHII:IHHHH:::IT..     . .   ...  . .    ''THHI::.'.' .;H.""."H"    ");
printf("         HHII:MHHI"::IWWL     . .     .    .  .     HH"HHHIIHHH":HWWM"      ");
printf("          """ MMHI::HY""ML,          ...     . ..  :"  :HIIIIIILTMH"        ");
printf("               MMHI:.'    'HL,,,,,,,,..,,,......,:" . ''::HH "HWW           ");
printf("               'MMH:..   . 'MMML,: """MM""""MMM"      .'.IH'"MH"            ");
printf("                "MMHL..   .. "MMMMMML,MM,HMMMF    .   .IHM"                 ");
printf("                  "MMHHL    .. "MMMMMMMMMMMM"  . .  '.IHF'                  ");
printf("                    'MMMML    .. "MMMMMMMM"  .     .'HMF                    ");
printf("                     HHHMML.                    .'MMF"                      ");
printf("                    IHHHHHMML.               .'HMF"                         ");
printf("                    HHHHHHITMML.           .'IF..                           ");
printf("                    "HHHHHHIITML,.       ..:F...                            ");
printf("                     'HHHHHHHHHMMWWWWWW::"......                            ");
printf("     AU                HHHHHHHMMMMMMF"'........                             ");
printf("                        HHHHHHHHHH............                              ");
printf("     REVOIR               HHHHHHHH...........                               ");
printf("                           HHHHIII..........                                ");
printf("     ...                    HHIII..........                                 ");
printf("                             HII.........                                   ");
printf("                              "H........                                    ");
printf("                                ......                                      ");

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
                AuRevoir();
                break;

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
                CLEAR();
                SaisirEcole(Ecole_t *Ec);
                MenuEtablissement();
                break;

		case 2:
                CLEAR();
                SaisirEcole(Ecole_t *Ec);
                MenuEtablissement();
                break;

		case 3:
                CLEAR();
                AfficherEcole(Ecole_t Ec);
                MenuEtablissement();
                break;

        case 4 :
                CLEAR();
                MenuPrincipal();
                break;

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
                CLEAR();
                SaisirClasse(Classe_t *C);
                MenuClasse();
                break;

		case 2:
                CLEAR();
                AjouterClasse(Classe_t **C);
                MenuClasse();
                break;

		case 3:
                CLEAR();
                AfficherClasse(Classe_t *C);
                MenuClasse();
                break;

        case 4 :
                CLEAR();
                MenuPrincipal();
                break;

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
                CLEAR();
                SaisirEleve(Eleve_t *E);
                MenuEleve();
                break;

		case 2:
                CLEAR();
                ModifierEleve(Classe_t *C);
                MenuEleve();
                break;

		case 3:

                break;

        case 4:
                CLEAR();
                SupprimerEleve(Classe_t *C);
                MenuEleve();
                break;

        case 5:
                CLEAR();
                AfficherEleve(Eleve_t E);
                MenuEleve();
                break;

        case 6 :
                CLEAR();
                MenuPrincipal();
                break;

		default :
                printf("Mauvaise saisie, recommencez...");
                MenuPrincipal();
	}
}
