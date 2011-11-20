#ifndef __gfinputset_h__
#define __gfinputset_h__

#include "gfcommon.h"
#include <SDL.h>

typedef struct _gfinputset {
  Uint32 keys[NUM_KEYS];
} gfinputset;



gfinputset *gfinputset_new(void);
void gfinputset_init(gfinputset *g);
void gfinputset_finish(gfinputset *g);
void gfinputset_destroy(gfinputset *g);


#endif //__gfinputset_h__
