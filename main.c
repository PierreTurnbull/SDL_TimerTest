#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_Image.h>

int   main(int argc, char **argv)
{
  SDL_Window		*window;
  SDL_Renderer	*rend;
	SDL_Texture		*img = IMG_LoadTexture(rend, "./images/range.png");
	int frame_nb;
	int timer;
	int i;
	int j;
	int k;
	int nb;

  if (SDL_Init(SDL_INIT_VIDEO) != 0 || (IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG) != IMG_INIT_JPG)
  {
      fprintf(stderr,"MAIN\nFailed SDL initialization: \"%s\"\n\n", SDL_GetError());
      return -1;
  }
	window = SDL_CreateWindow("Hello!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 480, 0);
	rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	frame_nb = 30;

	// TEST 1

	/*nb = 75;
	for (j = 0; j < frame_nb; j++)
	{
		timer = SDL_GetTicks();
		for (i = 0; i < nb; i++)
			SDL_RenderPresent(rend);
		fprintf(stderr, "Test 1 took %dms.\n", (SDL_GetTicks() - timer));
	}*/

	// TEST 2

	/*nb = 750;
	for (j = 0; j < frame_nb; j++)
	{
		timer = SDL_GetTicks();
		for (i = 0; i < nb; i++)
		{
			SDL_SetRenderDrawColor(rend, 255, 100, 20, 120);
			SDL_RenderClear(rend);
		}
		SDL_RenderPresent(rend);
		fprintf(stderr, "Test 2 took %dms.\n", (SDL_GetTicks() - timer));
	}*/

	// TEST 3

	/*nb = 1;
	SDL_Rect	rectangle = {0, 0, 200, 200};
	for (j = 0; j < frame_nb; j++)
	{
		timer = SDL_GetTicks();
		for (i = 0; i < nb; i++)
		{
			SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
			SDL_RenderClear(rend);
			SDL_RenderPresent(rend);
			for (k = 0; k < 30; k++)
			{
				rectangle.x = k * 10;
				rectangle.y = k * 10;
				SDL_SetRenderDrawColor(rend, 255, 100, 20, 120);
				SDL_RenderDrawRect(rend, &rectangle);
				SDL_RenderPresent(rend);
			}
		}
		fprintf(stderr, "Test 3 took %dms.\n", (SDL_GetTicks() - timer));
	}*/

	// TEST 4

	nb = 1;
	SDL_Rect 		img_pos = {0, 0, 600, 480};
	for (j = 0; j < frame_nb; j++)
	{
		timer = SDL_GetTicks();
		for (i = 0; i < nb; i++)
		{
			SDL_RenderClear(rend);
			SDL_RenderPresent(rend);
			for (k = 0; k < 100; k++)
			{
				SDL_RenderCopy(rend, img, NULL, &img_pos);
			}
			SDL_RenderPresent(rend);
		}
		fprintf(stderr, "Test 4 took %dms.\n", (SDL_GetTicks() - timer));
	}

	SDL_DestroyTexture(img);
	IMG_Quit();
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(window);
	SDL_Quit();
  return 0;
}
