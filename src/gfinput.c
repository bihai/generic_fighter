#include "gfinput.h"
#include <stdlib.h>


gfinput *gfinput_new(void) { 
	return (gfinput *) malloc(sizeof(gfinput));
}
void gfinput_init(gfinput *g) {

}

void gfinput_finish(gfinput *g){

}

void gfinput_destroy(gfinput *g){
	free(g); 
}

