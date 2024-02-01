#ifndef IMAGE_H
#define IMAGE_H
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

//this header contains functions related to image processing

extern SDL_Surface* load_image_surface(char* path);
extern SDL_Texture* create_texture(SDL_Surface** image_surface,SDL_Renderer** renderer);

#endif
