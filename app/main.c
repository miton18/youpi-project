#include <stdio.h>
#include "SDL2/SDL.h"

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL2 (%s)\n",SDL_GetError());
        return -1;
    }
    else
    {
		/* Création de la fenêtre */
        SDL_Window *win = 0;
        SDL_Renderer *ren = 0;

        SDL_CreateWindowAndRenderer(500, 500, 0, &win, &ren);

        /* Affichage du fond noir */
        SDL_SetRenderDrawColor(ren, 0, 255, 255, 255);
        SDL_RenderClear(ren);

		SDL_RenderPresent(ren);

		if( &win )
        {
            SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */

            SDL_DestroyWindow(win);
        }
        else
        {
            fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        }
	}
	SDL_Quit();
	return 0;
}
