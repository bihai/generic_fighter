#include "rect.h"
#include "gfscreen.h"
#include <stdlib.h>

rect *rect_new(void) {
  return (rect *) malloc(sizeof(rect));
}

void rect_init(rect *r) {
  
}

void rect_finish(rect *r) {

}

void rect_destroy(rect *r) {
  free(r);
}

void rect_draw(rect *r, gfscreen *s) {
  Uint32 color;
  color = SDL_MapRGB(s->sdl_surface->format, 0x00, 0x00, 0x00);

  gfscreen_draw_line(s, r->xlt, r->ylt, r->xrt, r->yrt, color);
  gfscreen_draw_line(s, r->xlt, r->ylt, r->xlb, r->ylb, color);
  gfscreen_draw_line(s, r->xlb, r->ylb, r->xrb, r->yrb, color);
  gfscreen_draw_line(s, r->xrt, r->yrt, r->xrb, r->yrb, color);
}
