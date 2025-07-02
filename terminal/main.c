#include <SDL2/SDL.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** args){
	SDL_Surface* winSurface = NULL;
	SDL_Window* window = NULL;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("Error Init failed");
		return 1;
	}

	window = SDL_CreateWindow("DaMo-Terminal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

	if (!window){
		printf("Failed to create window, SDL_CreateWindow bug");
		return 1;	
	}

	winSurface = SDL_GetWindowSurface(window);

	if (!winSurface){
		printf("failed to view windowSurf");
		return 1;
	}
	
	SDL_FillRect(winSurface, NULL, SDL_MapRGB (winSurface-> format, 0, 0, 0));
	SDL_UpdateWindowSurface(window);

	SDL_Event event;
	int running = 1;

	while (running){
		while (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				running = 0;
			}
		}
		SDL_Delay(10);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;


}


