#include <SDL2/SDL.h>
#include <SDL2/SDL_keyboard.h>
#include <stdio.h>
#include <unistd.h>

#include "renderer.h"
#include "input.h"
#include "output.h"

// Main loop for terminal
void terminal_loop(){
	SDL_StartTextInput();
	int running = 1;
	SDL_Event event;
	starting_string();

	while (running){
		// Detects key presses and other sdl events
		while(SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT){
				running = 0;
			}
			else if (event.type == SDL_KEYDOWN){ // Special keys will handle backspace, enter etc.
				
			}
			else if (event.type == SDL_TEXTINPUT){ // Input printed to screen.
				char press = event.text.text[0];
				key_press(press);	
			}
		}
	
		
		char* test = "Welcome to Damo-Terminal!";
		SDL_Texture* generatedText = generate_text(test, 0);

		int textW = 0, textH = 0;
		SDL_QueryTexture(generatedText, NULL, NULL, &textW, &textH);
				
		SDL_Rect pos = {5, 7, textW, textH};
		SDL_RenderCopy(getRenderer(), generatedText, NULL, &pos);
		SDL_RenderPresent(getRenderer());
		SDL_DestroyTexture(generatedText);
		SDL_Delay(10);
	}
			
}

void execute_command(char* command){

}
