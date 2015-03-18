/* ------------------------------------------------------
   Auteur : Collignon Rémi
   			Morvan Guy-Yann
   	Fonction ihm
   	Demande à l'utilisateur de rentrer 2 chiffres
   	-----------------------------------------------------*/
#include "ihm.h"

void ihm(int* e1, int* e2)
{
	char number[5];
	bool okNum=false;

	line();
	line();
	robot();
	printf("\n\t\tProgramme de dessin du bras Youpi\n");
	printf("\n\t\t--Projet CIR3  ---  MORVAN / COLLIGNON\n\n");
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
	printf("###################################################################################\n");
}
void robot() {
puts("                                         __-----__");
puts("                                        / \\_____/ \\ ");
puts("                                      <|<  \\___/  >|>");
puts("                                      _| |=== ===| |_");
puts("                                      \\|/         \\|/");
puts("                                       |\\   /^\\   /|");
puts("                                        \\    |    /");
puts("                                       [|\\_^---^_/|]");
puts("                                        |_\\_____/_|");
puts("            ___^_______^__           ___|_______|_|___           __^_______^___");
puts("          <||  ^ \\___/ ^  |      _^_|_______________|_|_^_      |  ^ \\___/ ^  ||>");
puts("          <||  ^   |   ^  |_____||^    \\___________/    ^||_____|  ^   |   ^  ||>");
puts("          <||  v   |   v  | | | ||^     \\_________/     ^|| | | |  v   |   v  ||>");
puts("          <||  v  _|_  v  |_|_|_||v      \\_______/  X1  v||_|_|_|  v  _|_  v  ||>");
puts("          <||__v_/___\\_v__|      \\\\   __________  _____ //      |__v_/___\\_v__||>");
puts("              |_________|         \\|      _______      |/         |_________|");
puts("               |____ |_|           \\_____/_______\\_____/           |____ |_|");
puts("               |____ |_|               |________ |_|               |____ |_|");
puts("               |____ |_|               |________ |_|               |____ |_|");
puts("              _|____ |_|_              |________ |_|              _|____ |_|_");
puts("            _|   \\___/   |_            |________ |_|            _|   \\___/   |_");
puts("           | |     |     | |         __|________ |_|__         | |     |     | |");
puts("           |_|    _|_    |_|       <|  \\___________/  |>       |_|    _|_    |_|");
puts("             |___/___\\___|        __|____ _     _ ____|__        |___/___\\___|");
puts("               |____ |_|         |  |||  | |   | |  |||  |         |____ |_|");
puts("               |____ |_|        /|  |||  | |   | |  |||  |\\        |____ |_|");
puts("             __|____ |_|__     |_|  |||  | |   | |  |||  |_|      _|____ |_|_");
puts("           <|<  <>   <>  >|>    \\|  |||  |\\_____/|  |||  |/      |___________|");
puts("            | ()    ()   (       |__|||__|       |__|||__|      <|< <>   <> >|>");
puts("             )   ()    () |       |__ |_|         |__ |_|        |___________|");
puts("            | ()    ()   (        |__ |_|         |__ |_|           |_____|");
puts("             )   ()    () |       |__ |_|         |__ |_|          / \\   / \\ ");
puts("            | ()    ()   (        |__ |_|         |__ |_|         /   \\ /   \\ ");
puts("             )   ()    () |       |__ |_|         |__ |_|        / \\  (o)    \\ ");
puts("            |_____________|       |__ |_|         |__ |_|      <|\\\\  / V \\    |>");
puts("             \\___________/        |__ |_|         |__ |_|      <| \\ /     \\   |>");
puts("               _|||||||_          |__ |_|         |__ |_|      <|  |>     <|  |>");
puts("              \\ |     | /      ___|__ |_|___   ___|__ |_|___     \\ |>     <| /");
puts("               \\|_____|/      |     |||     | |     |||     |     \\|>     <|/");
puts("                 |___|       /|   -/   \\-   | |   -/   \\-   |\\");
/*puts("                            |_|  -|  x  |-  | |  -|  x  |-  |_|");
puts("                             \\|   -\\___/-   | |   -\\___/-   |/");
puts(" GIANT ASCII ROBOTS           |_____|||_____| |_____|||_____|");
puts("                                |_________|     |_________|");
puts("   X1 Battle-Bot                 |_||_||_|       |_||_||_|");
puts("                                 /_______\\       /_______\\ ");
puts(" © copyright 2007               _/_______\\_     _/_______\\_");
puts("Joseph V. Barrile Jr.          /           \\   /           \\ ");
puts(" January 16, 2007             /  \\_______/  \\ /  \\_______/  \\ ");
puts("                             |   |       |   |   |       |   |");
puts("                            /|   |   X   |   |   |   X   |   |\\ ");
puts("                           / |   |   1   |   |   |   1   |   | \\ ");
puts("                          /  |   |           |           |   |  \\ ");
puts("                         / \\ |      ___  |   |   |  ___      | \\ \\ ");
puts("                        /\\\\  |   | /___\\     |     /___\\ |   |\\\\  \\ ");
puts("                       /  \\  |    /_____\\    |    /_____\\    |  \\  \\ ");
puts("                      /______|___/=======\\___|___/=======\\___|______\\ ");
puts("                             /   \\_______/  \\ /  \\_______/   \\ ");
puts("                            /___/        \\__ | __/        \\___\\ ");
puts("                          <|_________________|_________________|>");
puts("                           |__|__|__|__|__|__|__|__|__|__|__|__|");
puts("----------------------------V V V V V V V V V V V V V V V V V V----------------------------");*/
puts("\n");
}
