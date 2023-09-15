#include <math.h>
#include <allegro.h>
#include <time.h>
#include "struct.h"
#include "math2.h"
#include "acteur.h"
#include "graph.h"
#include "perso.h"
#include "sauvegarde.h"
#include "menu.h"
#define PI 3.14159265
#define image_menu 7
#define imageb_menu 6
#define option 5
#define NIMAGE 10

#define DEBUG(msg) {\
   set_gfx_mode(GFX_TEXT,0,0,0,0);\
   allegro_message("%s\n",msg);\
   allegro_exit();\
   exit(EXIT_FAILURE);\
}

void menu ()
{
    int play=0;
    int droitier=1;
    int gaucher;/*


// Gestion de l'enchainement des images de la séquence
// indice de l'image courante
    int imgcourante=0;
// on passe à l'image suivante une fois tous les tmpimg
    int cptimg=0, tmpimg=4;

// Séquence d'animation
    BITMAP *img[NIMAGE];

// La tempo générale (fonction rest) sera réglable
    int tempoglobale=10;

// Pour charger la séquence
    int i;
    char nomfichier[256];
*/
    ////////////////////////////////////////////////////////////////
    ////                                                     //////
    ////                Creation des bitmap                  //////
    ///////////////////////////////////////////////////////////////


    // BITMAP servant de buffer d'affichage (double buffer)

    BITMAP * page;
    BITMAP * page1;
    BITMAP * page2;

    ///////////////////// Image du menu/////////////////////

    BITMAP * m[image_menu];
    BITMAP * mb [imageb_menu];

    ////////////////image des sous menus///////////////////////
    //dans options

    BITMAP * o[option];

    // dans credits

    BITMAP *c1;

    // dans score

    BITMAP *sc1;

//image du bouton coché et pas coché

    BITMAP*bouton0;
    BITMAP*bouton1;

// image de la patiente

    BITMAP*patiente;

//image du decors

    BITMAP * fond;

//image de la patte

    BITMAP* pat;

//////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////
/////                                        /////
////             lancement d'allgro          ////
////////////////////////////////////////////////

//    // Lancer allegro et le mode graphique
//    allegro_init();
//    install_keyboard();
//    install_mouse();


    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,660,517,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

/////////////////////////////////////////////////////////////

    // CREATION DU BUFFER D'AFFICHAGE à la taille de l'écran
    page=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);

    page1=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page1);


    page2=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page2);

///////////////////////////////////////////////////////////
////////                                             //////
///////           Chargement des images              /////
//////////////////////////////////////////////////////////

    ///////// charger image du menu ////////////////////

    //titre

    m[0]=load("images\\menu\\titre.bmp");
    // nouvelle partie

    m[1]=load("images\\menu\\nouvelle.bmp");

    //charger partie

    m[2]=load("images\\menu\\charger.bmp");

    //score

    m[3]=load("images\\menu\\score.bmp");

    //option

    m[4]=load("images\\menu\\option.bmp");

    //credits

    m[5]=load("images\\menu\\credits.bmp");

    //quitter

    m[6]=load("images\\menu\\quitter.bmp");

    // image de fond

    fond=load("images\\menu\\fond.bmp");

    // image du curseur

    pat=load("images\\menu\\patte.bmp");

    ///////////////image blanche du menu quand on passe la souris dessus ////////////////

// nouvelle partie blanche

    mb[0]=load("images\\menu\\nouvelle1.bmp");

//charger parie blanche

    mb[1]=load("images\\menu\\charger1.bmp");

    // score blanc

    mb[2]=load("images\\menu\\score1.bmp");

    //option blanc

    mb[3]=load("images\\menu\\option1.bmp");

    // credits blanc

    mb[4]=load("images\\menu\\credits1.bmp");

// quitter blanc

    mb[5]=load("images\\menu\\quitter1.bmp");

//////////////////// charger l'image pendant le chargement //////////////////////:

    patiente=load("images\\menu\\patiente.bmp");

////////////////////charger les images de l'animation pendant le chargement ////////////

