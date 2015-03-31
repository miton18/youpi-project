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
		SDL_Window   * vuePrincipale 	= NULL;
		SDL_Renderer * render 			= NULL;
    	vuePrincipale 					= SDL_CreateWindowAndRenderer( WIDTH, HEIGHT, SDL_WINDOW_BORDERLESS, &vuePrincipale, &render );/* SDL_WINDOW_BORDERLESS*/
		int imgFlags = IMG_INIT_PNG;
		IMG_Init( imgFlags );

		//TTF_Init();

		//SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

		if(vuePrincipale == 0 && render ==0)
		{
			printf("\nImpossible d ouvrir la fenetre...");
			exit(EXIT_FAILURE);
		}

		SDL_Event eve;

		SDL_SetRenderDrawColor(render, 255, 255, 255, 200);
		SDL_RenderClear(render);
    	//SDL_RenderPresent(render);

		SDL_Texture * img_close=NULL;
		img_close = IMG_LoadTexture(render, "image/close.png");

		//SDL_QueryTexture(img_close, NULL, NULL, &w, &h);
		SDL_Rect Rclose;
		Rclose.x = WIDTH - 50;
		Rclose.y = 0;
		Rclose.w = 50;
		Rclose.h = 50;

		SDL_RenderCopy(render, img_close, NULL, &Rclose);

		//dessinTraceZone(render);
		//dessinClose(render);
		SDL_RenderPresent(render);

		while(keephere)
		{

			while (SDL_PollEvent(&eve)) //ATTENTE D EVENEMENTS
			{
				switch (eve.type)
				{
					case SDL_QUIT: //BOUTON FERMER
						exit(0);
					break;

					case SDL_MOUSEMOTION // SOURIE
						mouse( eve.motion.x, eve.motion.y);

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

  	//SDL_RenderPresent(ren);
}
void mouse( int x, int y )
{
	if(mouseIn(x, y, WIDTH - 50, WIDTH, , ))
	{

	}
}
bool mouseIn( int mx, int my, int fxa, int fya, int fxb, int fyb)
{
	if( mx > fxa && mx < fxb && my > fya && my < fyb )
	{
		return true;
	}
	else {
		return false;
	}
}

void dessinClose(SDL_Renderer * ren )
{
	/*SDL_rect r;
	r.w = 50;
	r.h = 50;
	r.x = 0;
	r.y = WIDTH - 50;
	//SDL_Surface * image = IMG_Load("image/close.png");*/
}
