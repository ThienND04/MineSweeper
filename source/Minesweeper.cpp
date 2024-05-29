//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <Button.h>
#include <Window.h>
#include <iostream>
#include <Minesweeper.h>
#include <Window_Game.h>
#include <GameEasy.h>
#include <MainTest.h>
#include <cstring>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool Minesweeper::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}
		int imgFlags = IMG_INIT_PNG;
		if( !( IMG_Init( imgFlags ) & imgFlags ) )
		{
			printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
			success = false;
		}

		//Initialize SDL_ttf
        if( TTF_Init() == -1 )
        {
            printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
            success = false;
        }
	}

	return success;
}

void Minesweeper::exit()
{
	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void Minesweeper::start() {
	// window = new Window("TITLE", SCREEN_WIDTH, SCREEN_HEIGHT);
	window = new WindowGame(GameEasy::getInstance());
	gameController = GameController::getInstance();
	gameController->setWindowGame((WindowGame*) window);
	printf("cpn size: %d\n", window->getComponents()->size());

	// printf("%d\n", ((WindowGame*) window)->getGame());
	printf("WindowGameAdd: %p\n", ((WindowGame*) window)->getGame());
	printf("Instance add: %p\n", GameEasy::getInstance());
	if (((WindowGame*) window)->getGame() == GameEasy::getInstance()) {
		printf("Same\n");
	} else printf("Diff\n");
	printf("Window size: %d %d\n", ((WindowGame*) window)->getGame()->getNRow(), ((WindowGame*) window)->getGame()->getNCol());
		//Main loop flag
		bool quit = false;
		//Event handler
		SDL_Event e;
		//While application is running
		while( !quit )
		{
			
			//Handle events on queue
			while( SDL_PollEvent( &e ) != 0)
			{
				//User requests quit
				if( e.type == SDL_QUIT )
				{
					quit = true;
				} else {
					window->handleEvent(&e);
				}
			}
			gameController->updateGUI();
			window->clearScreen();
			window->render();
			SDL_RenderPresent(window->getRenderer());
			SDL_Delay(1000/60);
		}
}

int main( int argc, char* args[] )
{
	srand(time(0));
	FILE *LOG = freopen("log.txt", "w", stdout);
	printf ("start\n");
	Minesweeper *game = NULL;

	printf("Arg[1]: %s\n", args[1]);
	if (argc > 1 && strcmp(args[1], "test") == 0) {
		printf("Test\n");
		mainTest();
	} else {

		try {
			game = new Minesweeper();
			//Start up SDL and create window
			if(! game->init())
			{
				printf( "Failed to initialize!\n" );
			}
			else
			{	
				printf("Success\n");
				game->start();
			}
			//Free resources and close SDL
			game->exit();
		} catch (std::exception e) {
			printf ("Error: %s\n", SDL_GetError());
		}
	}

	if (game != NULL) game->exit();

	return 0;
}
