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

void cleantab_b(char tab[30][80])
{
    int i,j;
    for(i=0; i<30; i++)
        for(j=0; j<80; j++)
            tab[i][j]=0;
}

void shootenemy_B(int maskshootb[30][80],int maskshootb_1[30][80],int maskshootb_2[30][80],int maskshootb_3[30][80],int maskshootb_4[30][80])
{
    //ressources
    int i,j;
    for(i=0; i<30; i++)
        for(j=0; j<80; j++)
        {
            if(maskshootb[i][j])
            {
                maskshootb_1[i][j]=1;
                maskshootb_2[i][j]=1;
                maskshootb_3[i][j]=1;
                maskshootb_4[i][j]=1;
            }
        }
}

void colision_B(int coord[2],int coordenem[11][2],int maskship[30][80],int maskwall[30][80],int maskenemy[30][80],int maskshoote[30][80],int maskshoota[30][80],char maskboss[30][80],int maskshootb[30][80],int maskshootb_1[30][80],int maskshootb_2[30][80],int maskshootb_3[30][80],int maskshootb_4[30][80],int* bosslife,int* life,int* score,int sound)
{
    int i,j,k,l,a=0,m=0,n=0,o=0;
    int test;

    for(i=0; i<30; i++)
        for(j=0; j<80; j++)
        {

            //collision avec le boss

            if((maskshoota[i][j])&&(maskboss[i][j]!=0))
            {
                maskshoota[i][j]=0;
                (*bosslife)--;
            }


            if((maskship[i][j]||maskshoota[i][j]||maskshoota[i][j+1])&&maskenemy[i][j])//colision entre un enemi et un objet qui le detruit
            {
                if(sound)
                printf("\a");
                for(k=1; k<=coordenem[0][0]; k++) //on parcours les vaisseaux enemis pour trouver qui a percuter l avion
                {
                    if((coordenem[k][0]==j)&&(coordenem[k][1]==i))
                    {
                        coordenem[k][0]=0;
                        coordenem[k][1]=0;
                        coordenem[0][0]--;//on retire un vaisseau au nbr de vaisseau present
                        refreshcoordenem(coordenem);

                    }


                }
            }
            test=(maskwall[i][j]||maskshoote[i][j]||maskshootb[i][j]||maskshootb_1[i][j]||maskshootb_2[i][j]||maskshootb_3[i][j]||maskshootb_4[i][j]);
            if(maskship[i][j]&&test)//collision entre avion et un objet qui le detruit
            {
                life[0]--;//on retire une vie
                //gotoligcol(DECAL_LIG+33)
                //printf("\a");//faire un bruit + ralentir
                //on efface le vaisseau et ce qui aurais pu le percuter
                for(k=0; k<4; k++)
                {


                    maskship[coord[1]][coord[0]+k]=0;

                    maskenemy[coord[1]][coord[0]+k]=0;

                    maskshoote[coord[1]][coord[0]+k]=0;

                    maskshootb[coord[1]][coord[0]+k]=0;

                    maskshootb_1[coord[1]][coord[0]+k]=0;

                    maskshootb_2[coord[1]][coord[0]+k]=0;

                    maskshootb_3[coord[1]][coord[0]+k]=0;

                    maskshootb_4[coord[1]][coord[0]+k]=0;
                }





                for(k=0; k<30; k++) //recherche des murs dans la premiere colone
                {

                    if(maskwall[k][0]&&!m)//on cherche la premiere etoile
                    {
                        a=k; //on note la coordonnee de la premiere etoile
                        m++;//on empeche de modifie celle ci a la 2 eme etoile
                    }
                    if(maskwall[k][0]&&m) // on ne peut rentrer qu'une fois que a a ete affecte
                    {
                        n=k;//on note la coordonnee de la 2 eme etoile
                        o++;//on retiens qu'on lui a donner une valeur
                    }

                }
                if(m&&o)//les coordonees de la premiere et deuxieme etoile existe
                {
                    // on place le vaisseau entre les 2 etoiles
                    maskship[((n-a)/2)+a][0]=1;
                    maskship[((n-a)/2)+a][1]=1;
                    maskship[((n-a)/2)+a][2]=1;
                    maskship[((n-a)/2)+a][3]=1;
                    coord[0]=0;
                    coord[1]=((n-a)/2)+a;//on actualise les coordonnées
                }
            }
            if(maskshoota[i][j]&&(maskwall[i][j]||maskwall[i][j-1]))//colision missile ally mur 2 cas possible car avec le double decalage le missile pourrais traverser le mur
            {
                maskshoota[i][j]=0; //effacer le missile
            }
            if(maskshoote[i][j]&&(maskwall[i][j]||maskwall[i][j+1]))//colision missile ally mur 2 cas possible car avec le double decalage le missile pourrais traverser le mur
            {
                maskshoote[i][j]=0; //effacer le missile
            }
            //if(maskshoote[i][j]&&(maskwall[i][j]||maskwall[i][j+1]||maskwall[j+2]))//colision missile enem mur 2 cas possible car avec le double decalage le missile pourrais traverser le mur
            //{
            //    maskshoote[i][j]=0; //effacer le missile
            //}
            test=0;//test faux de base
            if(coord[0])//si on est pas tout a gauche
                test=maskenemy[i][j-2];
            if(maskshoota[i][j]&&(maskenemy[i][j]||maskenemy[i][j-1]||maskshootb[i][j-1]||maskshootb[i][j]||test)) //collision tir ally et chose qu'il detruit
            {
                maskshoota[i][j]=0;
                if(maskenemy[i][j])// pr ne pas allez dans les negatifs
                    maskenemy[i][j]--;
                if(maskenemy[i][j-1])
                    maskenemy[i][j-1]--;

                if(maskshootb[i][j-1])
                    maskshootb[i][j-1]--;

                if(maskshootb[i][j])
                    maskshootb[i][j]--;

                // nous n'acualisons pas les coordonnees pour pas ralentir le process elle s effaceront automatiquement quand ils auraient du passez a 0
            }










        }
}


