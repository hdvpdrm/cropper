#ifndef ACTIONS_H
#define ACTIONS_H
#include<SDL2/SDL.h>
#include<stdbool.h>
//this header contains procedures related to keyboard event procesess

extern void move_left_corner_down(SDL_Event* e, SDL_Rect* rect, int max_height, int cropping_step);
extern void move_left_corner_up(SDL_Event* e, SDL_Rect* rect,  int cropping_step);
extern void move_left_corner_left(SDL_Event* e,SDL_Rect* rect,  int cropping_step);
extern void move_left_corner_right(SDL_Event* e, SDL_Rect* rect, int max_width, int cropping_step);

extern void move_right_bottom_corner_down(SDL_Event* e, SDL_Rect* rect, int max_height, int cropping_step);
extern void move_right_bottom_corner_up(SDL_Event* e, SDL_Rect* rect, int cropping_step);
extern void move_right_bottom_corner_left(SDL_Event* e,SDL_Rect* rect, int cropping_step);
extern void move_right_bottom_corner_right(SDL_Event* e, SDL_Rect* rect, int max_width, int cropping_step);

extern int should_save(SDL_Event* e);
extern void undo(SDL_Event* e, bool* should_draw_cropper);

extern void increase_step(SDL_Event* e, int* step);
extern void decrease_step(SDL_Event* e, int* step);
#endif 
