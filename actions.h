#ifndef ACTIONS_H
#define ACTIONS_H
#include<SDL2/SDL.h>
//this header contains procedures related to keyboard event procesess

extern void move_left_corner_down(SDL_Event* e, SDL_Rect* rect, int max_height);
extern void move_left_corner_up(SDL_Event* e, SDL_Rect* rect);
extern void move_left_corner_left(SDL_Event* e,SDL_Rect* rect);
extern void move_left_corner_right(SDL_Event* e, SDL_Rect* rect, int max_width);

extern void move_right_bottom_corner_down(SDL_Event* e, SDL_Rect* rect, int max_height);
extern void move_right_bottom_corner_up(SDL_Event* e, SDL_Rect* rect);
extern void move_right_bottom_corner_left(SDL_Event* e,SDL_Rect* rect);
extern void move_right_bottom_corner_right(SDL_Event* e, SDL_Rect* rect, int max_width);

int should_save(SDL_Event* e);
#endif 
