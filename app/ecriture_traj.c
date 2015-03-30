/* ------------------------------------------------------
   Auteur : Collignon Rémi
   			Morvan Guy-Yann
   	Fonction ecritureTraj
   	-----------------------------------------------------*/
#include "ecriture_traj.h"

void ecritureTraj(float* tt1, float* tt2, float* tt3, int* ttr, int np)
{
	/*FILE * fichier = NULL;
	char * rep;
	int i;

	fichier = fopen( "trajectoire.dat", "r" );

	if( fichier != NULL  ) {		// CAS OU LE FICHIER EXISTE DEJA

		printf("/!\\ ATTENTION le fichier trajectoire.dat éxiste déja et va être écraser! Continuer? ( o ou n)\n");
		fgets( rep , sizeof( char ), stdin);

		if( *rep!='o' && *rep!='O' && *rep!='Y' && *rep!='y') {
			printf("le programme va se fermer...");
			exit(EXIT_SUCCESS);
		}
		fclose(fichier);
	}
	fichier = fopen( "trajectoire.dat", "w+" ); //OUVERTURE EN ECRITURE EN LE VIDANT AVANT

	for( i=0; i<np; i++) {

		fprintf(fichier, "%f %f %f 0.000000 0.000000  %d\n", tt1[i], tt2[i], tt3[i], ttr[i]);
		printf("%d % \r", (i / np * 100 ) );

	}

	fclose(fichier);
	printf("écriture du fichier terminée!");*/
}
