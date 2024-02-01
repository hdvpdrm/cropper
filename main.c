#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<stdio.h>
#include<stdbool.h>
#include"actions.h"

int init_window(SDL_Window** window,
		SDL_Renderer** renderer,
		int width, int height);

SDL_Surface* load_image_surface(char* path);
SDL_Texture* create_texture(SDL_Surface** image_surface,SDL_Renderer** renderer);

int main(int argc, char** argv)
{
  //#1: check args
  if(argc != 2)
    {
      printf("%s\n","cropper error: incorrect number of arguments");
      printf("%s\n","cropper usage example: ./cropper image.png");
      return 1;
    }

  //#2: load image
  SDL_Surface* image_surface = load_image_surface(argv[1]);
  if(image_surface == NULL) return 1;
 
  //#3: prepare window and renderer
  SDL_Window* window     = NULL;
  SDL_Renderer* renderer = NULL;
  if(init_window(&window,&renderer, image_surface->w,image_surface->h) != 0) return 1;

  //#4: init rect represents cropping area

  //make available change of alpha chanell
  if(SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND) < 0)
    {
      printf("cropper error: %s\n",SDL_GetError());
      return 1;
    }
  SDL_Rect rect = {0,0, image_surface->w,image_surface->h};
  

  
  //#5: create drawable texture based on image surface
  SDL_Texture* texture = create_texture(&image_surface, &renderer);
  if(texture == NULL) return 1;


  int width = image_surface->w;
  int height= image_surface->h;
  
  
  SDL_Event e;
  bool quit = false;
  while(!quit)
  {
    if(SDL_WaitEvent(&e))
      {
	if( e.type == SDL_QUIT ) quit = true;
	if(e.type == SDL_KEYDOWN)
	  {
	    //move if it's required
	    move_left_corner_down(&e,&rect,height);
	    move_left_corner_up(&e,&rect);
	    move_left_corner_left(&e,&rect);
	    move_left_corner_right(&e,&rect,width);
	    move_right_bottom_corner_up(&e,&rect);
	    move_right_bottom_corner_down(&e,&rect,height);
	    move_right_bottom_corner_left(&e,&rect);
	    move_right_bottom_corner_right(&e,&rect,width);
	  }
      }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);

    SDL_SetRenderDrawColor(renderer,0,0,100,100);
    SDL_RenderFillRect(renderer,&rect);
    
    SDL_RenderPresent(renderer);    
  }

  SDL_DestroyRenderer(renderer);
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
        printf( "cropper error: %s\n", path, IMG_GetError() );
	return NULL;
    }
    return surface;
}
SDL_Texture* create_texture(SDL_Surface** image_surface, SDL_Renderer** renderer)
{
  //i don't check is image_surface NULL, because it can be NULL. it's already checked
  
  SDL_Texture* texture = SDL_CreateTextureFromSurface(*renderer,*image_surface);
  if(texture == NULL)
    {
      printf("cropper error: %s\n",SDL_GetError());
      return NULL;
    }
  SDL_FreeSurface(*image_surface);
  return texture;
}
