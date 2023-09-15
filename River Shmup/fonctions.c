#define DECAL_COL 30
#define DECAL_LIG 10

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "boss.h"
#include "graph.h"
#include "fonctions.h"
#include "fonctions_B.h"
#include "menu.h"
#include "boss.h"


void sauvegarde (char* joueur,int* score,int* life,int* progress,int* niveau)
{



    FILE*fp=NULL;
    fp=fopen("fichiersauvegarde.txt","w");
    if(fp==NULL) printf("erreur");
    else

    {
        fprintf(fp,"%s %d %d %d %d",joueur,score[0],life[0],progress[0],niveau[0]);
        fclose(fp);
    }


}


void showhighscore()
{


    int i,rank=0,done=0;
    int highscore[10];
    int stamphighscore[10];
    char joueur[10][100];
    char stampjoueur[10][100];

    system("cls");

    gotoligcol(0,0);
    Color(10,0);
    printf("\n\n\t\t\t   ______ _____ _    _ _______  ______      _______ _     _ _______ _     _  _____ \n");
    printf("\t\t\t  |_____/   |    \\  /  |______ |_____/      |______ |_____| |  |  | |     | |_____]\n");
    printf("\t\t\t  |    \\_ __|__   \\/   |______ |    \\_      ______| |     | |  |  | |_____| |      \n");
    printf("\t\t\t____________________________________________________________________________________\n\n\n\n\n\n\n\n\n");
    Color(2,0);
    FILE*fp=NULL;
    fp=fopen("highscore.txt","r");

//on recupere les anciens highscore
    if(fp==NULL) printf("erreur");
    else

    {
        fscanf(fp,"%d %d %d %d %d %d %d %d %d %d",&highscore[0],&highscore[1],&highscore[2],&highscore[3],&highscore[4],&highscore[5],&highscore[6],&highscore[7],&highscore[8],&highscore[9]);
        fclose(fp);
    }

    fp=fopen("nom.txt","r");
    if(fp==NULL) printf("erreur");
    else

    {
        fscanf(fp,"%s %s %s %s %s %s %s %s %s %s",joueur[0],joueur[1],joueur[2],joueur[3],joueur[4],joueur[5],joueur[6],joueur[7],joueur[8],joueur[9]);
        fclose(fp);    //tout mettre en majuscule

        for(i=0; i<10; i++)
        {
            if((joueur[i][0]>='a')&&(joueur[i][0]<='z'))
                joueur[i][0]=(joueur[i][0]+'A'-'a');

        }
    }



    gotoligcol(DECAL_LIG,DECAL_COL+20);
    printf("                   ");
    gotoligcol(DECAL_LIG+11,DECAL_COL+20);
    printf("         %c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219);
    gotoligcol(DECAL_LIG+12,DECAL_COL+20);
    printf("         %c          %c\n",219,219);
    gotoligcol(DECAL_LIG+13,DECAL_COL+20);
    printf("%c%c%c%c%c%c%c%c%c%c    %c     %c\n",219,219,219,219,219,219,219,219,219,219,219,219);
    gotoligcol(DECAL_LIG+14,DECAL_COL+20);
    printf("%c        %c    %c     %c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoligcol(DECAL_LIG+15,DECAL_COL+20);
    printf("%c  %c  %c  %c          %c         %c\n",219,219,219,219,219,219);
    gotoligcol(DECAL_LIG+16,DECAL_COL+20);
    printf("%c  %c  %c  %c          %c  %c %c %c  %c\n",219,219,219,219,219,219,219,219,219);
    gotoligcol(DECAL_LIG+17,DECAL_COL+20);
    printf("%c        %c          %c  %c %c %c  %c\n",219,219,219,219,219,219,219);
    gotoligcol(DECAL_LIG+18,DECAL_COL+20);
    printf("%c        %c          %c         %c\n",219,219,219,219);
    gotoligcol(DECAL_LIG+19,DECAL_COL+20);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    gotoligcol(DECAL_LIG+8,DECAL_COL+30);
    Color(12,0);
    printf("%s",joueur[0]);
    gotoligcol(DECAL_LIG+9,DECAL_COL+31);
    printf("%d",highscore[0]);

    gotoligcol(DECAL_LIG+10,DECAL_COL+21);
    Color(9,0);
    printf("%s",joueur[1]);
    gotoligcol(DECAL_LIG+11,DECAL_COL+22);
    printf("%d",highscore[1]);

    gotoligcol(DECAL_LIG+11,DECAL_COL+42);
    Color(14,0);
    printf("%s",joueur[2]);
    gotoligcol(DECAL_LIG+12,DECAL_COL+43);
    printf("%d",highscore[2]);


    for(i=3; i<10; i++)
    {
        gotoligcol(DECAL_LIG+20+2*i,DECAL_COL+25);
        Color(10,0);
        printf("%d : %s - %d",i+1,joueur[i],highscore[i]);



    }


    playdemo();







    Color(2,0);
}

void shighscore(int* score)
{
    int i,rank=0,done=0;
    int highscore[10];
    int stamphighscore[10];
    char joueur[10][100];
    char stampjoueur[10][100];



    FILE*fp=NULL;
    fp=fopen("highscore.txt","r");

//on recupere les anciens highscore
    if(fp==NULL) printf("erreur");
    else

    {
        fscanf(fp,"%d %d %d %d %d %d %d %d %d %d",&highscore[0],&highscore[1],&highscore[2],&highscore[3],&highscore[4],&highscore[5],&highscore[6],&highscore[7],&highscore[8],&highscore[9]);
        fclose(fp);
    }

    for(i=0; i<10; i++)
    {
        stamphighscore[i]=highscore[i]; // on copie la chaine pour pouvoir la décalé sans probleme de repercussion
    }

    fp=fopen("nom.txt","r");
    if(fp==NULL) printf("erreur");
    else

    {
        fscanf(fp,"%s %s %s %s %s %s %s %s %s %s",joueur[0],joueur[1],joueur[2],joueur[3],joueur[4],joueur[5],joueur[6],joueur[7],joueur[8],joueur[9]);
        fclose(fp);
    }
    for(i=0; i<10; i++)
    {
        strcpy(stampjoueur[i],joueur[i]);
    }

//on traite le score actuel

    for(i=0; i<10; i++)
    {
        if((*score)>=highscore[i])
        {

            if(i<9)
            {

                highscore[i+1]=stamphighscore[i];

                strcpy(joueur[i+1],stampjoueur[i]);


                if(!done)
                {
                    highscore[i]=(*score);
                    done=1;
                    rank=i;
                }
            }

        }
    }
    fflush(stdin);
    Sleep(1000);
    system("cls");
    gotoligcol(10,20);
    printf("Vous avez le %d eme meilleur score, entrez votre nom vous figurerez dans le palmares :",rank+1);
    fflush(stdin);
    for(i=0; i<100; i++) //on nettoie la chaine de caractere
        joueur[rank][i]=' ';
    gets(joueur[rank]);

    //blindage
    do
    {
        i=0;
        while((joueur[rank][i]!=' ')&&(i<100))
        {
            i++;
        }
        joueur[rank][i]='\0';

        if((i==100)||(i==0)||(i==1))
        {
            system("cls");
            gotoligcol(10,20);
            printf("Le format de votre nom est incorrect:");
            gotoligcol(11,20);
            printf("s'il vous plait saisissez un nom celui ci doit faire entre 1 et 6 caracteres et ne pas contenir d'espace:");
            gets(joueur[rank]);
        }

    }
    while((i==100)||(i==0)||(i==1));




    fp=fopen("highscore.txt","w");
    if(fp==NULL) printf("erreur");
    else

    {
        fprintf(fp,"%d %d %d %d %d %d %d %d %d %d",highscore[0],highscore[1],highscore[2],highscore[3],highscore[4],highscore[5],highscore[6],highscore[7],highscore[8],highscore[9]);
        fclose(fp);
    }

    fp=fopen("nom.txt","w");
    if(fp==NULL) printf("erreur");
    else

    {
        fprintf(fp,"%s %s %s %s %s %s %s %s %s %s",joueur[0],joueur[1],joueur[2],joueur[3],joueur[4],joueur[5],joueur[6],joueur[7],joueur[8],joueur[9]);
        fclose(fp);
    }

}

void charge(char* joueur,int* score,int* life,int* progress,int* niveau)
{



    FILE*fp=NULL;
    fp=fopen("fichiersauvegarde.txt","r");
    if(fp==NULL) printf("erreur");
    else

    {
        fscanf(fp,"%s %d %d %d %d",joueur,score,life,progress,niveau);
        fclose(fp);
    }


}



void Color(int t, int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}
void cleantab(int* tab[30][80])
{
    int i,j;

    for(i=0; i<30; i++)
        for(j=0; j<80; j++)
            tab[i][j]=0;
}

void typing(char* string,int ligne,int colonne,int longueurligne)
{

    int key,i,j=0,k=0;
    fflush(stdin);
    Color(2,0);
    for(i=0; i<5; i++)
    {
        //faire clignoter un curseur
        gotoligcol(ligne,colonne);
        Sleep(200);
        printf(" ");
        gotoligcol(ligne,colonne);
        Sleep(200);
        printf("%c",219);

    }

    printf(" ");
    gotoligcol(ligne,colonne);
    for(i=0; i<strlen(string); i++)
    {
        if(kbhit())
        {
            key=getch();
        }
        if((key==13)||(key==27))
            i=strlen(string);

        Sleep(50);

        printf("%c",string[i]);
        if((i%longueurligne+10>=longueurligne)&&(string[i]==' ')&&((i-k)>10))//faire des que on depasse la longueur d une ligne qu on a un espace et qu on a pas fait un espace trop recement
        {
            k=i;

            j++;
            gotoligcol(ligne+j,colonne);
        }





    }

    Sleep(1000);





}


void shoota(int coord[2],int maskshoota[30][80],int key,int* bonus)
{

// coord[0] colone coord[1] ligne
    if(key==32) maskshoota[coord[1]][coord[0]+4]=1;
    if(((*bonus)>0)&&(key==32))
    {

        maskshoota[coord[1]+1][coord[0]+4]=1;
        maskshoota[coord[1]-1][coord[0]+4]=1;
    }
}



void shootenemy( int coordenem[11][2],int maskshoote[30][80])

{
    int i;
    for(i=1; i<=coordenem[0][0]; i++)
    {

        if(rand()%4==0) maskshoote[coordenem[i][1]][(coordenem[i][0])-1]=1;
    }


}

void  createnemy(int maskenemy[30][80],int coord[2],int maskwall[30][80],int niveau,int coordenem[11][2])
{

    int alea1,i,j,k,a=0,m=0,n=0,o=0;
    for(k=0; k<30; k++) //recherche des murs dans la premiere colone
    {

        if(maskwall[k][79]&&!m)//on cherche la premiere etoile
        {
            a=k; //on note la coordonnee de la premiere etoile
            m++;//on empeche de modifie celle ci a la 2 eme etoile
        }
        if(maskwall[k][79]&&m) // on ne peut rentrer qu'une fois que a a ete affecte
        {
            n=k;//on note la coordonnee de la 2 eme etoile
            o++;//on retiens qu'on lui a donner une valeur
        }

    }


    alea1=(rand()%(n-a-1))+a+1; //aleatoire entre les 2 etoiles
    maskenemy[alea1][79]=1; // on place le vaisseau enemi

    //coordenem[0][0] correspond au nombre de vaisseau deja present sur la map
    coordenem[coordenem[0][0]+1][0]= 79;
    coordenem[coordenem[0][0]+1][1]=alea1;
    coordenem[0][0]++;





}

void colision(int coord[2],int coordenem[11][2],int maskship[30][80],int maskwall[30][80],int maskenemy[30][80],int maskshoote[30][80],int maskshoota[30][80],int maskbonus[30][80],int* life,int* score,int* bonus,int sound)
{
    int i,j,k,l,a=0,m=0,n=0,o=0,colis=0;
    int test;

    for(i=0; i<30; i++)
        for(j=0; j<80; j++)
        {

            if(maskbonus[i][j]&&maskship[i][j])
            {
                maskbonus[i][j]=0;
                if(rand()%5)
                {
                    (*life)++;//4 chance sur 5 vie suplémentaire
                }
                else
                    (*bonus)++;// 1 chance sur 5 = tir multiple
            }


            if((maskship[i][j]||maskshoota[i][j]||maskshoota[i][j+1])&&maskenemy[i][j])//colision entre un enemi et un objet qui le detruit
            {
                for(k=1; k<=coordenem[0][0]; k++) //on parcours les vaisseaux enemis pour trouver qui a percuter l avion
                {
                    if((coordenem[k][0]==j)&&(coordenem[k][1]==i))
                    {
                        coordenem[k][0]=0;
                        coordenem[k][1]=0;
                        coordenem[0][0]--;//on retire un vaisseau au nbr de vaisseau present
                        refreshcoordenem(coordenem);
                        maskenemy[i][j]=0;
                        if(maskship[i][j])
                            colis++;

                        *score+=10;

                    }


                }
            }
            test=(maskwall[i][j]||maskshoote[i][j]);
            if((maskship[i][j]&&test)||colis)//collision entre avion et un objet qui le detruit
            {
                if(sound)
                printf("\a");
                if((*bonus)>0)
                    (*bonus)--;
                colis=0;
                life[0]--;//on retire une vie
                //gotoligcol(DECAL_LIG+33)
                //printf("\a");//faire un bruit + ralentir
                //on efface le vaisseau et ce qui aurais pu le percuter
                maskship[coord[1]][coord[0]]=0;
                maskship[coord[1]][coord[0]+1]=0;
                maskship[coord[1]][coord[0]+2]=0;
                maskship[coord[1]][coord[0]+3]=0;
                maskenemy[coord[1]][coord[0]]=0;
                maskenemy[coord[1]][coord[0]+1]=0;
                maskenemy[coord[1]][coord[0]+2]=0;
                maskenemy[coord[1]][coord[0]+3]=0;
                maskshoote[coord[1]][coord[0]]=0;
                maskshoote[coord[1]][coord[0]+1]=0;
                maskshoote[coord[1]][coord[0]+2]=0;
                maskshoote[coord[1]][coord[0]+3]=0;
                //on actualise les coordonnées des enemis




                for(k=0; k<30; k++) //recherche des murs dans la premiere colone
                {

                    if(maskwall[k][0]&&!m)//on cherche la premiere etoile
                    {
                        a=k; //on note la coordonnee de la premiere etoile
                        m++;//on empeche de modifie celle ci a la 2 eme etoile
                    }
                    if(maskwall[k][0]&&m) // on ne peut rentrer qu'une fois que a a ete affecte
                    {
                        n=k;//on note la coordonnee de la 2 eme etoile
                        o++;//on retiens qu'on lui a donner une valeur
                    }

                }
                if(m&&o)//les coordonees de la premiere et deuxieme etoile existe
                {
                    // on place le vaisseau entre les 2 etoiles
                    maskship[((n-a)/2)+a][0]=1;
                    maskship[((n-a)/2)+a][1]=1;
                    maskship[((n-a)/2)+a][2]=1;
                    maskship[((n-a)/2)+a][3]=1;
                    coord[0]=0;
                    coord[1]=((n-a)/2)+a;//on actualise les coordonnées
                }
            }
            if(maskshoota[i][j]&&(maskwall[i][j]||maskwall[i][j-1]))//colision missile ally mur 2 cas possible car avec le double decalage le missile pourrais traverser le mur
            {
                maskshoota[i][j]=0; //effacer le missile
            }
            if(maskshoote[i][j]&&(maskwall[i][j]||maskwall[i][j+1]))//colision missile ally mur 2 cas possible car avec le double decalage le missile pourrais traverser le mur
            {
                maskshoote[i][j]=0; //effacer le missile
            }
            //if(maskshoote[i][j]&&(maskwall[i][j]||maskwall[i][j+1]||maskwall[j+2]))//colision missile enem mur 2 cas possible car avec le double decalage le missile pourrais traverser le mur
            //{
            //    maskshoote[i][j]=0; //effacer le missile
            //}
            test=0;//test faux de base
            if(coord[0])//si on est pas tout a gauche
                test=maskenemy[i][j-2];
            if(maskshoota[i][j]&&(maskenemy[i][j]||maskenemy[i][j-1]||test)) //collision tir ally et chose qu'il detruit
            {
                maskshoota[i][j]=0;
                if(maskenemy[i][j])
                    maskenemy[i][j]--;
                if(maskenemy[i][j-1])
                    maskenemy[i][j-1]--;
                // nous n'acualisons pas les coordonnees pour pas ralentir le process elle s effaceront automatiquement quand ils auraient du passez a 0
            }








        }
}

void  decalcoordenem(int coordenem[11][2])
{
    int i,k=0;

    for(i=1; i<=coordenem[0][0]; i++)
    {
        coordenem[i][0]--;
        if(coordenem[i][0]<=0)
        {
            k++;

            coordenem[i][1]=0;
            coordenem[i][0]=0;
        }
    }
    coordenem[0][0]=coordenem[0][0]-k;

}

void  refreshcoordenem(int coordenem[11][2])
{

    int i,k=0;

    for(i=1; i<10; i++)
        if(coordenem[i][0]<=0)//si une coordonnee est (0,0)
        {
            k=0;
            do
            {
                k++;

                coordenem[i][0]=coordenem[i+k][0]; //ramener la coordonnee d'après a cet emplacement
                coordenem[i][1]=coordenem[i+k][1];
                coordenem[i+k][0]=0;
                coordenem[i+k][1]=0;
            }
            while((!coordenem[i][0])&&(k<10-i));//repeter tant qu'on a pas une valeur dans la case ou qu'on l'a fait suffisament pour etre sur de ne pas avoir laisser de valeur plus haut

        }




}


void gotoligcol( int lig, int col )
{
    // ressources
    COORD mycoord;

    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );

}

void playdemo()
{
    int i=0,j=0,k;
    int life;
    int progress;
    int score;
    int niveau=1;
    FILE*fp=NULL;
    char stamp;
    float compteur=0;
    do
    {
        compteur++;
        if((compteur/100)>=5000)
        {
            fp=fopen("demo.txt","r");
            if(fp==NULL) printf("erreur");
            else
            {
                system("cls");

                gotoligcol(0,0);
                Color(10,0);
                printf("\n\n\t\t\t       ______ _____ _    _ _______  ______      _______ _     _ _______ _     _  _____ \n");
                printf("\t\t\t      |_____/   |    \\  /  |______ |_____/      |______ |_____| |  |  | |     | |_____]\n");
                printf("\t\t\t      |    \\_ __|__   \\/   |______ |    \\_      ______| |     | |  |  | |_____| |      \n");
                printf("\t\t\t    ____________________________________________________________________________________\n\n\n\n\n\n\n\n\n");
                gotoligcol(DECAL_LIG+35,DECAL_COL+10);
                printf("DEMO : Appuyez sur n'importe quelle touche pour continuer!");
                Color(2,0);
                gotoligcol(DECAL_LIG-1,DECAL_COL-1);

                for(i=0; i<82; i++) printf("%c",219);//cadre sup

                for(i=0; i<30; i++) //cadre lateraux
                {
                    gotoligcol(DECAL_LIG+i,DECAL_COL-1);
                    printf("%c",219);
                    gotoligcol(DECAL_LIG+i,DECAL_COL+80);
                    printf("%c",219);

                }
                gotoligcol(DECAL_LIG+30,DECAL_COL-1);
                for(i=0; i<82; i++) //cadre inf
                    printf("%c",219);


                do
                {
                    i++;



                    fscanf(fp,"%c",&stamp);
                    switch(stamp)
                    {
                    case ' ':
                        printf(" ");
                        break;
                    case '*':
                        Color(14,0);
                        printf("*");
                        break;
                    case '-':
                        Color(10,0);
                        printf("-");
                        break;
                    case '_':
                        Color(12,0);
                        printf("-");
                        break;
                    case '+':
                        Color(2,0);
                        printf("+");
                        break;
                    case 'O':
                        Color(2,0);
                        printf("O");
                        break;
                    case '{':
                        Color(4,0);
                        printf("{");
                        break;
                    case '\n':
                        j++;
                        gotoligcol(DECAL_LIG+j%30,DECAL_COL);
                        break;
                    default:
                        Color(6,0);
                        printf("%c",stamp);
                        break;

                    }

                    Color(10,0);


                    if(i%((80*30)+30)==0)//revenir au debut a chaque fois qu'on a copier un ecran entier le +30 correspond au nombre de retour chariotm
                    {
                        fscanf(fp,"%d %d %d",&life,&progress,&score);//recuperez les variables

                        if(score>=1000)
                            niveau=2;
                        //afficher les variables

                        gotoligcol(DECAL_LIG+32,DECAL_COL+4);
                        printf("score: %d",score);
                        gotoligcol(DECAL_LIG+32,DECAL_COL+24);
                        printf("distance du boss: %d",400+niveau*100-progress);
                        //effacer les caracters résiduels quand ca ratrécie
                        if(400+niveau-progress<100)
                            gotoligcol(DECAL_LIG+32,DECAL_COL+45);
                        printf(" ");
                        if(400+niveau-progress<10)
                            gotoligcol(DECAL_LIG+32,DECAL_COL+44);
                        printf(" ");
                        if(400+niveau-progress<1)
                            gotoligcol(DECAL_LIG+32,DECAL_COL+43);
                        printf(" ");
                        gotoligcol(DECAL_LIG+32,DECAL_COL+54);
                        printf("Vie: ");
                        Color(13,0);
                        for(k=0; k<life; k++)
                            printf("%c",3);
                        Color(10,0);
                        //effacer les caracteres residuels
                        for(k=0; k<(10-life); k++)
                        {
                            gotoligcol(DECAL_LIG+32,DECAL_COL+68-i);
                            printf(" ");
                        }

                        gotoligcol(DECAL_LIG,DECAL_COL);

                    }


                }
                while((!feof(fp))&&(!kbhit()));
                system("cls");
                 gotoligcol(0,0);
                Color(10,0);
                printf("\n\n\t\t\t       ______ _____ _    _ _______  ______      _______ _     _ _______ _     _  _____ \n");
                printf("\t\t\t      |_____/   |    \\  /  |______ |_____/      |______ |_____| |  |  | |     | |_____]\n");
                printf("\t\t\t      |    \\_ __|__   \\/   |______ |    \\_      ______| |     | |  |  | |_____| |      \n");
                printf("\t\t\t    ____________________________________________________________________________________\n\n\n\n\n\n\n\n\n");


            }
        }
    }
    while((stamp != EOF)&&(!kbhit()));
}



void recordemo(int maskship[30][80],int maskwall[30][80],int maskenemy[30][80],int maskshoota[30][80],int maskshoote[30][80],int maskbonus[30][80],int life,int progress,int score)
{
    int i,j;
    FILE*fp=NULL;
    fp=fopen("demo.txt","a");
    if(fp==NULL) printf("erreur");
    else
    {


        for(i=0; i<30; i++)
        {



            for(j=0; j<80; j++)
            {





                if(maskship[i][j])//sa prend 4 case d'espace
                {

                    if(!maskship[i][j-1])//test pour ne pas avoir le vaisseau qui se repète
                    {



                        fprintf(fp,"+OOO");//4 case également

                    }
                }
                else  if(maskwall[i][j])
                {

                    fprintf(fp,"*");

                }

                else if(maskshoota[i][j])
                {
                    fprintf(fp,"-");
                }

                else if(maskshoote[i][j])
                {

                    fprintf(fp,"_");


                }
                else if(maskenemy[i][j])
                {

                    fprintf(fp,"{");

                }
                else if(maskbonus[i][j])
                {

                    fprintf(fp,"%c",1);

                }
                else
                {

                    fprintf(fp," ");

                }


            }

            fprintf(fp,"\n");

        }
        fprintf(fp,"%d %d %d",life,progress,score);
        fprintf(fp,"\n");

        fclose(fp);
    }
}





void createwall(int maskwall[30][80],int niveau)
{
    int i,j,k=-100,l=0;


    for(i=0; i<30; i++)
    {
        if (maskwall[i][78])//si il y a un mur dans l avant derniere colonne
        {
            do
            {
                l++; //l sert a compter le nombre de tour pour evite de se retrouver dans une situation ou notre while se repeterais en illimite car la 1ere etoile est descendu trop bas et bloque la 2 eme
                j=(rand()%3)-1;
                if((l==2)&&(maskwall[29-(13-niveau)][79]))
                {
                    maskwall[k][79]=0;
                    maskwall[k-1][79]=1;
                }

            }
            while((i+j<0)||(i+j>29)||((i+j-k)<13-niveau));

            maskwall[i+j][79]=1;
            k=i+j;

        }
    }

}

void printmap(int maskship[30][80],int maskwall[30][80],int maskenemy[30][80],int maskshoota[30][80],int maskshoote[30][80],int maskbonus[30][80])
{
    int i,j;





    for(i=0; i<30; i++)
    {
        gotoligcol(DECAL_LIG+i,DECAL_COL);

        for(j=0; j<80; j++)
        {





            if(maskship[i][j])//sa prend 4 case d'espace
            {

                if(!maskship[i][j-1])//test pour ne pas avoir le vaisseau qui se repète
                {


                    Color(2,0);
                    printf("+OOO");//4 case également
                    Color(10,0);
                }
            }
            else  if(maskwall[i][j])
            {
                Color(14,0);
                printf("*");
                Color(10,0);
            }

            else if(maskshoota[i][j])
            {
                printf("-");
            }

            else if(maskshoote[i][j])
            {
                Color(12,0);
                printf("-");
                Color(10,0);

            }
            else if(maskenemy[i][j])
            {
                Color(4,0);
                printf("{");
                Color(10,0);
            }
            else if(maskbonus[i][j])
            {
                Color(10,0);
                printf("%c",1);
                Color(10,0);
            }
            else
            {

                printf(" ");

            }


        }


    }


}

void decalmapL(int tab[30][80],int x)
{
    int i,j,k;
    //double boucle for parcours de tableau
    for(i=0; i<30; i++)
    {

        for(j=0; j<80-x; j++)
        {
            tab[i][j]=tab[i][j+x]; //on fait scroll de x par la gauche

        }
        for(k=1; k<=x; k++) //on efface les colonnes qui n ont pas été touché pour ne pas avoir de résidu
            tab[i][80-k]=0;
    }
}


void decalmapU(int tab[30][80],int x)
{
    int i,j,k;
    //double boucle for parcours de tableau
    for(i=0; i<30-x; i++)
    {

        for(j=0; j<80; j++)
        {
            tab[i][j]=tab[i+x][j]; //on fait scroll de x par la gauche

        }

    }
    for(k=1; k<=x; k++) //on efface les colonnes qui n ont pas été touché pour ne pas avoir de résidu
        for(j=0; j<80; j++)
            tab[30-k][j]=0;
}


void decalmapD(int tab[30][80],int x)
{
    int i,j,k;
    //double boucle for parcours de tableau
    for(j=0; j<80; j++)
    {
        for(i=29; i>=x; i--)
        {
            tab[i][j]=tab[i-x][j]; //on fait scroll de x par la gauche

        }

    }
    for(k=1; k<=x; k++) //on efface les colonnes qui n ont pas été touché pour ne pas avoir de résidu
        for(j=0; j<80; j++)
            tab[k-1][j]=0;
}


void decalmapR(int tab[30][80],int x)
{
    int i,j,k;
    //double boucle for pour parcours du tableau
    for(i=29; i>=0; i--)
    {

        for(j=79; j>=x; j--)
        {
            tab[i][j]=tab[i][j-x];//on scroll de x vers la droite
            tab[i][j-x]=0;
        }
        for(k=0; k<x; k++) //on efface les colonnes qui n ont pas été touché pour ne pas avoir de résidu
            tab[i][x]=0;

    }



}


void moveenemy(int maskenemy[30][80],int coordenem[11][2],int maskwall[30][80])
{

    int i,k,nbalea,nbalea1,horizmove=0,vertmove=0;
    k = rand()%2;

    for(i=1; i<=coordenem[0][0]; i++)
    {

        if((maskwall[coordenem[i][1]][coordenem[i][0]-1])&&(maskwall[coordenem[i][1]+1][coordenem[i][0]]))
            // si il y a une etoile devant et dessous le vaisseau ennemi
        {
            maskenemy[coordenem[i][1]][coordenem[i][0]]=0;// on efface le vaisseau
            coordenem[i][1]--;//on le force a monter d'une case
            maskenemy[coordenem[i][1]][coordenem[i][0]]=1;// on le replace
        }
        else if((maskwall[coordenem[i][1]][coordenem[i][0]-1])&&(maskwall[coordenem[i][1]-1][coordenem[i][0]]))
            //si il y a une etoile une etoile devant et dessus le vaisseau ennemi
        {
            maskenemy[coordenem[i][1]][coordenem[i][0]]=0;// on efface le vaisseau
            coordenem[i][1]++;//on le force a descendre d'une case
            maskenemy[coordenem[i][1]][coordenem[i][0]]=1;// on le replace
        }
        else if (maskwall[coordenem[i][1]-1][coordenem[i][0]])// si le vaisseau ennemi se trouve en bas d'une etoile
        {
            maskenemy[coordenem[i][1]][coordenem[i][0]]=0;// on efface le vaisseau
            coordenem[i][1]++;//on le force a descendre d'une case
            maskenemy[coordenem[i][1]][coordenem[i][0]]=1;// on le replace

        }
        else if(maskwall[coordenem[i][1]+1][coordenem[i][0]])// si le vaisseau ennemi se trouve en haut d'une étoile
        {
            maskenemy[coordenem[i][1]][coordenem[i][0]]=0;// on efface le vaisseau
            coordenem[i][1]--;//on le force a descendre d'une case
            maskenemy[coordenem[i][1]][coordenem[i][0]]=1;// on le replace
        }

        else //s'il n'y a aucun obstacle devant lui il bouge de maniere aleatoire
        {
            if(k==0)
//1 chance sur 2 deplacement horizontal
            {
                nbalea=rand()%2;
                maskenemy[coordenem[i][1]][coordenem[i][0]]=0;//disparition de l'enemi
                coordenem[i][0] = coordenem[i][0] - nbalea;   // nouvelle position de l'enemi
                maskenemy[coordenem[i][1]][coordenem[i][0]]=1;//actualisation des coordonnées
            }

            else
// 1 chance sur 2 depacement vertical
            {
                nbalea1=rand()%3-1;
                maskenemy[coordenem[i][1]][coordenem[i][0]] = 0;//disparition de l'enemi
                coordenem[i][1] = coordenem[i][1] - nbalea1;     // nouvelle position de l'enemi
                maskenemy[coordenem[i][1]][coordenem[i][0]]=1;   //actualisation des coordonnées
            }
        }
    }
}







void moveship(int coord[2],int maskship[30][80],int key,int keyboard)
{

    int deplig=0;
    int depcol=0;
    //fflush(stdin);

    switch(keyboard)
    {
    case 1:
        switch(key)
        {
        case '1':
//déplacement vers la diagonale basse gauche
            deplig=1;
            depcol= -1;
            break;

        case '2':
//déplacement vers le bas
            deplig= 1;
            depcol=0;
            break;


        case '3':
//déplacement vers la diagonale basse droite
            deplig= 1;
            depcol=1;
            break;

        case '4':
//déplacement vers la gauche
            deplig=0;
            depcol= -1;
            break;

        case '6':
//déplacement vers la droite
            deplig=0;
            depcol=1;
            break;

        case '7':
//déplacement diagonale haute gauche
            deplig= -1;
            depcol= -1;
            break;

        case '8':
//déplacement vers le haut
            deplig= -1;
            depcol=0;
            break;


        case '9':
//déplacement diagonale haute droite
            deplig= -1;
            depcol=1;
            break;

        }
        break;
    case 2:

        switch(key)
        {
        case 'c':
//déplacement vers la diagonale basse ga'z'che
            deplig=1;
            depcol= -1;
            break;

        case 's':
//déplacement vers le bas
            deplig= 1;
            depcol=0;
            break;


        case 'w':
//déplacement vers la diagonale basse droite
            deplig= 1;
            depcol=1;
            break;

        case 'q':
//déplacement vers la gauche
            deplig=0;
            depcol= -1;
            break;

        case 'd':
//déplacement vers la droite
            deplig=0;
            depcol=1;
            break;

        case 'a':
//déplacement diagonale haute gauche
            deplig= -1;
            depcol= -1;
            break;

        case 'z':
//déplacement vers le haut
            deplig= -1;
            depcol=0;
            break;


        case 'e':
//déplacement diagonale haute droite
            deplig= -1;
            depcol=1;
            break;

        }
        break;
    default:
        switch(key)
        {
        case 'c':
//déplacement vers la diagonale basse gauche
            deplig=1;
            depcol= -1;
            break;

        case 's':
//déplacement vers le bas
            deplig= 1;
            depcol=0;
            break;


        case 'z':
//déplacement vers la diagonale basse droite
            deplig= 1;
            depcol=1;
            break;

        case 'a':
//déplacement vers la gauche
            deplig=0;
            depcol= -1;
            break;

        case 'd':
//déplacement vers la droite
            deplig=0;
            depcol=1;
            break;

        case 'q':
//déplacement diagonale haute gauche
            deplig= -1;
            depcol= -1;
            break;

        case 'w':
//déplacement vers le haut
            deplig= -1;
            depcol=0;
            break;


        case 'e':
//déplacement diagonale haute droite
            deplig= -1;
            depcol=1;
            break;

        }
        break;
    }





//test débordements
    if ((coord[1]+deplig)>29)deplig=0;
    if ((coord[1]+deplig)<0) deplig=0;
    if ((coord[0]+depcol)>79) depcol=0;
    if ((coord[0]+depcol)<0)  depcol=0;



    //actualisation des coordonnées et replacement du vaisseau
    maskship[coord[1]][coord[0]]=0;
    maskship[coord[1]][coord[0]+1]=0;
    maskship[coord[1]][coord[0]+2]=0;
    maskship[coord[1]][coord[0]+3]=0;
    coord[0]=coord[0]+depcol;
    coord[1]=coord[1]+deplig;
    maskship[coord[1]][coord[0]]=1;
    maskship[coord[1]][coord[0]+1]=1;
    maskship[coord[1]][coord[0]+2]=1;
    maskship[coord[1]][coord[0]+3]=1;

}

void debug(int x,int niveau,int boss,int progress,int score)
{
    gotoligcol(0,0);
    printf("Niveau:%d - boss:%d - progress:%d - score:%d",niveau,boss,progress,score);
    if(niveau>x) system("pause");
}




void init_newgame(int maskship[30][80],int maskwall[30][80],int maskenemy[30][80],int maskshoota[30][80],int maskshoote[30][80],int coordenem[10][2],int* niveau,int* life,int* score,int* progress,int* bonus,int* boss,int coord[2])
{
    int i,j;


    switch(*niveau)
    {
        //nouvelle partie
    case 1:

        //conditions initiales
        *life=5;
        *score=0;
        *progress=0;
        *bonus=0;
        maskship[10][0]=1;
        coord[0]=0;
        coord[1]=10;
        *niveau=1;
        *boss=0;


        system("cls");
        gen_decor(*niveau);

        for(i=0; i<30; i++)
            for(j=0; j<80; j++)
            {
                maskship[i][j]=0;
                maskwall[i][j]=0;
                maskenemy[i][j]=0;
                maskshoota[i][j]=0;
                maskshoote[i][j]=0;

            }
        for(i=0; i<11; i++)
            for(j=0; j<2; j++)
                coordenem[i][j]=0;
        maskwall[0][79]=1;
        maskwall[29][79]=1;
        for(i=0; i<80; i++)
        {
            decalmapL(maskwall,1);
            createwall(maskwall,*niveau);
        }

        break;

        //nouvelle partie
    case 2:

        //conditions initiales
        //*life=10;
        //*score=0;
        *progress=0;
//        *bonus=0;
        maskship[10][0]=1;
        coord[0]=0;
        coord[1]=10;
        //*niveau=1;
        *boss=0;


        system("cls");

        gen_decor(*niveau);



        for(i=0; i<30; i++)
            for(j=0; j<80; j++)
            {
                maskship[i][j]=0;
                maskwall[i][j]=0;
                maskenemy[i][j]=0;
                maskshoota[i][j]=0;
                maskshoote[i][j]=0;

            }

        for(i=0; i<11; i++)
            for(j=0; j<2; j++)
                coordenem[i][j]=0;
        maskwall[0][79]=1;
        maskwall[29][79]=1;

        for(i=0; i<80; i++)
        {
            decalmapL(maskwall,1);
            createwall(maskwall,*niveau);
        }


        break;

    case 3:

        //conditions initiales
        //*life=10;
        //*score=0;
        *progress=0;
//        *bonus=0;
        maskship[10][0]=1;
        coord[0]=0;
        coord[1]=10;
        //*niveau=1;
        *boss=0;


        system("cls");

        gen_decor(*niveau);



        for(i=0; i<30; i++)
            for(j=0; j<80; j++)
            {
                maskship[i][j]=0;
                maskwall[i][j]=0;
                maskenemy[i][j]=0;
                maskshoota[i][j]=0;
                maskshoote[i][j]=0;

            }

        for(i=0; i<11; i++)
            for(j=0; j<2; j++)
                coordenem[i][j]=0;
        maskwall[0][79]=1;
        maskwall[29][79]=1;

        for(i=0; i<80; i++)
        {
            decalmapL(maskwall,1);
            createwall(maskwall,*niveau);
        }


        break;

    case 4:

        //conditions initiales
        //*life=10;
        //*score=0;
        *progress=0;
//        *bonus=0;
        maskship[10][0]=1;
        coord[0]=0;
        coord[1]=10;
        //*niveau=1;
        *boss=0;


        system("cls");

        gen_decor(*niveau);



        for(i=0; i<30; i++)
            for(j=0; j<80; j++)
            {
                maskship[i][j]=0;
                maskwall[i][j]=0;
                maskenemy[i][j]=0;
                maskshoota[i][j]=0;
                maskshoote[i][j]=0;

            }

        for(i=0; i<11; i++)
            for(j=0; j<2; j++)
                coordenem[i][j]=0;
        maskwall[0][79]=1;
        maskwall[29][79]=1;

        for(i=0; i<80; i++)
        {
            decalmapL(maskwall,1);
            createwall(maskwall,*niveau);
        }


        break;

    case 5:

        //conditions initiales
        //*life=10;
        //*score=0;
        *progress=0;
//        *bonus=0;
        maskship[10][0]=1;
        coord[0]=0;
        coord[1]=10;
        //*niveau=1;
        *boss=0;


        system("cls");

        gen_decor(*niveau);



        for(i=0; i<30; i++)
            for(j=0; j<80; j++)
            {
                maskship[i][j]=0;
                maskwall[i][j]=0;
                maskenemy[i][j]=0;
                maskshoota[i][j]=0;
                maskshoote[i][j]=0;

            }

        for(i=0; i<11; i++)
            for(j=0; j<2; j++)
                coordenem[i][j]=0;
        maskwall[0][79]=1;
        maskwall[29][79]=1;

        for(i=0; i<80; i++)
        {
            decalmapL(maskwall,1);
            createwall(maskwall,*niveau);
        }


        break;


    }


}

void createbonus(int maskbonus[30][80], int maskwall[30][80])
{
    int alea1,i,j,k,a=0,m=0,n=0,o=0,alea2;
    alea2=rand()%200;
    if(alea2==0)
    {

        for(k=0; k<30; k++) //recherche des murs dans la premiere colone
        {

            if(maskwall[k][79]&&!m)//on cherche la premiere etoile
            {
                a=k; //on note la coordonnee de la premiere etoile
                m++;//on empeche de modifie celle ci a la 2 eme etoile
            }
            if(maskwall[k][79]&&m) // on ne peut rentrer qu'une fois que a a ete affecte
            {
                n=k;//on note la coordonnee de la 2 eme etoile
                o++;//on retiens qu'on lui a donner une valeur
            }

        }


        alea1=(rand()%(n-a-1))+a+1; //aleatoire entre les 2 etoiles
        maskbonus[alea1][79]=1; // on place le bonus

    }

}


void options(int* keyboard,int* sound)
{

    int key;
    int i;


    i=0;

    system("cls");

    gotoligcol(0,0);
    Color(10,0);
    printf("\n\n\t\t\t   ______ _____ _    _ _______  ______      _______ _     _ _______ _     _  _____ \n");
    printf("\t\t\t  |_____/   |    \\  /  |______ |_____/      |______ |_____| |  |  | |     | |_____]\n");
    printf("\t\t\t  |    \\_ __|__   \\/   |______ |    \\_      ______| |     | |  |  | |_____| |      \n");
    printf("\t\t\t____________________________________________________________________________________\n\n\n\n\n\n\n\n\n");
    Color(2,0);




    do
    {

        gotoligcol(14,0);
        if(i==0)Color(10,0);
        printf("\t\t    ____ ____ _  _ \n");
        printf("\t\t    [__  |  | |\\ | \n");
        printf("\t\t    ___] |__| | \\| \n\n\n\n\n");
        Color(2,0);
        if(i==1)Color(10,0);
        printf("\t\t    ___ _   _ ___  ____    ___  ____    ____ _    ____ _  _ _ ____ ____   \n");
        printf("\t\t     |   \\_/  |__] |___    |  \\ |___    |    |    |__| |  | | |___ |__/ \n");
        printf("\t\t     |    |   |    |___    |__/ |___    |___ |___ |  |  \\/  | |___ |  \\ \n\n\n");
        Color(2,0);
        if(i==2)Color(10,0);

        gotoligcol(28,88+10);
        printf("____ _  _ ");
        gotoligcol(29,88+10);
        printf("|  | |_/  ");
        gotoligcol(30,88+10);
        printf("|__| | \\_ ");
        Color(2,0);


        if(i==0)
            Color(10,0);

        if (*sound==1)
        {
            gotoligcol(14,86+10);
            printf(" ____ _  _ _");
            gotoligcol(15,86+10);
            printf(" |  | |  | |");
            gotoligcol(16,86+10);
            printf(" |__| |__| |");
        }
        else
        {
            gotoligcol(14,86+10);
            printf("_  _ ____ _  _   ");
            gotoligcol(15,86+10);
            printf("|\\ | |  | |\\ | ");
            gotoligcol(16,86+10);
            printf("| \\| |__| | \\| ");
        }
        Color(2,0);
        if(i==1)Color(10,0);
        if(*keyboard==1)
        {
            gotoligcol(21,88+10);
            printf(" 7  8  9 ");
            gotoligcol(22,88+10);
            printf(" 4     6 ");
            gotoligcol(23,88+10);
            printf(" 1  2  3 ");
        }
        else if (*keyboard==2)
        {
            gotoligcol(21,88+10);
            printf(" A  Z  E ");
            gotoligcol(22,88+10);
            printf(" Q     D ");
            gotoligcol(23,88+10);
            printf(" W  X  C ");
        }
        else
        {
            gotoligcol(21,88+10);
            printf(" Q  W  E ");
            gotoligcol(22,88+10);
            printf(" A     D ");
            gotoligcol(23,88+10);
            printf(" Z  X  C ");
        }
        Color(2,0);


        Color(10,0);
        gotoligcol(14+(i*7),80+10);
        printf(" /");
        gotoligcol(15+(i*7),80+10);
        printf("<");
        gotoligcol(16+(i*7),80+10);
        printf(" \\");



        gotoligcol(14+(i*7),103+10);
        printf("\\");
        gotoligcol(15+(i*7),103+10);
        printf(" >");
        gotoligcol(16+(i*7),103+10);
        printf("/");
        Color(2,0);


        gotoligcol(0,0);
        printf(" ");

        playdemo();
        key=getch();
        gotoligcol(14+(i*7),80+10);
        printf("       ");
        gotoligcol(15+(i*7),80+10);
        printf("       ");
        gotoligcol(16+(i*7),80+10);
        printf("       ");

        gotoligcol(14+(i*7),103+10);
        printf("       ");
        gotoligcol(15+(i*7),103+10);
        printf("       ");
        gotoligcol(16+(i*7),103+10);
        printf("       ");

        gotoligcol(14+(i*7),86+10);
        printf("                   ");
        gotoligcol(15+(i*7),86+10);
        printf("                   ");
        gotoligcol(16+(i*7),86+10);
        printf("                   ");


        if(key=='2'||key==80)i++;
        if(key=='8'||key==72)i--;
        if((i==0)&&(key=='4'||key==75||key=='6'||key==77)) (*sound)=((*sound)+1)%2;
        if((i==1)&&(key=='4'||key==75||key=='6'||key==77))(*keyboard)=((*keyboard)+1)%3;

        if(i<0) i=0;
        if(i>2) i=2;


    }
    while((i!=2)||(key!=13));

}
