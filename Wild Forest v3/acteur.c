#include <math.h>
#include <allegro.h>
#include <time.h>
#include "struct.h"
#include "math2.h"
#include "acteur.h"
#include "graph.h"
#include "perso.h"
#include "menu.h"
#define PI 3.14159265
#define LGRC 5100
#define HAUC 2120
#define PAS1 25
#define NACTEUR 1000

#define DEBUG(msg) {\
   set_gfx_mode(GFX_TEXT,0,0,0,0);\
   allegro_message("%s\n",msg);\
   allegro_exit();\
   exit(EXIT_FAILURE);\
}



/******************************************************************************
*******************************************************************************/

BITMAP * load(char *nomImage)
{
    BITMAP *bmp;
    bmp=load_bitmap(nomImage,NULL);
    if (!bmp)
    {
        allegro_message("pas pu trouver %s",nomImage);
        exit(EXIT_FAILURE);
    }
    return bmp;
}

/******************************************************************************
*******************************************************************************/

// Allouer et initialiser un acteur
t_acteur * creeracteur(t_panda* panda,int x,int y,int genre,int type,BITMAP*collision,t_listeActeurs * acteurs)
{
    t_acteur *nouv;



    // Allouer
    nouv=(t_acteur *)malloc(1*sizeof(t_acteur));

    //0 arbre , 1 missile , 2 ennemi
    switch(genre)
    {

    case 0://arbre






        switch(type)
        {
        case 0://bambou normal ennemi normal
            nouv->vivant=1;
            nouv->vie=10;
            nouv->genre=0;
            nouv->tab[0]=load("images\\decor\\bambou1.bmp");
            nouv->cptimg=0;
            nouv->comportement=0;
            nouv->tx=nouv->tab[0]->w;
            nouv->ty=nouv->tab[0]->h;
            nouv->x=x;
            nouv->y=y;

            break;

        case 1://bonus
            nouv->vivant=1;
            nouv->vie=10;
            nouv->genre=0;
            nouv->tab[0]=load("images\\decor\\bambou1.bmp");
            nouv->cptimg=0;
            nouv->comportement=0;
            nouv->tx=nouv->tab[0]->w;
            nouv->ty=nouv->tab[0]->h;
            nouv->x=x;
            nouv->y=y;
            break;


        case 2://plante
            nouv->vivant=1;
            nouv->vie=10;
            nouv->genre=0;
            nouv->tab[0]=load("images\\decor\\bambou1.bmp");
            nouv->cptimg=0;
            nouv->comportement=0;
            nouv->tx=nouv->tab[0]->w;
            nouv->ty=nouv->tab[0]->h;
            nouv->x=x;
            nouv->y=y;
            break;


        case 3://volant
            nouv->vivant=1;
            nouv->vie=10;
            nouv->genre=0;
            nouv->tab[0]=load("images\\decor\\bambou1.bmp");
            nouv->cptimg=0;
            nouv->comportement=0;
            nouv->tx=nouv->tab[0]->w;
            nouv->ty=nouv->tab[0]->h;
            nouv->x=x;
            nouv->y=y;
            break;

        case 4://boss
            nouv->vivant=1;
            nouv->vie=10;
            nouv->genre=0;
            nouv->tab[0]=load("images\\decor\\bambou1.bmp");
            nouv->cptimg=0;
            nouv->comportement=0;
            nouv->tx=nouv->tab[0]->w;
            nouv->ty=nouv->tab[0]->h;
            nouv->x=x;
            nouv->y=y;

            break;
        }
//dessiner une elipse dans la map de collision

        ellipsefill(collision, x +nouv->tab[0]->w/2, y+nouv->tab[0]->h,50, 25, makecol(255,0,0));

        break;
    case 1://tir
        // Initialiser ...

        // ici ce qui est commun a tout les acteurs acteurs
        nouv->genre=genre;
        nouv->x= x ;
        nouv->y= y ;
        nouv->type=type;
        nouv->comportement=0;
        nouv->cptexplo=0; // pas encore explosé mais on initialise par sécurité
        nouv->vivant=1;
        int a=atan2((mouse_y-((sqrt(2)/6)*y)),(mouse_x-x))+PI/4;

        // ici ce qui est spécifique aux types

        switch (type)
        {
            // laser
        case 0:
            nouv->tx=3;
            nouv->ty=3;
            nouv->dx=(mouse_x-panda->x)*40/sqrt(((mouse_x-panda->x)*(mouse_x-panda->x))+((mouse_y-panda->y)*(mouse_y-panda->y)));
            nouv->dy=(mouse_y-panda->y)*40/sqrt(((mouse_x-panda->x)*(mouse_x-panda->x))+((mouse_y-panda->y)*(mouse_y-panda->y)));

            nouv->couleur=makecol(255,255,0);
            break;

            // missile
        case 1:
            nouv->tx=40;
            nouv->ty=20;
            nouv->dx=(mouse_x-panda->x)*40/sqrt(((mouse_x-panda->x)*(mouse_x-panda->x))+((mouse_y-panda->y)*(mouse_y-panda->y)))+rand()%10-2;
            // petite dispersion dans la trajectoire des missiles :
            nouv->dy=(mouse_y-panda->y)*40/sqrt(((mouse_x-panda->x)*(mouse_x-panda->x))+((mouse_y-panda->y)*(mouse_y-panda->y)))+rand()%10-2;
            nouv->couleur=makecol(250,240,200);
            break;

        case 2:
            nouv->tx=40;
            nouv->ty=20;
            nouv->cible=trouverCible(acteurs,panda);
            nouv->dx=0;
            nouv->dy=3;
            if(nouv->cible <= 0)
                nouv=NULL;


            break;
        }
        //si le missile n'avance pas
        if(nouv!=NULL)
            if(!(nouv->dx)&&!(nouv->dy)) nouv=NULL;
        break;

    case 2://ennemis

        nouv->x=x;
        nouv->y=y;
//elements invariables selon les types
        nouv->genre=2;
        nouv->vivant=1;
        nouv->dx=0;
        nouv->dy=0;
        nouv->etat=0;

//elements variables selon les types

        if(type==0)
        {
            nouv->type=0;
            nouv->tmpimg=4;
            nouv->vie=5;

            nouv->tab[0]=load("images\\ennemis\\scorp1\\scorp00d.bmp");
            nouv->tab[1]=load("images\\ennemis\\scorp1\\scorp01d.bmp");
            nouv->tab[2]=load("images\\ennemis\\scorp1\\scorp02d.bmp");
            nouv->tab[3]=load("images\\ennemis\\scorp1\\scorp03d.bmp");
            nouv->tab[4]=load("images\\ennemis\\scorp1\\scorp04d.bmp");
            nouv->tab[5]=load("images\\ennemis\\scorp1\\scorp05d.bmp");
            nouv->tab[6]=load("images\\ennemis\\scorp1\\scorp06d.bmp");
            nouv->tab[7]=load("images\\ennemis\\scorp1\\scorp07d.bmp");
            nouv->tab[8]=load("images\\ennemis\\scorp1\\scorp08d.bmp");
            nouv->tab[13]=load("images\\ennemis\\scorp1\\scorpmort00.bmp");
            nouv->tab[14]=load("images\\ennemis\\scorp1\\scorpmort01.bmp");
            nouv->tab[15]=load("images\\ennemis\\scorp1\\scorpmort02.bmp");
            nouv->tab[16]=load("images\\ennemis\\scorp1\\scorpmort03.bmp");

        }



        if(type==1)
        {
            nouv->type=1;
            nouv->tmpimg=4;
            nouv->vie=2;

            nouv->tab[0]=load("images\\ennemis\\bonus1\\bonus00d.bmp");
            nouv->tab[1]=load("images\\ennemis\\bonus1\\bonus01d.bmp");
            nouv->tab[2]=load("images\\ennemis\\bonus1\\bonus02d.bmp");
            nouv->tab[3]=load("images\\ennemis\\bonus1\\bonus03d.bmp");
            nouv->tab[4]=load("images\\ennemis\\bonus1\\bonus04d.bmp");
            nouv->tab[5]=load("images\\ennemis\\bonus1\\bonus05d.bmp");
            nouv->tab[6]=load("images\\ennemis\\bonus1\\bonus06d.bmp");
            nouv->tab[7]=load("images\\ennemis\\bonus1\\bonus07d.bmp");
            nouv->tab[8]=load("images\\ennemis\\bonus1\\bonus08d.bmp");
            nouv->tab[9]=load("images\\ennemis\\bonus1\\bonus09d.bmp");
            nouv->tab[10]=load("images\\ennemis\\bonus1\\bonus10d.bmp");
            nouv->tab[11]=load("images\\ennemis\\bonus1\\bonus11d.bmp");
            nouv->tab[12]=load("images\\ennemis\\bonus1\\bonus12d.bmp");
            nouv->tab[13]=load("images\\ennemis\\bonus1\\bonusmort00.bmp");
            nouv->tab[14]=load("images\\ennemis\\bonus1\\bonusmort01.bmp");
            nouv->tab[15]=load("images\\ennemis\\bonus1\\bonusmort02.bmp");
            nouv->tab[16]=load("images\\ennemis\\bonus1\\bonusmort03.bmp");

        }

        if(type==2)
        {
            nouv->type=2;
            nouv->tmpimg=4;
            nouv->vie=10;
//            do
//            {
//                do
//                {
//                    nouv->x=rand()%4800;
//                }
//                while (nouv->x > panda->xa-250 && nouv->x < panda->xa+250);
//                do
//                {
//                    nouv->y=rand()%2050;
//                }
//                while(nouv->y > panda->ya-100 && nouv->y < panda->ya+100);
//
//            }
//            while(getpixel(collision,nouv->x,nouv->y)== makecol(255,0,0));

            nouv->tab[0]=load("images\\ennemis\\geo1\\geo00.bmp");
            nouv->tab[1]=load("images\\ennemis\\geo1\\geo01.bmp");
            nouv->tab[2]=load("images\\ennemis\\geo1\\geo02.bmp");
            nouv->tab[3]=load("images\\ennemis\\geo1\\geo03.bmp");
            nouv->tab[4]=load("images\\ennemis\\geo1\\geo04.bmp");
            nouv->tab[5]=load("images\\ennemis\\geo1\\geo05.bmp");
            nouv->tab[6]=load("images\\ennemis\\geo1\\geo06.bmp");
            nouv->tab[13]=load("images\\ennemis\\geo1\\geomort00.bmp");
            nouv->tab[14]=load("images\\ennemis\\geo1\\geomort01.bmp");
            nouv->tab[15]=load("images\\ennemis\\geo1\\geomort02.bmp");
            nouv->tab[16]=load("images\\ennemis\\geo1\\geomort03.bmp");

        }

        if(type==3)
        {
            nouv->type=3;
            nouv->tmpimg=4;
            nouv->vie=5;

            nouv->tab[0]=load("images\\ennemis\\fly1\\fly00d.bmp");
            nouv->tab[1]=load("images\\ennemis\\fly1\\fly01d.bmp");
            nouv->tab[2]=load("images\\ennemis\\fly1\\fly02d.bmp");
            nouv->tab[3]=load("images\\ennemis\\fly1\\fly03d.bmp");
            nouv->tab[4]=load("images\\ennemis\\fly1\\fly04d.bmp");
            nouv->tab[5]=load("images\\ennemis\\fly1\\fly05d.bmp");
            nouv->tab[6]=load("images\\ennemis\\fly1\\fly06d.bmp");
            nouv->tab[7]=load("images\\ennemis\\fly1\\fly07d.bmp");
            nouv->tab[13]=load("images\\ennemis\\fly1\\flymort00.bmp");
            nouv->tab[14]=load("images\\ennemis\\fly1\\flymort01.bmp");
            nouv->tab[15]=load("images\\ennemis\\fly1\\flymort02.bmp");
            nouv->tab[16]=load("images\\ennemis\\fly1\\flymort03.bmp");

        }


        if(type==4)
        {
            nouv->type=4;
            nouv->tmpimg=4;
            nouv->vie=100;

            nouv->tab[0]=load("images\\ennemis\\boss1\\boss00d.bmp");
            nouv->tab[1]=load("images\\ennemis\\boss1\\boss01d.bmp");
            nouv->tab[2]=load("images\\ennemis\\boss1\\boss02d.bmp");
            nouv->tab[3]=load("images\\ennemis\\boss1\\boss03d.bmp");
            nouv->tab[4]=load("images\\ennemis\\boss1\\boss04d.bmp");
            nouv->tab[13]=load("images\\ennemis\\boss1\\bossmort00.bmp");
            nouv->tab[14]=load("images\\ennemis\\boss1\\bossmort01.bmp");
            nouv->tab[15]=load("images\\ennemis\\boss1\\bossmort02.bmp");
            nouv->tab[16]=load("images\\ennemis\\boss1\\bossmort03.bmp");

        }


        break;


    }
    return nouv;

}

