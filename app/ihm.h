/* ------------------------------------------------------
   Auteur : Collignon Rémi
   			Morvan Guy-Yann
   	Header Fonction ihm
   	Demande à l'utilisateur de rentrer 2 chiffres
   	-----------------------------------------------------*/
#ifndef IHM_H
#define IHM_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	/* FONCTION PRINCIPALE */

	void ihm(int * e1, int * e2);
	void line();
	void robot();

	/* TYPE BOOLEAN*/
	typedef enum { false, true } bool;

#endif
