#include "lettres_moteur.h"

void lettresMoteur(float* tt1, float* tt2, float* tt3, int* ttr, int np)
{
	FT_STATUS ftStatus;
	FT_HANDLE ftHandle;
	DWORD numDevs, Flags, ID, Type, LocId, BytesWritten;
	char Description[64], SerialNumber[16];
	char * TxBuffer = malloc(sizeof(char) * 9); // Contains data to write to device

	float ang_moteur[ NB_MOTEUR ];
	float cptMoteur[ NB_MOTEUR ] = {0.0,0.0,0.0};

	int i, j;

	// LISTE LES PERIPHERIQUES
	/*if ( FT_CreateDeviceInfoList(&numDevs) == FT_OK)
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

			for( i=0; i<np; i++) // parcours de chaque positions
			{
				ang_moteur[0] = tt1[i]; // ON STOCK DES ANGLES FLOAT THETA
				ang_moteur[1] = tt2[i];
				ang_moteur[2] = tt3[i];

				for( j=0; j< (NB_MOTEUR - 1) ; j++)
				{
					if(ang_moteur[j] != cptMoteur[j]) // EVITE LES TRAMES INUTILES
					{
						createTrame( TxBuffer, cptMoteur[j], ang_moteur[j], j+1 );
						printf("TRAME N %d: %s\n", j, TxBuffer);
						cptMoteur[j] = ang_moteur[j];
					}

					//ftStatus = FT_Write(ftHandle, TxBuffer, sizeof(TxBuffer), &BytesWritten);// ECRITURE !!!!

					/*if (ftStatus == FT_OK) {
						printf("\t OK \t");
					}
					else {
						printf("L'ecriture n'a pas aboutie, arret....\n");
						return;
					}
					printf("Données n° %d envoyees: %d / %d\n", i, BytesWritten, sizeof(TxBuffer));
					FT_Close(ftHandle); 	//FERME LA CONNEXION*/
				}

			}/*
		}
	}
	else {
		puts("Impossible de detecter les péripheriques.\n");
	}*/
}
void createTrame( char * trame, float cpt , float ang_dest, int nMot )
{
	const char 	* sep  		= ";";
	int			  pas;
	char 		* Cpas 		= "xxxx";
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
		pas=( ((ang_dest - cpt) /0.0326 ) + 0.5);

	}
	else {
		pas=( ((ang_dest - cpt) /0.0281 ) + 0.5);
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
void toStr(char *str, int value) {

    sprintf(str, "%d", value);
    return ;
}
