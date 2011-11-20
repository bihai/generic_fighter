#ifndef __gfinput_h__
#define __gfinput_h__

typedef struct _gfinput {
  int input_set;
  int input_level;
  int action;
  int magic;
} gfinput;



gfinput *gfinput_new(void);
void gfinput_init(gfinput *g);
void gfinput_finish(gfinput *g);
void gfinput_destroy(gfinput *g);


#endif //__gfinput_h__
