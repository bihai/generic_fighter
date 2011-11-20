#ifndef __gfrect_h__
#define __gfrect_h__

#include "rect.h"

#define DIFERENCE_TO_LOSE_MUCH  50

typedef struct _gfrect {
  rect rect[2];//left and right
  int power_level;
  int index_action_win;
  int index_action_lose;
  int index_action_losemuch;
  int index_action_die;
  int defense; //bool
} gfrect;



gfrect *gfrect_new(void);
void gfrect_init(gfrect *g);
void gfrect_finish(gfrect *g);
void gfrect_destroy(gfrect *g);
int  gfrect_collide(gfrect *g1, gfrect *g2);


#endif //__gfrect_h__
