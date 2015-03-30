#include "lettres_moteur.h"

void lettresMoteur(float* tt1, float* tt2, float* tt3, int* ttr, int np)
{


	FT_STATUS ftStatus;
	FT_HANDLE ftHandleTemp;
	DWORD numDevs, Flags, ID, Type, LocId;
	char Description[64], SerialNumber[16];

	// LISTE LES PERIPHERIQUES
	if ( FT_CreateDeviceInfoList(&numDevs) == FT_OK) {
		printf("Nombre de peripheriques connectes: %d\n",numDevs);

		ftStatus = FT_GetDeviceInfoDetail(0, &Flags, &Type, &ID, &LocId, SerialNumber, Description, &ftHandleTemp);

		printf("Flags=0x%x\n Type=0x%x\n ID=0x%x\n LocId=0x%x\n SerialNumber=%s\n Description=%s\n ftHandle=0x%x\n", Flags, Type, ID, LocId, SerialNumber, Description, ftHandleTemp);


		/*	FT_HANDLE ftHandle;
			FT_STATUS ftStatus;
			ftStatus = FT_Open(0,&ftHandle);
			if (ftStatus == FT_OK) {
				// FT_Open OK, use ftHandle to access device
				FT_Close(ftHandle);
			}
			else {
				// FT_Open failed
			}
		*/
	}
	else {
		puts("Impossible de detecter les péripheriques.\n");
	}

}
