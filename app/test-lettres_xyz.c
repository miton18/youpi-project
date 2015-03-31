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

	int np=0;

	lettresXYZ( str, tx, ty, tz, ttr, &np);

	printf("nombre de points: %d", np);

	int i;
	for(i=0; i< np; i++)

	{
		printf("\nRETOUR: i=%d x=%f y=%f z=%f tr=%d",i, tx[i], ty[i], tz[i], ttr[i]);
	}

}
