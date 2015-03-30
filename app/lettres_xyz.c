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
   		for (i = 0; i < sizeof(str); ++i)
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

   	int lettreX(float* x, float* y,float* z,int* tr,int i,int *indice){
         int nbp=200;
         float hypo=sqrt(pow(9,2)+pow(11,2));
         float pas=hypo*2/nbp;
         float j;
         for (j = 0; j < hypo; j+=pas)
         {
            x[*indice]=(11/9)*j+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            if(i==(hypo-pas)){
               tr[*indice]=0;
            }
            else {
               tr[*indice]=1;
            }
            *indice++;
         }
         for (j = 0; j < hypo;j+=pas )
         {
            x[*indice]=((-11*j/9)+11)+145;
            y[*indice]=50;
            z[*indice]=j+(i*18);
            if(i==(hypo-pas)){
               tr[*indice]=0;
            }
            else {
               tr[*indice]=1;
            }
            *indice++;
         }

   	}
      int lettreI(float* x, float* y,float* z,int* tr,int i,int *indice){
         int nbp=150;
         float pas = (11+9*2)/nbp;
         float j;
         //points du trait du haut
         for (j = 0; j < 9; j+=pas)
         {
            x[*indice]=11+145;
            y[*indice]=50;
            z[*indice]=j+(i*18)-139.5;
            if(j==(9-pas)){
               tr[*indice]=0;
            }
            else {
               tr[*indice]=1;
            }
            *indice++;
         }
         //points du trait du bas
         for (j = 0; j < 9; j+=pas)
         {
            x[*indice]=0+145;
            y[*indice]=50;
            z[*indice]=j+(i*18);
            if(j==(9-pas)){
               tr[*indice]=0;
            }
            else {
               tr[*indice]=1;
            }
            *indice++;
         }
         //points du trait du milieu
         for (j = 0; j < 11; j+=pas)
         {
            x[*indice]=j+145;
            y[*indice]=50;
            z[*indice]=4.5+(i*18);
            tr[*indice]=1;
            *indice++;
         }
      }
      int lettreM(float* x, float* y,float* z,int* tr,int i,int *indice){
         int nbp=200;
         float pas = (11*2)/nbp;
         float j;
         //points du 1er trait vertical
         for (j = 0; j < 9; j+=pas)
         {
            x[*indice]=j+145;
            y[*indice]=50;
            z[*indice]=0+(i*18);
            if(j==(9-pas)){
               tr[*indice]=0;
            }
            else {
               tr[*indice]=1;
            }
            *indice++;
         }
         //points du 1er trait diagonal
         for (j = 0; j < 9; j+=pas)
         {
            x[*indice]=(-2*11/9)+11+145;
            y[*indice]=50;
            z[*indice]=j+(i*18);
            if(j==(9-pas)){
               tr[*indice]=0;
            }
            else {
               tr[*indice]=1;
            }
            *indice++;
         }
         //points du 2eme trait diagonal
         for (j = 0; j < 11; j+=pas)
         {
            x[*indice]=(2*11/9)-11+145;
            y[*indice]=50;
            z[*indice]=j+(i*18);
            if(j==(9-pas)){
               tr[*indice]=0;
            }
            else {
               tr[*indice]=1;
            }
            *indice++;
         }
         //points du 2em trait vertical
         for (j = 0; j < 11; j+=pas)
         {
            x[*indice]=j+145;
            y[*indice]=50;
            z[*indice]=9+(i*18);
            if(j==(9-pas)){
               tr[*indice]=0;
            }
            else {
               tr[*indice]=1;
            }
            *indice++;
         }
      }
      int lettreV(float* x, float* y,float* z,int* tr,int i,int *indice){}
      int lettreC(float* x, float* y,float* z,int* tr,int i,int *indice){}
      int lettreD(float* x, float* y,float* z,int* tr,int i,int *indice){}
      int lettreL(float* x, float* y,float* z,int* tr,int i,int *indice){}