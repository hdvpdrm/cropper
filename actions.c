#include"actions.h"

void move_left_corner_down(SDL_Event* e, SDL_Rect* rect, int max_height)
{
  if(e->key.keysym.sym == SDLK_s)
    {
      if(rect->y+1 < max_height)
	rect->y+=1;
    }
}
void move_left_corner_up(SDL_Event* e, SDL_Rect* rect)
{
  if(e->key.keysym.sym == SDLK_w)
    {
      if(rect->y-1 > 0)
	{
	  rect->y-=1;
	}
    }
}
void move_left_corner_left(SDL_Event* e,SDL_Rect* rect)
{
  if(e->key.keysym.sym == SDLK_a)
    {
      if(rect->x-1 > 0)
	{
	  rect->x-=1;
	}
    }
}
void move_left_corner_right(SDL_Event* e, SDL_Rect* rect, int max_width)
{
  if(e->key.keysym.sym == SDLK_d)
    {
      if(rect->x +1 < max_width)
	{
	  rect->x += 1;
	}
    }
}


void move_right_bottom_corner_down(SDL_Event* e, SDL_Rect* rect, int max_height)
{
  if(e->key.keysym.sym == SDLK_DOWN)
    {
      if(rect->h+1 < max_height)
	rect->h+=1;
    }
}
void move_right_bottom_corner_up(SDL_Event* e, SDL_Rect* rect)
{
  if(e->key.keysym.sym == SDLK_UP)
    {
      if(rect->h-1 > 0)
	{
	  rect->h-=1;
	}
    }
}
void move_right_bottom_corner_left(SDL_Event* e,SDL_Rect* rect)
{
  if(e->key.keysym.sym == SDLK_LEFT)
    {
      if(rect->w-1 > 0)
	{
	  rect->w-=1;
	}
    }
}
void move_right_bottom_corner_right(SDL_Event* e, SDL_Rect* rect, int max_width)
{
  if(e->key.keysym.sym == SDLK_RIGHT)
    {
      if(rect->w +1 < max_width)
	{
	  rect->w += 1;
	}
    }
}
int should_save(SDL_Event* e)
{
  if(e->key.keysym.sym == SDLK_SPACE) return 1;

  return 0;
}
