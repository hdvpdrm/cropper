#include"actions.h"

void move_left_corner_down(SDL_Event* e, SDL_Rect* rect, int max_height,  int cropping_step)
{
  if(e->key.keysym.sym == SDLK_s)
    {
      if(rect->y+cropping_step < max_height)
	rect->y+=cropping_step;
    }
}
void move_left_corner_up(SDL_Event* e, SDL_Rect* rect,  int cropping_step)
{
  if(e->key.keysym.sym == SDLK_w)
    {
      if(rect->y-cropping_step > 0)
	{
	  rect->y-=cropping_step;
	}
    }
}
void move_left_corner_left(SDL_Event* e,SDL_Rect* rect,  int cropping_step)
{
  if(e->key.keysym.sym == SDLK_a)
    {
      if(rect->x-cropping_step > 0)
	{
	  rect->x-=cropping_step;
	}
    }
}
void move_left_corner_right(SDL_Event* e, SDL_Rect* rect, int max_width,  int cropping_step)
{
  if(e->key.keysym.sym == SDLK_d)
    {
      if(rect->x +cropping_step < max_width)
	{
	  rect->x += cropping_step;
	}
    }
}


void move_right_bottom_corner_down(SDL_Event* e, SDL_Rect* rect, int max_height,  int cropping_step)
{
  if(e->key.keysym.sym == SDLK_DOWN)
    {
      if(rect->h+cropping_step < max_height)
	rect->h+=cropping_step;
    }
}
void move_right_bottom_corner_up(SDL_Event* e, SDL_Rect* rect,  int cropping_step)
{
  if(e->key.keysym.sym == SDLK_UP)
    {
      if(rect->h-cropping_step > 0)
	{
	  rect->h-=cropping_step;
	}
    }
}
void move_right_bottom_corner_left(SDL_Event* e,SDL_Rect* rect,  int cropping_step)
{
  if(e->key.keysym.sym == SDLK_LEFT)
    {
      if(rect->w-cropping_step > 0)
	{
	  rect->w-=cropping_step;
	}
    }
}
void move_right_bottom_corner_right(SDL_Event* e, SDL_Rect* rect, int max_width,  int cropping_step)
{
  if(e->key.keysym.sym == SDLK_RIGHT)
    {
      if(rect->w +cropping_step < max_width)
	{
	  rect->w += cropping_step;
	}
    }
}
int should_save(SDL_Event* e)
{
  if(e->key.keysym.sym == SDLK_SPACE) return 1;

  return 0;
}
void undo(SDL_Event* e, bool* should_draw_cropper)
{
  if(e->key.keysym.sym == SDLK_ESCAPE)
    *should_draw_cropper = true;
}

extern void increase_step(SDL_Event* e, int* step)
{
  if(e->key.keysym.sym == SDLK_x)
    if(*step != 100)*step+=1;
}
extern void decrease_step(SDL_Event* e, int* step)
{
  if(e->key.keysym.sym == SDLK_z)
    if(*step != 0)*step-=1;
}
