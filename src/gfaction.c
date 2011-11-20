#include "gfaction.h"
#include <stdlib.h>


gfaction *gfaction_new(void) { 
	return (gfaction *) malloc(sizeof(gfaction));
}
void gfaction_init(gfaction *g) {

}

void gfaction_finish(gfaction *g){

}

void gfaction_destroy(gfaction *g){
	free(g); 
}

