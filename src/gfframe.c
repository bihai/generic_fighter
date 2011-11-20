#include "gfframe.h"
#include <stdlib.h>


gfframe *gfframe_new(void) {
  return (gfframe *) malloc(sizeof(gfframe));
}
void gfframe_init(gfframe *g) {
  g->motion_x =0;
  g->motion_y =0;
  num_rects=0;
}

void gfframe_finish(gfframe *g){
  
}

void gfframe_destroy(gfframe *g){
  free(g); 
}

