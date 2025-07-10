#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "renderer.h"

int textH, textW;

// Produces the front string on the input text area.
void starting_string(){
	char* cd = get_cd();
	char* name = get_user_string();
	if (strlen(cd) + strlen(name) >= 255){
		return;
	}

	strcat(name, "$");
	strcat(name, cd);
	strcat(name, ":");


	SDL_Texture* generatedText = generate_text(name, 0);


	textW = 0, textH = 0;
	SDL_QueryTexture(generatedText, NULL, NULL, &textW, &textH);
			
	SDL_Rect pos = {5, 690, textW, textH};
	SDL_RenderCopy(getRenderer(), generatedText, NULL, &pos);
	SDL_RenderPresent(getRenderer());
	SDL_DestroyTexture(generatedText);
}


void enter_input(){}

void clear_input(){}

int get_text_height(){
	return textH;
}

int get_text_width(){
	return textW;
}

