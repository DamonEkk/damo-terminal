#include <SDL2/SDL.h>
#include <SDL2/SDL_keyboard.h>
#include <stdio.h>
#include <unistd.h>

#include "renderer.h"
#include "input.h"

void terminal_loop(){
	SDL_StartTextInput();
	int running = 1;
	SDL_Event event;

	while (running){
		while(SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT){
				running = 0;
			}
			else if (event.type == SDL_KEYDOWN){
				
			}
			else if (event.type == SDL_TEXTINPUT){
				char press = event.text.text[0];
				key_press(press);	
			}
		}
	
		
		char* test = "Welcome to Damo-Terminal!";
		SDL_Texture* generatedText = generate_text(test, 0);

		int textW = 0, textH = 0;
		SDL_QueryTexture(generatedText, NULL, NULL, &textW, &textH);
				
		SDL_Rect pos = {5, 7, textW, textH};
		SDL_RenderClear(getRenderer());
		SDL_RenderCopy(getRenderer(), generatedText, NULL, &pos);
		SDL_RenderPresent(getRenderer());
		SDL_DestroyTexture(generatedText);
		SDL_Delay(10);
	}
			
}
