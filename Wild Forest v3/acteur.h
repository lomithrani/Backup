#define NACTEUR 1000

/******************************************************************************
*******************************************************************************/

BITMAP * load(char *nomImage);

/******************************************************************************
*******************************************************************************/

// Allouer et initialiser un acteur
t_acteur * creeracteur(t_panda* panda,int x,int y,int genre,int type,BITMAP*collision,t_listeActeurs * acteurs);

/******************************************************************************
*******************************************************************************/

// Allouer et initialiser une liste (vide) de Acteurs
t_listeActeurs * creerListeActeurs(int maxActeurs);

/******************************************************************************
*******************************************************************************/

// Allouer et ajouter un acteur � la liste
// et retourner l'adresse de ce nouveau acteur
// retourne NULL en cas de probl�me
// ( mais il vaut mieux d'abord v�rifier qu'il
//   y a de la place disponible avant d'appeler )
t_acteur * ajouteracteur(t_panda* panda,t_listeActeurs *la,int x,int y,int genre,int type,BITMAP*collision);

/******************************************************************************
*******************************************************************************/

// Actualiser un acteur(bouger, sortie �cran, fin explosion ...)
void actualiseracteur(t_acteur *acteur,t_panda*panda,BITMAP*carte,BITMAP*collision,t_listeActeurs* acteurs);
/******************************************************************************
*******************************************************************************/

// G�rer l'�volution de l'ensemble des Acteurs
void actualiserListeActeurs(t_listeActeurs *la,t_panda* panda,BITMAP * carte,BITMAP * collision);

/******************************************************************************
*******************************************************************************/

void affichageacteur(t_acteur*acteur,t_panda *panda,BITMAP*buffer);

/******************************************************************************
*******************************************************************************/

void affichageListeActeurs(t_listeActeurs *liste,t_panda *panda,BITMAP* buffer);

/******************************************************************************
*******************************************************************************/


// Enlever et lib�rer un acteur qui �tait dans la liste en indice i
void enleveracteur(t_listeActeurs *la,int i);

/******************************************************************************
*******************************************************************************/

// Retourne un bool�en vrai si il reste de la place
// dans la liste, faux sinon
int libreListeActeurs(t_listeActeurs *la);

/******************************************************************************
*******************************************************************************/

void etatacteur(t_acteur*acteur); // besoin d'un etat et mvt �xistant.

/******************************************************************************
*******************************************************************************/

int nombreimg(t_acteur*nouv);

/******************************************************************************
*******************************************************************************/

int pasennemi(t_acteur* gogole);


/******************************************************************************
*******************************************************************************/

// Un acteur a �t� touch� ou a touch� une cible : modifier son �tat
// ici on indique qu'il passe en comportement 1 (explosion)
// et le vecteur vitesse est divis� en norme (ralentissement)
void destinacteur(t_acteur *acteur);


/******************************************************************************
*******************************************************************************/

// G�rer collision (�ventuelle) entre un acteur  et une liste d acteurs
void collisionacteur(t_listeActeurs *acteurs,t_acteur *acteur,t_panda *panda);


/******************************************************************************
*******************************************************************************/

// G�rer les collisions entre les Acteurs (tous les Acteurs) et les Acteurs
void collisionListeActeurs(t_listeActeurs *la,t_panda *panda);

/******************************************************************************
//*******************************************************************************/

// Trier les acteurs r�f�renc�s par ordre d'�loignement d�croisssant
// n'importe quel algo de tri peut �tre utilis�...
void trierTabActeurs(t_listeActeurs * liste);

