#include "lettres_moteur.h"

/**
	* Convertis 3 tableaux d'angles en ordre moteurs et les envoie dans
	  le premier device connécté et reconnu
  	* @param tt1, tt2, tt3 : tableaux d'angles
	  @param ttr: trace, indique si le point doit etre relier avec le précédent
	  @parma np:  nombre de points dans les tableaux
  	* @return void
*/
void lettresMoteur(float* tt1, float* tt2, float* tt3, int* ttr, int np)
{
	FT_STATUS ftStatus;
	FT_HANDLE ftHandle;
	DWORD numDevs, Flags, ID, Type, LocId, BytesWritten;
	char Description[64], SerialNumber[16];
	char * TxBuffer 	= malloc(sizeof(char) * 9); // Trame a envoyer
	char * startTrame 	= "0;-0000\r\n";

	float ang_moteur[ NB_MOTEUR ];
	float cptMoteur[ NB_MOTEUR ] = {0.0,0.0,0.0};

	int i, j;

	// LISTE LES PERIPHERIQUES
	if ( FT_CreateDeviceInfoList(&numDevs) == FT_OK)
	{
		printf("Nombre de peripheriques connectes: %d\n",numDevs);
		ftStatus = FT_GetDeviceInfoDetail(0, &Flags, &Type, &ID, &LocId, SerialNumber, Description, &ftHandle);
		printf("Flags=0x%x\n Type=0x%x\n ID=0x%x\n LocId=0x%x\n SerialNumber=%s\n Description=%s\n ftHandle=0x%x\n", Flags, Type, ID, LocId, SerialNumber, Description, ftHandle);


		ftStatus = FT_Open(0, &ftHandle); //OUVRE LA CONNEXION
		if(ftStatus != FT_OK)
		{
			printf("Impossible de se connecter au peripherique USB.\n");
			return;
		}
		else
		{
			printf("Connexion au peripheriques USB reussie.\n");// ON EST CONNECTER*/

			//TRAME DE DEBUT

			ftStatus = FT_Write(ftHandle, startTrame, sizeof(startTrame), &BytesWritten);

			for( i=0; i<np; i++) // parcours de chaque positions
			{
				ang_moteur[0] = tt1[i]; // ON STOCK DES ANGLES FLOAT THETA
				ang_moteur[1] = tt2[i];
				ang_moteur[2] = tt3[i];

				for( j=0; j< NB_MOTEUR ; j++)
				{
					if(ang_moteur[j] != cptMoteur[j]) // EVITE LES TRAMES INUTILES
					{
						createTrame( TxBuffer, cptMoteur[j], ang_moteur[j], j+1 );
						printf("TRAME: %s", TxBuffer);
						printf("LONGEUR: %d\n", strlen(TxBuffer));
						sleep(1);
						ftStatus = FT_Write(ftHandle, TxBuffer, sizeof(char)*9, &BytesWritten);// ECRITURE !!!!
						cptMoteur[j] = ang_moteur[j];
					}



					if (ftStatus == FT_OK) {
						printf("\t OK \t");
					}
					else {
						printf("L'ecriture n'a pas aboutie, arret....\n");
						return;
					}
					printf("Donnees n %d envoyees: %d / %d\n", i, BytesWritten, sizeof(char)*9);
				}

			}
			ftStatus = FT_Write(ftHandle, startTrame, sizeof(startTrame), &BytesWritten);
			FT_Close(ftHandle); 	//FERME LA CONNEXION*/
		}
	}
	else {
		puts("Impossible de detecter les péripheriques.\n");
	}
}

/**
	* Construit une trame (char*) en fonction de l'indice du moteur de la position actuelle du moteur et de son angle de destination
	* @param trame: chaine de caractere contenant l'ordre moteur
	  @param cpt: angle actuel du moteur
	  @param ang_dest: angle de destination
	  @param nMot: numéro du moteur concerné
	  @return void
	*
*/
void createTrame( char * trame, float cpt , float ang_dest, int nMot )
{
	const char 	* sep  		= ";";
	int			  pas;
	char 		* Cpas 		= malloc(sizeof(char) * 4);
	char 		* Cmot 		= malloc(sizeof(char));
	char 		* sgn  		= malloc(sizeof(char));
	char 		* Cmille  	= malloc(sizeof(char));
	char 		* Ccent  	= malloc(sizeof(char));
	char 		* Cdiz 		= malloc(sizeof(char));
	char 		* Cunit  	= malloc(sizeof(char));

	toStr(Cmot, nMot);
	strcpy( trame,  Cmot);  					// NUMERO DE MOTEUR
	strcat( trame, sep);			 			// SEPARATEUR

	if( (ang_dest - cpt) < 0 ) {				//SIGNE
		sprintf(trame, "%s%c", trame, '-');
	}
	else {
		sprintf(trame, "%s%c", trame, '+');
	}

	if( nMot == 1) //moteur avec 0.326
	{
		pas=abs( ((ang_dest - cpt) /0.0326 ) + 0.5);

	}
	else {
		pas=abs( ((ang_dest - cpt) /0.0281 ) + 0.5);
	}

	toStr(Cunit,  pas % 10);
	toStr(Cdiz ,  pas / 10 % 10);
	toStr(Ccent,  pas / 100 % 10);
	toStr(Cmille, pas / 1000 % 10);
	strcat( trame, Cmille	);
	strcat( trame, Ccent	);
	strcat( trame, Cdiz		);
	strcat( trame, Cunit	);

	sprintf(trame, "%s%c", trame, '\r');
	sprintf(trame, "%s%c", trame, '\n');

}

/**
	* Converti un int en (char *)
	* @param str: chaine de caracteres de destination
	  @param value: entier a convertir
	* @return void
*/
void toStr(char *str, int value)
{
    sprintf(str, "%d", value);
    return ;
}
