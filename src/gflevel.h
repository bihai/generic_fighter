#ifndef __GF_LEVEL_H__
#define __GF_LEVEL_H__

#include <SDL.h>
#include "gfscreen.h"

typedef struct _gflevel {
  char description[2048];
  SDL_Surface *bg_surface;
  gfscreen *screen;
  int width, height;
  int offsetx, offsety;
  int maxxoffset, maxyoffset;
  int draw_type; //If should draw tile of stretched
} gflevel;

gflevel *gflevel_new(void);
void gflevel_init(gflevel *level, gfscreen *scr);
void gflevel_finish(gflevel *level);
void gflevel_destroy(gflevel *level);
void gflevel_move(gflevel *level, int dx, int dy);
void gflevel_draw(gflevel *level);

#endif //__GF_LEVEL_H__
