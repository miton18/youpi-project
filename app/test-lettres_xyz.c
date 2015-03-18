#include "lettres_xyz.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	char * str = argv[1];

	float * tx =  malloc(sizeof(float) * 400 * strlen(str));
	float * ty =  malloc(sizeof(float) * 400 * strlen(str));
	float * tz =  malloc(sizeof(float) * 400 * strlen(str));
	int   * ttr = malloc(sizeof(float) * 400 * strlen(str));

	int np;

	lettresXYZ( str, tx, ty, tz, ttr, &np);

	printf("nombre de points: %d", np);
	for( int i=0; i< np; i++)
	{
		printf("\nRETOUR: x=%d y=%d z=%d tr=%d", tx[i], ty[i], tz[i], ttr[i]);
	}

}
