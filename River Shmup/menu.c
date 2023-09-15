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
int menu()
{
    int key,i;

    i=0; //sert pour la position de la fleche en face de notre choix

    system("cls");

    system("color 02");
    system("mode 140, 80");
    ShowCursor(0);

    do
    {

        gotoligcol(0,0);
        Color(10,0);
        printf("\n\n\t\t\t   ______ _____ _    _ _______  ______      _______ _     _ _______ _     _  _____ \n");
        printf("\t\t\t  |_____/   |    \\  /  |______ |_____/      |______ |_____| |  |  | |     | |_____]\n");
        printf("\t\t\t  |    \\_ __|__   \\/   |______ |    \\_      ______| |     | |  |  | |_____| |      \n");
        printf("\t\t\t____________________________________________________________________________________\n\n\n\n\n\n\n\n\n");
        Color(2,0);

        if(i==0)Color(10,0);
        printf("\t\t\t\t_  _ ____ _  _ _  _ ____ _    _    ____    ___  ____ ____ ___ _ ____    \n");
        printf("\t\t\t\t|\\ | |  | |  | |  | |___ |    |    |___    |__] |__| |__/  |  | |___    \n");
        printf("\t\t\t\t| \\| |__| |__|  \\/  |___ |___ |___ |___    |    |  | |  \\  |  | |___   \n\n\n\n\n");
        Color(2,0);
        if(i==1)Color(10,0);
        printf("\t\t\t\t   ____ _  _ ____ ____ ____ ____ ____    ___  ____ ____ ___ _ ____ \n");
        printf("\t\t\t\t   |    |__| |__| |__/ | __ |___ |__/    |__] |__| |__/  |  | |___\n");
        printf("\t\t\t\t   |___ |  | |  | |  \\ |__] |___ |  \\    |    |  | |  \\  |  | |___\n\n\n\n\n");
        Color(2,0);

        if(i==2)Color(10,0);
        printf("\t\t\t\t\t\t ____ ___  ___ _ ____ _  _ ____ \n");
        printf("\t\t\t\t\t\t |  | |__]  |  | |  | |\\ | [__  \n");
        printf("\t\t\t\t\t\t |__| |     |  | |__| | \\| ___] \n\n\n\n");
        Color(2,0);

        if(i==3)Color(10,0);
        printf("\t\t\t\t\t                                     \\       \n");
        printf("\t\t\t\t\t     ___  ____ _    _  _ ____ ____ ____ ____\n");
        printf("\t\t\t\t\t     |__] |__| |    |\\/| |__| |__/ |___ [__  \n");
        printf("\t\t\t\t\t     |    |  | |___ |  | |  | |  \\ |___ ___] \n\n\n\n\n");
        Color(2,0);

        if(i==4)Color(10,0);
        printf("\t\t\t\t\t\t\t____ _ ___  ____ \n");
        printf("\t\t\t\t\t\t\t|__| | |  \\ |___ \n");
        printf("\t\t\t\t\t\t\t|  | | |__/ |___ \n\n\n\n\n");
        Color(2,0);

        if(i==5)Color(10,0);
        printf("\t\t\t\t\t\t  ____ _  _ _ ___ ___ ____ ____ \n");
        printf("\t\t\t\t\t\t  |  | |  | |  |   |  |___ |__/ \n");
        printf("\t\t\t\t\t\t  |_\\| |__| |  |   |  |___ |  \\ \n\n\n\n\n");
        Color(2,0);



        Color(10,0);
        gotoligcol(14+(i*7),26);
        printf("  \\");
        gotoligcol(15+(i*7),26);
        printf("===>");
        gotoligcol(16+(i*7),26);
        printf("  /");



        gotoligcol(14+(i*7),102);
        printf(" /  ");
        gotoligcol(15+(i*7),102);
        printf("<===");
        gotoligcol(16+(i*7),102);
        printf(" \\ ");

        gotoligcol(0,0);
        printf(" ");


        playdemo();

        while(!kbhit());
        key=getch();
        gotoligcol(14+(i*7),26);
        printf("    ");
        gotoligcol(15+(i*7),26);
        printf("    ");
        gotoligcol(16+(i*7),26);
        printf("    ");



        gotoligcol(14+(i*7),102);
        printf("    ");
        gotoligcol(15+(i*7),102);
        printf("    ");
        gotoligcol(16+(i*7),102);
        printf("    ");
        if(key=='2'||key==80)
            i++;
        if(key=='8'||key==72)
            i--;
        if(i<0)
            i=0;
        if(i>5)
            i=5;
        Color(2,0);


    }
    while(key!=32&&key!=13);  //32=espace 13 = entree

    return i;

}

