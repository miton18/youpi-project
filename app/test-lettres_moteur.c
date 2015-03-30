/* ------------------------------------------------------
   Auteur : Collignon Rémi
   			Morvan Guy-Yann
   	Fonction test-Lettres_moteur
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "lettres_moteur.h"

int main(int argc, char* argv[]) {


	float * tt1 = malloc(sizeof(float) * 3 );
	float * tt2 = malloc(sizeof(float) * 3 );
	float * tt3 = malloc(sizeof(float) * 3 );
	int	  * ttr = malloc(sizeof(int)   * 3 );
	int 	np  = 3;

	tt1[0] = 0.0;
	tt2[0] = 0.0;
	tt3[0] = 0.0;
	ttr[0] = 1;

	//test n°1
	tt1[1] = 3.26;
	tt2[1] = 0.0;
	tt3[1] = 0.0;
	ttr[1] = 1;

	//test n°2
	/*tt1[1] = 0.0;
	tt2[1] = 2.81;
	tt3[1] = 0.0;
	ttr[1] = 1;*/

	//test n°3
	/*tt1[1] = 0.0;
	tt2[1] = 0.0;
	tt3[1] = 2.81;
	ttr[1] = 1;*/

	tt1[2] = -50.0;
	tt2[2] = 20.0;
	tt3[2] = -2.81;
	ttr[2] = 1;


	lettresMoteur(tt1, tt2, tt3, ttr, np);
	return 0;
}
