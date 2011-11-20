#include "gfinputset_receiver_key2.h"
#include <stdlib.h>


gfinputset_receiver_key2 *gfinputset_receiver_key2_new(void) { 
	return (gfinputset_receiver_key2 *) malloc(sizeof(gfinputset_receiver_key2));
}

void gfinputset_receiver_key2_init(gfinputset_receiver_key2 *g) {

}

void gfinputset_receiver_key2_finish(gfinputset_receiver_key2 *g){

}

void gfinputset_receiver_key2_destroy(gfinputset_receiver_key2 *g){
	free(g); 
	g=NULL;
}

void gfinputset_receiver_key2_receive(gfinputset_receiver_key2 *g, gfinputset *is, gfinputset *pass) {
  *is = *pass;
}
