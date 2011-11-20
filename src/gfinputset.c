#include "gfinputset.h"
#include <stdlib.h>


gfinputset *gfinputset_new(void) { 
	return (gfinputset *) malloc(sizeof(gfinputset));
}

void gfinputset_init(gfinputset *g) {
  int i;
  for (i=0; i<NUM_KEYS; i++)
    g->keys[i] = 0;
}

void gfinputset_finish(gfinputset *g){

}

void gfinputset_destroy(gfinputset *g){
	free(g); 
g=NULL;
}

