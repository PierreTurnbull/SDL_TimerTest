#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_Image.h>

int   main(int argc, char *argv[])
{
  SDL_Window      *window;
  SDL_Renderer    *rend;
  int i;

  if (SDL_Init(SDL_INIT_VIDEO) != 0 || (IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG) != IMG_INIT_JPG)
  {
      fprintf(stdout,"MAIN\nFailed SDL initialization: \"%s\"\n\n", SDL_GetError());
      return -1;
  }
  return 0;
}
