#define DECAL_COL 30
#define DECAL_LIG 10

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "boss.h"
#include "graph.h"
#include "fonctions.h"
#include "fonctions_B.h"
#include "menu.h"
#include "boss.h"
void loosebyshoot()
{
    int j;


    system("cls");
    gotoligcol(10,10);
    printf("                           ___");
    gotoligcol(11,10);
    printf("                          /   \\");
    gotoligcol(12,10);
    printf("   |    /MMMMMMMMMMMMMMMMMMMMMMMMMMMMM\\");
    gotoligcol(13,10);
    printf(" -MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM|");
    gotoligcol(14,10);
    printf("   |    \\MMMMMMMMMMMMMMMMMMMMMMMMMMMMM/");

    gotoligcol(10,100);
    printf("        MMMMM");
    gotoligcol(11,100);
    printf("     MMMMMMMM   MMMMMMM");
    gotoligcol(12,100);
    printf("   MMMMMMM     M");
    gotoligcol(13,100);
    printf("(MMMMMMMMMMMMMMMMMM");
    gotoligcol(14,100);
    printf("   MMMMMMM     M");
    gotoligcol(15,100);
    printf("    MMMMMMMMM   MMMMMMM");
    gotoligcol(16,100);
    printf("        MMMMM");
    Sleep(500);
    gotoligcol(13,99);
    printf("<");
    Sleep(50);
    gotoligcol(13,98);
    printf("<=");
    Sleep(50);
    gotoligcol(13,97);
    printf("<=+");
    for(j=0; j<48; j++)
    {
        Sleep(20);
        gotoligcol(13,96-j);
        printf("<=+ ");
    }

    gotoligcol(10,10);
    printf("                           ___");
    gotoligcol(11,10);
    printf("                          /   \\        ' #");
    gotoligcol(12,10);
    printf("   |    /MMMMMMMMMMMMMMMMMMMMMMMMMMMMM# #");
    gotoligcol(13,10);
    printf(" -MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM  ");
    gotoligcol(14,10);
    printf("   |    \\MMMMMMMMMMMMMMMMMMMMMMMMMMMMM #/");

    Sleep(50);
    gotoligcol(10,10);
    printf("                           ___");
    gotoligcol(11,10);
    printf("                          /   \\   #  #  ' #");
    gotoligcol(12,10);
    printf("   |    /MMMMMMMMMMMMMMMMMMMMMMMMMMM  # #");
    gotoligcol(13,10);
    printf(" -MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM#          ");
    gotoligcol(14,10);
    printf("   |    \\MMMMMMMMMMMMMMMMMMMMMMMMM #  #/");
    gotoligcol(15,10);
    printf("                                  ' #");


    Sleep(50);
    gotoligcol(10,10);
    printf("                           ___   #    # ");
    gotoligcol(11,10);
    printf("                          /   \\ #  #  #  ' #");
    gotoligcol(12,10);
    printf("   |    /MMMMMMMMMMMMMMMMMMMMMMMM  # #");
    gotoligcol(13,10);
    printf(" -MMMMMMMMMMMMMMMMMMMMMMMMMMMM  #            ");
    gotoligcol(14,10);
    printf("   |    \\MMMMMMMMMMMMMMMMMMMMMMMMM #  #/");
    gotoligcol(15,10);
    printf("                                  ' #");
    gotoligcol(16,10);
    printf("                                  ' #");


    Sleep(50);
    gotoligcol(10,10);
    printf("                   \\     ___/   #    # ");
    gotoligcol(11,10);
    printf("                                #  #  #  ' #");
    gotoligcol(12,10);
    printf("   |    /MMMMMMMMMMMMMMMMMMMMMMMM  # #");
    gotoligcol(13,10);
    printf(" -MMMMMMMMMMMMMMMMMMMMMMMMMMMM  #            ");
    gotoligcol(14,10);
    printf("   |    \\MMMMMMMMMMMMMMMMMMMMM #  #    ");
    gotoligcol(15,10);
    printf("                                  '   #");
    gotoligcol(16,10);
    printf("                                  ' #");
    Sleep(50);

    gotoligcol(8,10);
    printf("                   \\     ___/   #    # ");
    gotoligcol(9,10);
    printf("                                #  #  #  ' #");
    gotoligcol(10,10);
    printf("                     #  ''   #    # ");
    gotoligcol(11,10);
    printf("                                #  #  #  ' #");
    gotoligcol(12,10);
    printf("   |    /MMMMMMMMMMMM    '  #       # #");
    gotoligcol(13,10);
    printf(" -MMMMMMMMMMMMMMMMMMMMMMM    #               ");
    gotoligcol(14,10);
    printf("   |    \\MMMMMMMMMMMMMM   #  '  #        ");
    gotoligcol(15,10);
    printf("                                #     #  ");
    gotoligcol(16,10);
    printf("                                   '     #    ");
    gotoligcol(17,10);
    printf("                                    ' #");
    Sleep(50);
    gotoligcol(7,10);
    printf("               #    '\\ #        ___     /   #    # ");
    gotoligcol(8,10);
    printf("                                   #  #  #  ' #");
    gotoligcol(9,10);
    printf("           '    #         #  ''   #    # ");
    gotoligcol(10,10);
    printf("                                    #  #  #  ' #");
    gotoligcol(11,10);
    printf("            #          #  #  #  ' #        ");
    gotoligcol(12,10);
    printf("   |    /MMMMM#  ' #  '   '  #       # #");
    gotoligcol(13,10);
    printf(" -MMMMMMMMMMMMM#'  # ' '    #               ");
    gotoligcol(14,10);
    printf("   |    \\MMMMMM#   '   '   #  #  '  #        ");
    gotoligcol(15,10);
    printf("                                #           #  ");
    gotoligcol(16,10);
    printf("                        #    '        #     #  ");
    gotoligcol(17,10);
    printf("                              #         '     #    ");
    gotoligcol(18,10);
    printf("                          '   #           ' #");

    Sleep(50);
    gotoligcol(6,10);
    printf("               #    '\\ #        ___     /   #    # ");
    gotoligcol(7,10);
    printf("                                   #  #  #  ' #");
    gotoligcol(8,10);
    printf("   \\        '    #         #  ''   #    # ");
    gotoligcol(9,10);
    printf("       /                             #  #  #  ' #");
    gotoligcol(10,10);
    printf("            #          #  #  #  ' #        ");
    gotoligcol(11,10);
    printf("            #          #  #  #  ' #        ");
    gotoligcol(12,10);
    printf("     #   '  #  #  ' #  '   '  #       # #");
    gotoligcol(13,10);
    printf(" #   '  #  #  '#'  # ' '    #               ");
    gotoligcol(14,10);
    printf("   |    # #  '  ##   '   '   #  #  '  #        ");
    gotoligcol(16,10);
    printf("                                #           #  ");
    gotoligcol(17,10);
    printf("           \\             #    '        #     #  ");
    gotoligcol(18,10);
    printf("                              #         '     #    ");
    gotoligcol(19,10);
    printf("                          '   #           ' #");

    Sleep(50);
    system("cls");
    gotoligcol(6,5);
    printf("          _____                    _____                    _____                    _____                    _____       ");
    gotoligcol(7,5);
    printf("         /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\                  /\\    \\         ");
    gotoligcol(8,5);
    printf("        /::\\    \\                /::\\    \\                /::\\    \\                /::\\    \\                /::\\____\\        ");
    gotoligcol(9,5);
    printf("       /::::\\    \\              /::::\\    \\              /::::\\    \\              /::::\\    \\              /:::/    /        ");
    gotoligcol(10,5);
    printf("      /::::::\\    \\            /::::::\\    \\            /::::::\\    \\            /::::::\\    \\            /:::/    /         ");
    gotoligcol(11,5);
    printf("     /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/\\:::\\    \\          /:::/    /          ");
    gotoligcol(12,5);
    printf("    /:::/__\\:::\\    \\        /:::/__\\:::\\    \\        /:::/__\\:::\\    \\        /:::/  \\:::\\    \\        /:::/    /           ");
    gotoligcol(13,5);
    printf("   /::::\\   \\:::\\    \\      /::::\\   \\:::\\    \\      /::::\\   \\:::\\    \\      /:::/    \\:::\\    \\      /:::/    /            ");
    gotoligcol(14,5);
    printf("  /::::::\\   \\:::\\    \\    /::::::\\   \\:::\\    \\    /::::::\\   \\:::\\    \\    /:::/    / \\:::\\    \\    /:::/    /      _____  ");
    gotoligcol(15,5);
    printf(" /:::/\\:::\\   \\:::\\____\\  /:::/\\:::\\   \\:::\\    \\  /:::/\\:::\\   \\:::\\____\\  /:::/    /   \\:::\\ ___\\  /:::/____/      /\\    \\");
    gotoligcol(16,5);
    printf("/:::/  \\:::\\   \\:::|    |/:::/__\\:::\\   \\:::\\____\\/:::/  \\:::\\   \\:::|    |/:::/____/     \\:::|    ||:::|    /      /::\\____\\");
    gotoligcol(17,5);
    printf("\\::/    \\:::\\  /:::|____|\\:::\\   \\:::\\   \\::/    /\\::/   |::::\\  /:::|____|\\:::\\    \\     /:::|____||:::|____\\     /:::/    /");
    gotoligcol(18,5);
    printf(" \\/_____/\\:::\\/:::/    /  \\:::\\   \\:::\\   \\/____/  \\/____|:::::\\/:::/    /  \\:::\\    \\   /:::/    /  \\:::\\    \\   /:::/    / ");
    gotoligcol(19,5);
    printf("          \\::::::/    /    \\:::\\   \\:::\\    \\            |:::::::::/    /    \\:::\\    \\ /:::/    /    \\:::\\    \\ /:::/    /  ");
    gotoligcol(20,5);
    printf("           \\::::/    /      \\:::\\   \\:::\\____\\           |::|\\::::/    /      \\:::\\    /:::/    /      \\:::\\    /:::/    /   ");
    gotoligcol(21,5);
    printf("            \\::/____/        \\:::\\   \\::/    /           |::| \\::/____/        \\:::\\  /:::/    /        \\:::\\__/:::/    /    ");
    gotoligcol(22,5);
    printf("             ~~               \\:::\\   \\/____/            |::|  ~|               \\:::\\/:::/    /          \\::::::::/    /     ");
    gotoligcol(23,5);
    printf("                               \\:::\\    \\                |::|   |                \\::::::/    /            \\::::::/    /      ");
    gotoligcol(24,5);
    printf("                                \\:::\\____\\               \\::|   |                 \\::::/    /              \\::::/    /       ");
    gotoligcol(25,5);
    printf("                                 \\::/    /                \\:|   |                  \\::/____/                \\::/____/        ");
    gotoligcol(26,5);
    printf("                                  \\/____/                  \\|___|                   ~~                       ~~              ");


    Sleep(150);
    system("color 20");
    Sleep(150);
    system("color 02");
    Sleep(150);
    system("color 20");
    Sleep(150);
    system("color 02");
    Sleep(150);



    // Sleep(5000);

}



