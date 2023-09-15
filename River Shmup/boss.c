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
//#include "boss.h"


void Boss(int keyboard,int* boss,int maskship[30][80],int maskwall[30][80],int maskenemy[30][80],int maskshoota[30][80],int maskshoote[30][80],int* niveau,int* life,int* score,int* progress,int* bonus,int* coord,int coordenem[10][2],int sound)
{

//declaration des ressources
    int maskshootb_1[30][80]= {0}, maskshootb_2[30][80]= {0},maskshootb_3[30][80]= {0},maskshootb_4[30][80]= {0};
    char maskboss[30][80]= {0};
    char bosstamp[5][22]= {0};
    int bosslife;
    int coordboss[2];
    int  maskshootb[30][80];
    int bossprogress;
    char stamp[100];
    int key;
    int i,j,m;

    if(*boss)
    {
        //initialisation generale du boss


        bosslife=200*(*boss);

        bossprogress=0;




        switch(*boss)
        {
        case 1:
            //initialisation spécifique
            coordboss[0]=20; //haut
            coordboss[1]=25;//bas
            //mise en place du boss en memoire

            sprintf(stamp,"  /\\_________");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[0][j]=stamp[j];

            sprintf(stamp,"-(\\          \\");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[1][j]=stamp[j];

            sprintf(stamp,"  //^^\\ krah  \\  //");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[2][j]=stamp[j];

            sprintf(stamp,"{O)-----------|-+==");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[3][j]=stamp[j];

            sprintf(stamp,"   \\\\________/   \\\\");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[4][j]=stamp[j];



            gotoligcol(30+DECAL_LIG+10,0);


            //apparition du boss

            for(j=0; j<22; j++) // 20 tour different pour l apparition
            {
                decalmapL_B(maskboss,1);
                decalmapR(maskshoota,1);


                for(m=0; m<5; m++) //hauteur
                {
                    maskboss[20+m][79]=bosstamp[m][j];
                }

                printmap_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4);
                //recordemo_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4,*life,*progress,*score);

                Sleep(25);

            }




            j=1;//variable pour alternée
            do//boucle de jeu du boss
            {
                bossprogress++;
                //deplacement du boss
                if(1/*bossprogress%2*/)
                {


                    if(j)
                    {
                        decalmapU_B(maskboss,1);
                        coordboss[0]--;//haut du vaisseau
                        coordboss[1]--;//bas du vaisseau
                        if(coordboss[0]==1)//si on arrive tout en haut
                        {
                            j=0;
                            bossprogress++;// on decale les etoiles pour pas pouvoir rester sur place
                        }

                    }
                    else
                    {
                        decalmapD_B(maskboss,1);
                        coordboss[0]++;
                        coordboss[1]++;
                        if(coordboss[1]==28)//si le boss arive en bas
                        {
                            j=1;
                            bossprogress++;// on decale les etoiles pour pas pouvoir rester sur place

                        }
                    }
                }

                //faire tirer la tourelle du haut
                if(!(bossprogress%3))
                    maskshoote[coordboss[0]+1][57]=1;

                //fait tirer la tourelle du bas
                if(!(bossprogress%150))
                    maskshootb[coordboss[0]+3][57]=2;
                //fait tirer les mines

                if(!(bossprogress%4))
                    shootenemy_B(maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4);
                colision_B(coord,coordenem,maskship,maskwall,maskenemy,maskshoote,maskshoota,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4,&bosslife,life,score,sound);

                moveship(coord,maskship,key,keyboard);



                shoota(coord,maskshoota,key,bonus);
                key=0;//on empeche d'avoir le tir bloquer
                printmap_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4);
                //recordemo_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4,*life,*progress,*score);
                if(kbhit())
                    key=getch();
                decalmapR(maskshoota,1);
                if(!(bossprogress%5))//1 fois sur 5 on fait le decalage des mines pour qu'elle aille plus lentement
                    decalmapL(maskshootb,1);

                decalmapL(maskshoote,1);

                decalmapL(maskshootb_1,1);
                decalmapU(maskshootb_1,1);
                decalmapU(maskshootb_2,1);
                decalmapR(maskshootb_2,1);
                decalmapD(maskshootb_3,1);
                decalmapR(maskshootb_3,1);
                decalmapL(maskshootb_4,1);
                decalmapD(maskshootb_4,1);


                // printf("%d    %d",bosslife,*niveau);

                if(bosslife<=0)
                {
                    (*niveau)++;
                    init_newgame(maskship,maskwall,maskenemy,maskshoota,maskshoote,coordenem,niveau,life,score,progress,bonus,boss,coord);


                    cleantab_b(maskboss);
                    cleantab(maskshootb);
                    cleantab(maskshootb_1);
                    cleantab(maskshootb_2);
                    cleantab(maskshootb_3);
                    cleantab(maskshootb_4);
                    (*score)+=500;
                    (*boss)=0;
                }


//affichage du score





                gotoligcol(DECAL_LIG+32,DECAL_COL+54);
                printf("Vie: ");
                Color(13,0);
                for(i=0; i<*life; i++)
                    printf("%c",3);
                Color(10,0);
                //effacer les caracteres residuels
                for(i=0; i<(10-*life); i++)
                {
                    gotoligcol(DECAL_LIG+32,DECAL_COL+68-i);
                    printf(" ");
                }

                /*gotoligcol(DECAL_LIG+34,DECAL_COL+34);
                printf("krah: ");
                for(i=0; i<(bosslife/(20*boss)); i++)
                    printf("%c",3);
                //effacer les caracteres residuels
                for(i=0; i<(10-(bosslife/(20*boss))); i++)
                {
                    gotoligcol(DECAL_LIG+34,DECAL_COL+48-i);
                    printf(" ");
                }*/

            }
            while((bosslife>0)&&(*life));



            break;






        case 5:


            //initialisation spécifique
            coordboss[0]=20; //haut
            coordboss[1]=25;//bas
            //mise en place du boss en memoire

            sprintf(stamp,"  /\\_________");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[0][j]=stamp[j];

            sprintf(stamp,"-(\\          \\");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[1][j]=stamp[j];

            sprintf(stamp,"  //oo\\ krih  \\  //");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[2][j]=stamp[j];

            sprintf(stamp,"{O)-----------|-+==");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[3][j]=stamp[j];

            sprintf(stamp,"   \\\\________/   \\\\");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[4][j]=stamp[j];



            gotoligcol(30+DECAL_LIG+10,0);


            //apparition du boss

            for(j=0; j<22; j++) // 20 tour different pour l apparition
            {
                decalmapL_B(maskboss,1);
                decalmapR(maskshoota,1);


                for(m=0; m<5; m++) //hauteur
                {
                    maskboss[20+m][79]=bosstamp[m][j];
                }

                printmap_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4);
                //recordemo_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4,*life,*progress,*score);

                Sleep(25);

            }




            j=1;//variable pour alternée
            do//boucle de jeu du boss
            {
                bossprogress++;
                //deplacement du boss
                if(1/*bossprogress%2*/)
                {


                    if(j)
                    {
                        decalmapU_B(maskboss,1);
                        coordboss[0]--;//haut du vaisseau
                        coordboss[1]--;//bas du vaisseau
                        if(coordboss[0]==1)//si on arrive tout en haut
                        {
                            j=0;
                            bossprogress++;// on decale les etoiles pour pas pouvoir rester sur place
                        }

                    }
                    else
                    {
                        decalmapD_B(maskboss,1);
                        coordboss[0]++;
                        coordboss[1]++;
                        if(coordboss[1]==28)//si le boss arive en bas
                        {
                            j=1;
                            bossprogress++;// on decale les etoiles pour pas pouvoir rester sur place

                        }
                    }
                }

                //faire tirer la tourelle du haut
                if(!(bossprogress%3))
                    maskshoote[coordboss[0]+1][57]=1;

                //fait tirer la tourelle du bas
                if(!(bossprogress%150))
                    maskshootb[coordboss[0]+3][57]=2;
                //fait tirer les mines

                if(!(bossprogress%4))
                    shootenemy_B(maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4);
                colision_B(coord,coordenem,maskship,maskwall,maskenemy,maskshoote,maskshoota,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4,&bosslife,life,score,sound);

                moveship(coord,maskship,key,keyboard);



                shoota(coord,maskshoota,key,bonus);
                key=0;//on empeche d'avoir le tir bloquer
                printmap_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4);
                //recordemo_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4,*life,*progress,*score);
                if(kbhit())
                    key=getch();
                decalmapR(maskshoota,1);
                if(!(bossprogress%5))//1 fois sur 5 on fait le decalage des mines pour qu'elle aille plus lentement
                    decalmapL(maskshootb,1);

                decalmapL(maskshoote,1);

                decalmapL(maskshootb_1,1);
                decalmapU(maskshootb_1,1);
                decalmapU(maskshootb_2,1);
                decalmapR(maskshootb_2,1);
                decalmapD(maskshootb_3,1);
                decalmapR(maskshootb_3,1);
                decalmapL(maskshootb_4,1);
                decalmapD(maskshootb_4,1);


                // printf("%d    %d",bosslife,*niveau);
                if(bosslife<=0)
                {
                    (*niveau)++;
                    init_newgame(maskship,maskwall,maskenemy,maskshoota,maskshoote,coordenem,niveau,life,score,progress,bonus,boss,coord);

                    cleantab_b(maskboss);
                    cleantab(maskshootb);
                    cleantab(maskshootb_1);
                    cleantab(maskshootb_2);
                    cleantab(maskshootb_3);
                    cleantab(maskshootb_4);
                    (*score)+=500;
                    (*boss)=0;

                }


