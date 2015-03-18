/* ------------------------------------------------------
   Auteur : Collignon Rémi
   			Morvan Guy-Yann
   	Header Fonction lettresTheta
 -----------------------------------------------------*/

#include "lettres_theta.h"


void lettresTheta(float* tx, float* ty, float* tz, int np, float* tt1, float* tt2, float* tt3)
{
	//ALLOCATION MEMOIRE DES TABLEAUX -- MEMOIRE MAX
	tt1 = malloc( sizeof(float) * 400 * np ); //nombre de point Max x taille float x nombre d'indices
	tt2 = malloc( sizeof(float) * 400 * np );
	tt3 = malloc( sizeof(float) * 400 * np );


	for (int i=0; i< np; i++) // tout les indices du/des tableaux
	{
		tt1[i]= ;
		tt2[i]= ;
		tt3[i]= ;
	}
}
