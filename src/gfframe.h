#ifndef __gfframe_h__
#define __gfframe_h__

#include <SDL_mixer.h>

#define NUM_RECTS_ON_FRAME 10

typedef struct _gfframe {
  int motion_x, motion_y;
  int num_rects;
  int rects[NUM_RECTS_ON_FRAME];
  SDL_Surface *image[2];
  Mix_Chunk   *sound;
} gfframe;



gfframe *gfframe_new(void);
void gfframe_init(gfframe *g);
void gfframe_finish(gfframe *g);
void gfframe_destroy(gfframe *g);


#endif //__gfframe_h__
