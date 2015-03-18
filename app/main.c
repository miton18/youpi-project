/* ----------------------------------------------------
   Auteur : Collignon Rémi
   			Morvan Guy-Yann
   	Fonction principale main
-----------------------------------------------------*/
#include "declaration.h"


int main(int argc, char* argv[])
{

	int e1, e2;
	int resultat;
	char * str;
	
	if( argc == 3)
	{
		printf("lancement mode console:");

	}
	else {
		ihm(&e1, &e2);
		resultat = calcul(e1,e2);
		printf("Resultat = %d\n",resultat);
		str = conversion( resultat );

		printf("\nchaine : %s", str);
	}
	return 0;
}