void aide()
{

    system("cls");

    gotoligcol(0,0);
    Color(10,0);
    printf("\n\n\t\t\t   ______ _____ _    _ _______  ______      _______ _     _ _______ _     _  _____ \n");
    printf("\t\t\t  |_____/   |    \\  /  |______ |_____/      |______ |_____| |  |  | |     | |_____]\n");
    printf("\t\t\t  |    \\_ __|__   \\/   |______ |    \\_      ______| |     | |  |  | |_____| |      \n");
    printf("\t\t\t____________________________________________________________________________________\n\n\n\n\n\n\n\n\n");
    Color(2,0);

    gotoligcol(12,25);
    printf("Le principe du jeu est de faire evoluer un vaisseau dans un univers horizontal ");
    gotoligcol(14,25);
    printf("et de simuler le vol du vaisseau en deplacant regulierement l'univers de la droite");
    gotoligcol(16,25);
    printf("vers la gauche .Votre vaisseau le +000  peut monter, descendre, avancer reculer ");
    gotoligcol(18,25);
    printf("a l'aide des touches : 1,2,3,4,6,7,8,9 ou A,Z,E,Q,D,W,X,C ou Q,W,E,A,X,D en fonction ");
    gotoligcol(20,25);
    printf("du type de clavier choisi dans les options.Il peut egalement tirer devant");
    gotoligcol(22,25);
    printf("lui des lasers par appui sur la barre d'espace (appui continu ou intermittent).");
    gotoligcol(27,25);
    printf("Le decor ou evolue votre vaisseau peut contenir des obstacles (etoiles),");
    gotoligcol(29,25);
    printf("que vous devrez eviter en deplacant le vaisseau sous peine de perdre des vies. ");
    gotoligcol(31,25);
    printf("Votre vaisseau peut egalement etre confronte a des escouades d'ennemis les {{{{{ ");
    gotoligcol(33,25);
    printf("qui volent a sa rencontre et eventuellement lui tire dessus.");
    gotoligcol(38,25);
    printf("En volant, votre vaisseau peut intercepter des bonus flottants qui peuvent  ");
    gotoligcol(40,25);
    printf("supplementaire, ou augmenter votre score , ou vous apportez une competence  ");
    gotoligcol(42,25);
    printf("vous apporter une viespeciale au niveau de vos tirs.Votre score augmentea en  ");
    gotoligcol(44,25);
    printf("fonction du nombred'enemis tues,de votre progression dans le jeu ou encore des ");
    gotoligcol(46,25);
    printf("bonus interceptes lors de votre vol.");

    gotoligcol(50,25);
    printf("Appuyez sur une touche pour revenir au menu :)");
    playdemo();





}

