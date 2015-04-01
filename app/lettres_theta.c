/* ------------------------------------------------------
   Auteur : Collignon Rémi
   			Morvan Guy-Yann
   	Header Fonction lettresTheta
   	Conversion en angles
 -----------------------------------------------------*/

#include "lettres_theta.h"

/* Fonction lettresTheta
   parametre : float* tx , tableau contenant les coordonnées x
   			   float* ty , tableau contenant les coordonnées y
   			   float* tz , tableau contenant les coordonnées z
   			   int np , nombre de points total
   			   float* tt1 , tableau contenant les angles theta1(sortie)
   			   float* tt2 , tableau contenant les angles theta2(sortie)
   			   float* tt3 , tableau contenant les angles theta3(sortie)
*/
void lettresTheta(float* tx, float* ty, float* tz, int np, float* tt1, float* tt2, float* tt3)
{
	int i;

	for ( i=0; i< np; i++) // tout les indices du/des tableaux
	{
		//printf("LETTRETHETA x: %f y: %f z: %f\n", tx[i], ty[i], tz[i]); //OK

		tt1[i]= atan( - tz[i] / tx[i]) * 57.295779513082;
		tt3[i]= acos(
							(  pow(tx[i],2)
							 + pow(tz[i],2)
							 + pow((ty[i] - L1),2)
							 - pow(L2,2)
							 - pow(L3,2) )/ ( 2 * L2 * L3 )) * -57.295779513082;
		tt2[i]= -0.5 * (acos(
							( pow(tx[i],2) + pow(tz[i],2) - pow((ty[i]-L1),2) )
							/
							( pow(tx[i],2) + pow(tz[i],2) + pow((ty[i]-L1),2) )
						)* 57.295779513082 + tt3[i]);
	}
	//printf("Angles: T1: %f, T2: %f, T3: %f", tt1[0], tt2[0], tt3[0]);
}
