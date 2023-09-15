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


/******************************************************************************
*******************************************************************************/

void dessiner_pave(BITMAP* buffer,int x,int y, int z, float a,int l,int p,int color)
{

    int ra,v,b;


    float r=sqrt((((l)/2)*((l)/2))*2);
    float sr=sqrt(2)/6;

    float xa=r*cos(a)+x;
    float ya=sr*(r*sin(a)+y)+sr*(p*2+z);
    float xb=r*cos(a+PI/2)+x;
    float yb=sr*(r*sin(a+PI/2)+y)+sr*(p*2+z);
    float xc=r*cos(a+PI)+x;
    float yc= sr*(r*sin(a+PI)+y)+sr*(p*2+z);
    float xd=r*cos(a-PI/2)+x;
    float yd=sr*(r*sin(a-PI/2)+y)+sr*(p*2+z);
    float xe=r*cos(a)+x;
    float ye=sr*(r*sin(a)+y)+sr*(z-p*2);
    float xf=r*cos(a+PI/2)+x;
    float yf=sr*(r*sin(a+PI/2)+y)+sr*(z-p*2);
    float xg=r*cos(a+PI)+x;
    float yg= sr*(r*sin(a+PI)+y)+sr*(z-p*2);
    float xh=r*cos(a-PI/2)+x;
    float yh=sr*(r*sin(a-PI/2)+y)+sr*(z-p*2);
    int points[8]= {xa,ya,xb,yb,xc,yc,xd,yd};
    int points2[8]= {xe,ye,xf,yf,xg,yg,xh,yh};
    int points3[8]= {xa,ya,xb,yb,xf,yf,xe,ye};
    int points4[8]= {xe,ye,xa,ya,xd,yd,xh,yh};
    int points5[8]= {xb,yb,xc,yc,xg,yg,xf,yf};
    int points6[8]= {xd,yd,xc,yc,xg,yg,xh,yh};



    polygon(buffer,4,points,color);
    polygon(buffer,4,points2,color);
    polygon(buffer,4,points3,color);
    polygon(buffer,4,points5,color);
    polygon(buffer,4,points6,color);
    if((a<4)&&(a>0.8))
        polygon(buffer,4,points4,color);


    ra=getr(color);
    v=getg(color);
    b=getb(color);

    ra=ra-20;
    if(ra>255) ra=255;
    if(ra<0) ra=0;

    v=v-20;
    if(v>255) v=255;
    if(v<0) v=0;


    b=b-20;
    if(b>255) b=255;
    if(b<0) b=0;

    fastline(buffer,xe,ye,xf,yf,makecol(ra,v,b));
    fastline(buffer,xf,yf,xg,yg,makecol(ra,v,b));
    fastline(buffer,xg,yg,xh,yh,makecol(ra,v,b));
    fastline(buffer,xh,yh,xe,ye,makecol(ra,v,b));

    if((a<4)&&(a>0.8))
    {
        fastline(buffer,xe,ye,xa,ya,makecol(ra,v,b));
        fastline(buffer,xd,yd,xh,yh,makecol(ra,v,b));
        fastline(buffer,xd,yd,xa,ya,makecol(ra,v,b));
    }







}


/******************************************************************************
*******************************************************************************/

