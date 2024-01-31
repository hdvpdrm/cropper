#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<stdio.h>
#include<stdbool.h>


int init_window(SDL_Window** window,
		SDL_Renderer** renderer,
		int width, int height);
SDL_Surface* load_image_surface(char* path);
int main(int argc, char** argv)
{
  if(argc != 2)
    {
      printf("%s\n","cropper error: incorrect number of arguments");
      printf("%s\n","cropper usage example: ./cropper image.png");
      return 1;
    }

  SDL_Surface* image_surface = load_image_surface(argv[1]);
  if(image_surface == NULL) return 1;
  
  
  SDL_Window* window     = NULL;
  SDL_Renderer* renderer = NULL;
  
  if(init_window(&window,&renderer, image_surface->w,image_surface->h) != 0) return 1;

  SDL_Event e;
  bool quit = false;
  while(!quit)
  {
    if(SDL_WaitEvent(&e))
      {
	if( e.type == SDL_QUIT ) quit = true;
      }

    SDL_RenderClear(renderer);                        
    SDL_RenderPresent(renderer);    
  }
  
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
int init_window(SDL_Window** window, SDL_Renderer** renderer,int width, int height)
{
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      printf("%s\n","cropper error: failed to init SDL!");
      return 1;
    }
  if(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0)
    {
      printf("%s\n","cropperer error: failed to init SDL_image!");
      return 1;
    }
  
  *window = SDL_CreateWindow("Cropper",
			     0,
			     0,
			     width,
			     height,
			     SDL_WINDOW_SHOWN);
  if(*window == NULL)
    {
      printf("%s\n","cropper error: failed to create window!");
      return 1;
    }

  *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED );
  if(*renderer == NULL)
  {
      printf("cropper error: %s\n", SDL_GetError());
      return 1;
  }   
  SDL_SetRenderDrawColor(*renderer, 0xFF, 0xFF, 0xFF, 0xFF);

  return 0;
}

SDL_Surface* load_image_surface(char* path)
{  
  if(path == NULL) return NULL;
  

    //Load image at specified path
    SDL_Surface* surface = IMG_Load(path);
    if(surface == NULL )
    {
        printf( "cropper error:: %s\n", path, IMG_GetError() );
	return NULL;
    }
    return surface;
}
