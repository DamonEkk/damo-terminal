#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
 
static SDL_Renderer* renderer = NULL;

void renderer_init(SDL_Window* window){
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!renderer){
		printf("renderer failed to init");
	}
}

SDL_Renderer* getRenderer(){
	return renderer;
}

void renderer_destroy(){
	if (renderer){
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
	}

	TTF_Quit();
	SDL_Quit();
}

void generateText(){

	SDL_Color fontColour = {255, 255, 255};
	uint8_t sizeOfFont = 16;

	if (TTF_Init() < 0){
		printf("Could not init TTF");
	}

	TTF_Font* font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf", sizeOfFont);

	if (font == nullptr){
		printf("Failed to load font");
		return 0;
	}

	SDL_Surface* surfaceText = TTF_RenderText_Solid(font, "testing", fontColour); 
}

