/* ------------------------------------------------------
   Auteur : Collignon Rémi
   			Morvan Guy-Yann
   	Header Fonction lettresTheta
 -----------------------------------------------------*/

#include "lettres_theta.h"


void lettresTheta(float* tx, float* ty, float* tz, int np, float* tt1, float* tt2, float* tt3)
{

	for (int i=0; i< np; i++) // tout les indices du/des tableaux
	{
		tt1[i]= (float) atan( - tz[i] / tx[i]);
		tt2[i]= (float) -acos(1);
		tt3[i]= (float) 2.0;
	}
}
