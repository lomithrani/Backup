/******************************************************************************
*******************************************************************************/

//dessine modelise un pave dans l espace a partir de son centre et de l'angle a correspondant a la rotation horizontale
void dessiner_pave(BITMAP* buffer,int x,int y, int z, float a,int l,int p,int color);

/******************************************************************************
*******************************************************************************/

//modelise une unique face du pavé
void dessiner_face(BITMAP* buffer,int x,int y, int z, float a,int l,int p,int color);

/******************************************************************************
*******************************************************************************/

//affiche la carte
void affichageCarte(BITMAP * carte,BITMAP * buffer,t_panda * panda);

/******************************************************************************
*******************************************************************************/
//assombrircarte
BITMAP* assombrir_bitmap(BITMAP* bmp);
