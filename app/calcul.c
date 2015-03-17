#include "calcul.h"

int calcul(int a, int b)
{
	int resultat = 0;
	resultat = a + b;
	if (resultat < 0)
	{
		printf("Resultat inferieur a zero! Suite impossible.\n");
		exit(0);
	}
	else if (resultat > 3999)
	{
		printf("Resultat trop grand ! On ne peut depasser 3999.\n");
		exit(0);
	}
	else {
		return resultat;
	}
}