/******************************************************************************
*******************************************************************************/

// Allouer et initialiser une liste (vide) de Acteurs
t_listeActeurs * creerListeActeurs(int maxActeurs)
{
    t_listeActeurs *nouv;
    int i;

    nouv=(t_listeActeurs *)malloc(1*sizeof(t_listeActeurs));

    nouv->max=maxActeurs;
    nouv->n=0;
    nouv->tab=(t_acteur **)malloc(maxActeurs*sizeof(t_acteur*));

    for (i=0; i<maxActeurs; i++)
        nouv->tab[i]=NULL;

    return nouv;
}

/******************************************************************************
*******************************************************************************/

// Allouer et ajouter un acteur à la liste
// et retourner l'adresse de ce nouveau acteur
// retourne NULL en cas de problème
// ( mais il vaut mieux d'abord vérifier qu'il
//   y a de la place disponible avant d'appeler )
t_acteur * ajouteracteur(t_panda* panda,t_listeActeurs *la,int x,int y,int genre,int type,BITMAP*collision)
{
    int i;
    t_acteur *acteur;

    // Liste pleine, on alloue rien et on retourne NULL...
    if (la->n >= la->max)
        return NULL;

    // Allouer un acteur initialisé
    acteur=creeracteur(panda,x,y,genre,type,collision,la);

    // Chercher un emplacement libre
    i=0;
    while (la->tab[i]!=NULL && i<la->max)
        i++;

    // Si on a trouvé ...
    // (normalement oui car on a vérifié n<max)
    if (i<la->max)
    {
        // Accrocher le acteur à l'emplacement trouvé
        la->tab[i]=acteur;
        la->n++;
    }
    // Sinon c'est qu'il y a un problème de cohérence
    else
        allegro_message("Anomalie gestion ajouter acteur: liste corrompue");

    return acteur;
}

