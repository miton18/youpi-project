#include "declaration.h"

int main(int argc, char* argv[])
{
	//int e1, e2;
	int *a,*b;
	int resultat;

	if( argc == 3)
	{
		printf("lancement mode console:");
		//e1 = argv[1];
		//e2 = argv[2];

	}
	else {
		*a=2;
		*b=3;

		//ihm( &e1, &e2);
		resultat = calcul(a,b);
		printf("Resultat = %d\n",resultat);
	}
	return 0;
}
