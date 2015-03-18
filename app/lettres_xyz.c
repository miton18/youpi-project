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

   		for (int i = 0; i < sizeof(str); ++i)
   		{
   			temp = str[i];
   			switch (temp)
   			{
   				case 'I':
   				nptemp=lettreI(tx,ty,tz,ttr);
   				break;

   				case 'V':
   				nptemp=lettreV(tx,ty,tz,ttr);
   				break;

   				case 'X':
   				nptemp=lettreX(tx,ty,tz,ttr);
   				break;

   				case 'L':
   				nptemp=lettreL(tx,ty,tz,ttr);
   				break;

   				case 'C':
   				nptemp=lettreC(tx,ty,tz,ttr);
   				break;

   				case 'D':
   				nptemp=lettreD(tx,ty,tz,ttr);
   				break;

   				case 'M':
   				nptemp=lettreM(tx,ty,tz,ttr);
   				break;
   			}
   			*np +=nptemp;
   		}
   		return 0;
   	}

   	int lettreX(float* x, float* y,float* z,int* tr){

   	}
         int lettreI(float* x, float* y,float* z,int* tr){}
   int lettreM(float* x, float* y,float* z,int* tr){}
   int lettreV(float* x, float* y,float* z,int* tr){}
   int lettreC(float* x, float* y,float* z,int* tr){}
   int lettreD(float* x, float* y,float* z,int* tr){}
   int lettreL(float* x, float* y,float* z,int* tr){}