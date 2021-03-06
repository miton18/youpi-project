/* ------------------------------------------------------
   Auteur : Collignon Rémi
   			Morvan Guy-Yann
   	Fonction ecritureTraj
   	Ecriture de la trajectoire dans le fichier trajectoire.dat
   	-----------------------------------------------------*/
#include "ecriture_traj.h"

/**
	* fonction ecritureTraj
	* parametre : float* tt1 , tableau contenant les angles du moteur 1
	*             float* tt2 , tableau contenant les angles du moteur 2 
	*			  float* tt3 , tableau contenant les angles du moteur 3
	*			  float* ttr , tableau contenant la trace
	*			  int np, contient le nombre de point total
	* retourne void
*/
void ecritureTraj(float* tt1, float* tt2, float* tt3, int* ttr, int np)
{
	FILE * fichier = NULL;
	char   rep[2];
	int i;

	fichier = fopen( "trajectoire.dat", "r" );

	if( fichier != NULL  ) {		// CAS OU LE FICHIER EXISTE DEJA

		printf("/!\\ ATTENTION le fichier trajectoire.dat existe deja\n et va etre ecraser! Continuer? ( o ou n) ");
		fgets( rep , sizeof( rep ), stdin);

		if( rep[0]!='o' && rep[0]!='y') {
			printf("le programme va se fermer...");
			exit(EXIT_SUCCESS);
		}
		fclose(fichier);
	}
	fichier = fopen( "trajectoire.dat", "w+" ); //OUVERTURE EN ECRITURE EN LE VIDANT AVANT

	for( i=0; i<np; i++) {

		fprintf(fichier, "%f %f %f 0.000000 0.000000  %d", tt1[i], tt2[i], tt3[i], ttr[i]);
		if( i!= (np - 1) )
		{
			fprintf(fichier, "\n");
		}
		//printf("%d % \r", (i / np * 100 ) );

	}
	fclose(fichier);
	printf("ecriture du fichier terminee!\n");
}
