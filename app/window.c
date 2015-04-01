#include "window.h"
void window_start()
{
	//TEMPORAIRE
	char  * str;
	int nb_point, e1, e2;
	char  * Ce1[10];
	char  * Ce2[10];
	int 	Eactive;

	float * tx  = malloc( sizeof(float) * 400 * 16 ); //TABLEAUX DE POSITIONS X Y Z
	float * ty  = malloc( sizeof(float) * 400 * 16 );
	float * tz  = malloc( sizeof(float) * 400 * 16 );

	int   * ttr = malloc( sizeof(int)   * 400 * 16 );

	float * tt1 = malloc( sizeof(float) * 400 * 16 ); // TABLEAU D ANGLES T1 T2 T3
	float * tt2 = malloc( sizeof(float) * 400 * 16 ); //nombre de point Max x taille float x nombre de caractere max
	float * tt3 = malloc( sizeof(float) * 400 * 16 );

	ihm(&e1, &e2);
	str = conversion( calcul(e1,e2) );
	lettresXYZ(    str, tx,  ty,  tz, 		ttr, 		&nb_point);
	lettresTheta(  tx,  ty,  tz,  nb_point, 	tt1, 		tt2, 		tt3);
	ecritureTraj(  tt1, tt2, tt3, ttr, 		nb_point);

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
		int imgFlags 					= IMG_INIT_PNG;
		SDL_Event eve;
		int action;
		IMG_Init( imgFlags );
		TTF_Init();
		SDL_StartTextInput();

		if(vuePrincipale == 0 && render ==0){ printf("\nImpossible d ouvrir la fenetre..."); exit(EXIT_FAILURE); }

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

		dessinNumberZone( 	render, 0, 90); // number 1
		dessinNumberZone( 	render, 0, 130); // number 2
		dessinTraceZone(	render);
		dessinButton( 		render, buttonV, 10, 10);

		char * t1 = "Youpi: addition";
		dessinTexte( render, t1, 16, 18, 600, WHITE);
		char * t2 = "Lancer!";
		dessinTexte( render, t2, 20, ( HEIGHT / 2 ) + 150, 1900, BLACK);

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

						mouse( eve.button.x, eve.button.y, &action);
						if(mouseIn( eve.button.x, eve.button.y, 0, 90, 0+150, 90+25 ))
						{
							Eactive = 1;
							puts("active: e1");
						}
						else if(mouseIn( eve.button.x, eve.button.y, 0, 130, 150, 130+25 ))
						{
							//e_active = 2;
							puts("active: e2");
						}
					break
					case SDL_KEYDOWN:		//TOUCHE CLAVIER

						switch (eve.key.keysym.sym)
						{
							case SDLK_ESCAPE:

								keephere = false;
							break;
							case SDLK_KP_0:

								puts("0");
								//strcat( ((e_active==1)? *Ce1 : *Ce2), "0" );
							break;
							case SDLK_KP_1:

								puts("1");
							break;
							case SDLK_KP_2:
								puts("2");
							break;
							case SDLK_KP_3:
								puts("3");
							break;
							case SDLK_KP_4:
								puts("4");
							break;
							case SDLK_KP_5:
								puts("5");
							break;
							case SDLK_KP_6:
								puts("6");
							break;
							case SDLK_KP_7:
								puts("7");
							break;
							case SDLK_KP_8:
								puts("8");
							break;
							case SDLK_KP_9:
								puts("9");
							break;
						}
            		break;
				}
				if(action == 1)
				{
					startDraw(render, tx, ty, tz, ttr, nb_point);
					action = 0;
				}
			}
		}
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(vuePrincipale);
		TTF_Quit();
		SDL_Quit();
	}
}


void dessinTraceZone(SDL_Renderer * ren)
{
	int colr, colg, colb;
  	SDL_Rect r;
  	int width 	= WIDTH;
	int height 	= 150;


  	SDL_SetRenderDrawBlendMode(ren,SDL_BLENDMODE_BLEND);
	r.w = width;
	r.h = height;
	r.x = 0;
	r.y =  ( HEIGHT / 2 )- ( height / 2 );

	SDL_SetRenderDrawColor( ren, 10, 10, 10, 20);
	SDL_RenderFillRect(ren, &r);

  	//SDL_RenderPresent(ren);
}


void dessinNumberZone(SDL_Renderer * ren, int x, int y)
{
	int colr, colg, colb;
  	SDL_Rect r;
  	int width 	= 150;
	int height 	= 25;

  	SDL_SetRenderDrawBlendMode(ren,SDL_BLENDMODE_BLEND);
	r.w = width;
	r.h = height;
	r.x = x;
	r.y = y;

	SDL_SetRenderDrawColor( ren, 10, 10, 10, 20);
	SDL_RenderFillRect(ren, &r);
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
	SDL_Color color_white = {   5,  5,   5 };
	SDL_Color color_black = { 255,255, 255 };
	SDL_Color color_red   = { 255,  5,   5 };
	SDL_Color color_grey  = { 181,  0, 128 };
	if( color == WHITE)
	{
		Tcolor = color_black;
	}
	else if( color == BLACK)
	{
		Tcolor = color_white;
	}
	else if ( color == RED)
	{
		Tcolor = color_red;
	}
	TTF_Font 	* 	font  = TTF_OpenFont("font/Roboto-Regular.ttf", size);

	SDL_Rect R;
		R.x = x;
		R.y = y;
		R.w = 80;
		R.h = 25;

	SDL_Surface * texte  = TTF_RenderText_Blended( font, txt, Tcolor);
	//SDL_Surface * texte  = TTF_RenderText_Shaded( font, txt, Tcolor, color_grey);
	SDL_Texture * Ttexte = SDL_CreateTextureFromSurface(ren, texte);
	SDL_RenderCopy(ren, Ttexte, NULL, &R);

	SDL_FreeSurface(texte);
	SDL_DestroyTexture( Ttexte );
	TTF_CloseFont(font);
}






void mouse( int x, int y, int * action )
{
	if(mouseIn( x, y, WIDTH - 50, 0, WIDTH, 50 ) == true)
	{
		exit(0);
	}
	else if(mouseIn( x, y,  20, ( HEIGHT / 2 ) + 150, 80+20, ( HEIGHT / 2 ) + 150 +25 ) )
	{
		puts("lancer...\n");
		*action = 1;
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


void startDraw(	SDL_Renderer * ren, float * tx, float * ty, float * tz, int * ttr, int nb_point) // z horizontal, x verticale
{
	int i, j, x, y;
	char * wait = "PATIENTEZ SVP";
	SDL_SetRenderDrawColor( ren, 10, 10, 10, 255);
	dessinTexte( ren, wait, 80, HEIGHT - 50, 400, RED);

	for( i=0; i< nb_point; i++)
	{
		x = ((tz[i])  + 139.5) * 6 +20 ;
		y = ( -(tx[i] - 145  ) * 6 + (     ( HEIGHT / 2 ) + 30 )    );
		Sleep(10);
		//printf("point: %d, %d\n", x, y);
		SDL_RenderDrawPoint(ren, x, y );

		SDL_RenderPresent(ren);
	}

	SDL_Rect r;
  	SDL_SetRenderDrawBlendMode(ren,SDL_BLENDMODE_BLEND);
	r.w = 300;
	r.h = 50;
	r.x = 80;
	r.y = HEIGHT - 50;

	SDL_SetRenderDrawColor( ren, 255, 255, 255, 255);
	SDL_RenderFillRect(ren, &r);
	SDL_RenderPresent(ren);
}
