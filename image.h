#ifndef IMAGE_H
#define IMAGE_H
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

//this header contains functions related to image processing

extern SDL_Surface* load_image_surface(char* path);
extern SDL_Texture* create_texture(SDL_Surface** image_surface,SDL_Renderer** renderer);
extern void save_image(const char* file_name,
		      SDL_Renderer** renderer,
		      SDL_Texture** texture,
		      SDL_Rect* area,
		      int ext_type);
#endif
