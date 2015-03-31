/* ----------------------------------------------------
   Auteur : Collignon Rémi
   			Morvan Guy-Yann
   	Fonction principale main
-----------------------------------------------------*/
#include "declaration.h"


int main(int argc, char* argv[])
{

	int 	e1, e2;
	int 	resultat, nb_point=0;
	char  * str;
	
	float * tx  = malloc( sizeof(float) * 400 * 16 ); //TABLEAUX DE POSITIONS X Y Z
	float * ty  = malloc( sizeof(float) * 400 * 16 );
	float * tz  = malloc( sizeof(float) * 400 * 16 );

	int   * ttr = malloc( sizeof(int)   * 400 * 16 );

	float * tt1 = malloc( sizeof(float) * 400 * 16 ); // TABLEAU D ANGLES T1 T2 T3
	float * tt2 = malloc( sizeof(float) * 400 * 16 ); //nombre de point Max x taille float x nombre de caractere max
	float * tt3 = malloc( sizeof(float) * 400 * 16 );

	if( argc == 3) // si passe 2 arguments ( des nombres)
	{
		e1=atoi(argv[1]);
		e2=atoi(argv[2]);
		printf("Les parametres d entree ont ete pris en compte: %d %d\n", e1, e2);
	}
	else if( argc == 2 && argv[1]=="-ui")
	{

	}
	else {
		ihm(&e1, &e2);
	}

	resultat = calcul(e1,e2);
	printf("Resultat = %d\n",resultat);
	str = conversion( resultat );

	printf("\nchaine : %s\n", str);

	lettresXYZ(    str, tx,  ty,  tz, 		ttr, 		&nb_point);
	lettresTheta(  tx,  ty,  tz,  nb_point, 	tt1, 		tt2, 		tt3);
	ecritureTraj(  tt1, tt2, tt3, ttr, 		nb_point);

	//lettresMoteur( tt1, tt2, tt3, ttr, 		nb_point);

	return 0;
}
