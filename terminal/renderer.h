#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

void renderer_init(SDL_Window* window);

SDL_Renderer* getRenderer();

void renderer_destroy();

SDL_Texture* generate_text(const char* text, int flag);

void render_background(SDL_Color colour);

