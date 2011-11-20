#ifndef __GF_GAMELOOP_H__
#define __GF_GAMELOOP_H__

#include "gfsprite.h"
#include "gflevel.h"

typedef struct _gfgameloop {
  SDL_Event event;       //To receive events from SDL  
  int y_ground, x_margin;
  gflevel *level;
  gfscreen *screen;
  gfsprite *player1, *player2;
} gfgameloop;

gfgameloop *gfgameloop_new(void);
void gfgameloop_init(gfgameloop *l, gfscreen *scr);
void gfgameloop_finish(gfgameloop *l);
void gfgameloop_destroy(gfgameloop *l);
int gfgameloop_run(gfgameloop *l);
int gfgameloop_loadlevel(gfgameloop *l, char *path, char *level_filename);
int gfgameloop_freelevel(gfgameloop *l);
int gfgameloop_setplayer1(gfgameloop *l, gfsprite *p1);
int gfgameloop_setplayer2(gfgameloop *l, gfsprite *p2);

#endif //__GF_GAMELOOP_H__
