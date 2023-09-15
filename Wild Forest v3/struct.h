/******************************************************************************
*******************************************************************************/

typedef struct panda
{
    //position d'affichage
    int x,y,z;
    //coordonnée réelle
    int xa,ya,za;
    //angle
    float a;

    int vie;

    int gourde;

    int rechargegourde;

    //arme active
    int arme;//0=laser, 1=mitraillette, 2=L.rocket téléguidée, 3=lance flamme
    //temporasion des armes
    int munitions[4];
    int cmptr[2];

    int points;

    BITMAP *img; // sprite (image chargée)


} t_panda;


/******************************************************************************
*******************************************************************************/

typedef struct acteur
{
    int genre;
    //0 arbre , 1 tir , 2 ennemi

    // position du coin sup. gauche
    int x,y;

    // vecteur deplacement
    int dx,dy;

    // largeur hauteur
    int tx,ty;

    // couleur (ne sera plus pertinent avec des sprites importés...)
    int couleur;

    // type de tir, 0=laser 1=missile:
    // type de monstre, 0=normal, 1=bonus, 2=plante, 3=volant, 4=boss
    //type d arbre,
    int type;
    int cible;

    // comportement :
    //   0 normal déplacement
    //   1 explosion
    int comportement;
    int cptexplo; // temps depuis l'explosion

    // vivant :
    //   0 mort (doit disparaitre de la liste)
    //   1 vivant
    int vivant;

    int vie;

    int tmpimg;


    int cptimg;

    int etat;

    BITMAP*tab[17] ;


} t_acteur;

/******************************************************************************
*******************************************************************************/

// Une collection de tirs
typedef struct listeActeurs
{
    // nombre maxi d'éléments
    // =taille du tableau de pointeurs
    int max;

    // nombre effectif de pointeurs utilisés
    // (les autres sont à NULL)
    int n;

    // le tableau de pointeurs (alloué dynamiquement)
    t_acteur **tab;

} t_listeActeurs;

/******************************************************************************
*******************************************************************************/
