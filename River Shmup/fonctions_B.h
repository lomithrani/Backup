void recordemo_B(int maskship[30][80],int maskwall[30][80],int maskenemy[30][80],int maskshoota[30][80],int maskshoote[30][80],char maskboss[30][80],int maskshootb[30][80],int maskshootb_1[30][80],int maskshootb_2[30][80],int maskshootb_3[30][80],int maskshootb_4[30][80],int life,int progress,int score);



void shootenemy_B(int maskshootb[30][80],int maskshootb_1[30][80],int maskshootb_2[30][80],int maskshootb_3[30][80],int maskshootb_4[30][80]);

void colision_B(int coord[2],int coordenem[11][2],int maskship[30][80],int maskwall[30][80],int maskenemy[30][80],int maskshoote[30][80],int maskshoota[30][80],char maskboss[30][80],int maskshootb[30][80],int maskshootb_1[30][80],int maskshootb_2[30][80],int maskshootb_3[30][80],int maskshootb_4[30][80],int* bosslife,int* life,int* score,int sound);

void printmap_B(int maskship[30][80],int maskwall[30][80],int maskenemy[30][80],int maskshoota[30][80],int maskshoote[30][80],char maskboss[30][80],int maskshootb[30][80],int maskshootb_1[30][80],int maskshootb_2[30][80],int maskshootb_3[30][80],int maskshootb_4[30][80]);

void decalmapL_B(char tab[30][80],int x);

void decalmapU_B(char tab[30][80],int x);

void decalmapD_B(char tab[30][80],int x);

void decalmapR_B(char tab[30][80],int x);

