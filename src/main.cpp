#include "SDL_main.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <iostream>

int main(int argc, char *argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_CreateWindowAndRenderer(400, 300, 0, &window, &renderer);

	std::wstring text = L"申し訳ございませんがたくさんあります。\n忘れている世界によって忘れている世界。\n汚れのない心の永遠の日差し！\nそれぞれの祈りが受け入れられ、それぞれが辞任を望む";
	TTF_Font *roboto = TTF_OpenFont("KosugiMaru-Regular.ttf", 16);
	
	SDL_Surface *sur = TTF_RenderUNICODE_Blended_Wrapped(roboto, (const Uint16*) text.c_str(), SDL_Color{ 255, 255, 255, 255 }, 300);
	SDL_Rect rect{ 50, 100, sur->w, sur->h };
	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, sur);
	SDL_FreeSurface(sur);

	SDL_Event event;
	bool done = false;

	while (!done) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
					done = 1;
				}
			}
		}

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, tex, NULL, &rect);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_CloseFont(roboto);

	return 0;
}