/******************************************************************************
*******************************************************************************/


// Actualiser un acteur(bouger, sortie écran, fin explosion ...)
void actualiseracteur(t_acteur *acteur,t_panda*panda,BITMAP*carte,BITMAP*collision,t_listeActeurs* acteurs)
{
    int PAS2;
    int colorr;

    PAS2=pasacteur(acteur);
    colorr=makecol(255,0,0);

    switch(acteur->genre)
    {

    case 0://arbre

        // si en cours d'explosion incrémenter cptexplo
        // et si explose depuis trop longtemps alors disparait
        if(acteur->vie <= 0)
            acteur->comportement =1;
        if (acteur->comportement==1)
        {
            acteur->cptexplo++;
            if (acteur->cptexplo > 7)
                acteur->vivant=0;
        }




        break;


    case 1://tir
        //mise a jour du dx et dy si missile a tête chercheuse
        if(acteur->type == 2)
        {

            acteur->dx=(acteurs->tab[acteur->cible]->x-acteur->x)*40/(int)sqrt(((acteurs->tab[acteur->cible]->x-acteur->x)*(acteurs->tab[acteur->cible]->x-acteur->x))+((acteurs->tab[acteur->cible]->y-acteur->y)*(acteurs->tab[acteur->cible]->y-acteur->y)));
            DEBUG("halala")
            acteur->dx=(acteurs->tab[acteur->cible]->y-acteur->y)*40/(int)sqrt(((acteurs->tab[acteur->cible]->x-acteur->x)*(acteurs->tab[acteur->cible]->x-acteur->x))+((acteurs->tab[acteur->cible]->y-acteur->y)*(acteurs->tab[acteur->cible]->y-acteur->y)));
        }

        // deplacement
        acteur->x=acteur->x+acteur->dx;
        acteur->y=acteur->y+acteur->dy;

        // type missile : accélère en dx mais pas au dela d'une limite
        //if (acteur->type==1 && acteur->dx<14)
        //    acteur->dx++;

        // si dépasse le bord alors disparait
        if (acteur->x-panda->xa+SCREEN_W/2+acteur->tx<0 || acteur->x-panda->xa+SCREEN_W/2>SCREEN_W || acteur->y-panda->ya+SCREEN_H/2+acteur->ty<0 || acteur->y-panda->ya+SCREEN_H/2>SCREEN_H )
            acteur->vivant=0;

        // si en cours d'explosion incrémenter cptexplo
        // et si explose depuis trop longtemps alors disparait
        if (acteur->comportement==1)
        {
            acteur->cptexplo++;
            if (acteur->cptexplo > 7)
                acteur->vivant=0;
        }
        break;

    case 2://ennemi
        //direction monstre

        if ((acteur->x)+((acteur->tab[0]->w)/2)<=(panda->xa))
        {
            if (getpixel(collision,acteur->x+(acteur->tab[0]->w)+PAS2+1,acteur->y+(acteur->tab[0]->h))!=colorr)
            {
                acteur->dx=1;
            }
//            else acteur->dx=-1;

        }
        if ((acteur->x)-5+((acteur->tab[0]->w)/2)>(panda->xa))
        {
            if (getpixel(collision,acteur->x-PAS2-1,acteur->y+(acteur->tab[0]->h))!=colorr)
            {


                acteur->dx=-1;
            }
//            else
//                acteur->dx=1;

        }
        if ((acteur->y)+((acteur->tab[0]->h)/2)>=(panda->ya))
        {
            if (getpixel(collision,acteur->x+(acteur->tab[0]->w)/2,acteur->y+(acteur->tab[0]->h)-50-PAS2-1)!=colorr)//-50 pour donner l'impression de pieds
            {
                acteur->dy=-1;
            }
            else acteur->dy=1;

        }
        if ((acteur->y)+((acteur->tab[0]->h)/2)<(panda->ya))
        {
            if (getpixel(collision,acteur->x+(acteur->tab[0]->w)/2,acteur->y+(acteur->tab[0]->h)+PAS2+1)!=colorr)
            {
                acteur->dy=1;
            }
            else acteur->dy=-1;

        }
        acteur->x+=(acteur->dx)*pasacteur(acteur);
        acteur->y+=(acteur->dy)*pasacteur(acteur);

// sécurité bords:
        if (acteur->x>(carte->w)-(acteur->tab[0]->w)) acteur->x=(carte->w)-(acteur->tab[0]->w);
        if (acteur->x<5) acteur->x=5;
        if (acteur->y<0) acteur->y=5;
        if (acteur->y>(carte->h)-5) acteur->y=(carte->h)-10;

        break;



    }
}


