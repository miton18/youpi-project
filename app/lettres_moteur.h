/* ------------------------------------------------------
	Auteur : Collignon Rémi
   			Morvan Guy-Yann
	Header Fonction lettresMoteur
-----------------------------------------------------*/

#ifndef LETTRESMOTEUR
#define LETTRESMOTEUR

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <windows.h>
	#include <math.h>
	#include "ftd2xx.h"

	// NOMBRE DE MOTEUR A PILOTER
	#define NB_MOTEUR 3

   	void lettresMoteur(float* tt1, float* tt2, float* tt3, int* ttr, int np);
	void createTrame( char * trame, float cpt , float ang_dest, int nMot );
	void toStr(char *str, int value);
#endif
