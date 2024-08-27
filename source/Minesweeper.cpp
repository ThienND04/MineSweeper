//Using SDL, SDL_image, standard IO, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
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
	initWindows();
	Timer::getInstance()->start();

	//Main loop flag
	bool quit = false;
	//Event handler
	SDL_Event e;
	//While application is running
	while( !quit )
	{
		
		// Handle events on queue
		while( SDL_PollEvent( &e ) != 0)
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			} else {
				windowsHandleEvent(&e);
			}
		}
		Timer::getInstance()->update();
		updateGUI();
		clearScreens();
		renderAll();
		SDL_Delay(1000/FPS);
	}
}

void Minesweeper::updateGUI() {
	for (int i = 0; i < windows.size(); i ++) {
		if (windows[i]->isShowed()){
			controllers[i]->updateGUI();
		}
	}
}

void Minesweeper::windowsHandleEvent(SDL_Event *event) {
	for (int i = 0; i < windows.size(); i ++) {
		if (windows[i]->isShowed()) {
			windows[i]->handleEvent(event);
		}
	}
}

void Minesweeper::clearScreens() {
	for (int i = 0; i < windows.size(); i ++) {
		if (windows[i]->isShowed()){
			windows[i]->clearScreen();
		}
	}
}

void Minesweeper::renderAll() {
	for (int i = 0; i < windows.size(); i ++) {
		if (windows[i]->isShowed()) {
			windows[i]->render();
		}
	}
}

void Minesweeper::initWindows() {
	windows.resize(WINDOWS::WINDOW_TOTALS);
	controllers.resize(WINDOWS::WINDOW_TOTALS);

	windows[WINDOWS::WINDOW_START] = WindowStart::getInstance();
	windows[WINDOWS::WINDOW_START]->setShown(true);
	controllers[WINDOWS::WINDOW_START] = ControllerStart::getInstance();

	windows[WINDOWS::WINDOW_GAME_EASY] = new WindowGame(GameEasy::getInstance());
	windows[WINDOWS::WINDOW_GAME_EASY]->setShown(false);
	controllers[WINDOWS::WINDOW_GAME_EASY] = GameController::getInstance();
	((GameController*) controllers[WINDOWS::WINDOW_GAME_EASY])->setWindowGame((WindowGame *)windows[WINDOWS::WINDOW_GAME_EASY]);
}

int main( int argc, char* args[] )
{
	srand(time(0));
	FILE *LOG = freopen("log.txt", "w", stdout);
	printf ("start hehe\n");
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
		} catch (...) {
			printf ("Error: %s\n", SDL_GetError());
		} 
	}

	if (game != NULL) game->exit();
	
	return 0;
}
