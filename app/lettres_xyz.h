/* ------------------------------------------------------
   Auteur : Collignon Rémi
   			Morvan Guy-Yann
   	Header Fonction lettresXYZ
   	-----------------------------------------------------*/
#ifndef LETTRESXYZ_H
#define LETTRESXYZ_H


	char* lettresXYZ(char* str, float* tx, float* ty,float* tz,int* ttr,int* np);
	
	//Génération des points pour les differents chiffres romains
	//return le nombre de point
	int lettreX(float* x, float* y,float* z,int* tr);
	int lettreI(float* x, float* y,float* z,int* tr);
	int lettreM(float* x, float* y,float* z,int* tr);
	int lettreV(float* x, float* y,float* z,int* tr);
	int lettreC(float* x, float* y,float* z,int* tr);
	int lettreD(float* x, float* y,float* z,int* tr);
	int lettreL(float* x, float* y,float* z,int* tr);
#endif