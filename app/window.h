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

	#include "ihm.h"
	#include "calcul.h"
	#include "conversion.h"
	#include "lettres_xyz.h"
	#include "lettres_theta.h"
	#include "lettres_moteur.h"
	#include "ecriture_traj.h"

	#define HEIGHT 500
	#define WIDTH 500

	#define BLACK 1
	#define WHITE 1

	void window_start();

	//DEFINITION DU TYPE BOOLEEN
	//typedef enum { false, true } bool; //deja present dans ihm

	void dessinTraceZone(	SDL_Renderer * ren);
	void dessinNumberZone(	SDL_Renderer * ren, int x, int y);
	void dessinButton( 		SDL_Renderer * ren, SDL_Texture * Text, int x, int y);
	void dessinTexte( 		SDL_Renderer * ren, char * txt, int x, int y, int size, int color);
	void startDraw(			SDL_Renderer * ren, float * tx, float * ty, float * tz, int * ttr, int nb_point);
	void mouse( int x, int y , int * action);
	bool mouseIn( int mx, int my, int fxa, int fya, int fxb, int fyb);

#endif
