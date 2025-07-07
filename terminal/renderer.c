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

SDL_Texture* generate_text(const char* text, int flag){
	// Flag is used to determine if the text is user input:

	SDL_Color fontColour = {255, 255, 255};
	uint8_t sizeOfFont = 16;

	if (TTF_Init() < 0){
		printf("Could not init TTF");
	}

	TTF_Font* font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf", sizeOfFont);

	if (font == NULL){
		printf("Failed to load font");
		return 0;
	}

	SDL_Surface* surfaceText = TTF_RenderText_Solid(font, text, fontColour); 

	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, surfaceText);
	SDL_FreeSurface(surfaceText);
	TTF_CloseFont(font);

	return textTexture;

}

void render_background(SDL_Color colour){
	SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}

