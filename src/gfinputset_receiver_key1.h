#ifndef __gfinputset_receiver_key1_h__
#define __gfinputset_receiver_key1_h__

#include "gfinputset.h"
#include <SDL.h>

typedef struct _gfinputset_receiver_key1 {
  gfinputset inputset;
  SDL_Event event;
} gfinputset_receiver_key1;



gfinputset_receiver_key1 *gfinputset_receiver_key1_new(void);
void gfinputset_receiver_key1_init(gfinputset_receiver_key1 *g);
void gfinputset_receiver_key1_finish(gfinputset_receiver_key1 *g);
void gfinputset_receiver_key1_destroy(gfinputset_receiver_key1 *g);
void gfinputset_receiver_key1_receive(gfinputset_receiver_key1 *g, gfinputset *is, gfinputset *pass);

#endif //__gfinputset_receiver_key1_h__
