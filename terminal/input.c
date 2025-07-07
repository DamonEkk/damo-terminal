#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "renderer.h"

static char input[256] = {0};
static int buf_index = 0;

void special_key(SDL_Keycode key){
 
}

void key_press(char inputPress){
	printf("Detected Press");
	fflush(stdout);
	if (inputPress == '\0'){
		return;
	}

	if (buf_index < sizeof(input) - 1){
		input[buf_index] = inputPress;
		buf_index++;
		input[buf_index] = '\0';

		SDL_Texture* generatedText = generate_text(input, 0);
	


		int textW = 0, textH = 40;
		SDL_QueryTexture(generatedText, NULL, NULL, &textW, &textH);
				
		SDL_Rect pos = {5, 7, textW, textH};
		SDL_RenderClear(getRenderer());
		SDL_RenderCopy(getRenderer(), generatedText, NULL, &pos);
		SDL_RenderPresent(getRenderer());
		SDL_DestroyTexture(generatedText);
	}
}
