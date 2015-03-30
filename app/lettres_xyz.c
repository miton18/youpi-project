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
         printf("%d\n",strlen(str) );
         for (i = 0; i < strlen(str); ++i)
         {
            temp = str[i];
            switch (temp)
            {
               case 'I':
   				nptemp=lettreI(tx,ty,tz,ttr,i,&indiceTableau);
               printf("fini\n");
   				break;

   				case 'V':
               printf("Dans V\n");
   				nptemp=lettreV(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   				case 'X':
               printf("Dans X\n");
   				nptemp=lettreX(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   				case 'L':
               printf("Dans L\n");
   				//nptemp=lettreL(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   				case 'C':
               printf("Dans C\n");
   				//nptemp=lettreC(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   				case 'D':
               printf("Dans D\n");
   				//nptemp=lettreD(tx,ty,tz,ttr,i,&indiceTableau);
   				break;

   				case 'M':
               printf("Dans M\n");
   				//nptemp=lettreM(tx,ty,tz,ttr,i,&indiceTableau);
   				break;
   			}
   			*np +=nptemp;
            printf("nb = %d\n",*np );
   		}
   	}

   	int lettreX(float* x, float* y,float* z,int* tr,int i,int* indice){
         int nbp=202;
         float hypo=sqrt(pow(9,2)+pow(11,2));
         float pas=hypo*2/nbp;
         float j;
         for (j = 0; j < hypo; j+=pas)
         {
            x[*indice]=(11/9)*j +145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         tr[*indice-1]=0;
         for (j = 0; j < hypo;j+=pas )
         {
            x[*indice]=((-11*j/9)+11)+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         tr[*indice-1]=0;
         return nbp;

   	}

      int lettreI(float* x, float* y,float* z,int* tr,int i,int* indiceTableau){
         int nbp=150;
         float pas = 0;
         pas = (11+9*2)/((float)nbp);
         float j;
         //points du trait du haut
         for (j = 0; j < 9; j=j+pas)
         {
            x[*indiceTableau]=11+145;
            y[*indiceTableau]=50;
            z[*indiceTableau]=j+(i*18)-139.5;
            tr[*indiceTableau]=1;
            *indiceTableau=*indiceTableau+1;
         }
         tr[*indiceTableau-1]=0;
         //points du trait du bas
         for (j = 0; j < 9; j+=pas)
         {
            x[*indiceTableau]=0+145;
            y[*indiceTableau]=50;
            z[*indiceTableau]=j+(i*18)-139.5;
            tr[*indiceTableau]=1;
            *indiceTableau=*indiceTableau+1;
         }
         tr[*indiceTableau-1]=0;
         //points du trait du milieu
         for (j = 0; j < 11; j+=pas)
         {
            x[*indiceTableau]=j+145;
            y[*indiceTableau]=50;
            z[*indiceTableau]=4.5+(i*18)-139.5;
            tr[*indiceTableau]=1;
            tr[*indiceTableau]=1;
            *indiceTableau=*indiceTableau+1;
         }
         tr[*indiceTableau-1]=0;
         return nbp;
      }

      int lettreM(float* x, float* y,float* z,int* tr,int i,int* indice){
         int nbp=200;
         float hypo = sqrt(pow(11,2)+pow(4.5,2));
         float pas = (hypo*2+11*2)/nbp;
         float j;
         //points du 1er trait vertical
         for (j = 0; j < 9; j+=pas)
         {
            x[*indice]=j+145;
            y[*indice]=50;
            z[*indice]=0+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         //points du 1er trait diagonal
         for (j = 0; j < 9; j+=pas)
         {
            x[*indice]=(-2*11/9)+11+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         //points du 2eme trait diagonal
         for (j = 0; j < 11; j+=pas)
         {
            x[*indice]=(2*11/9)-11+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         //points du 2em trait vertical
         for (j = 0; j < 11; j+=pas)
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
         float hypo = sqrt(pow(11,2)+pow(4.5,2));
         float pas = (hypo*2)/nbp;
         float j;
         //points du 1er trait diagonal
         for (j = 0; j < hypo; j+=pas)
         {
            x[*indice]=(-2*11/9)+11+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         //points du 2eme trait diagonal
         for (j = 0; j < hypo; j+=pas)
         {
            x[*indice]=(2*11/9)-11+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         tr[*indice-1]=0;
         return nbp;
      }

      int lettreC(float* x, float* y,float* z,int* tr,int i,int* indice){
         int nbp=200;
         return nbp;
      }

      int lettreD(float* x, float* y,float* z,int* tr,int i,int* indice){
         int nbp=200;
         return nbp;
      }

      int lettreL(float* x, float* y,float* z,int* tr,int i,int* indice){
         int nbp=202;
         float pas = (11+9)/nbp;
         float j;
         //points du trait vertical
         for (j = 0; j < 9; j+=pas)
         {
            x[*indice]=j+145;
            y[*indice]=50;
            z[*indice]=0+(i*18)-139.5;
            tr[*indice]=1;
            *indice=*indice+1;
         }
         //points du trait orizontal
         for (j = 0; j < 11; j+=pas)
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