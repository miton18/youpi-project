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
   				nptemp=lettreI(*tx,*ty,*tz,*ttr);
   				break;

   				case 'V':
   				nptemp=lettreV(*tx,*ty,*tz,*ttr);
   				break;

   				case 'X':
   				nptemp=lettreX(*tx,*ty,*tz,*ttr);
   				break;

   				case 'L':
   				nptemp=lettreL(*tx,*ty,*tz,*ttr);
   				break;

   				case 'C':
   				nptemp=lettreC(*tx,*ty,*tz,*ttr);
   				break;

   				case 'D':
   				nptemp=lettreD(*tx,*ty,*tz,*ttr);
   				break;

   				case 'M':
   				nptemp=lettreM(*tx,*ty,*tz,*ttr);
   				break;
   			}
   			*np +=nptemp;
   		}
   		return 0;
   	}

   	int lettreX(float* x, float* y,float* z,int* tr){
<<<<<<< HEAD

   	}
=======
   		return 1;
   	}
>>>>>>> d03161e736ff6b808b08f8d46f98a8481c72d612