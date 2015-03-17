#include "ihm.h"

void ihm(int* e1, int* e2)
{
	char number[5];
	bool okNum=false;

	line();
	line();
	printf("\n\tProgramme de dessin du bras Youpi\n");
	printf("\n\t--Projet CIR3  ---  MORVAN / COLLIGNON\n\n");
	line();
	line();

	do {
		printf("\nEntrez votre premi%cre valeur: ", 138); //	138 = é
		fgets(number, sizeof number, stdin);

		if ( *e1 = atoi(number) )
		{
			printf("Nombre: %d \n", *e1);
			okNum = true;
		}
		else {

			printf("\nIncorrect: ");
			okNum = false;
		}
		fflush(stdin); // nettoie le buffer
	} while( !okNum );
	do {
		printf("\nEntrez votre deuxi%cme valeur: ", 138);
		fgets(number, sizeof number, stdin);

		if ( *e2 = atoi(number) )
		{
			printf("Nombre: %d \n", *e2);
			okNum = true;
		}
		else
		{
			printf("\nIncorrect: ");
			okNum = false;
		}
		fflush(stdin);	// nettoie le buffer
	} while( !okNum );

	line();
	printf("\n calcul %d + %d \n\n", *e1, *e2);
	line();

	/*if (SDL_Init(SDL_INIT_VIDEO) != 0 )
	{
		fprintf(stdout,"Échec de l'initialisation de la SDL2 (%s)\n",SDL_GetError());
		return -1;
	}
	else
	{
		/* Création de la fenêtre */
		/*SDL_Window *win = 0;
		SDL_Renderer *ren = 0;

		SDL_CreateWindowAndRenderer(500, 500, 0, &win, &ren);

		/* Affichage du fond noir */
		/*SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
		SDL_RenderClear(ren);

		SDL_RenderPresent(ren);

		if( &win )
		{
			SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */

		/*	SDL_DestroyWindow(win);
		}
		else
		{
			fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
		}
	}
	SDL_Quit();*/
}
void line()
{
	printf("####################################################\n");
}
