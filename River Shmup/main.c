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




















int main()
{



    // Ressources
    int coordenem[11][2]= {0};
    int maskship[30][80]= {0},maskwall[30][80],maskenemy[30][80]= {0},maskshoota[30][80]= {0},maskshoote[30][80]= {0},maskbonus[30][80]= {0};
    int coord[2]; //coord[0]=colone coord[1]=ligne
    char joueur[100];

    int i,j,k,m,key,life,choice,progress,bonus=0,score,boss=0;

    int keyboard=0;
    int sound=0;
    int niveau=1;
    char stamp[100];

    system("cls");
    system("color 02");
    system("mode 140, 80");


    srand(time(NULL));
    ShowCursor(-1);

    do
    {


        choice=menu();

        switch(choice)
        {

        case 0:
            niveau=1;

            do
            {



                init_newgame(maskship,maskwall,maskenemy,maskshoota,maskshoote,coordenem,&niveau,&life,&score,&progress,&bonus,&boss,coord);

                //boucle du jeu


                do//boucle de jeu
                {


                    colision(coord,coordenem,maskship,maskwall,maskenemy,maskshoote,maskshoota,maskbonus,&life,&score,&bonus,sound);
                    moveship(coord,maskship,key,keyboard);



                    shoota(coord,maskshoota,key,&bonus);
                    key=0;//on empeche d'avoir le tir bloquer}

                    if(!(progress%5))//une case sur 5
                        if((!(rand()%(6-niveau)))&&(coordenem[0][0]<5+niveau)&&(400+niveau*100-progress>80))
                            createnemy(maskenemy,coord,maskwall,niveau,coordenem);

                    createbonus(maskbonus,maskwall);

                    moveenemy(maskenemy,coordenem,maskwall);

                    if(!(rand()%4))
                        shootenemy(coordenem,maskshoote);

                    printmap(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskbonus);
                    //recordemo(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskbonus,life,progress,score);

                    //effet battement battement d aile / nage pour ordi lent sert egalement au deboggage pour verifier les coordonnées
                    /* for(i=1; i<=coordenem[0][0]; i++)
                     {
                         gotoligcol(DECAL_LIG+coordenem[i][1],DECAL_COL+coordenem[i][0]);
                         printf("M");

                     }

                            */


                    decalmapL(maskwall,1);
                    decalmapR(maskshoota,1);

                    decalmapL(maskenemy,1);
                    decalmapL(maskbonus,1);

                    decalcoordenem(coordenem);

                    refreshcoordenem(coordenem);
                    decalmapL(maskshoote,2);


                    if(400+niveau*100-progress>80)
                        createwall(maskwall,niveau);

                    if((400+niveau*100-progress)<=0)
                    {

                        boss=niveau;
                    }


                    Boss(keyboard,&boss,maskship,maskwall,maskenemy,maskshoota,maskshoote,&niveau,&life,&score,&progress,&bonus,&coord,coordenem,sound);






                    if(kbhit())
                        key=getch();

                    //affichage du score




                    gotoligcol(DECAL_LIG+32,DECAL_COL+4);
                    printf("score: %d",score);
                    gotoligcol(DECAL_LIG+32,DECAL_COL+24);
                    printf("distance du boss: %d",400+niveau*100-progress);
                    //effacer les caracters résiduels quand ca ratrécie
                    if(400+niveau-progress<100)
                        gotoligcol(DECAL_LIG+32,DECAL_COL+45);
                    printf(" ");
                    if(400+niveau-progress<10)
                        gotoligcol(DECAL_LIG+32,DECAL_COL+44);
                    printf(" ");
                    gotoligcol(DECAL_LIG+32,DECAL_COL+54);
                    printf("Vie: ");
                    Color(13,0);
                    for(i=0; i<life; i++)
                        printf("%c",3);
                    Color(10,0);
                    //effacer les caracteres residuels
                    for(i=0; i<(10-life); i++)
                    {
                        gotoligcol(DECAL_LIG+32,DECAL_COL+68-i);
                        printf(" ");
                    }

                    //avancement des variables
                    if(!boss)
                    {

                        progress++;
                        score++;
                    }


                }
                while((key!=27)&&(key!='p')&&(key!='P')&&(life>0));
                i=0;//on remet i a 0 pour ne pas quitter si une boucle de i etait sur 5

                if((key=='p')||(key=='p'))
                {
                    key=0;
                    gotoligcol(DECAL_LIG+12,DECAL_COL+35);
                    printf("Pause");
                    gotoligcol(DECAL_LIG+15,DECAL_COL+20);
                    printf("Appuyez sur P pour reprendre la partie");
                    do
                    {

                        if(kbhit())
                        {
                            //fflush(stdin);
                            key=getch();
                        }


                    }
                    while(key!='p');
                    key=0;
                    i=1;//on reprends la partie
                }

                if(key==27)//touche echap
                {

                    system("cls");
                    gotoligcol(0,0);
                    gotoligcol(DECAL_LIG+8,DECAL_COL+30);
                    printf("Voulez vous sauvegarder ?");
                    gotoligcol(DECAL_LIG+10,DECAL_COL+28);
                    printf("     * Oui        non");
                    i=0; //on place le curseur en memoire
                    do
                    {
                        key=0;
                        //fflush(stdin);
                        if(kbhit())
                            key=getch();
                        if(key)//anti clignotement
                        {
                            gotoligcol(DECAL_LIG+10,DECAL_COL+33+i*11);
                            printf(" ");
                        }
                        if(key=='6'||key==77)//position du curseur
                            i=1;
                        if(key=='4'||key==75)
                            i=0;
                        if(key)//anti clignotement
                        {
                            gotoligcol(DECAL_LIG+10,DECAL_COL+33+i*11);
                            printf("*");
                        }



                    }
                    while(key!=32&&key!=13);
                    //sauvegarde
                    if (i==0)
                    {
                        gotoligcol(25,50);
                        printf("Saisissez votre pseudo ---> ");
                        gets(joueur);
                        sauvegarde(&joueur,&score,&life,&progress,&niveau);
                    }


                    i=0;//pour quitter le jeu
                }



                if(life<=0)//si on a perdu
                {
                    loosebyshoot();
                    shighscore(&score);
                    key=0;
                }

            }
            while(i&&(life>0)); //on quitte le jeu

            break;

        case 1:


            do
            {



                init_newgame(maskship,maskwall,maskenemy,maskshoota,maskshoote,coordenem,&niveau,&life,&score,&progress,&bonus,&boss,coord);
                charge(&joueur,&score,&life,&progress,&niveau);

                //boucle du jeu


                do//boucle de jeu
                {


                    colision(coord,coordenem,maskship,maskwall,maskenemy,maskshoote,maskshoota,maskbonus,&life,&score,&bonus,sound);
                    moveship(coord,maskship,key,keyboard);



                    shoota(coord,maskshoota,key,&bonus);
                    key=0;//on empeche d'avoir le tir bloquer}

                    if(!(progress%5))//une case sur 5
                        if((!(rand()%(6-niveau)))&&(coordenem[0][0]<5+niveau)&&(400+niveau*100-progress>80))
                            createnemy(maskenemy,coord,maskwall,niveau,coordenem);

                    createbonus(maskbonus,maskwall);

                    moveenemy(maskenemy,coordenem,maskwall);

                    if(!(rand()%4))
                        shootenemy(coordenem,maskshoote);

                    printmap(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskbonus);

                    //effet battement battement d aile / nage pour ordi lent sert egalement au deboggage pour verifier les coordonnées
                    /* for(i=1; i<=coordenem[0][0]; i++)
                     {
                         gotoligcol(DECAL_LIG+coordenem[i][1],DECAL_COL+coordenem[i][0]);
                         printf("M");

                     }

                            */


                    decalmapL(maskwall,1);
                    decalmapR(maskshoota,1);

                    decalmapL(maskenemy,1);
                    decalmapL(maskbonus,1);

                    decalcoordenem(coordenem);

                    refreshcoordenem(coordenem);
                    decalmapL(maskshoote,2);


                    if(400+niveau*100-progress>80)
                        createwall(maskwall,niveau);

                    if((400+niveau*100-progress)<=0)
                    {

                        boss=niveau;
                    }

                    if(boss)
                    {

                        Boss(keyboard,&boss,maskship,maskwall,maskenemy,maskshoota,maskshoote,&niveau,&life,&score,&progress,&bonus,&coord,coordenem,sound);
                        boss=0;

                    }






                    if(kbhit())
                        key=getch();

                    //affichage du score




                    gotoligcol(DECAL_LIG+32,DECAL_COL+4);
                    printf("score: %d",score);
                    gotoligcol(DECAL_LIG+32,DECAL_COL+24);
                    printf("distance du boss: %d",400+niveau*100-progress);
                    //effacer les caracters résiduels quand ca ratrécie
                    if(400+niveau-progress<100)
                        gotoligcol(DECAL_LIG+32,DECAL_COL+45);
                    printf(" ");
                    if(400+niveau-progress<10)
                        gotoligcol(DECAL_LIG+32,DECAL_COL+44);
                    printf(" ");
                    if(400+niveau-progress<1)
                        gotoligcol(DECAL_LIG+32,DECAL_COL+43);
                    printf(" ");
                    gotoligcol(DECAL_LIG+32,DECAL_COL+54);
                    printf("Vie: ");
                    Color(13,0);
                    for(i=0; i<life; i++)
                        printf("%c",3);
                    Color(10,0);
                    //effacer les caracteres residuels
                    for(i=0; i<(10-life); i++)
                    {
                        gotoligcol(DECAL_LIG+32,DECAL_COL+68-i);
                        printf(" ");
                    }

                    //avancement des variables
                    if(!boss)
                    {

                        progress++;
                        score++;
                    }


                }
                while((key!=27)&&(key!='p')&&(key!='P')&&(life>0)&&(niveau<6));
                i=0;//on remet i a 0 pour ne pas quitter si une boucle de i etait sur 5

                if((key=='p')||(key=='P'))
                {
                    key=0;
                    gotoligcol(DECAL_LIG+12,DECAL_COL+35);
                    printf("Pause");
                    gotoligcol(DECAL_LIG+15,DECAL_COL+20);
                    printf("Appuyez sur P pour reprendre la partie");
                    do
                    {

                        if(kbhit())
                        {
                            //fflush(stdin);
                            key=getch();
                        }


                    }
                    while(key!='p');
                    key=0;
                    i=1;//on reprends la partie
                }

                if(key==27)//touche echap
                {

                    system("cls");
                    gotoligcol(0,0);
                    gotoligcol(DECAL_LIG+8,DECAL_COL+30);
                    printf("Voulez vous sauvegarder ?");
                    gotoligcol(DECAL_LIG+10,DECAL_COL+28);
                    printf("     * Oui        non");
                    i=0; //on place le curseur en memoire
                    do
                    {
                        key=0;
                        //fflush(stdin);
                        if(kbhit())
                            key=getch();
                        if(key)//anti clignotement
                        {
                            gotoligcol(DECAL_LIG+10,DECAL_COL+33+i*11);
                            printf(" ");
                        }
                        if(key=='6'||key==77)//position du curseur
                            i=1;
                        if(key=='4'||key==75)
                            i=0;
                        if(key)//anti clignotement
                        {
                            gotoligcol(DECAL_LIG+10,DECAL_COL+33+i*11);
                            printf("*");
                        }



                    }
                    while(key!=32&&key!=13);
                    //sauvegarde
                    if (i==0)
                    {
                        gotoligcol(25,50);
                        printf("Saisissez votre pseudo ---> ");
                        gets(joueur);
                        sauvegarde(&joueur,&score,&life,&progress,&niveau);
                    }


                    i=0;//pour quitter le jeu
                }

                if(niveau>=6)//si on gagne
                {
                    endofgame(score);
                    i=0;
                }



                if(life<=0)//si on a perdu
                {
                    loosebyshoot();
                    shighscore(&score);
                    key=0;
                    i=0;
                }

            }
            while(i); //on quitte le jeu

            break;
        case 2://options

            options(&keyboard,&sound);


            break;

        case 3://highscores

            showhighscore();

            break;

        case 4://aide
            aide();
            break;




        }


    }
    while(choice!=5);//si on es sur quitter et qu'on appui sur entree

    return 0;
}
