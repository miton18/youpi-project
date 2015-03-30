#include <stdio.h>
#include <stdlib.h>
#include "lettres_moteur.h"

int main(int argc, char* argv[]) {


	float * tt1 = malloc(sizeof(float) *2 );
	float * tt2 = malloc(sizeof(float) *2 );
	float * tt3 = malloc(sizeof(float) *2 );
	int	  * ttr = malloc(sizeof(float) *2 );
	int 	np  = 2;

	tt1[0] = 0.0;
	tt2[0] = 0.0;
	tt3[0] = 0.0;
	ttr[0] = 1;

	//test n°1
	tt1[0] = 3.26;
	tt2[0] = 0.0;
	tt3[0] = 0.0;
	ttr[0] = 1;

	//test n°2
	/*tt1[0] = 0.0;
	tt2[0] = 2.81;
	tt3[0] = 0.0;
	ttr[0] = 1;*/

	//test n°3
	/*tt1[0] = 0.0;
	tt2[0] = 0.0;
	tt3[0] = 2.81;
	ttr[0] = 1;*/

	lettresMoteur(tt1, tt2, tt3, ttr, np);

	return 0;
}