void recordemo_B(int maskship[30][80],int maskwall[30][80],int maskenemy[30][80],int maskshoota[30][80],int maskshoote[30][80],char maskboss[30][80],int maskshootb[30][80],int maskshootb_1[30][80],int maskshootb_2[30][80],int maskshootb_3[30][80],int maskshootb_4[30][80],int life,int progress,int score)
{
    int i,j;
    FILE*fp=NULL;
    fp=fopen("demo.txt","a");
    if(fp==NULL) fprintf(fp,"erreur");
    else

    {



        for(i=0; i<30; i++)
        {


            for(j=0; j<80; j++)
            {



                if(maskship[i][j])//sa prend 4 case d'espace
                {

                    if(!maskship[i][j-1])//test pour ne pas avoir le vaisseau qui se repète

                        fprintf(fp,"+OOO");//4 case également



                }


                else if(maskshoota[i][j])
                {
                    fprintf(fp,"-");
                }

                else if(maskshoote[i][j])
                {


                    fprintf(fp,"_");


                }
                else if(maskboss[i][j])
                {

                    fprintf(fp,"%c",maskboss[i][j]);

                }
                else if(maskshootb[i][j])
                {

                    fprintf(fp,"O");

                }
                else if((maskshootb_1[i][j])||(maskshootb_2[i][j])||(maskshootb_3[i][j])||(maskshootb_4[i][j]))
                {

                    fprintf(fp,"+");

                }
                else
                {
                    fprintf(fp," ");
                }


            }

            fprintf(fp,"\n");
        }
        fprintf(fp,"%d %d %d",life,score,progress);
        fprintf(fp,"\n");

    }
}



void printmap_B(int maskship[30][80],int maskwall[30][80],int maskenemy[30][80],int maskshoota[30][80],int maskshoote[30][80],char maskboss[30][80],int maskshootb[30][80],int maskshootb_1[30][80],int maskshootb_2[30][80],int maskshootb_3[30][80],int maskshootb_4[30][80])
{
    int i,j;





    for(i=0; i<30; i++)
    {
        gotoligcol(DECAL_LIG+i,DECAL_COL);

        for(j=0; j<80; j++)
        {



            if(maskship[i][j])//sa prend 4 case d'espace
            {
                Color(2,0);
                if(!maskship[i][j-1])//test pour ne pas avoir le vaisseau qui se repète

                    printf("+OOO");//4 case également
                Color(10,0);


            }


            else if(maskshoota[i][j])
            {
                printf("-");
            }

            else if(maskshoote[i][j])
            {
                Color(12,0);

                printf("-");
                Color(10,0);

            }
            else if(maskboss[i][j])
            {
                Color(6,0);
                printf("%c",maskboss[i][j]);
                Color(10,0);
            }
            else if(maskshootb[i][j])
            {
                Color(14,0);
                printf("O");
                Color(10,0);
            }
            else if((maskshootb_1[i][j])||(maskshootb_2[i][j])||(maskshootb_3[i][j])||(maskshootb_4[i][j]))
            {
                Color(12,0);
                printf("+");
                Color(10,0);
            }
            else
            {
                printf(" ");
            }


        }


    }


}

void decalmapL_B(char tab[30][80],int x)
{
    int i,j,k;
    //double boucle for parcours de tableau
    for(i=0; i<30; i++)
    {

        for(j=0; j<80-x; j++)
        {
            tab[i][j]=tab[i][j+x]; //on fait scroll de x par la gauche

        }
        for(k=1; k<=x; k++) //on efface les colonnes qui n ont pas été touché pour ne pas avoir de résidu
            tab[i][80-k]=0;
    }
}



void decalmapU_B(char tab[30][80],int x)
{
    int i,j,k;
    //double boucle for parcours de tableau
    for(i=0; i<30-x; i++)
    {

        for(j=0; j<80; j++)
        {
            tab[i][j]=tab[i+x][j]; //on fait scroll de x par la gauche

        }

    }
    for(k=1; k<=x; k++) //on efface les colonnes qui n ont pas été touché pour ne pas avoir de résidu
        for(j=0; j<80; j++)
            tab[30-k][j]=0;
}



void decalmapD_B(char tab[30][80],int x)
{
    int i,j,k;
    //double boucle for parcours de tableau
    for(j=0; j<80; j++)
    {
        for(i=29; i>=x; i--)
        {
            tab[i][j]=tab[i-x][j]; //on fait scroll de x par la gauche

        }

    }
    for(k=1; k<=x; k++) //on efface les colonnes qui n ont pas été touché pour ne pas avoir de résidu
        for(j=0; j<80; j++)
            tab[k-1][j]=0;
}



void decalmapR_B(char tab[30][80],int x)
{
    int i,j,k;
    //double boucle for pour parcours du tableau
    for(i=29; i>=0; i--)
    {

        for(j=79; j>=x; j--)
        {
            tab[i][j]=tab[i][j-x];//on scroll de x vers la droite
            tab[i][j-x]=0;
        }
        for(k=0; k<x; k++) //on efface les colonnes qui n ont pas été touché pour ne pas avoir de résidu
            tab[i][x]=0;

    }



}

