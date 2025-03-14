#include "Window.h"

Window::Window(const char* title, int width, int height) {
    window = SDL_CreateWindow( title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
	components.clear();
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );	
}

Window::~Window() {
    SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	window = NULL;
	renderer = NULL;
}

void Window::render() {
	for (EventReceiver *cpn:components) {
		cpn->render();
	}
	SDL_RenderPresent(renderer);
}

void Window::clearScreen() {
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
}

void Window::handleEvent(SDL_Event* event) {
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	for (EventReceiver *cpn:components) {
		if (cpn->isInRect(mouseX, mouseY)) {
			cpn->handleEvent(event);
		}
	}
}