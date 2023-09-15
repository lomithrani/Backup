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


int carre(int x1)
{
    return x1*x1;
}
