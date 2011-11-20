#include "gflevel.h"
#include <stdlib.h>

gflevel *gflevel_new(void) {
  return (gflevel *) malloc(sizeof(gflevel));
}

void gflevel_init(gflevel *level, gfscreen *scr) {
  level->bg_surface=NULL;
  level->width=level->height=0;
  level->offsetx=level->offsety=0;
  level->screen = scr;
  level->maxxoffset=0;
  level->maxyoffset=0;
}

void gflevel_finish(gflevel *level) {
  
}

void gflevel_destroy(gflevel *level) {
  free(level);
}

void gflevel_move(gflevel *level, int dx, int dy) {
  level->offsetx += dx;
  level->offsety += dy;
  if ((level->offsetx)>level->maxxoffset)
    level->offsetx = level->maxxoffset;
  if ((level->offsety)>level->maxyoffset)
    level->offsety = level->maxyoffset;

  if (level->offsetx<0) level->offsetx = 0;
  if (level->offsety<0) level->offsety = 0;
}

void gflevel_draw(gflevel *level) {
  int i, j;
  SDL_Rect srcrect, dstrect;
  
  //  level->offsetx +=3;
  level->offsetx = level->offsetx % level->bg_surface->w;
  //  level->offsety +=3;
  level->offsety = level->offsety % level->bg_surface->h;
  for (i=0; i<SCREEN_WIDTH+(level->bg_surface->w); i+=(level->bg_surface->w))
    for (j=0; j<SCREEN_HEIGHT+(level->bg_surface->h); j+=(level->bg_surface->h)) {
      srcrect.x = 0;
      srcrect.y = 0;
      srcrect.w = level->bg_surface->w;
      srcrect.h = level->bg_surface->h;
      dstrect.x = i-level->offsetx;
      dstrect.y = j-level->offsety;
      dstrect.w = level->bg_surface->w;
      dstrect.h = level->bg_surface->h;
      
      SDL_BlitSurface(level->bg_surface,          
		      &srcrect, 
		      level->screen->sdl_surface, 
 		      &dstrect);
    } 
}

