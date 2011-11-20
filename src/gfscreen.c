#include <stdlib.h>
#include "gfscreen.h"


gfscreen *gfscreen_new(void) {
  return (gfscreen *) malloc(sizeof(gfscreen));
}

void gfscreen_init( gfscreen *s) {
  SDL_Init(SDL_INIT_EVERYTHING);
  s->sdl_surface = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 
				    SCREEN_BPP, SDL_SRCALPHA | SDL_ANYFORMAT);// | SDL_FULLSCREEN);  
  if (!(s->sdl_surface)) {
    fprintf(stderr, "Error initializing library: %s\n", SDL_GetError());
    exit(1);
  }
}

void gfscreen_finish( gfscreen *s) {
  SDL_FreeSurface(s->sdl_surface);
  SDL_Quit();
}

void gfscreen_destroy( gfscreen *s) {
  free(s);
}

void gfscreen_draw_line(gfscreen *s, int x1, int y1, int x2, int y2, Uint32 color) {
  Uint8 *screen;
  int x_unit, y_unit;
  int offset;
  int ydiff, xdiff;
  int length, i, error_term;
  int bpp, pitch;

  bpp = s->sdl_surface->format->BytesPerPixel;
  pitch = s->sdl_surface->pitch;
  if (x1<0) x1=0; if (x1>SCREEN_WIDTH) x1 = SCREEN_WIDTH;
  if (x2<0) x2=0; if (x2>SCREEN_WIDTH) x2 = SCREEN_WIDTH;
  if (y1<0) y1=0; if (y1>SCREEN_HEIGHT) y1 = SCREEN_HEIGHT;
  if (y2<0) y2=0; if (y2>SCREEN_HEIGHT) y2 = SCREEN_HEIGHT;

  screen = (Uint8 *)(s->sdl_surface->pixels );
  //  for (i=0; i<SCREEN_WIDTH; i++)
  //    *(screen+ (y1*pitch) +i) = (Uint8)255;
  offset=y1*pitch+x1*bpp;
  ydiff=y2-y1;
  if (ydiff<0) {
    ydiff=-ydiff;
    y_unit=-SCREEN_WIDTH;
  } else y_unit=SCREEN_WIDTH;
  xdiff=x2-x1;
  if (xdiff<0) {
    xdiff=-xdiff;
    x_unit=-1;
  } else x_unit=1;
  
  error_term=0;
  if (xdiff>ydiff) {
    length = xdiff+1;
    for (i=0; i<length; i++) {
      switch (s->sdl_surface->format->BytesPerPixel) {
      case 1:
	screen[offset]=color;
        break;
      case 2:
	*((Uint16 *)(screen+offset))=color;
        break;
      case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
	  screen[offset]=   (color >> 16) & 0xff;
	  screen[offset+1]= (color >> 8 ) & 0xff;
	  screen[offset+2]= (color      ) & 0xff;
        } else {
	  screen[offset]=   (color      ) & 0xff;
	  screen[offset+1]= (color >> 8 ) & 0xff;
	  screen[offset+2]= (color >> 16) & 0xff;
        }
        break;
      case 4:
	*((Uint32 *)(screen+offset))=color;
	break;
      }      
      offset+=x_unit*bpp;
      error_term+=ydiff*bpp;
      if (error_term>xdiff*bpp) {
	error_term-=xdiff*bpp;
	offset+=y_unit*bpp;
      }
    }
  } else {
    length = ydiff+1;
    for (i=0; i<length; i++) {
      switch (s->sdl_surface->format->BytesPerPixel) {
      case 1:
	screen[offset]=color;
        break;
      case 2:
	*((Uint16 *)(screen+offset))=color;
        break;
      case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
	  screen[offset]=   (color >> 16) & 0xff;
	  screen[offset+1]= (color >> 8 ) & 0xff;
	  screen[offset+2]= (color      ) & 0xff;
        } else {
	  screen[offset]=   (color      ) & 0xff;
	  screen[offset+1]= (color >> 8 ) & 0xff;
	  screen[offset+2]= (color >> 16) & 0xff;
        }
        break;
      case 4:
	*((Uint32 *)(screen+offset))=color;
	break;
      }      
      offset+=y_unit*bpp;
      error_term+=xdiff*bpp;
      if (error_term>0) {
	error_term-=ydiff*bpp;
	offset+=x_unit*bpp;
      }
    }
  }
}
