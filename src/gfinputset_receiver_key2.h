#ifndef __gfinputset_receiver_key2_h__
#define __gfinputset_receiver_key2_h__

#include "gfinputset.h"
#include <SDL.h>

typedef struct _gfinputset_receiver_key2 {
  gfinputset inputset;
  SDL_Event event;
} gfinputset_receiver_key2;



gfinputset_receiver_key2 *gfinputset_receiver_key2_new(void);
void gfinputset_receiver_key2_init(gfinputset_receiver_key2 *g);
void gfinputset_receiver_key2_finish(gfinputset_receiver_key2 *g);
void gfinputset_receiver_key2_destroy(gfinputset_receiver_key2 *g);
void gfinputset_receiver_key2_receive(gfinputset_receiver_key2 *g, gfinputset *is, gfinputset *pass);

#endif //__gfinputset_receiver_key2_h__
