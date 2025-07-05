#include <SDL2/SDL.h>
#include <stdio.h>
#include <unistd.h>

#include "renderer.h"

void terminal_loop(){
	int running = 1;
	SDL_Event event;

	while (running){
		while(SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT){
				running = 0;
			}
		}
	
		
		char* test = "Testing 123";
		SDL_Texture* generatedText = generate_text(test);

		int textW = 0, textH = 0;
		SDL_QueryTexture(generatedText, NULL, NULL, &textW, &textH);
				
		SDL_Rect pos = {100, 100, textW, textH};
		SDL_RenderClear(getRenderer());
		SDL_RenderCopy(getRenderer(), generatedText, NULL, &pos);
		SDL_RenderPresent(getRenderer());
		SDL_DestroyTexture(generatedText);
		SDL_Delay(10);
	}
			
}
