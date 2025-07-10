#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "renderer.h"
#include "utils.h"
#include "output.h"

static char input[255] = {0};
static int buf_index = 0;

void special_key(SDL_Keycode key){
 	printf("SPecial key clicked");
	fflush(stdout);

}

void key_press(char inputPress){
	if (inputPress == '\0'){
		return;
	}

	if (buf_index < sizeof(input) - 1){
		input[buf_index] = inputPress;
		buf_index++;
		input[buf_index] = '\0';

		SDL_Texture* generatedText = generate_text(input, 0);
	


		int textW = 0, textH = 0;
		SDL_QueryTexture(generatedText, NULL, NULL, &textW, &textH);

		int xPos = get_text_width() + 10;
				
		SDL_Rect pos = {xPos, 690, textW, textH};
		SDL_RenderCopy(getRenderer(), generatedText, NULL, &pos);
		SDL_RenderPresent(getRenderer());
		SDL_DestroyTexture(generatedText);
	}
}


