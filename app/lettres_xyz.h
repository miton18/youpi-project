/* ------------------------------------------------------
   Auteur : Collignon Rémi
   			Morvan Guy-Yann
   	Header Fonction lettresXYZ
   	-----------------------------------------------------*/
#ifndef LETTRESXYZ_H
#define LETTRESXYZ_H

   	#include <math.h>
	void lettresXYZ(char* str, float* tx, float* ty,float* tz,int* ttr,int* np);
	
	//Génération des points pour les differents chiffres romains
	//return le nombre de point
	int lettreX(float* x, float* y,float* z,int* tr,int i,int *indice);
	int lettreI(float* x, float* y,float* z,int* tr,int i,int *indice);
	int lettreM(float* x, float* y,float* z,int* tr,int i,int *indice);
	int lettreV(float* x, float* y,float* z,int* tr,int i,int *indice);
	int lettreC(float* x, float* y,float* z,int* tr,int i,int *indice);
	int lettreD(float* x, float* y,float* z,int* tr,int i,int *indice);
	int lettreL(float* x, float* y,float* z,int* tr,int i,int *indice);
#endif
