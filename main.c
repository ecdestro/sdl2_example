#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow(
					"Simple SDL2 Example", 
				       	SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					SCREEN_WIDTH, SCREEN_HEIGHT,
					SDL_WINDOW_SHOWN);
	if (window == NULL) {
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return 1;
	}

	bool quit = false;
	SDL_Event e;
	bool isBlue = false;

	while(!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				if (e.button.button == SDL_BUTTON_LEFT) {
					isBlue = true;
				} else {
					isBlue = false;
				}
			}
		}

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		SDL_Rect square = {SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
		if (isBlue) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		} else {
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		}

		SDL_RenderFillRect(renderer, &square);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