// charger les images de la séquence d'animation
    /*  for (i=0; i<NIMAGE; i++)
      {
    // sprintf permet de faire un printf dans une chaine
          sprintf(nomfichier,"panda%d.bmp",i);

          img[i] = load_bitmap(nomfichier,NULL);
          if (!img[i])
          {
              allegro_message("pas pu trouver panda%s",nomfichier);
              exit(EXIT_FAILURE);
          }
      }
    */
//////////////////chargement des images dans option ///////////////////////

    // load des bouton

//bouton pas coché

    bouton0=load("images\\menu\\bouton0.bmp");

//bouton coché

    bouton1=load("images\\menu\\bouton1.bmp");

// load des ecritures

//titre

    o[0]=load("images\\menu\\option_titre.bmp");

    //droitier/gaucher

    o[1]=load("images\\menu\\droit.bmp");

    //son

    o[2]=load("images\\menu\\son.bmp");

    //retour1

    o[3]=load("images\\menu\\espace1.bmp");

    //retour2

    o[4]=load("images\\menu\\espace2.bmp");

///////////////////chargement des images dans credits////////////////////////

    c1=load("images\\menu\\credits_titre.bmp");

////////////////////chargement des images dans score /////////////////

    sc1=load("images\\menu\\score_titre.bmp");

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

// initialisation des données du panda
    /*

        int x = 300;
        int y = 200;


        int     cptdx=0;
        int   tmpdx=1;

        imgcourante=0;
        cptimg=0;
        tmpimg=5;



    */

//////////////////////////boucle d'animation//////////////////////////////

    while (play!=1)
    {

        /////////////////////////////////////////////////////////////
        ////////
        ///////            BLIT DU MENU
        ///////        avec changement de couleur quand
        //////           on passe la souris
        //////////////////////////////////////////////////////////////

// blit fond

        blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);

//blit du titre

        draw_sprite(page,m[0], 107 ,10);

//blit nouvelle partie

        draw_sprite(page,m[1], 7 ,122);

        if ( mouse_x<285 && mouse_x>14 && mouse_y>124 && mouse_y<167)

        {
            draw_sprite(page,mb[0], 7 ,122);
        }

//blit charger partie
//
//        draw_sprite(page,m[2], 7 ,180);
//
//        if ( mouse_x<300 && mouse_x>14 && mouse_y>186 && mouse_y<225)
//
//        {
//            draw_sprite(page,mb[1], 7 ,180);
//        }

//blit score

        draw_sprite(page,m[3], 5 ,239);

        if ( mouse_x<142 && mouse_x>15 && mouse_y>241 && mouse_y<283)

        {
            draw_sprite(page,mb[2], 5 ,239);
        }

//blit option

        draw_sprite(page,m[4], 6 ,293);

        if ( mouse_x<211 && mouse_x>16 && mouse_y>297 && mouse_y<340)

        {
            draw_sprite(page,mb[3], 6 ,293);
        }

//Blit credits

        draw_sprite(page,m[5], 8 ,350);

        if ( mouse_x<202 && mouse_x>16 && mouse_y>353 && mouse_y<398)

        {
            draw_sprite(page,mb[4], 8 ,350);
        }

//Blit Quitter

        draw_sprite(page,m[6], 10 ,407);

        if ( mouse_x<187 && mouse_x>16 && mouse_y>411 && mouse_y<447)

        {
            draw_sprite(page,mb[5], 10 ,407);
        }

//blit de la patte

        draw_sprite(page,pat, mouse_x-27, mouse_y-23);

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

