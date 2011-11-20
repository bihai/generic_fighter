#ifndef __RECT_H__
#define __RECT_H__

#include "gfscreen.h"

typedef struct _rect {
  int xlt,ylt;   //left top
  int xlb, ylb;  //left bottom
  int xrt, yrt;  //right top
  int xrb, yrb;  //right bottom
} rect;

rect *rect_new(void);
void rect_init(rect *r);
void rect_finish(rect *r);
void rect_destroy(rect *r);
void rect_draw(rect *r, gfscreen *s);

#endif // __RECT_H__
