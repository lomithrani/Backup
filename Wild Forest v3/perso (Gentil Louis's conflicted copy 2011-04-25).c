#include <math.h>
#include <allegro.h>
#include <time.h>
#include "struct.h"
#include "acteur.h"
#include "graph.h"
#include "perso.h"
#include "menu.h"
#define PI 3.14159265

#define DEBUG(msg) {\
   set_gfx_mode(GFX_TEXT,0,0,0,0);\
   allegro_message("%s\n",msg);\
   allegro_exit();\
   exit(EXIT_FAILURE);\
}

#define PAS1   25


/******************************************************************************
*******************************************************************************/

void dessiner_panda(BITMAP* buffer,int x,int y,int z, float a)
{

    rectfill(buffer,0,0,buffer->w,buffer->h,makecol(255,0,255));
    x=SCREEN_W/4+x;
    y=SCREEN_H+y;
    z=z+SCREEN_H/3;
//for(i=0;i<4;i++)
    //dessiner_pave(boutons[i],20*cos(a-PI/4)+x,27*sin(a-PI/4)+y,z+135+89+i*50,a,2,2,makecol(0,0,0));
    //dessiner_pave(tete,x,y,z, a,50,20,makecol(240,240,240));
    dessiner_pave(buffer,48*cos(a+PI/4)+x,48*sin(a+PI/4)+y,z+320,a,14,20,makecol(0,0,0));//main1
    dessiner_pave(buffer,54*cos(a-PI/16)+x,54*sin(a-PI/16)+y,z+320,a+PI/2,14,20,makecol(0,0,0));//main2
    dessiner_pave(buffer,33*cos(a+PI/4)+x,33*sin(a+PI/4)+y,z+40,a,14,20,makecol(0,0,0));//oreille1
    dessiner_pave(buffer,33*cos(a-3*PI/4)+x,33*sin(a-3*PI/4)+y,z+40,a,14,20,makecol(0,0,0));//oreille2
    dessiner_face(buffer,20*cos(a-PI/16)+x,20*sin(a-PI/16)+y,z+20+80,a+PI/2,17,17,makecol(0,0,0));//oeuil1
    dessiner_pave(buffer,27*cos(a-PI/4)+x,27*sin(a-PI/4)+y,z+70+80,a,5,5,makecol(0,0,0));//nez
    dessiner_face(buffer,22*cos(a-PI/4)+x,27*sin(a-PI/4)+y,z+90+80,a+PI/2,10,2,makecol(0,0,0));//bouche1
    dessiner_face(buffer,20*cos(a-7*PI/16)+x,20*sin(a-7*PI/16)+y,z+20+80,a+PI/2,17,17,makecol(0,0,0));//oeuil2
    dessiner_pave(buffer,48*cos(a-5*PI/4)+x,48*sin(a-5*PI/4)+y,z+500,a,15,15,makecol(0,0,0));//queue1
    dessiner_pave(buffer,x,y,z+200+80+160,a,80,60,makecol(245,245,245));//corps1
    dessiner_pave(buffer,x,y,z+40+80+160,a,80,20,makecol(5,5,5));//corps2
    dessiner_pave(buffer,x,y,z+40+80, a,50,50,makecol(240,240,240));//tete2

    if((a<2.35)&&(a>-0.8))
    {
        dessiner_pave(buffer,33*cos(a+PI/4)+x,33*sin(a+PI/4)+y,z+40,a,14,20,makecol(0,0,0));//oreille1
        dessiner_pave(buffer,48*cos(a+PI/4)+x,48*sin(a+PI/4)+y,z+320,a,14,20,makecol(0,0,0));//main1
    }


    if((a>2.21)||(a<-0.8))
        dessiner_pave(buffer,33*cos(a-3*PI/4)+x,33*sin(a-3*PI/4)+y,z+40,a,14,20,makecol(0,0,0));//oreille2


    if((a<4)&&(a>0.8))
    {

        dessiner_pave(buffer,54*cos(a-PI/16)+x,54*sin(a-PI/16)+y,z+320,a+PI/2,14,20,makecol(0,0,0));//main2
        dessiner_face(buffer,20*cos(a-PI/16)+x,20*sin(a-PI/16)+y,z+20+80,a+PI/2,17,17,makecol(0,0,0));//oeuil1
        dessiner_pave(buffer,27*cos(a-PI/4)+x,27*sin(a-PI/4)+y,z+70+80,a,5,5,makecol(0,0,0));//nez
        dessiner_face(buffer,22*cos(a-PI/4)+x,27*sin(a-PI/4)+y,z+90+80,a+PI/2,10,2,makecol(0,0,0));//bouche1
        dessiner_face(buffer,20*cos(a-7*PI/16)+x,20*sin(a-7*PI/16)+y,z+20+80,a+PI/2,17,17,makecol(0,0,0));//oeuil2


    }
    else
        dessiner_pave(buffer,48*cos(a-5*PI/4)+x,48*sin(a-5*PI/4)+y,z+500,a,15,15,makecol(0,0,0));//queue1


}

