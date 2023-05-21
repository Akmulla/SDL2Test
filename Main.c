#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Could not initialize window");
		return -1;
	}

	printf("Window initialized");

	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Event e;
	bool quit = false;

	while (quit == false)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT) 
				quit = true;
		}
	}

	return 0;
}