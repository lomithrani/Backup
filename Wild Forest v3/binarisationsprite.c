#include <math.h>
#include <allegro.h>
#include <time.h>



int main()
{

BITMAP* image;
int i;
int j;

    // Lancer allegro et le mode graphique
    allegro_init();



    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }


    image=load_bitmap("images\\decor\\bambou.bmp",NULL);


    for(i=0;i<image->w;i++)
    for(j=0;j<image->h;j++)
    {
        if(getpixel(image,i,j)!=makecol(0,0,0))
        putpixel(image,i,j,makecol(255,0,255));
        else
        putpixel(image,i,j,makecol(39,166,126));


    }

       save_bitmap("images\\decor\\bambou1.bmp",image,NULL);



}END_OF_MAIN();

