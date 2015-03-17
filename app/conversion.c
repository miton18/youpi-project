#include "conversion.h"

char * conversion(int s)
{
	char * number[];

	int unite 		= s % 10;
	int dizaine 	= s / 10 % 10;
	int centaine 	= s / 100 % 10;
	int millier 	= s / 1000 % 10;
	printf("millier: %d centaine: %d dizaine: %d unit%C: %d", millier, centaine, dizaine, 130, unite);


	return *number;
}