int compterActeurs(t_listeActeurs*acteurs,int genr)
{
    int cpt=0;
    int i;
    for(i=0; i<acteurs->max; i++)
    {
        if(acteurs->tab[i]!= NULL)
            if(acteurs->tab[i]->genre == genr)
                cpt++;
    }
    return cpt;
}

/******************************************************************************
*******************************************************************************/

// Gérer l'évolution de l'ensemble des Acteurs
void actualiserListeActeurs(t_listeActeurs *la,t_panda* panda,BITMAP * carte,BITMAP * collision)
{
    int cpt=0;
    int i;
    int largeurarbre;
    int hauteurarbre;

    // actualiser chaque acteur
    // si un acteur n'est plus vivant, l'enlever de la la
    for (i=0; i<la->max; i++)
        if (la->tab[i]!=NULL)
        {
            switch(la->tab[i]->genre)
            {

            case 0://arbre

                // actualiser chaque tir
                // si un tir n'est plus vivant, l'enlever de la liste

                if((!(rand()%(100*compterActeurs(la,0))))&&(!cpt))
                {
                  if(!(rand()%100))
                  ajouteracteur(panda,la,la->tab[i]->x+la->tab[i]->tab[0]->w/2,la->tab[i]->y+la->tab[i]->tab[0]->h/2,2,4,collision);
                    else
                    ajouteracteur(panda,la,la->tab[i]->x+la->tab[i]->tab[0]->w/2,la->tab[i]->y+la->tab[i]->tab[0]->h/2,2,rand()%4,collision);
                    cpt++;

                }


                actualiseracteur(la->tab[i],panda,carte,collision,la);




                if (!(la->tab[i]->vivant))
                {


                    ellipsefill(collision,la->tab[i]->x +la->tab[i]->tab[0]->w/2, la->tab[i]->y+la->tab[i]->tab[0]->h,50, 25, makecol(0,0,0));
                    enleveracteur(la,i);



                }



                break;


            case 1://tir

                // actualiser chaque tir
                // si un tir n'est plus vivant, l'enlever de la liste


                actualiseracteur(la->tab[i],panda,carte,collision,la);

                if (!(la->tab[i]->vivant))
                {


                    enleveracteur(la,i);

                }


                break;


            case 2://ennemi
                etatacteur(la->tab[i]);
                actualiseracteur(la->tab[i],panda,carte,collision,la);





                if (la->tab[i]->vie <= 0)
                {

                    switch(la->tab[i]->type)
                    {
                    case 0://normal
                        largeurarbre=138;
                        hauteurarbre=342;
                        break;

                    case 1://bonus
                        largeurarbre=138;
                        hauteurarbre=342;
                        break;

                    case 2://immobile
                        largeurarbre=138;
                        hauteurarbre=342;
                        break;

                    case 3://vole
                        largeurarbre=138;
                        hauteurarbre=342;
                        break;

                    case 4://boss
                        largeurarbre=138;
                        hauteurarbre=342;

                        break;
                    }

                    ajouteracteur(panda,la,la->tab[i]->x + (la->tab[i]->tab[0]->w / 2) - (largeurarbre/2)  ,la->tab[i]->y + la->tab[i]->tab[0]->h  - hauteurarbre, 0 , la->tab[i]->type,collision );




                    enleveracteur(la,i);



                }
                break;

            }
        }
}