/******************************************************************************
*******************************************************************************/

void deplacer_panda(BITMAP* collision,t_panda * panda)
{
    int colorr=makecol(255,0,0);
    int colorj=makecol(255,255,0);

    if (key[KEY_A])
    {
        if (getpixel(collision,panda->xa-PAS1-1,panda->ya)!=colorr)
        {
            panda->xa-=PAS1;
            if (panda->xa<0) panda->xa=0;
        }

    }
    if (key[KEY_D])
    {
        if (getpixel(collision,panda->xa+PAS1+1,panda->ya)!=colorr)
        {
            panda->xa+=PAS1;
            if (panda->xa>(collision->w)-(50)) panda->xa=(collision->w)-(50);
        }


    }
    if (key[KEY_W])
    {
        if (getpixel(collision,panda->xa,panda->ya-PAS1-1)!=colorr)
        {
            panda->ya-=PAS1;
            if (panda->ya<0) panda->ya=0;
        }
    }
    if (key[KEY_S])
    {
        if (getpixel(collision,panda->xa,panda->ya+PAS1+1)!=colorr)
        {
            panda->ya+=PAS1;
            if (panda->ya>(collision->h)-(50)) panda->ya=(collision->h)-(50);
        }


    }


}

/******************************************************************************
*******************************************************************************/


void actualiser_panda(t_panda * panda)
{
    clear_bitmap(panda->img);
    panda->a=atan2((mouse_y-panda->y),(mouse_x-panda->x))+PI/4;
}

/******************************************************************************
*******************************************************************************/

t_panda*  intialiser_panda()
{
    t_panda *nouv;

    // Allouer
    nouv=(t_panda *)malloc(1*sizeof(t_panda));

    //initialisation
    nouv->x=SCREEN_W/2;
    nouv->y=SCREEN_H/2;
    nouv->z=0;
    nouv->xa=1000;
    nouv->ya=1000;
    nouv->a=0;
    nouv->cmptr[0]=0;
    nouv->cmptr[1]=0;
    nouv->img=create_bitmap(SCREEN_W,SCREEN_H);
    nouv->vie=10;

    return nouv;

}
/******************************************************************************
*******************************************************************************/

void chargerdecor()
{
    BITMAP*arbreboss;
    BITMAP*coeur[11];
    BITMAP*gourde[4];

arbreboss=load("images\\decor\\arbreboss.bmp");

coeur[10]=load("images\\decor\\coeur\\coeur1.bmp");
coeur[9]=load("images\\decor\\coeur\\coeur2.bmp");
coeur[8]=load("images\\decor\\coeur\\coeur3.bmp");
coeur[7]=load("images\\decor\\coeur\\coeur4.bmp");
coeur[6]=load("images\\decor\\coeur\\coeur5.bmp");
coeur[5]=load("images\\decor\\coeur\\coeur6.bmp");
coeur[4]=load("images\\decor\\coeur\\coeur7.bmp");
coeur[3]=load("images\\decor\\coeur\\coeur8.bmp");
coeur[2]=load("images\\decor\\coeur\\coeur9.bmp");
coeur[1]=load("images\\decor\\coeur\\coeur10.bmp");
coeur[0]=load("images\\decor\\coeur\\coeur11.bmp");

gourde[0]=load("images\\decor\\gourde\\gourde0.bmp");
gourde[1]=load("images\\decor\\gourde\\gourde1.bmp");
gourde[2]=load("images\\decor\\gourde\\gourde2.bmp");
gourde[3]=load("images\\decor\\gourde\\gourde3.bmp");


}

/******************************************************************************
*******************************************************************************/

void affichagemunition(t_panda*panda)
{chargerdecor();

int a;
a=a*2;

}

/******************************************************************************
*******************************************************************************/

void affichagevie(t_panda*panda)
{chargerdecor();
    BITMAP*coeur;
int i;
for(i=0;i<11;i++)
{
    coeur=(BITMAP*)malloc(sizeof(BITMAP));



}

}

/******************************************************************************
*******************************************************************************/

void affichagourde(t_panda*panda)
{chargerdecor();
int a;
a=a*2;}

/******************************************************************************
*******************************************************************************/
