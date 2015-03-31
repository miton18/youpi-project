#include "window.h"

void window_start(int * e1, int * e2)
{
	bool keephere = true;

	if (SDL_Init(SDL_INIT_VIDEO) != 0 )
	{
		printf("Échec de l'initialisation de la SDL2 (%s)\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
	else
	{

		SDL_Window   * vuePrincipale = 0;
		SDL_Renderer * render =0;
    	vuePrincipale = SDL_CreateWindowAndRenderer( WIDTH, HEIGHT, SDL_WINDOW_BORDERLESS, &vuePrincipale, &render );/* SDL_WINDOW_BORDERLESS*/
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

		if(vuePrincipale == 0 && render ==0)
		{
			printf("\nImpossible d ouvrir la fenetre...");
			exit(EXIT_FAILURE);
		}

		SDL_Event eve;

		SDL_SetRenderDrawColor(render, 255, 255, 255, 100);
  		SDL_RenderClear(render);
  		SDL_RenderPresent(render);

		SDL_Surface * img_close;
		/*if( img_close = IMG_Load("image/close.png" ) )
		{
    		printf("IMG_Load: %s\n", IMG_GetError());
		}*/

		dessinTraceZone(render);
		dessinClose(render);

		while(keephere)
		{

			while (SDL_PollEvent(&eve)) //ATTENTE D EVENEMENTS
			{
				switch (eve.type)
				{
					case SDL_QUIT: //BOUTON FERMER
						exit(0);
					break;

					case SDL_KEYDOWN:		//TOUCHE CLAVIER
						switch (eve.key.keysym.sym)
						{
							case SDLK_ESCAPE:
								keephere = false;
							break;

							case SDLK_DELETE:
								//input->erase = 1;
							break;

							case SDLK_c:
								//input->jump = 1;
							break;

							case SDLK_v:
								//input->attack = 1;
							break;

							case SDLK_LEFT:
								//input->left = 1;
							break;

							case SDLK_RIGHT:
								//input->right = 1;
							break;

							case SDLK_RETURN:
								//input->enter = 1;
							break;

							default:
							break;
						}
            		break;
				}
			}
		}
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(vuePrincipale);
		SDL_Quit();
	}

	*e1 = 5;
	*e2 = 10;
}
void dessinTraceZone(SDL_Renderer * ren)
{
	int colr, colg, colb;
  	SDL_Rect r;
  	int width 	= 300;
	int height 	= 100;


  	SDL_SetRenderDrawBlendMode(ren,SDL_BLENDMODE_BLEND);
	r.w = width;
	r.h = height;
	r.x = 0;
	r.y =  ( HEIGHT / 2 )- ( height / 2 );

	SDL_SetRenderDrawColor( ren, 10, 10, 10, 20);
	SDL_RenderFillRect(ren, &r);

  	SDL_RenderPresent(ren);
}
void dessinClose(SDL_Renderer * ren)
{
	//SDL_Surface * image = IMG_Load("image/close.png");
}