/******************************************************************************
*******************************************************************************/

void affichageacteur(t_acteur*acteur,t_panda *panda,BITMAP*buffer)
{
    int i;
    int nbrimg;

    switch(acteur->genre)
    {

    case 0://arbre

        if (acteur->comportement==0)
        {

            // if(rand()%2)
            draw_sprite(buffer,acteur->tab[0],acteur->x + buffer->w / 2  - panda->xa,acteur->y + buffer->h / 2 - panda->ya);
            //else
            //  draw_sprite_h_flip(buffer,acteur->tab[0],acteur->x + buffer->w / 2 - panda->xa,acteur->y + buffer->h / 2 - panda->ya);
        }
        else//brule
        {

            draw_sprite(buffer,acteur->tab[0],acteur->x + buffer->w / 2  - panda->xa,acteur->y + buffer->h / 2 - panda->ya);


        }

        // norme de la distance socle objet socle joueur   (int)sqrt(carre(acteur->x+acteur->tab[0]->w/2-panda->xa)+carre(acteur->y+acteur->tab[0]->h-panda->ya))

        if((panda->y < 0-(acteur->y - panda->ya - buffer->h/2 + acteur->tab[0]->h))&&( 64 > (int)sqrt(carre(acteur->x+acteur->tab[0]->w/2-panda->xa)+carre(acteur->y+acteur->tab[0]->h-panda->ya)) ))
        {

            // textprintf_ex(screen,font,40,20,makecol(255,255,255),-1,"panda->y=%d   arbre=%d",acteur->y,(sqrt((acteur->x-panda->xa)*(acteur->x-panda->xa)+(acteur->y-panda->ya)*(acteur->y-panda->ya))));

            // dessiner_panda(panda->img,panda->x,panda->y,panda->z,panda->a);
            //draw_sprite(buffer,panda->img,0,0);

            stretch_sprite(buffer, panda->img, 100, 100, 0.5*panda->img->w, 0.5*panda->img->h);

        }




        break;

    case 1://tirs

        // Si pas d'explosion
        if (acteur->comportement==0)
        {
            switch(acteur->type)
            {
            case 0:
                rectfill(buffer,acteur->x + buffer->w / 2  - panda->xa,acteur->y + buffer->h / 2 - panda->ya,acteur->x + buffer->w / 2  - panda->xa+acteur->tx,acteur->y + buffer->h / 2 - panda->ya+acteur->ty,acteur->couleur);
                break;
            case 1:
                ellipsefill(buffer,acteur->x + buffer->w / 2  - panda->xa,acteur->y + buffer->h / 2 - panda->ya+acteur->ty/2,2*acteur->tx/3,acteur->ty/2,makecol(255,100,25));
                ellipsefill(buffer,acteur->x + buffer->w / 2  - panda->xa,acteur->y + buffer->h / 2 - panda->ya+acteur->ty/2,acteur->tx/3,acteur->ty/3,makecol(255,200,50));
                //triangle(buffer,acteur->x + buffer->w / 2  - panda->xa,acteur->y + buffer->h / 2 - panda->ya,acteur->x + buffer->w / 2  - panda->xa,acteur->y + buffer->h / 2 - panda->ya+acteur->ty,acteur->x + buffer->w / 2  - panda->xa+acteur->tx,acteur->y + buffer->h / 2 - panda->ya+acteur->ty/2,acteur->couleur);
                break;

            case 2:
                ellipsefill(buffer,acteur->x + buffer->w / 2  - panda->xa,acteur->y + buffer->h / 2 - panda->ya+acteur->ty/2,2*acteur->tx/3,acteur->ty/2,makecol(255,255,25));
                ellipsefill(buffer,acteur->x + buffer->w / 2  - panda->xa,acteur->y + buffer->h / 2 - panda->ya+acteur->ty/2,acteur->tx/3,acteur->ty/3,makecol(255,255,50));

                break;
            }
        }
        // sinon on dessine l'explosion
        // d'un diamètre décroissant et d'une couleur rougissante
        else
        {
            switch(acteur->type)
            {
            case 0:
                circlefill(buffer,acteur->x + buffer->w / 2  - panda->xa+acteur->tx/2,acteur->y + buffer->h / 2 - panda->ya+acteur->ty/2,30-4*acteur->cptexplo,makecol(255,255-15*acteur->cptexplo,255-30*acteur->cptexplo));
                break;
            case 1:
                circlefill(buffer,acteur->x + buffer->w / 2  - panda->xa+acteur->tx/2,acteur->y + buffer->h / 2 - panda->ya+acteur->ty/2,60-6*acteur->cptexplo,makecol(255-15*acteur->cptexplo,128-15*acteur->cptexplo,0));
                break;
            }
        }

        break;
    case 2://ennemi
        nbrimg=nombreimg(acteur);


        for(i=0; i<=(nbrimg)-1; i++)
        {

            if(abs((acteur->x+(acteur->tab[0]->w /2))-panda->xa) <= (pasacteur(acteur)+10)  )// x acteur et x panda à peu près egaux
            {

                if(abs((acteur->y+(acteur->tab[0]->h /2))- panda->ya) <= (pasacteur(acteur)+1)) draw_sprite(buffer,acteur->tab[i], (buffer->w) / 2 - (acteur->tab[0]->w) / 2 ,(buffer->h) / 2 - (acteur->tab[0]->h )/ 2);
                else
                {
                    if (acteur->etat>=(i)*(acteur->tmpimg) && acteur->etat<=(i+1)*(acteur->tmpimg)-1)
                    {
                        draw_sprite(buffer,acteur->tab[i], buffer->w / 2 - acteur->tab[0]->w / 2 ,acteur->y + buffer->h / 2 - panda->ya); //afficher acteur au x panda pour eviter l effet d indecision
                    }
                }

            }

            else
            {

                if (acteur->etat>=(i)*(acteur->tmpimg) && acteur->etat<=(i+1)*(acteur->tmpimg)-1)
                {
                    if ( abs((acteur->y+(acteur->tab[0]->h )/2)-panda->ya) <= (pasacteur(acteur)+1))
                    {
                        if (acteur->dx==1) draw_sprite(buffer,acteur->tab[i],acteur->x + buffer->w / 2  - panda->xa,(buffer->h )/ 2 - (acteur->tab[0]->h)/2);
                        if (acteur->dx==-1) draw_sprite_h_flip(buffer,acteur->tab[i],acteur->x + buffer->w / 2 - panda->xa,(buffer->h )/ 2 - (acteur->tab[0]->h)/2);
                    }
                    else
                    {
                        if (acteur->dx==1) draw_sprite(buffer,acteur->tab[i],acteur->x + buffer->w / 2  - panda->xa,acteur->y + buffer->h / 2 - panda->ya);
                        if (acteur->dx==-1) draw_sprite_h_flip(buffer,acteur->tab[i],acteur->x + buffer->w / 2 - panda->xa,acteur->y + buffer->h / 2 - panda->ya);
                    }
                }
            }
        }




        break;
    }



}

