/* ------------------------------------------------------
	Auteur : Collignon Rémi
   			Morvan Guy-Yann
	Header Fonction window
-----------------------------------------------------*/

#ifndef LETTRESMOTEUR
#define LETTRESMOTEUR



	#include "SDL2/SDL.h"
	#include <SDL2/SDL_image.h>
	#include <SDL2/SDL_ttf.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <windows.h>

	#define HEIGHT 500
	#define WIDTH 500

	#define BLACK 1
	#define WHITE 1

	void window_start( int * e1, int * e2);

	//DEFINITION DU TYPE BOOLEEN
	typedef enum { false, true } bool;

	void dessinTraceZone(	SDL_Renderer * ren);
	void dessinButton( 		SDL_Renderer * ren, SDL_Texture * Text, int x, int y);
	void dessinTexte( 		SDL_Renderer * ren, char * txt, int x, int y, int size, int color);
	void mouse( int x, int y );
	bool mouseIn( int mx, int my, int fxa, int fya, int fxb, int fyb);

#endif
