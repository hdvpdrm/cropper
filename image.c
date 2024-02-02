#include"image.h"

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
int save_image(const char* file_name, SDL_Renderer** renderer,SDL_Texture** texture, SDL_Rect* area)
{
  SDL_Texture* target = SDL_GetRenderTarget(*renderer);
  SDL_SetRenderTarget(*renderer, *texture);

  int width, height;
  SDL_QueryTexture(*texture, NULL, NULL, &width, &height);
  SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);

  SDL_RenderReadPixels(*renderer, area, surface->format->format, surface->pixels, surface->pitch);
  IMG_SavePNG(surface, file_name);
  SDL_FreeSurface(surface);
  SDL_SetRenderTarget(*renderer, target);
}