/******************************************************************************
*******************************************************************************/

void affichageListeActeurs(t_listeActeurs *liste,t_panda *panda,BITMAP* buffer)
{

    //trierTabActeurs(liste);
    int i;

    for (i=0; i<liste->max; i++)
        if (liste->tab[i]!=NULL)
        {
            affichageacteur(liste->tab[i],panda,buffer);

        }
}


/******************************************************************************
*******************************************************************************/


// Enlever et libèrer un acteur qui était dans la liste en indice i
void enleveracteur(t_listeActeurs *la,int i)
{


    // Vérifier qu'il y a bien un acteur accroché en indice i
    if (la->tab[i]!=NULL)
    {
        // libérer la mémoire de l acteur
        free(la->tab[i]);

        // marquer l'emplacement comme libre
        la->tab[i]=NULL;
        la->n--;

    }
}

/******************************************************************************
*******************************************************************************/

// Retourne un booléen vrai si il reste de la place
// dans la liste, faux sinon
int libreListeActeurs(t_listeActeurs *la)
{
    return la->n < la->max;
}

/******************************************************************************
*******************************************************************************/

void etatacteur(t_acteur*acteur) // besoin d'un etat et mvt éxistant.
{
    int nbrimg;

    nbrimg=nombreimg(acteur);

    if (acteur->cptimg==acteur->tmpimg-1) acteur->etat=((acteur->etat+1)%(nbrimg*acteur->tmpimg-1));
    else
    {
        acteur->cptimg++;
        (acteur->cptimg)=(acteur->cptimg)%(acteur->tmpimg);
    }

}

/******************************************************************************
*******************************************************************************/


int nombreimg(t_acteur*nouv)
{
    int nbrimg;

    if (nouv->type==0) nbrimg=9;
    if (nouv->type==1) nbrimg=13;
    if (nouv->type==2) nbrimg=7;
    if (nouv->type==3) nbrimg=8;
    if (nouv->type==4) nbrimg=5;
    return nbrimg;
}

/******************************************************************************
*******************************************************************************/


