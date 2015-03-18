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
	
	float * tt1 = malloc( sizeof(float) * 400 * 16 ); //nombre de point Max x taille float x nombre de caractere max
	float * tt2 = malloc( sizeof(float) * 400 * 16 );
	float * tt3 = malloc( sizeof(float) * 400 * 16 );

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
