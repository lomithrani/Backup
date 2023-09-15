#include <math.h>
#include <allegro.h>
#include <time.h>
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

int main()
{


    // Buffer
    BITMAP* buffer;
    //map colision
    BITMAP*collision;
    //carte
    BITMAP*carte;
    //Perso
    t_panda* panda;
    // La collection d acteurs
    t_listeActeurs *acteurs;

    // Il y aura du hasard
    srand(time(NULL));
    // Lancer allegro et le mode graphique
    allegro_init();
    install_keyboard();
    install_mouse();
do{
    menu();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1024,768,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    // buffer
    buffer=create_bitmap(SCREEN_W,SCREEN_H);


    carte=load("images\\map\\cartecollision.bmp");



    collision=load("images\\map\\cartecollision.bmp");

    panda=intialiser_panda();


    acteurs=creerListeActeurs(1000);


    ajouteracteur(panda,acteurs,1000,1000,0,0,collision);
    // BOUCLE DE JEU

    while (!key[KEY_ESC]  && panda->vie>0 )
    {

        show_mouse(screen);
        clear_bitmap(buffer);
        actualiser_panda(panda);




        if(mouse_b & 1)
        {


            munitions(panda,buffer);
            if (panda->munitions[panda->arme]>0)
            {
                ajouteracteur(panda,acteurs,panda->xa,panda->ya,1,panda->arme,collision);
            }
        }

            // entrée = missile
            if (key[KEY_Q])
            {
                panda->arme=(panda->arme +1)%2; // fonction changer arme défaillante
                key[KEY_Q]=0;
            }

//trierTabActeurs()

            // bouger tout le monde
            //actualiserJoueur(vaisseau,acteurs);

            deplacer_panda(collision,panda);
            actualiserListeActeurs(acteurs,panda,carte,collision);
            // gérer les collisions
            collisionListeActeurs(acteurs,panda);


            // afficher tout le monde
            //dessinerJoueur(page,vaisseau);dz
            //dessinerEnnemi(page,cible);


            //blit(mapbuffer,carte,0,0,0,0,carte->w,carte->h);


            affichageCarte(carte,buffer,panda);

            dessiner_panda(panda->img,panda->x,panda->y,panda->z,panda->a);
            stretch_sprite(buffer, panda->img, 100, 100, 0.5*panda->img->w, 0.5*panda->img->h);
            affichageListeActeurs(acteurs,panda,buffer);
            //draw_sprite(buffer,panda->img,0,0);



            affichagourde(panda,buffer);
            affichagevie(panda,buffer);
            remplissagegourde(panda,collision);
            affichagepoints(panda,buffer,acteurs);
            affichagearme(panda,buffer);

//buffer=assombrir_bitmap(buffer);
            blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            // rectfill(screen,panda->x-5,panda->y-5,panda->x+5,panda->y+5,makecol(255,0,0));

            rest(20);


        }

}while(1);

        return 0;
    }
    END_OF_MAIN();
