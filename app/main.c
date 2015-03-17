#include "declaration.h"

int main(int argc, char* argv[])
{

	int e1, e2;
	int resultat;
	
	if( argc == 3)
	{
		printf("lancement mode console:");

	}
	else {
		ihm(&e1, &e2);
		resultat = calcul(&e1,&e2);
		printf("Resultat = %d\n",resultat);
	}
	return 0;
}
