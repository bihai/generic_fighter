#ifndef __GF_SCREEN_H__
#define __GF_SCREEN_H__

#include <SDL.h>
#define SCREEN_WIDTH   640
#define SCREEN_HEIGHT  480
#define SCREEN_BPP 0

typedef struct _gfscreen {
  SDL_Surface *sdl_surface;
  SDL_Surface *screen_surface;
} gfscreen;


gfscreen *gfscreen_new(void);
void gfscreen_init( gfscreen *s);
void gfscreen_finish( gfscreen *s);
void gfscreen_destroy( gfscreen *s);
void gfscreen_draw_line(gfscreen *s, int x1, int y1, int x2, int y2, Uint32 color);

#endif //__GF_SCREEN_H__
