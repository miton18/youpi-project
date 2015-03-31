/* ------------------------------------------------------
   Auteur : Collignon Rémi
   			Morvan Guy-Yann
   	Fonction lettresXYZ
   	Création des trajectoires en x,y,z 
   	-----------------------------------------------------*/
#include "lettres_xyz.h"

   	void lettresXYZ(char* str, float* tx, float* ty,float* tz,int* ttr,int* np){
         char temp;
         int nptemp=0;
         int indiceTableau=0;
         int i;
         for (i = 0; i < strlen(str); ++i)
         {
            temp = str[i];
            switch (temp)
            {
               case 'I':
   				nptemp=lettreI(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   				case 'V':
   				nptemp=lettreV(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   				case 'X':
   				nptemp=lettreX(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   				case 'L':
   				nptemp=lettreL(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   				case 'C':
   				nptemp=lettreC(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   				case 'D':
   				nptemp=lettreD(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   				case 'M':
   				nptemp=lettreM(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   			}
   			*np +=nptemp;
   		}
   	}

   	int lettreX(float* x, float* y,float* z,int* tr,int i,int* indice){
         int nbp=202;
         float pas = 9*2/((float) nbp);
/*         float hypo=sqrt(pow(9,2)+pow(11,2));
         float pas=hypo*2/((float)nbp);*/
         float j;
         int trace = 1;
         //tracé points deuxieme diagonale
         for (j = 0; j < 9; j=j+pas)
         {
            x[*indice]=(11/9)*j +145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            if (trace==1){
               tr[*indice]=0;
               trace =0;
            }else
            {
               tr[*indice]=1;
            }
            *indice=*indice+1;
         }
         trace =1;
         //tracé points première diagonale
         for (j = 0; j < 9;j=j+pas )
         {
            x[*indice]=((-11/9)*j+11)+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            if (trace==1){
               tr[*indice]=0;
               trace =0;
            }else
            {
               tr[*indice]=1;
            }
            *indice=*indice+1;
         }
         return nbp;

   	}

      int lettreI(float* x, float* y,float* z,int* tr,int i,int* indiceTableau){
         int nbp=150;
         float pas = (11+9*2)/((float)nbp);
         float pas2 = (0);
         float j;
         int trace = 1;
         //tracé points du trait du haut
         for (j = 0; j < 9; j=j+pas)
         {
            x[*indiceTableau]=11+145;
            y[*indiceTableau]=50;
            z[*indiceTableau]=j+(i*18)-139.5;
            if (trace == 1){
               tr[*indiceTableau]=0;
               trace=0;
            }
            else{
               tr[*indiceTableau]=1;
            }
            *indiceTableau=*indiceTableau+1;
         }
         trace =1;
         //tracé points du trait du milieu
         for (j = 0; j < 11; j+=pas)
         {
            x[*indiceTableau]=j+145;
            y[*indiceTableau]=50;
            z[*indiceTableau]=4.5+(i*18)-139.5;
            if (trace == 1){
               tr[*indiceTableau]=0; 
               trace = 0;
            }
            else{
               tr[*indiceTableau]=1;
            }
            *indiceTableau=*indiceTableau+1;
         }
         trace =1;
         //tracé points du trait du bas
         for (j = 0; j < 9; j+=pas)
         {
            x[*indiceTableau]=0+145;
            y[*indiceTableau]=50;
            z[*indiceTableau]=j+(i*18)-139.5;
            if (trace == 1){
               tr[*indiceTableau]=0; 
               trace = 0;
            }
            else{
               tr[*indiceTableau]=1;
            }
            *indiceTableau=*indiceTableau+1;
         }
         return nbp;
      }

      int lettreM(float* x, float* y,float* z,int* tr,int i,int* indice){
         int nbp=200;
/*         float hypo = sqrt(pow(11,2)+pow(4.5,2));
         float pas = (hypo*2+11*2)/((float)nbp);*/
         float pas = (9+11*2)/(float)nbp;
         float j;
         int trace =1;
         //tracé points du 1er trait vertical
         for (j = 0; j < 11; j=j+pas)
         {
            x[*indice]=j+145;
            y[*indice]=50;
            z[*indice]=0+(i*18)-139.5;
            if (trace == 1){
               tr[*indice]=0; 
               trace = 0;
            }
            else{
               tr[*indice]=1;
            }
            *indice=*indice+1;
         }
         //tracé points du 1er trait diagonal
         for (j = 0; j < 4.5; j=j+pas)
         {
            x[*indice]=(-2*11*j/9)+11+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         //tracé points du 2eme trait diagonal
         for (j = 4.5; j < 9; j=j+pas)
         {
            x[*indice]=(2*11*j/9)-11+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         //tracé points du 2em trait vertical
         for (j = 0; j < 11; j=j+pas)
         {
            x[*indice]=j+145;
            y[*indice]=50;
            z[*indice]=9+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         tr[*indice-1]=0;
         return nbp;
      }

      int lettreV(float* x, float* y,float* z,int* tr,int i,int* indice){
         int nbp=200;
/*         float hypo = sqrt(pow(11,2)+pow(4.5,2));
         float pas = (hypo*2)/((float)nbp);*/
         float pas = 9/(float)nbp;
         float j;
         int trace = 1 ;
         //tracé points du 1er trait diagonal
         for (j = 0; j < 4.5; j=j+pas)
         {
            x[*indice]=(-2*11*j/9)+11+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            if (trace == 1){
               tr[*indice]=0; 
               trace = 0;
            }
            else{
               tr[*indice]=1;
            }
            *indice=*indice+1;
         }
         //tracé points du 2eme trait diagonal
         for (j = 4.5; j < 9; j=j+pas)
         {
            x[*indice]=(2*11*j/9)-11+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         tr[*indice-1]=0;
         printf("indice = %d\n",*indice );
         return nbp;
      }

      int lettreC(float* x, float* y,float* z,int* tr,int i,int* indice){
         int nbp=200;
         float j;
         float pas = 180/((float)nbp);

         //tracé point de l'ellipse
         for ( j = 0; j < 181; j=j+pas)
         {
            x[*indice]=5.5*cos(j)+145;
            y[*indice]=50;
            z[*indice]=4.5*sin(j)+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         tr[*indice-1]=0;
         return nbp;
      }

      int lettreD(float* x, float* y,float* z,int* tr,int i,int* indice){
         int nbp=200;
         float j;
         float pas1 = 11/(0.35*(float)nbp);
         float pas2 = 180/(0.75*(float)nbp);

         //tracé points du trait vertical
         for (j = 0; j < 11; j=j+pas1)
         {
            x[*indice]=j+145;
            y[*indice]=50;
            z[*indice]=0+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;      
         }

         // tracé points de l'ellipse
         for ( j = 0; j > -180; j=j-pas2)
         {
            x[*indice]=5.5*cos(j)+145;
            y[*indice]=50;
            z[*indice]=9*sin(j)+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         tr[*indice-1]=0;
         return nbp;
      }

      int lettreL(float* x, float* y,float* z,int* tr,int i,int* indice){
         int nbp=202;
         float pas = (9+11)/((float)nbp);
         float j;
         int trace = 1;
         //tracé points du trait vertical
         for (j = 0; j < 11; j=j+pas)
         {
            x[*indice]=j+145;
            y[*indice]=50;
            z[*indice]=0+(i*18)-139.5;
            if(trace == 1){
               tr[*indice]=0;
               trace = 0;
            }
            tr[*indice]=1;
            *indice=*indice+1;
         }
         //tracé points du trait orizontal
         for (j = 0; j < 9; j=j+pas)
         {
            x[*indice]=0+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         tr[*indice-1]=0;
         return nbp;
      }