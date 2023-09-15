void Color(int t, int f);

void sauvegarde (char* joueur,int* score,int* life,int* progress,int* niveau);

void showhighscore();

void debug(int x,int niveau,int boss,int progress,int score);

void shighscore(int* score);

void options(int* keyboard,int* sound);

void charge(char* joueur,int* score,int* life,int* progress,int* niveau);

void createbonus(int maskbonus[30][80], int maskwall[30][80]);

void cleantab(int* tab[30][80]);

void typing(char* string,int ligne,int colonne,int longueurligne);

void shoota(int coord[2],int maskshoota[30][80],int key,int* bonus);

void shootenemy( int coordenem[11][2],int maskshoote[30][80]);

void  createnemy(int maskenemy[30][80],int coord[2],int maskwall[30][80],int niveau,int coordenem[11][2]);

void colision(int coord[2],int coordenem[11][2],int maskship[30][80],int maskwall[30][80],int maskenemy[30][80],int maskshoote[30][80],int maskshoota[30][80],int maskbonus[30][80],int* life,int* score,int* bonus,int colision);

void  decalcoordenem(int coordenem[11][2]);

void  refreshcoordenem(int coordenem[11][2]);

void playdemo();

void gotoligcol( int lig, int col );

void createwall(int maskwall[30][80],int niveau);

void recordemo(int maskship[30][80],int maskwall[30][80],int maskenemy[30][80],int maskshoota[30][80],int maskshoote[30][80],int maskbonus[30][80],int life,int progress,int score);


void printmap(int maskship[30][80],int maskwall[30][80],int maskenemy[30][80],int maskshoota[30][80],int maskshoote[30][80],int maskbonus[30][80]);

void decalmapL(int tab[30][80],int x);
void decalmapU(int tab[30][80],int x);
void decalmapD(int tab[30][80],int x);
void decalmapR(int tab[30][80],int x);

void moveenemy(int maskenemy[30][80],int coordenem[11][2],int maskwall[30][80]);

void moveship(int coord[2],int maskship[30][80],int key,int keyboard);

void init_newgame(int maskship[30][80],int maskwall[30][80],int maskenemy[30][80],int maskshoota[30][80],int maskshoote[30][80],int coordenem[10][2],int* niveau,int* life,int* score,int* progress,int* bonus,int* boss,int coord[2]);

