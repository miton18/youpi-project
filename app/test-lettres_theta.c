#include "lettres_theta.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	int x = atoi( argv[1]);
	int y = atoi( argv[2]);
	int z = atoi( argv[3]);

	float * tx = malloc( sizeof(float) * 400 * 16 );
	float * ty = malloc( sizeof(float) * 400 * 16 );
	float * tz = malloc( sizeof(float) * 400 * 16 );
	tx[0] = x;
	ty[0] = y;
	tz[0] = z;

	//printf("tx0 %f\n", tx[0]);


	float * tt1 = malloc( sizeof(float) * 400 * 16 ); //nombre de point Max x taille float x nombre de caractere max
	float * tt2 = malloc( sizeof(float) * 400 * 16 );
	float * tt3 = malloc( sizeof(float) * 400 * 16 );


	lettresTheta(tx, ty, tz, 1, tt1, tt2, tt3);

	printf("\nVALEUR DE RETOUR: T1: %f T2: %f T3: %f\n", tt1[0], tt2[0], tt3[0]);
}
