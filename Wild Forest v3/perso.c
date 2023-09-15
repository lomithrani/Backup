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
x=5*SCREEN_W/6 -20;//SCREEN_W-x;
    y=3*SCREEN_H+40;//+y;
    z=z-380;//zSCREEN_H-SCREEN_H/3;//z+SCREEN_H/3;
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
    int i;
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
    nouv->vie=6;
    nouv->gourde=0;
    nouv->rechargegourde=1;
    nouv->points=0;
    nouv->arme=0;
    for(i=0;i<4;i++)
    {nouv->munitions[i]=50;}

    return nouv;

}
/******************************************************************************
*******************************************************************************/

BITMAP* arbreboss()
{
    BITMAP*arbreboss;

arbreboss=load("images\\decor\\arbreboss.bmp");

    return arbreboss;
}

/******************************************************************************
*******************************************************************************/

void affichagevie(t_panda*panda,BITMAP*buffer)
{
    BITMAP*coeur[11];
    int i;
i=panda->vie;
if(i<=0)
{
panda->vie=0;
i=0;
}

if(i==10)coeur[10]=load("images\\decor\\coeur\\coeur1.bmp");
if(i==9)coeur[9]=load("images\\decor\\coeur\\coeur2.bmp");
if(i==8)coeur[8]=load("images\\decor\\coeur\\coeur3.bmp");
if(i==7)coeur[7]=load("images\\decor\\coeur\\coeur4.bmp");
if(i==6)coeur[6]=load("images\\decor\\coeur\\coeur5.bmp");
if(i==5)coeur[5]=load("images\\decor\\coeur\\coeur6.bmp");
if(i==4)coeur[4]=load("images\\decor\\coeur\\coeur7.bmp");
if(i==3)coeur[3]=load("images\\decor\\coeur\\coeur8.bmp");
if(i==2)coeur[2]=load("images\\decor\\coeur\\coeur9.bmp");
if(i==1)coeur[1]=load("images\\decor\\coeur\\coeur10.bmp");
if(i==0)coeur[0]=load("images\\decor\\coeur\\coeur11.bmp");

  draw_sprite(buffer,coeur[i],0,0);

}



/******************************************************************************
*******************************************************************************/

void affichagourde(t_panda*panda,BITMAP*buffer)
{
    BITMAP*gourde[4];
       int i;
i=panda->gourde;
if(i==3)
{
    panda->vie++;
    if(panda->vie>10) panda->vie=10;
    panda->gourde=0;
}

if(i==0)gourde[0]=load("images\\decor\\gourde\\gourde0.bmp");
if(i==1)gourde[1]=load("images\\decor\\gourde\\gourde1.bmp");
if(i==2)gourde[2]=load("images\\decor\\gourde\\gourde2.bmp");
if(i==3)gourde[3]=load("images\\decor\\gourde\\gourde3.bmp");

  draw_sprite(buffer,gourde[i],buffer->w-gourde[i]->w,buffer->h-gourde[i]->h);
}

/******************************************************************************
*******************************************************************************/

void remplissagegourde(t_panda*panda,BITMAP*collision)//et recharge lance flamme
{//recharge lance flamme
    if(getpixel(collision,panda->xa,panda->ya)==makecol(255,255,0))
{
panda->munitions[panda->arme]++;
}
if(panda->rechargegourde>=100)
{
if(getpixel(collision,panda->xa,panda->ya)==makecol(255,255,0))
{(panda->gourde=(panda->gourde+1)%4);
panda->rechargegourde=0;
}
}
else{panda->rechargegourde=(panda->rechargegourde+1);}

}

/******************************************************************************
*******************************************************************************/

void affichagepoints(t_panda*panda,BITMAP*buffer,t_listeActeurs*acteurs)
{
    int a;

    panda->points=panda->points+compterActeurs(acteurs,0);
    a=panda->points/100;
textprintf_ex(buffer,font,buffer->w-100,20,makecol(255,255,255),-1,"POINTS: %d",a);


}

/******************************************************************************
*******************************************************************************/

void munitions(t_panda*panda,BITMAP*buffer)
{


    panda->munitions[panda->arme]--;
    if(panda->arme==0) panda->munitions[panda->arme]++;
    if (panda->munitions[panda->arme]<0) panda->munitions[panda->arme]=0;

}

/******************************************************************************
******************************************************************************/

void affichagearme(t_panda*panda,BITMAP*buffer)
{
    BITMAP*arme;

    textprintf_ex(buffer,font,110,buffer->h-50,makecol(255,255,255),-1," %d",panda->munitions[panda->arme]);
    if(panda->arme==2)arme=load("images\\arme\\fusillaser.bmp");
    if(panda->arme==0)arme=load("images\\arme\\mitraillette.bmp");
    if(panda->arme==3)arme=load("images\\arme\\lancerocket.bmp");
    if(panda->arme==1)arme=load("images\\arme\\lanceflamme.bmp");

     draw_sprite(buffer,arme,10,buffer->h-arme->h-5);

}

/******************************************************************************
*******************************************************************************/

void changerarme(t_panda*panda,BITMAP*buffer)
{
    panda->arme=(panda->arme +1)%2;
}