int pasacteur(t_acteur* gogole)
{
    int pas;

    if (gogole->type==0) pas=PAS1*0.3;
    if (gogole->type==1) pas=PAS1*0.3;
    if (gogole->type==2) pas=PAS1*0;
    if (gogole->type==3) pas=PAS1*0.5;
    if (gogole->type==4) pas=PAS1*0.65;

    return pas;
}

/******************************************************************************
*******************************************************************************/

// Un acteur a été touché ou a touché une cible : modifier son état
// ici on indique qu'il passe en comportement 1 (explosion)
// et le vecteur vitesse est divisé en norme (ralentissement)
void destinacteur(t_acteur *acteur)
{

    acteur->dx/=4;
    acteur->dy/=4;
    acteur->comportement=1;
    acteur->cptexplo=0;

}


/******************************************************************************
*******************************************************************************/

// Gérer collision (éventuelle) entre un acteur  et une liste d acteurs
void collisionacteur(t_listeActeurs *acteurs,t_acteur *acteur,t_panda *panda)
{
    int i,cpt,j;
    int m[4],imin;

    cpt=0;

    switch(acteur->genre)
    {


    case 1://tir
        // si il n'explose déjà pas !
        if ( acteur->comportement==0 )
        {

            //verifier la collision avec tout les Acteurs possibles
            for(i=0; i<acteurs->max; i++)
                if(((acteurs->tab[i])!=NULL)&&(cpt<acteurs->n)&&((acteurs->tab[i]->genre == 2)||(acteurs->tab[i]->genre == 0)))//si l acteurs existe est un ennemi et qu'on a pas deja traiter tout les Acteurs
                {

                    cpt+1;
                    // si il est dans la cible alors appeler destinacteur (explosion)

                    switch(acteur->type)
                    {
                    case 0: // acteur de type 1: laser

                        // calcul de collision
                        // Calcul des marges d'intersection (a2 par rapport à a1)
                        m[0]=acteurs->tab[i]->x + acteurs->tab[i]->tab[0]->w - acteur->x; // 0: à droite
                        m[1]=acteur->x + 20 - acteurs->tab[i]->x; // 1: à gauche
                        m[2]=acteurs->tab[i]->y + acteurs->tab[i]->tab[0]->h - acteur->y; // 2: en bas
                        m[3]=acteur->y + 20 - acteurs->tab[i]->y; // 3: en haut



                        //rectfill(screen,(acteurs->tab[i]->x - panda->xa + SCREEN_W/2 + 20), (acteurs->tab[i]->y - panda->ya + SCREEN_H/2 + 20) ,acteurs->tab[i]->x + acteurs->tab[i]->tab[0]->w - panda->xa + SCREEN_W/2 - 20,acteurs->tab[i]->y+acteurs->tab[i]->tab[0]->h - panda->ya + SCREEN_H/2 - 20,makecol(255,255,255));





                        // Chercher l'indice de la plus petite marge
                        imin=0;
                        for (j=1; j<4; j++)
                            if (m[j]<m[imin])
                                imin=j;
                        //textprintf_ex(screen,font,40,120,makecol(255,255,255),-1,"vie%d", acteurs->tab[i]->vie);


                        // Si la plus petite marge n'est pas strictement négative
                        // alors c'est qu'on a une collision et cette collision est de ce coté
                        if(acteurs->tab[i]->genre==2)//que pour les ennemis
                            if (m[imin]>=0)
                            {


                                destinacteur(acteur);

                                acteurs->tab[i]->vie--;

                            }






                        break;

                    case 1: // acteur de type 2: lance flamme

                        // acteur de type 1: laser

                        // calcul de collision


                        // Calcul des marges d'intersection (a2 par rapport à a1)
                        m[0]=acteurs->tab[i]->x + acteurs->tab[i]->tab[0]->w - acteur->x; // 0: à droite
                        m[1]=acteur->x + 20 - acteurs->tab[i]->x; // 1: à gauche
                        m[2]=acteurs->tab[i]->y + acteurs->tab[i]->tab[0]->h - acteur->y; // 2: en bas
                        m[3]=acteur->y + 20 - acteurs->tab[i]->y; // 3: en haut



                        //rectfill(screen,(acteurs->tab[i]->x - panda->xa + SCREEN_W/2 + 20), (acteurs->tab[i]->y - panda->ya + SCREEN_H/2 + 20) ,acteurs->tab[i]->x + acteurs->tab[i]->tab[0]->w - panda->xa + SCREEN_W/2 - 20,acteurs->tab[i]->y+acteurs->tab[i]->tab[0]->h - panda->ya + SCREEN_H/2 - 20,makecol(255,255,255));





                        // Chercher l'indice de la plus petite marge
                        imin=0;
                        for (j=1; j<4; j++)
                            if (m[j]<m[imin])
                                imin=j;
                        //textprintf_ex(screen,font,40,120,makecol(255,255,255),-1,"vie%d", acteurs->tab[i]->vie);


                        // Si la plus petite marge n'est pas strictement négative
                        // alors c'est qu'on a une collision et cette collision est de ce coté
                        if (m[imin]>=0)
                        {


                            destinacteur(acteur);

                            acteurs->tab[i]->vie--;

                        }



                        break;




                    }




                }
        }

        break;

    case 2://ennemi

        //verifier la collision avec le panda

        if( (int)sqrt(carre(acteur->x+acteur->tab[0]->w/2-panda->xa)+carre(acteur->y+acteur->tab[0]->h-panda->ya)) < 50)
        {
            acteur->vie=0;
            panda->vie--;
        }




        break;

    }
}


