
#ifndef __GF_SPRITE_H__
#define __GF_SPRITE_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "gfcommon.h"
#include "gfrect.h"
#include "gfframe.h"
#include "gfaction.h"
#include "gfinputset.h"
#include "gfinput.h"

enum {
  SPRITE_SIDELEFT=0,
  SPRITE_SIDERIGHT
};

typedef struct _gfsprite {
  int num_gfrects, num_frames, num_actions;
  int num_inputsets, num_magics, num_inputs;
  gfrect *rects;
  gfframe *frames;
  gfaction *actions;
  gfinputset *inputsets;
  gfinput *inputs;

  //private
  int current_action;
  int current_frame;
  int x, y;
  int current_side;
  int energy;
} gfsprite;

gfsprite *gfsprite_new(void);
void gfsprite_init(gfsprite *sp);
void gfsprite_finish(gfsprite *sp);
void gfsprite_destroy(gfsprite *sp);
int  gfsprite_load(gfsprite *sp, char *sprdir, char *sprfile);
void gfsprite_unload(gfsprite *sp);
int  gfsprite_process_inputset(gfsprite *sp, gfsprite *enemy, gfinputset *is,
			       int offsetx, int offsety );
int gfsprite_draw(gfsprite *sp, gfscreen *sc, int screen_width, int offsetx, int offsety, int *offsetxdone);
int gfsprite_be_on_screen(gfsprite *sp, gfscreen *sc, int offsetx, int offsety);
int gfsprite_process_colision(gfsprite *sp, gfsprite *enemy);

#endif // __GF_SPRITE_H__
