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
    	vuePrincipale 					= SDL_CreateWindowAndRenderer( WIDTH, HEIGHT, SDL_WINDOW_BORDERLESS, &vuePrincipale, &render );
		int imgFlags = IMG_INIT_PNG;
		SDL_Event eve;
		IMG_Init( imgFlags );
		TTF_Init();

		if(vuePrincipale == 0 && render ==0)
		{
			printf("\nImpossible d ouvrir la fenetre...");
			exit(EXIT_FAILURE);
		}

		SDL_SetRenderDrawColor(render, 255, 255, 255, 200); // COULEUR DU BACKGROUND
		SDL_RenderClear(render);

		SDL_Texture * buttonV 	= IMG_LoadTexture(render, "image/button.png");
		SDL_Texture * img_close = IMG_LoadTexture(render, "image/close.png");

		SDL_Rect Rclose;
		Rclose.x = WIDTH - 50;
		Rclose.y = 0;
		Rclose.w = 50;
		Rclose.h = 50;
		SDL_RenderCopy(render, img_close, NULL, &Rclose);

		dessinTraceZone(render);
		dessinButton( render, buttonV, 10, 10);

		char * t1 = "Youpi: addition";
		dessinTexte( render, t1, 16, 18, 400, BLACK);
		char * t2 = "Lancer!";
		dessinTexte( render, t2, 20, ( HEIGHT / 2 ) + 60, 400, BLACK);


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

					case SDL_MOUSEBUTTONDOWN: // SOURIE
						mouse( eve.button.x, eve.button.y);

					break;

					case SDL_KEYDOWN:		//TOUCHE CLAVIER
						switch (eve.key.keysym.sym)
						{
							case SDLK_ESCAPE:
								keephere = false;
						}
            		break;
				}
			}
		}
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(vuePrincipale);
		TTF_Quit();
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






void dessinButton( SDL_Renderer * ren, SDL_Texture * Text, int x, int y)
{
	int h, w;

	SDL_QueryTexture( Text, NULL, NULL, &w, &h);
	SDL_Rect R;
		R.x = x;
		R.y = y;
		R.w = 100;
		R.h = 40;
	SDL_RenderCopy(ren, Text, NULL, &R);
}










void dessinTexte( SDL_Renderer * ren, char * txt, int x, int y, int size, int color)
{
	SDL_Color Tcolor;
	SDL_Color color_white = {   5,  5,  5 };
	SDL_Color color_black = { 255,255,255 };
	if( color == WHITE)
	{
		Tcolor = color_white;
	}
	else if( color == BLACK)
	{
		Tcolor = color_black;
	}
	TTF_Font 	* 	font  = TTF_OpenFont("font/Roboto-Condensed.ttf", size);

	SDL_Rect R;
		R.x = x;
		R.y = y;
		R.w = 80;
		R.h = 25;

	SDL_Surface * texte  = TTF_RenderText_Blended( font, txt, Tcolor);
	SDL_Texture * Ttexte = SDL_CreateTextureFromSurface(ren, texte);
	SDL_RenderCopy(ren, Ttexte, NULL, &R);

	SDL_FreeSurface(texte);
	SDL_DestroyTexture( Ttexte );
	TTF_CloseFont(font);
}






void mouse( int x, int y )
{
	if(mouseIn( x, y, WIDTH - 50, 0, WIDTH, 50 ) == true)
	{
		exit(0);
	}
	else if(mouseIn( x, y,  20, ( HEIGHT / 2 ) + 60, 80+20, ( HEIGHT / 2 ) + 60 +25 ) )
	{
		puts("lancer...\n");

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