//affichage du score





                gotoligcol(DECAL_LIG+32,DECAL_COL+54);
                printf("Vie: ");
                Color(13,0);
                for(i=0; i<*life; i++)
                    printf("%c",3);
                Color(10,0);
                //effacer les caracteres residuels
                for(i=0; i<(10-*life); i++)
                {
                    gotoligcol(DECAL_LIG+32,DECAL_COL+68-i);
                    printf(" ");
                }

            }
            while((bosslife>0)&&(*life));




            break;


        case 4:


            //initialisation spécifique
            coordboss[0]=20; //haut
            coordboss[1]=25;//bas
            //mise en place du boss en memoire

            sprintf(stamp,"  /\\_________");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[0][j]=stamp[j];

            sprintf(stamp,"-(\\          \\");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[1][j]=stamp[j];

            sprintf(stamp,"  //oo\\ krih  \\  //");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[2][j]=stamp[j];

            sprintf(stamp,"{O)-----------|-+==");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[3][j]=stamp[j];

            sprintf(stamp,"   \\\\________/   \\\\");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[4][j]=stamp[j];



            gotoligcol(30+DECAL_LIG+10,0);


            //apparition du boss

            for(j=0; j<22; j++) // 20 tour different pour l apparition
            {
                decalmapL_B(maskboss,1);
                decalmapR(maskshoota,1);


                for(m=0; m<5; m++) //hauteur
                {
                    maskboss[20+m][79]=bosstamp[m][j];
                }

                printmap_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4);
                //recordemo_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4,*life,*progress,*score);

                Sleep(25);

            }




            j=1;//variable pour alternée
            do//boucle de jeu du boss
            {
                bossprogress++;
                //deplacement du boss
                if(1/*bossprogress%2*/)
                {


                    if(j)
                    {
                        decalmapU_B(maskboss,1);
                        coordboss[0]--;//haut du vaisseau
                        coordboss[1]--;//bas du vaisseau
                        if(coordboss[0]==1)//si on arrive tout en haut
                        {
                            j=0;
                            bossprogress++;// on decale les etoiles pour pas pouvoir rester sur place
                        }

                    }
                    else
                    {
                        decalmapD_B(maskboss,1);
                        coordboss[0]++;
                        coordboss[1]++;
                        if(coordboss[1]==28)//si le boss arive en bas
                        {
                            j=1;
                            bossprogress++;// on decale les etoiles pour pas pouvoir rester sur place

                        }
                    }
                }

                //faire tirer la tourelle du haut
                if(!(bossprogress%3))
                    maskshoote[coordboss[0]+1][57]=1;

                //fait tirer la tourelle du bas
                if(!(bossprogress%150))
                    maskshootb[coordboss[0]+3][57]=2;
                //fait tirer les mines

                if(!(bossprogress%4))
                    shootenemy_B(maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4);
                colision_B(coord,coordenem,maskship,maskwall,maskenemy,maskshoote,maskshoota,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4,&bosslife,life,score,sound);

                moveship(coord,maskship,key,keyboard);



                shoota(coord,maskshoota,key,bonus);
                key=0;//on empeche d'avoir le tir bloquer
                printmap_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4);
                //recordemo_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4,*life,*progress,*score);
                if(kbhit())
                    key=getch();
                decalmapR(maskshoota,1);
                if(!(bossprogress%5))//1 fois sur 5 on fait le decalage des mines pour qu'elle aille plus lentement
                    decalmapL(maskshootb,1);

                decalmapL(maskshoote,1);

                decalmapL(maskshootb_1,1);
                decalmapU(maskshootb_1,1);
                decalmapU(maskshootb_2,1);
                decalmapR(maskshootb_2,1);
                decalmapD(maskshootb_3,1);
                decalmapR(maskshootb_3,1);
                decalmapL(maskshootb_4,1);
                decalmapD(maskshootb_4,1);


                // printf("%d    %d",bosslife,*niveau);
                if(bosslife<=0)
                {
                    (*niveau)++;
                    init_newgame(maskship,maskwall,maskenemy,maskshoota,maskshoote,coordenem,niveau,life,score,progress,bonus,boss,coord);

                    cleantab_b(maskboss);
                    cleantab(maskshootb);
                    cleantab(maskshootb_1);
                    cleantab(maskshootb_2);
                    cleantab(maskshootb_3);
                    cleantab(maskshootb_4);
                    (*score)+=500;
                    (*boss)=0;

                }


