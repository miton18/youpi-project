#include "calcul.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

	int a = atoi( argv[1] );
	int b = atoi( argv[2] );

	int test = calcul( a, b );

	printf("\nVALEUR DE RETOUR: %d\n", test);
}