void endofgame(int score)
{
    system("cls");


    gotoligcol(DECAL_LIG,DECAL_COL);
    printf("Bravo ! vous avez reussi a finir ce jeu, et je sais bien que ce n'etait pas donner =) vous n avez pas tricher au moins ? ");
    gotoligcol(DECAL_LIG+1,DECAL_COL);
    printf("votre scores est de : %d felicitation !!! :)",score);

}

void gen_decor(int niveau)
{


    char story1[]="Bonjour valeureux navigateur, vous etes volontaire pour cette mission de haut risque, comme vous le savez la menace est toujours presente, les envahisseurs utilisent leur engins aquatiques pour passer par les tunnels souterrains et attaquer aquacity, rendez vous tout d'abord au tunnel nord et debarassez nous du seigneur krah qui y reside. Mefiez vous avant d'arriver a lui vous croiserez sans doute de nombreux ennemis! Courage , et revenez moi vivant pour d'autre missions.";

    char story2[]="Vous avez survecu a la menace que representait Krah , je vous en felicite! Mais vous n'avez pas le temps de vous reposer sur vos lauriers , en effet son frere Krih a affreter un autre engin de guerre et s'apprete a attaquer la porte ouest , vous connaissez votre tache !";
    char story3[]="Je ne peut que remarquer que Krih fut une simple formalite pour vous , il semblerait que vous ayez grandement progresser , que penseriez vous si je vous demandais d'allez affronter Kraboss dans les tunnels du sud? Allez soldat que faites vous encore ici ! Direction le sud ";
    char story4[]="Vous avez survecu a la menace que representait Krah , je vous en felicite! Mais vous n'avez pas le temps de vous reposer sur vos lauriers , en effet son frere Krih a affreter un autre engin de guerre et s'apprete a attaquer la porte ouest , vous connaissez votre tache !";
    char story5[]="Vous avez survecu a la menace que representait Krah , je vous en felicite! Mais vous n'avez pas le temps de vous reposer sur vos lauriers , en effet son frere Krih a affreter un autre engin de guerre et s'apprete a attaquer la porte ouest , vous connaissez votre tache !";

    char* story;

    int i;


    switch(niveau)
    {
    case 1:
        story=(char*)malloc(sizeof(char)*(strlen(story1)+2));
        story=story1;
        break;
    case 2:
        story=(char*)malloc(sizeof(char)*(strlen(story2)+2));
        story=story2;
        break;
    case 3:
        story=(char*)malloc(sizeof(char)*(strlen(story2)+2));
        story=story3;
        break;
    case 4:
        story=(char*)malloc(sizeof(char)*(strlen(story2)+2));
        story=story4;
        break;
    case 5:
        story=(char*)malloc(sizeof(char)*(strlen(story2)+2));
        story=story5;
        break;

        // default:
        // story=(char*)malloc(sizeof(char)*(strlen(story2)+2));
        // story=story2;
        // break;
    }


    //generation du decor fixe
    gotoligcol(0,0);
    Color(10,0);
    printf("\n\n\t\t\t       ______ _____ _    _ _______  ______      _______ _     _ _______ _     _  _____ \n");
    printf("\t\t\t      |_____/   |    \\  /  |______ |_____/      |______ |_____| |  |  | |     | |_____]\n");
    printf("\t\t\t      |    \\_ __|__   \\/   |______ |    \\_      ______| |     | |  |  | |_____| |      \n");
    printf("\t\t\t    ____________________________________________________________________________________\n\n\n\n\n\n\n\n\n");
    Color(2,0);

    typing(story,DECAL_LIG,DECAL_COL,79);

    system("cls");

    gotoligcol(0,0);
    Color(10,0);
    printf("\n\n\t\t\t       ______ _____ _    _ _______  ______      _______ _     _ _______ _     _  _____ \n");
    printf("\t\t\t      |_____/   |    \\  /  |______ |_____/      |______ |_____| |  |  | |     | |_____]\n");
    printf("\t\t\t      |    \\_ __|__   \\/   |______ |    \\_      ______| |     | |  |  | |_____| |      \n");
    printf("\t\t\t    ____________________________________________________________________________________\n\n\n\n\n\n\n\n\n");
    Color(2,0);
    gotoligcol(DECAL_LIG-1,DECAL_COL-1);

    for(i=0; i<82; i++) printf("%c",219);//cadre sup

    for(i=0; i<30; i++) //cadre lateraux
    {
        gotoligcol(DECAL_LIG+i,DECAL_COL-1);
        printf("%c",219);
        gotoligcol(DECAL_LIG+i,DECAL_COL+80);
        printf("%c",219);

    }
    gotoligcol(DECAL_LIG+30,DECAL_COL-1);
    for(i=0; i<82; i++) //cadre inf
        printf("%c",219);




}


