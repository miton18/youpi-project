#include "conversion.h"
#include <stdio.h>

int main(int argc, char* argv[]) {

	int r = atoi( argv[1] );

	char * test = conversion( r );

	printf("\nVALEUR DE RETOUR: str=%s\n", test);
}
