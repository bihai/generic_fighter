#ifndef __gfaction_h__
#define __gfaction_h__

typedef struct _gfaction {
  int index_next_action_if_jump;
  int index_next_action_if_on_ground;
  int input_level;
  int number_of_frames;
  int *frames;   //Frame Vector
} gfaction;



gfaction *gfaction_new(void);
void gfaction_init(gfaction *g);
void gfaction_finish(gfaction *g);
void gfaction_destroy(gfaction *g);


#endif //__gfaction_h__