//affichage du score





                gotoligcol(DECAL_LIG+32,DECAL_COL+54);
                printf("Vie: ");
                Color(13,0);
                for(i=0; i<*life; i++)
                    printf("%c",3);
                Color(10,0);
                //effacer les caracteres residuels
                for(i=0; i<(10-*life); i++)
                {
                    gotoligcol(DECAL_LIG+32,DECAL_COL+68-i);
                    printf(" ");
                }

            }
            while((bosslife>0)&&(*life));




            break;

        case 3:


            //initialisation spécifique
            coordboss[0]=20; //haut
            coordboss[1]=25;//bas
            //mise en place du boss en memoire

            sprintf(stamp,"  /\\_________");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[0][j]=stamp[j];

            sprintf(stamp,"-(\\          \\");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[1][j]=stamp[j];

            sprintf(stamp,"  //oo\\ krih  \\  //");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[2][j]=stamp[j];

            sprintf(stamp,"{O)-----------|-+==");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[3][j]=stamp[j];

            sprintf(stamp,"   \\\\________/   \\\\");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[4][j]=stamp[j];



            gotoligcol(30+DECAL_LIG+10,0);


            //apparition du boss

            for(j=0; j<22; j++) // 20 tour different pour l apparition
            {
                decalmapL_B(maskboss,1);
                decalmapR(maskshoota,1);


                for(m=0; m<5; m++) //hauteur
                {
                    maskboss[20+m][79]=bosstamp[m][j];
                }

                printmap_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4);
                //recordemo_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4,*life,*progress,*score);

                Sleep(25);

            }




            j=1;//variable pour alternée
            do//boucle de jeu du boss
            {
                bossprogress++;
                //deplacement du boss
                if(1/*bossprogress%2*/)
                {


                    if(j)
                    {
                        decalmapU_B(maskboss,1);
                        coordboss[0]--;//haut du vaisseau
                        coordboss[1]--;//bas du vaisseau
                        if(coordboss[0]==1)//si on arrive tout en haut
                        {
                            j=0;
                            bossprogress++;// on decale les etoiles pour pas pouvoir rester sur place
                        }

                    }
                    else
                    {
                        decalmapD_B(maskboss,1);
                        coordboss[0]++;
                        coordboss[1]++;
                        if(coordboss[1]==28)//si le boss arive en bas
                        {
                            j=1;
                            bossprogress++;// on decale les etoiles pour pas pouvoir rester sur place

                        }
                    }
                }

                //faire tirer la tourelle du haut
                if(!(bossprogress%3))
                    maskshoote[coordboss[0]+1][57]=1;

                //fait tirer la tourelle du bas
                if(!(bossprogress%150))
                    maskshootb[coordboss[0]+3][57]=2;
                //fait tirer les mines

                if(!(bossprogress%4))
                    shootenemy_B(maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4);
                colision_B(coord,coordenem,maskship,maskwall,maskenemy,maskshoote,maskshoota,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4,&bosslife,life,score,sound);

                moveship(coord,maskship,key,keyboard);



                shoota(coord,maskshoota,key,bonus);
                key=0;//on empeche d'avoir le tir bloquer
                printmap_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4);
                //recordemo_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4,*life,*progress,*score);
                if(kbhit())
                    key=getch();
                decalmapR(maskshoota,1);
                if(!(bossprogress%5))//1 fois sur 5 on fait le decalage des mines pour qu'elle aille plus lentement
                    decalmapL(maskshootb,1);

                decalmapL(maskshoote,1);

                decalmapL(maskshootb_1,1);
                decalmapU(maskshootb_1,1);
                decalmapU(maskshootb_2,1);
                decalmapR(maskshootb_2,1);
                decalmapD(maskshootb_3,1);
                decalmapR(maskshootb_3,1);
                decalmapL(maskshootb_4,1);
                decalmapD(maskshootb_4,1);


                // printf("%d    %d",bosslife,*niveau);
                if(bosslife<=0)
                {
                    (*niveau)++;
                    init_newgame(maskship,maskwall,maskenemy,maskshoota,maskshoote,coordenem,niveau,life,score,progress,bonus,boss,coord);

                    cleantab_b(maskboss);
                    cleantab(maskshootb);
                    cleantab(maskshootb_1);
                    cleantab(maskshootb_2);
                    cleantab(maskshootb_3);
                    cleantab(maskshootb_4);
                    (*score)+=500;
                    (*boss)=0;

                }