////// Quand on clique sur les differents textes /////////////////////

        if (mouse_b & 1)
        {
            ///////////sur nouvelle partie/////////////////

            if ( mouse_x<285 && mouse_x>14 && mouse_y>124 && mouse_y<167)

            {

                clear_bitmap(screen);
                clear_bitmap(page);

                draw_sprite(page1,patiente, 10 ,200);
                play=1;

                // gestion enchainement des images
// incrémenter imgcourante une fois sur tmpimg
                /*                    cptimg++;
                                    if (cptimg>=tmpimg)
                                    {
                                        cptimg=0;

                                        imgcourante++;

                // quand l'indice de l'image courante arrive à NIMAGE
                // on recommence la séquence à partir de 0
                                        if (imgcourante>=NIMAGE)
                                            imgcourante=0;
                                    }


                */
// affichage du buffer à l'écrane

                //          blit(img,page1,0,0,0,0,SCREEN_W,SCREEN_H);
                blit(page1,screen,0,0,0,0,SCREEN_W,SCREEN_H);

                rest (300);

            }

            ////////////////// sur chargerpartie/////////////////////////
            if ( mouse_x<300 && mouse_x>14 && mouse_y>186 && mouse_y<225)

                {}

            //////////////////sur score//////////////////////////
            if ( mouse_x<142 && mouse_x>15 && mouse_y>241 && mouse_y<283)

            {
                while(!key[KEY_SPACE])
                {
                    clear_bitmap(page);

                    // blit fond

                    blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);

                    // titre

                    draw_sprite(page,sc1, 200, 20);

                    ///// blit du retour

                    draw_sprite(page,o[3], 10 ,400);
                    draw_sprite(page,o[4], 8 ,420);

                    ///////blit de la patte

                    draw_sprite(page,pat, mouse_x-27, mouse_y-23);

                    //blit de tout

                    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);



                    rest(20);
                }
            }
            ///////////////sur option////////////////////////////

            if ( mouse_x<211 && mouse_x>16 && mouse_y>297 && mouse_y<340)

            {
                while(!key[KEY_SPACE])
                {
                    clear_bitmap(page);

                    // blit fond

                    blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);


                    // blit des titre

                    draw_sprite(page,o[0], 200, 20);
                    draw_sprite(page,o[1], 10, 150);
                    draw_sprite(page,o[2], 100, 203);


                    /////blit des boutons coché et pas coché

                    draw_sprite(page,bouton1, 340, 150);
                    draw_sprite(page,bouton0, 400, 150);
                    draw_sprite(page,bouton1, 340, 203);
                    draw_sprite(page,bouton0, 400, 203);

                    ///// blit du retour

                    draw_sprite(page,o[3], 10 ,400);
                    draw_sprite(page,o[4], 8 ,420);

                    // si on clique sur le bouton

                    if (mouse_b & 1)
                    {

                        if ( mouse_x<440 && mouse_x>400 && mouse_y>150 && mouse_y<200)

                        {

                            if(droitier==1)

                            {


                                blit(fond, page, 340, 150, 340, 150, SCREEN_W,30);


                                draw_sprite(page,bouton1, 400, 150);
                                draw_sprite(page,bouton0, 340, 150);
                                rest(10);
                                droitier=0;
                                gaucher=1;


                            }

                        }

                    }

                    ///////blit de la patte

                    draw_sprite(page,pat, mouse_x-27, mouse_y-23);

                    //blit de tout

                    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

                    rest (20);

                }

            }

            /////////////////////////sur credits////////////////////////

            if ( mouse_x<202 && mouse_x>16 && mouse_y>353 && mouse_y<398)
            {
                while(!key[KEY_SPACE])
                {
                    clear_bitmap(page);

                    // blit fond

                    blit(fond,page,0,0,0,0,SCREEN_W,SCREEN_H);

                    //blit du titre

                    draw_sprite(page,c1, 200, 20);

                    ///// blit du retour

                    draw_sprite(page,o[3], 10 ,400);
                    draw_sprite(page,o[4], 8 ,420);

                    ///////blit de la patte

                    draw_sprite(page,pat, mouse_x-27, mouse_y-23);
                     textprintf_ex(page,font,10,200,makecol(255,255,255),-1,"Z,Q,S,D pour le déplacement, A pour le changement d'arme.\n ");
                     textprintf_ex(page,font,10,230,makecol(255,255,255),-1,"récuperez de la vie et des munitions, \n dans les zones jaunes");
                    textprintf_ex(page,font,10,260,makecol(255,255,255),-1,"WILLIAM LEFEBVRE \n LOUIS GENTIL \n MAXIME PEDRON  \n sprite emprunter sur le net");
                    //blit de tout

                    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
                    rest(20);
                }
            }
            //////////////////// sur quitter////////////////////////

            if ( mouse_x<187 && mouse_x>16 && mouse_y>411 && mouse_y<447)
            {

                allegro_exit();
                exit(EXIT_FAILURE);

            }
        }

/////////////////////////////////////////////////////////////////////////////
///////////////////////////////blit de tout///////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

// petite pause

        rest(20);
    }


}
