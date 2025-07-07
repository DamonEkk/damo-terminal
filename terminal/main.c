#include <SDL2/SDL.h>
#include <stdio.h>
#include <unistd.h>

#include "renderer.h"
#include "terminal.h"

int main(int argc, char** args){
	SDL_Surface* winSurface = NULL;
	SDL_Window* window = NULL;
	printf("does this work");

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("Error Init failed");
		return 1;
	}

	window = SDL_CreateWindow("DaMo-Terminal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

	if (!window){
		printf("Failed to create window, SDL_CreateWindow bug");
		return 1;	
	}

	renderer_init(window);
		SDL_Color DEFAULT_BACKGROUND = {10, 10, 10, 200}; 
	render_background(DEFAULT_BACKGROUND);
	terminal_loop();

	renderer_destroy();

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;


}