void affichageCarte(BITMAP * carte,BITMAP * buffer,t_panda * panda)
{

    blit(carte,buffer,(panda->xa)-(SCREEN_W/2),(panda->ya)-(SCREEN_H/2),0,0,SCREEN_W,SCREEN_H);
//
//
//    if (panda->xa-(SCREEN_W)/2<=0 && panda->ya-(SCREEN_H)/2<=0 ) blit(carte,buffer, 0,0,0,0,SCREEN_W, SCREEN_H);
//    else
//    {
//        if (panda->xa-(SCREEN_W)/2<=0 && panda->ya-(SCREEN_H)/2>=0 && panda->ya+(SCREEN_H)/2<=(carte->h)) blit(carte,buffer, 0,panda->ya-(SCREEN_H)/2,0,0,SCREEN_W, SCREEN_H);
//        else
//        {
//            if (panda->xa-(SCREEN_W)/2<=0 && panda->ya+(SCREEN_H)/2>=(carte->h)) blit(carte,buffer, 0,(carte->h)-(SCREEN_H),0,0,SCREEN_W, SCREEN_H);
//            else
//            {
//                if (panda->xa-(SCREEN_W)/2>=0 && panda->xa+(SCREEN_W)/2<=(carte->w) && panda->ya-(SCREEN_H)/2<=0 ) blit(carte,buffer,panda->xa-(SCREEN_W)/2,0,0,0,SCREEN_W, SCREEN_H);
//                else
//                {
//                    if (panda->xa-(SCREEN_W)/2>=0 && panda->ya-(SCREEN_H)/2>=0 && panda->xa+(SCREEN_W)/2<=(carte->w) && panda->ya+(SCREEN_H)/2<=(carte->h))blit(carte, buffer, panda->xa-(SCREEN_W)/2,panda->ya-(SCREEN_H)/2,0,0,SCREEN_W, SCREEN_H);
//                    else
//                    {
//                        if (panda->xa-(SCREEN_W)/2>=0 && panda->xa+(SCREEN_W)/2<=(carte->w) && panda->ya+(SCREEN_H)/2>=(carte->h)) blit(carte, buffer, panda->xa-(SCREEN_W)/2,(carte->h)-(SCREEN_H),0,0,SCREEN_W, SCREEN_H);
//                        else
//                        {
//                            {
//                                if (panda->xa+(SCREEN_W)/2>=(carte->w) &&  panda->ya-(SCREEN_H)/2<=0) blit(carte, buffer, (carte->w)-(SCREEN_W),0,0,0,SCREEN_W, SCREEN_H);
//                                else
//                                {
//                                    if (panda->xa+(SCREEN_W)/2>=(carte->w) && panda->ya+(SCREEN_H)/2<=(carte->h) && panda->ya-(SCREEN_H)/2>=0) blit(carte, buffer, (carte->w)-(SCREEN_W),panda->ya-(SCREEN_H)/2,0,0,SCREEN_W, SCREEN_H);
//
//                                    else
//                                    {
//                                        if (panda->xa+(SCREEN_W)/2>=(carte->w) && panda->ya+(SCREEN_H)/2>=(carte->h))blit(carte, buffer, (carte->w)-(SCREEN_W),(carte->h)-(SCREEN_H),0,0,SCREEN_W, SCREEN_H);
//                                    }
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }

}

/******************************************************************************
*******************************************************************************/

void dessiner_face(BITMAP* buffer,int x,int y, int z, float a,int l,int p,int color)
{





    float r=sqrt((((l)/2)*((l)/2))*2);
    float sr=sqrt(2)/6;


    float xc=r*cos(a+PI)+x;
    float yc= sr*(r*sin(a+PI)+y)+sr*(p*2+z);
    float xd=r*cos(a-PI/2)+x;
    float yd=sr*(r*sin(a-PI/2)+y)+sr*(p*2+z);
    float xg=r*cos(a+PI)+x;
    float yg= sr*(r*sin(a+PI)+y)+sr*(z-p*2);
    float xh=r*cos(a-PI/2)+x;
    float yh=sr*(r*sin(a-PI/2)+y)+sr*(z-p*2);
    int points6[8]= {xd,yd,xc,yc,xg,yg,xh,yh};


    //tests


    //if((a<4)&&(a>0.8))
    polygon(buffer,4,points6,color);




}

/******************************************************************************
*******************************************************************************/

BITMAP* assombrir_bitmap(BITMAP* bmp)
{
    BITMAP* bmpmod;
    bmpmod=create_bitmap(SCREEN_W,SCREEN_H);
    int i,j,r,v,b,color;
    //on parcours tout l écran
    //allegro_message("apres");
    for(i=0; i<SCREEN_H; i++)
        for(j=0; j<SCREEN_W; j++)
        {

            //on chope le pixel
            color=getpixel(bmp,j,i);
            //on décompose les couleurs
            r=getr(color);
            v=getg(color);
            b=getb(color);
            //on traite les couleurs
            r=r-(i/10);
            if(r>255) r=255;
            if(r<0) r=0;
            v=v-(i/10);
            if(v>255) v=255;
            if(v<0) v=0;
            b=b-(i/10);
            if(b>255) b=255;
            if(b<0) b=0;

            putpixel(bmpmod,j,i,makecol(r,v,b));

        }

    return bmpmod;

}
