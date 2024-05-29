#include <MainTest.h>

void mainTest() {

    Minesweeper *game = new Minesweeper();
    game->init();
    
    try {
        test01();
    } catch (std::exception e) {
        printf("Error: %s\n", e.what());
    }
}

void test01() {
    Window *window = new WindowGame(GameEasy::getInstance());
    TextureCreator::getInstance()->setFont("fonts/open-sans/OpenSans-Bold.ttf", 24);
    TextureCreator::getInstance()->setRenderer(window->getRenderer());
    Texture *number = TextureCreator::getInstance()->createTexture("HELLO", {255, 0, 0, 0xFF});
    // Texture *number1 = new Texture(window->getRenderer());
    // TTF_Font *font = TTF_OpenFont("fonts/lazy/lazy.ttf", 24);
    // std::cout << "Fontadd: " << font << std::endl;
    // number1->setFont(font);
    // number1->loadFromRenderedText("HALLO", {0, 0, 0, 255});
    bool quit = false;
	//Event handler
	SDL_Event e;
	//While application is running
	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
		}
		window->clearScreen();
        window->render();
		number->render(0, 0);
        // number1->render(20, 20);
		SDL_RenderPresent(window->getRenderer());
	}
}