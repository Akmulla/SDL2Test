#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
//#include <SDL_image.h>

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

SDL_Surface* LoadSurface(const char* path)
{
	SDL_Surface* optimizedSurface = NULL;

	SDL_Surface* loadedSurface = SDL_LoadBMP(path);

	if (loadedSurface == NULL)
	{
		printf("Unable to load image");
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

bool LoadImage(const char* path)
{
	gHelloWorld = SDL_LoadBMP(path);
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image");
		return false;
	}

	return true;
}

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Could not initialize SDL\n");
		return -1;
	}

	printf("SDL initialized\n");

	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (gWindow == NULL)
	{
		printf("Could not initialize window\n");
		return -1;
	}

	printf("Window initialized\n");

	gScreenSurface = SDL_GetWindowSurface(gWindow);

	if (!LoadImage("Images/Idle.bmp"))
	{
		return -1;
	}

	SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

	SDL_Surface* optimizedSurface = LoadSurface("Images/Idle.bmp");
	SDL_Rect stretchRect;
	stretchRect.x = 100;
	stretchRect.y = 100;
	stretchRect.w = 100;
	stretchRect.h = 100;
	SDL_BlitScaled(optimizedSurface, NULL, gScreenSurface, &stretchRect);

	SDL_UpdateWindowSurface(gWindow);

	//Main loop
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

	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();

	return 0;
}

