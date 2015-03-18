/* ------------------------------------------------------
   Auteur : Collignon Rémi
   			Morvan Guy-Yann
   	Fonction calcul
   	Addition de deux entier
   	-----------------------------------------------------*/
#include "calcul.h"

int calcul(int a, int b)
{
	int resultat = 0;
	resultat = a + b;
	//Test si le résultat est positif
	if (resultat < 0 || resultat = 0)
	{
		printf("Resultat inferieur ou egale a zero! Suite impossible.\n");
		exit(0);
	}
	//Test si le resultat est inferieur a 3999 (maximum pour affichage des chiffres romains)
	else if (resultat > 3999)
	{
		printf("Resultat trop grand ! On ne peut depasser 3999.\n");
		exit(0);
	} //sinon envoi du résultat au main
	else {
		return resultat;
	}
}
