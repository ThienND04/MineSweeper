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
#include <Window_Start.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Minesweeper *Minesweeper::instance = NULL;

Minesweeper *Minesweeper::getInstance() {
	if (instance == NULL) {
		instance = new Minesweeper();
	}
	return instance;
}

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
	TextureCreator::getInstance()->setFont("fonts/lazy/lazy.ttf", 20);
	setWindow(WindowStart::getInstance());
	setController(GameController::getInstance());
	window->createComponents();

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
		// controller->updateGUI();
		// printf("Game easy button event: %d\n",  (window->getComponents()->at(1)->handleLeftClick.operator bool()));
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
			game = Minesweeper::getInstance();
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
			printf ("Error: %s\n", e.what());
			printf ("Error: %s\n", SDL_GetError());
		}
	}

	if (game != NULL) game->exit();

	return 0;
}