/******************************************************************************
*******************************************************************************/

// Gérer les collisions entre les Acteurs (tous les Acteurs) et les Acteurs
void collisionListeActeurs(t_listeActeurs *la,t_panda *panda)
{


    int i;

    // regarder pour chaque acteur...
    for (i=0; i<la->max; i++)
        if (la->tab[i]!=NULL)
            collisionacteur(la,la->tab[i],panda);

}

/******************************************************************************
*******************************************************************************/

void tasserListeActeurs(t_listeActeurs* acteurs)
{
    int i,cpt;
    cpt=0;
    for(i=0; i<acteurs->max; i++)
    {
        if(acteurs->tab[i]!=NULL)
        {

            acteurs->tab[cpt]=acteurs->tab[i];
            enleveracteur(acteurs,i);
            cpt++;

        }
    }

}

int trouverCible(t_listeActeurs * acteurs,t_panda * panda)
{
    int cible=-2;
    int i=0;
    int imin;
    int j;
    int m[4];
    for(i=0; i<acteurs->max; i++)
    {
        if(acteurs->tab[i]!=NULL)
        {


            m[0]=acteurs->tab[i]->x + acteurs->tab[i]->tab[0]->w - (mouse_x+SCREEN_W/2-panda->xa) ; // 0: à droite
            m[1]=mouse_x+SCREEN_W/2-panda->xa + 20 - acteurs->tab[i]->x; // 1: à gauche
            m[2]=acteurs->tab[i]->y + acteurs->tab[i]->tab[0]->h - (mouse_y+SCREEN_H/2-panda->ya); // 2: en bas
            m[3]=(mouse_y+SCREEN_H/2-panda->ya) + 20 - acteurs->tab[i]->y; // 3: en haut



            //rectfill(screen,(acteurs->tab[i]->x - panda->xa + SCREEN_W/2 + 20), (acteurs->tab[i]->y - panda->ya + SCREEN_H/2 + 20) ,acteurs->tab[i]->x + acteurs->tab[i]->tab[0]->w - panda->xa + SCREEN_W/2 - 20,acteurs->tab[i]->y+acteurs->tab[i]->tab[0]->h - panda->ya + SCREEN_H/2 - 20,makecol(255,255,255));


            // Chercher l'indice de la plus petite marge
            imin=0;
            for (j=1; j<4; j++)
                if (m[j]<m[imin])
                    imin=j;
            //textprintf_ex(screen,font,40,120,makecol(255,255,255),-1,"vie%d", acteurs->tab[i]->vie);


            // Si la plus petite marge n'est pas strictement négative
            // alors c'est qu'on a une collision et cette collision est de ce coté
            if(acteurs->tab[i]->genre==2)//que pour les ennemis
                if (m[imin]>=0)
                {
                    cible=i;

                }

        }

    }
    return cible;
}



void trierTabActeurs(t_listeActeurs * liste)
{
    tasserListeActeurs(liste);
    int i,j,permute;
    t_acteur *tmp;



    j=liste->n;
    do
    {


        permute=0;
        for (i=0; i<j; i++)
        {
            if(liste->tab[i]!=NULL)
                if (liste->tab[i]->y > liste->tab[i+1]->y)
                {
                    permute=1;
                    tmp=liste->tab[i];
                    liste->tab[i]=liste->tab[i+1];
                    liste->tab[i+1]=tmp;
                }
        }
        j--;

    }
    while (permute);
}


/******************************************************************************
*******************************************************************************/
//
/////// Trier les acteurs référencés par ordre d'éloignement décroisssant
/////// n'importe quel algo de tri peut être utilisé...
//void trierTabActeurs(t_listeActeurs * liste)
//{
//    tasserListeActeurs(liste);
//    int i,j,permute;
//    t_acteur *tmp;
//
//
//
//    j=liste->max-1;
//    do
//    {
//
//
//        permute=0;
//        for (i=0; i<j; i++)
//        {
//            if((liste->tab[i]!=NULL)&&(liste->tab[i+1]!=NULL))
//                if (liste->tab[i]->y > liste->tab[i+1]->y)
//                {
//
//                    permute=1;
//                    tmp=liste->tab[i];
//                    liste->tab[i]=liste->tab[i+1];
//                    liste->tab[i+1]=tmp;
//                }
//                else
//                {
//                    tmp=liste->tab[i];
//                    liste->tab[i]=liste->tab[i+1];
//                    liste->tab[i+1]=tmp;
//
//                }
//        }
//        j--;
//    }
//    while (permute);
//
//}

///// Trier les acteurs référencés par ordre d'éloignement décroisssant
///// n'importe quel algo de tri peut être utilisé...
//void trierTabActeurs(t_acteur * tab[NACTEUR])
//{
//    int i,j,permute;
//    t_acteur *tmp;
//
//    j=NACTEUR-1;
//    do
//    {
//        permute=0;
//        for (i=0;i<j;i++)
//        {
//            if(tab[i]!=NULL)
//            if (tab[i]->y > tab[i+1]->y)
//            {
//                permute=1;
//                tmp=tab[i];
//                tab[i]=tab[i+1];
//                tab[i+1]=tmp;
//            }
//        }
//        j--;
//    } while (permute);
//}