//affichage du score





                gotoligcol(DECAL_LIG+32,DECAL_COL+54);
                printf("Vie: ");
                Color(13,0);
                for(i=0; i<*life; i++)
                    printf("%c",3);
                Color(10,0);
                //effacer les caracteres residuels
                for(i=0; i<(10-*life); i++)
                {
                    gotoligcol(DECAL_LIG+32,DECAL_COL+68-i);
                    printf(" ");
                }

            }
            while((bosslife>0)&&(*life));




            break;



        case 2:


            //initialisation spécifique
            coordboss[0]=20; //haut
            coordboss[1]=25;//bas
            //mise en place du boss en memoire

            sprintf(stamp,"  /\\_________");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[0][j]=stamp[j];

            sprintf(stamp,"-(\\          \\");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[1][j]=stamp[j];

            sprintf(stamp,"  //oo\\ krih  \\  //");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[2][j]=stamp[j];

            sprintf(stamp,"{O)-----------|-+==");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[3][j]=stamp[j];

            sprintf(stamp,"   \\\\________/   \\\\");
            for(j=0; j<=strlen(stamp); j++)
                bosstamp[4][j]=stamp[j];



            gotoligcol(30+DECAL_LIG+10,0);


            //apparition du boss

            for(j=0; j<22; j++) // 20 tour different pour l apparition
            {
                decalmapL_B(maskboss,1);
                decalmapR(maskshoota,1);


                for(m=0; m<5; m++) //hauteur
                {
                    maskboss[20+m][79]=bosstamp[m][j];
                }

                printmap_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4);
                //recordemo_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4,*life,*progress,*score);

                Sleep(25);

            }




            j=1;//variable pour alternée
            do//boucle de jeu du boss
            {
                bossprogress++;
                //deplacement du boss
                if(1/*bossprogress%2*/)
                {


                    if(j)
                    {
                        if(bossprogress%3)
                        {
                            decalmapU_B(maskboss,1);
                            coordboss[0]--;//haut du vaisseau
                            coordboss[1]--;//bas du vaisseau
                        }
                        else
                        {
                            decalmapD_B(maskboss,1);
                            coordboss[0]++;//haut du vaisseau
                            coordboss[1]++;//bas du vaisseau
                        }



                        if(coordboss[0]==1)//si on arrive tout en haut
                        {
                            j=0;
                            bossprogress++;// on decale les etoiles pour pas pouvoir rester sur place
                        }

                    }
                    else
                    {

                        if(bossprogress%3)
                        {
                            decalmapD_B(maskboss,1);
                            coordboss[0]++;
                            coordboss[1]++;
                        }
                        else
                        {
                            decalmapU_B(maskboss,1);
                            coordboss[0]--;//haut du vaisseau
                            coordboss[1]--;//bas du vaisseau
                        }

                        if(coordboss[1]==28)//si le boss arive en bas
                        {
                            j=1;
                            bossprogress++;// on decale les etoiles pour pas pouvoir rester sur place

                        }
                    }
                }

                //faire tirer la tourelle du haut
                if(!(bossprogress%3))
                    maskshoote[coordboss[0]+1][57]=1;

                //fait tirer la tourelle du bas
                if(!(bossprogress%130))
                    maskshootb[coordboss[0]+3][57]=2;
                //fait tirer les mines

                if(!(bossprogress%4))
                    shootenemy_B(maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4);
                colision_B(coord,coordenem,maskship,maskwall,maskenemy,maskshoote,maskshoota,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4,&bosslife,life,score,sound);

                moveship(coord,maskship,key,keyboard);



                shoota(coord,maskshoota,key,bonus);
                key=0;//on empeche d'avoir le tir bloquer
                printmap_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4);
                //recordemo_B(maskship,maskwall,maskenemy,maskshoota,maskshoote,maskboss,maskshootb,maskshootb_1,maskshootb_2,maskshootb_3,maskshootb_4,*life,*progress,*score);
                if(kbhit())
                    key=getch();
                decalmapR(maskshoota,1);
                if(!(bossprogress%5))//1 fois sur 5 on fait le decalage des mines pour qu'elle aille plus lentement
                    decalmapL(maskshootb,1);

                decalmapL(maskshoote,1);

                decalmapL(maskshootb_1,1);
                decalmapU(maskshootb_1,1);
                decalmapU(maskshootb_2,1);
                decalmapR(maskshootb_2,1);
                decalmapD(maskshootb_3,1);
                decalmapR(maskshootb_3,1);
                decalmapL(maskshootb_4,1);
                decalmapD(maskshootb_4,1);


                // printf("%d    %d",bosslife,*niveau);
                if(bosslife<=0)
                {
                    (*niveau)++;
                    init_newgame(maskship,maskwall,maskenemy,maskshoota,maskshoote,coordenem,niveau,life,score,progress,bonus,boss,coord);

                    cleantab_b(maskboss);
                    cleantab(maskshootb);
                    cleantab(maskshootb_1);
                    cleantab(maskshootb_2);
                    cleantab(maskshootb_3);
                    cleantab(maskshootb_4);
                    (*score)+=500;
                    (*boss)=0;

                }


//affichage du score





                gotoligcol(DECAL_LIG+32,DECAL_COL+54);
                printf("Vie: ");
                Color(13,0);
                for(i=0; i<*life; i++)
                    printf("%c",3);
                Color(10,0);
                //effacer les caracteres residuels
                for(i=0; i<(10-*life); i++)
                {
                    gotoligcol(DECAL_LIG+32,DECAL_COL+68-i);
                    printf(" ");
                }

            }
            while((bosslife>0)&&(*life));




            break;



        }












    }

}

