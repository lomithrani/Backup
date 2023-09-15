#include <math.h>
#include <allegro.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "acteur.h"
#include "graph.h"
#include "perso.h"
#include "menu.h"
#include "sauvegarde.h"
#define PI 3.14159265

#define DEBUG(msg) {\
   set_gfx_mode(GFX_TEXT,0,0,0,0);\
   allegro_message("%s\n",msg);\
   allegro_exit();\
   exit(EXIT_FAILURE);\
}


void shighscore(int score)
{
    int i,rank=0,done=0;
    int highscore[10];
    int stamphighscore[10];
    char joueur[10][100];
    char stampjoueur[10][100];



    FILE*fp=NULL;
    fp=fopen("highscore.txt","r");

//on recupere les anciens highscore
    if(fp==NULL) printf("erreur");
    else

    {
        fscanf(fp,"%d %d %d %d %d %d %d %d %d %d",&highscore[0],&highscore[1],&highscore[2],&highscore[3],&highscore[4],&highscore[5],&highscore[6],&highscore[7],&highscore[8],&highscore[9]);
        fclose(fp);
    }

    for(i=0; i<10; i++)
    {
        stamphighscore[i]=highscore[i]; // on copie la chaine pour pouvoir la décalé sans probleme de repercussion
    }

    fp=fopen("nom.txt","r");
    if(fp==NULL) printf("erreur");
    else

    {
        fscanf(fp,"%s %s %s %s %s %s %s %s %s %s",joueur[0],joueur[1],joueur[2],joueur[3],joueur[4],joueur[5],joueur[6],joueur[7],joueur[8],joueur[9]);
        fclose(fp);
    }
    for(i=0; i<10; i++)
    {
        strcpy(stampjoueur[i],joueur[i]);
    }

//on traite le score actuel

    for(i=0; i<10; i++)
    {
        if(score>=highscore[i])
        {

            if(i<9)
            {

                highscore[i+1]=stamphighscore[i];

                strcpy(joueur[i+1],stampjoueur[i]);


                if(!done)
                {
                    highscore[i]=(score);
                    done=1;
                    rank=i;
                }
            }

        }
    }
    fflush(stdin);
        system("cls");

        allegro_message("veuillez vous dirigez vers la console svp");

    printf("Vous avez le %d eme meilleur score, entrez votre nom vous figurerez dans le palmares :",rank+1);
    fflush(stdin);
    for(i=0; i<100; i++) //on nettoie la chaine de caractere
        joueur[rank][i]=' ';
    gets(joueur[rank]);

    //blindage
    do
    {
        i=0;
        while((joueur[rank][i]!=' ')&&(i<100))
        {
            i++;
        }
        joueur[rank][i]='\0';

        if((i==100)||(i==0)||(i==1))
        {
            system("cls");

            printf("Le format de votre nom est incorrect:");

            printf("s'il vous plait saisissez un nom celui ci doit faire entre 1 et 6 caracteres et ne pas contenir d'espace:");
            gets(joueur[rank]);
        }

    }
    while((i==100)||(i==0)||(i==1));




    fp=fopen("highscore.txt","w");
    if(fp==NULL) printf("erreur");
    else

    {
        fprintf(fp,"%d %d %d %d %d %d %d %d %d %d",highscore[0],highscore[1],highscore[2],highscore[3],highscore[4],highscore[5],highscore[6],highscore[7],highscore[8],highscore[9]);
        fclose(fp);
    }

    fp=fopen("nom.txt","w");
    if(fp==NULL) printf("erreur");
    else

    {
        fprintf(fp,"%s %s %s %s %s %s %s %s %s %s",joueur[0],joueur[1],joueur[2],joueur[3],joueur[4],joueur[5],joueur[6],joueur[7],joueur[8],joueur[9]);
        fclose(fp);
    }

}



void showhighscore(BITMAP*buffer)
{


    int i,rank=0,done=0;
    int highscore[10];
    int stamphighscore[10];
    char joueur[10][100];
    char stampjoueur[10][100];


    FILE*fp=NULL;
    fp=fopen("highscore.txt","r");

//on recupere les anciens highscore
    if(fp==NULL) allegro_message("erreur");
    else

    {
        fscanf(fp,"%d %d %d %d %d %d %d %d %d %d",&highscore[0],&highscore[1],&highscore[2],&highscore[3],&highscore[4],&highscore[5],&highscore[6],&highscore[7],&highscore[8],&highscore[9]);
        fclose(fp);
    }

    fp=fopen("nom.txt","r");
    if(fp==NULL) printf("erreur");
    else

    {
        fscanf(fp,"%s %s %s %s %s %s %s %s %s %s",joueur[0],joueur[1],joueur[2],joueur[3],joueur[4],joueur[5],joueur[6],joueur[7],joueur[8],joueur[9]);
        fclose(fp);    //tout mettre en majuscule

        for(i=0; i<10; i++)
        {
            if((joueur[i][0]>='a')&&(joueur[i][0]<='z'))
                joueur[i][0]=(joueur[i][0]+'A'-'a');

        }
    }



    for(i=0; i<10; i++)
    {
      textprintf_ex(buffer,font,buffer->w/2-100,150+20*i,makecol(0,0,0),-1," %d : %s  - %d",i+1,joueur[i],highscore[i]);
      //  printf("%d : %s - %d",i,joueur[i],highscore[i]);



    }







}
