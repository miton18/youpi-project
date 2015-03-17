#include "ihm.h"

void ihm(int* e1, int* e2)
{
	char number[5];
	bool okNum=false;

	line();
	line();
	robot();
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

			printf("\nIncorrect! ");
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
			printf("\nIncorrect! ");
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
void robot() {
puts("\n                                         __-----__");
puts("\n                                        / \\_____/ \\ ");
puts("\n                                      <|<  \\___/  >|>");
puts("\n                                      _| |=== ===| |_");
puts("\n                                      \\|/         \\|/");
puts("\n                                       |\\   /^\\   /|");
puts("\n                                        \\    |    /");
puts("\n                                       [|\\_^---^_/|]");
puts("\n                                        |_\\_____/_|");
puts("\n            ___^_______^__           ___|_______|_|___           __^_______^___");
puts("\n          <||  ^ \\___/ ^  |      _^_|_______________|_|_^_      |  ^ \\___/ ^  ||>");
puts("\n          <||  ^   |   ^  |_____||^    \\___________/    ^||_____|  ^   |   ^  ||>");
puts("\n          <||  v   |   v  | | | ||^     \\_________/     ^|| | | |  v   |   v  ||>");
puts("\n          <||  v  _|_  v  |_|_|_||v      \\_______/  X1  v||_|_|_|  v  _|_  v  ||>");
puts("\n          <||__v_/___\\_v__|      \\\\   __________  _____ //      |__v_/___\\_v__||>");
puts("\n              |_________|         \\|      _______      |/         |_________|");
puts("\n               |____ |_|           \\_____/_______\\_____/           |____ |_|");
puts("\n               |____ |_|               |________ |_|               |____ |_|");
puts("\n               |____ |_|               |________ |_|               |____ |_|");
puts("\n              _|____ |_|_              |________ |_|              _|____ |_|_");
puts("\n            _|   \\___/   |_            |________ |_|            _|   \\___/   |_");
puts("\n           | |     |     | |         __|________ |_|__         | |     |     | |");
puts("\n           |_|    _|_    |_|       <|  \\___________/  |>       |_|    _|_    |_|");
puts("\n             |___/___\\___|        __|____ _     _ ____|__        |___/___\\___|");
puts("\n               |____ |_|         |  |||  | |   | |  |||  |         |____ |_|");
puts("\n               |____ |_|        /|  |||  | |   | |  |||  |\\        |____ |_|");
puts("\n             __|____ |_|__     |_|  |||  | |   | |  |||  |_|      _|____ |_|_");
puts("\n           <|<  <>   <>  >|>    \\|  |||  |\\_____/|  |||  |/      |___________|");
puts("\n            | ()    ()   (       |__|||__|       |__|||__|      <|< <>   <> >|>");
puts("\n             )   ()    () |       |__ |_|         |__ |_|        |___________|");
puts("\n            | ()    ()   (        |__ |_|         |__ |_|           |_____|");
puts("\n             )   ()    () |       |__ |_|         |__ |_|          / \\   / \\ ");
puts("\n            | ()    ()   (        |__ |_|         |__ |_|         /   \\ /   \\ ");
puts("\n             )   ()    () |       |__ |_|         |__ |_|        / \\  (o)    \\ ");
puts("\n            |_____________|       |__ |_|         |__ |_|      <|\\\\  / V \\    |>");
puts("\n             \\___________/        |__ |_|         |__ |_|      <| \\ /     \\   |>");
puts("\n               _|||||||_          |__ |_|         |__ |_|      <|  |>     <|  |>");
puts("\n              \\ |     | /      ___|__ |_|___   ___|__ |_|___     \\ |>     <| /");
puts("\n               \\|_____|/      |     |||     | |     |||     |     \\|>     <|/");
puts("\n                 |___|       /|   -/   \\-   | |   -/   \\-   |\\");
puts("\n                            |_|  -|  x  |-  | |  -|  x  |-  |_|");
puts("\n                             \\|   -\\___/-   | |   -\\___/-   |/");
puts("\n GIANT ASCII ROBOTS           |_____|||_____| |_____|||_____|");
puts("\n                                |_________|     |_________|");
puts("\n   X1 Battle-Bot                 |_||_||_|       |_||_||_|");
puts("\n                                 /_______\\       /_______\\ ");
puts("\n © copyright 2007               _/_______\\_     _/_______\\_");
puts("\nJoseph V. Barrile Jr.          /           \\   /           \\ ");
puts("\n January 16, 2007             /  \\_______/  \\ /  \\_______/  \\ ");
puts("\n                             |   |       |   |   |       |   |");
puts("\n                            /|   |   X   |   |   |   X   |   |\\ ");
puts("\n                           / |   |   1   |   |   |   1   |   | \\ ");
puts("\n                          /  |   |           |           |   |  \\ ");
puts("\n                         / \\ |      ___  |   |   |  ___      | \\ \\ ");
puts("\n                        /\\\\  |   | /___\\     |     /___\\ |   |\\\\  \\ ");
puts("\n                       /  \\  |    /_____\\    |    /_____\\    |  \\  \\ ");
puts("\n                      /______|___/=======\\___|___/=======\\___|______\\ ");
puts("\n                             /   \\_______/  \\ /  \\_______/   \\ ");
puts("\n                            /___/        \\__ | __/        \\___\\ ");
puts("\n                          <|_________________|_________________|>");
puts("\n                           |__|__|__|__|__|__|__|__|__|__|__|__|");
puts("\n----------------------------V V V V V V V V V V V V V V V V V V----------------------------");
puts("\n");
}
