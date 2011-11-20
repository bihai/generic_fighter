
#include "gfsprite.h"

gfsprite *gfsprite_new(void) {
  return  (gfsprite *) malloc(sizeof(gfsprite));
}

void gfsprite_init(gfsprite *sp) {
  sp->current_action = sp->current_frame = 0;
  sp->x = sp->y = 0;
  sp->current_side = SPRITE_SIDELEFT;
  sp->energy = 100;
}

void gfsprite_finish(gfsprite *sp) {

}

void gfsprite_destroy(gfsprite *sp) {
  free(sp);
}

int  gfsprite_load(gfsprite *sp, char *sprdir, char *sprfile) {
  FILE *f;
  char spr_filename[FILE_BUFFER_SIZE];
  char buffer[FILE_BUFFER_SIZE];
  char image_filename[FILE_BUFFER_SIZE], image_filename2[FILE_BUFFER_SIZE],
    sound_filename[FILE_BUFFER_SIZE];
  int i, j;
  int idsound, idimage;
  int numgfrects, numframes, numactions, numinputsets, nummagics, numinputs;
  int numimages, numsounds;
  SDL_Surface **images;
  SDL_Surface **images2;
  Mix_Chunk   **sounds;
  gfrect *rects;
  gfframe *frames;
  gfaction *actions;
  gfinputset *inputsets;
  gfinput *inputs;  

  //open the sprfile located on sprdir
  strcpy(spr_filename, sprdir);
  strcat(spr_filename, "/");
  strcat(spr_filename, sprfile);
  f = fopen(spr_filename, "r"); //Open the file
  if (!f) {
    fprintf(stderr, "Couldn't open file '%s'\n", buffer);
    return 0;
  }
  //Read the header from the file
  for (i=0; (i<10) && (!feof(f)); i++)    //Skip the ten first lines
    fgets(buffer, FILE_BUFFER_SIZE-1, f);
  
  //Read the content of the file
  fgets(buffer, FILE_BUFFER_SIZE-1, f);
  sscanf(buffer, "images=%d", &numimages);
  if (feof(f)) return 0;
  fgets(buffer, FILE_BUFFER_SIZE-1, f);
  sscanf(buffer, "sounds=%d", &numsounds);
  if (feof(f)) return 0;
  fgets(buffer, FILE_BUFFER_SIZE-1, f);
  sscanf(buffer, "gfrects=%d", &numgfrects);
  if (feof(f)) return 0;
  fgets(buffer, FILE_BUFFER_SIZE-1, f);
  sscanf(buffer, "frames=%d", &numframes);
  if (feof(f)) return 0;
  fgets(buffer, FILE_BUFFER_SIZE-1, f);
  sscanf(buffer, "actions=%d", &numactions);
  if (feof(f)) return 0;
  fgets(buffer, FILE_BUFFER_SIZE-1, f);
  sscanf(buffer, "inputsets=%d", &numinputsets);
  if (feof(f)) return 0;
  fgets(buffer, FILE_BUFFER_SIZE-1, f);
  sscanf(buffer, "magics=%d", &nummagics);
  if (feof(f)) return 0;
  fgets(buffer, FILE_BUFFER_SIZE-1, f);
  sscanf(buffer, "inputs=%d", &numinputs);
  if (feof(f)) return 0;
  printf("Information read from sprite file \"%s\": ", spr_filename);
  printf("gfrects=%d, frames=%d, actions=%d, inputsets=%d, magics=%d, inputs=%d\n",
	 numgfrects, numframes, numactions, numinputsets, nummagics, numinputs);
  rects = (gfrect *) malloc(sizeof(gfrect)*numgfrects);
  frames = (gfframe *) malloc(sizeof(gfrect)*numframes);
  actions = (gfaction *) malloc(sizeof(gfrect)*numactions);
  inputsets = (gfinputset *) malloc(sizeof(gfrect)*numinputsets);
  inputs = (gfinput *) malloc(sizeof(gfrect)*numinputs);
  images = (SDL_Surface **) malloc(sizeof(SDL_Surface *)*numimages);
  images2 = (SDL_Surface **) malloc(sizeof(SDL_Surface *)*numimages);
  sounds = (Mix_Chunk **) malloc(sizeof(Mix_Chunk *)*numsounds);
  //Read image files
  for (i=0; i<numimages; i++) {
    fgets(buffer, FILE_BUFFER_SIZE-1, f);
    sscanf(buffer, "image=%s ;%s ", image_filename, image_filename2);
    printf("image file name readed=%s ; %s\n", image_filename, image_filename2);
    strcpy(spr_filename, sprdir);
    strcat(spr_filename, "/");
    strcat(spr_filename, image_filename);
    images[i] = IMG_Load(spr_filename);
    if (!(images[i])) {
      fprintf(stderr, "WARNING: error on loading file \"%s\"\n", spr_filename);
    }
    strcpy(spr_filename, sprdir);
    strcat(spr_filename, "/");
    strcat(spr_filename, image_filename2);
    images2[i] = IMG_Load(spr_filename);
    if (!(images2[i])) {
      fprintf(stderr, "WARNING: error on loading file \"%s\"\n", spr_filename);
    }
  }
  //Read sound files
  for (i=0; i<numsounds; i++) {
    fgets(buffer, FILE_BUFFER_SIZE-1, f);
    sscanf(buffer, "sound=%s ", sound_filename);
    printf("sound file name readed=%s\n", sound_filename);
    strcpy(spr_filename, sprdir);
    strcat(spr_filename, "/");
    strcat(spr_filename, sound_filename);
    sounds[i] = Mix_LoadWAV(spr_filename);
    if (!(sounds[i])) {
      fprintf(stderr, "WARNING: error on loading file \"%s\"\n", spr_filename);
    }
  }    
  //Read the gfrects
  for (i=0; i<numgfrects; i++) {
    fgets(buffer, FILE_BUFFER_SIZE-1, f);
    sscanf(buffer, "gfrect=%d,%d;%d,%d;%d,%d;%d,%d; flip=%d,%d;%d,%d;%d,%d;%d,%d; %d;%d;%d;%d;%d;%d", 
	   &(rects[i].rect[0].xlt), &(rects[i].rect[0].ylt),
	   &(rects[i].rect[0].xrt), &(rects[i].rect[0].yrt),
	   &(rects[i].rect[0].xlb), &(rects[i].rect[0].ylb),
	   &(rects[i].rect[0].xrb), &(rects[i].rect[0].yrb),
	   &(rects[i].rect[1].xlt), &(rects[i].rect[1].ylt),
	   &(rects[i].rect[1].xrt), &(rects[i].rect[1].yrt),
	   &(rects[i].rect[1].xlb), &(rects[i].rect[1].ylb),
	   &(rects[i].rect[1].xrb), &(rects[i].rect[1].yrb),
	   &(rects[i].power_level), 
	   &(rects[i].index_action_win), &(rects[i].index_action_lose),
	   &(rects[i].index_action_losemuch), &(rects[i].index_action_die),
	   &(rects[i].defense)
	   );
    printf("gfrect readed=%d,%d;%d,%d;%d,%d; flip=%d,%d;%d,%d;%d,%d;%d,%d %d,%d;%d;%d;%d;%d;%d;%d\n", 
	   (rects[i].rect[0].xlt), (rects[i].rect[0].ylt),
	   (rects[i].rect[0].xrt), (rects[i].rect[0].yrt),
	   (rects[i].rect[0].xlb), (rects[i].rect[0].ylb),
	   (rects[i].rect[0].xrb), (rects[i].rect[0].yrb),
	   (rects[i].rect[1].xlt), (rects[i].rect[1].ylt),
	   (rects[i].rect[1].xrt), (rects[i].rect[1].yrt),
	   (rects[i].rect[1].xlb), (rects[i].rect[1].ylb),
	   (rects[i].rect[1].xrb), (rects[i].rect[1].yrb),
	   (rects[i].power_level),
	   (rects[i].index_action_win), (rects[i].index_action_lose),
	   (rects[i].index_action_losemuch), (rects[i].index_action_die),
	   (rects[i].defense)
	   );

    if (feof(f)) return 0;
  }
  //Read the frames
  for (i=0; i<numframes; i++) {
    fgets(buffer, FILE_BUFFER_SIZE-1, f);
    frames[i].num_rects = -4 +
    	sscanf(buffer, "frame=%d,%d;%d ;%d ;%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",
	   &(frames[i].motion_x), &(frames[i].motion_y),
	   &idimage, &idsound,
	   &(frames[i].rects[0]), &(frames[i].rects[1]),
	   &(frames[i].rects[2]), &(frames[i].rects[3]),
	   &(frames[i].rects[4]), &(frames[i].rects[5]),
	   &(frames[i].rects[6]), &(frames[i].rects[7]),
	   &(frames[i].rects[8]), &(frames[i].rects[9])
	   );
    frames[i].image[0] =  images[idimage];
    frames[i].image[1] = images2[idimage];
    if (idsound>=0)
      frames[i].sound = sounds[idsound];
    else
      frames[i].sound = NULL;
    printf("frame readed=mx=%d,my=%d; img1=%p;img2=%p;snd=%p; rects[0-9]=%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",
	   (frames[i].motion_x), (frames[i].motion_y),
	   images[idimage], images2[idimage], frames[i].sound,
	   (frames[i].rects[0]), (frames[i].rects[1]),
	   (frames[i].rects[2]), (frames[i].rects[3]),
	   (frames[i].rects[4]), (frames[i].rects[5]),
	   (frames[i].rects[6]), (frames[i].rects[7]),
	   (frames[i].rects[8]), (frames[i].rects[9])
	   );
    if (feof(f)) return 0;
  }
  //Read the actions
  for (i=0; i<numactions; i++) {
    fgets(buffer, FILE_BUFFER_SIZE-1, f);
    sscanf(buffer, "action=%d;%d;%d;%d",
	   &(actions[i].index_next_action_if_jump),
	   &(actions[i].index_next_action_if_on_ground),
	   &(actions[i].input_level),
	   &(actions[i].number_of_frames));
    printf("actions readed=%d;%d;%d;%d\n",
	   (actions[i].index_next_action_if_jump),
	   (actions[i].index_next_action_if_on_ground),
	   (actions[i].input_level),
	   (actions[i].number_of_frames));
    //Read the NF frames...
    //Alloc memory to NF frame indexes...
    actions[i].frames = (int *) malloc(sizeof(int)*(actions[i].number_of_frames));
    printf("Frames within this action: ");
    for (j=0; j<(actions[i].number_of_frames); j++) {
      fscanf(f, "%d,",
	     &(actions[i].frames[j]));
      printf("%d,",
	     (actions[i].frames[j]));
    }
    fgets(buffer, FILE_BUFFER_SIZE-1, f);
    //    fscanf(f, "\n");
    printf("\n");
    if (feof(f)) return 0;
  }

  //Read the inputsets
  for (i=0; i<numinputsets; i++) {
    fscanf(f, "inputset=%d", &(inputsets[i].keys[0]));
    printf("InputSets readed are: %d",(inputsets[i].keys[0]));
    for (j=1; j<NUM_KEYS; j++) {
      fscanf(f, ",%d", &(inputsets[i].keys[j]));
      printf(",%d",(inputsets[i].keys[j]));
    }
    fgets(buffer, FILE_BUFFER_SIZE-1, f);
    //    fscanf(f, "\n");
    printf("\n");
    if (feof(f)) return 0;
  }
  //Read the inputs
  for (i=0; i<numinputs; i++) {
    fgets(buffer, FILE_BUFFER_SIZE-1, f);
    sscanf(buffer, "input=%d;%d;%d;%d",
	   &(inputs[i].input_set), &(inputs[i].input_level),
	   &(inputs[i].action), &(inputs[i].magic)
	     );
    printf("inputs readed are=%d;%d;%d;%d\n",
	   (inputs[i].input_set), (inputs[i].input_level),
	   (inputs[i].action), (inputs[i].magic)
	   );
    if (feof(f)) return 0;
  }
  fclose(f);
  sp->num_gfrects   = numgfrects;
  sp->num_frames    = numframes;
  sp->num_actions   = numactions;
  sp->num_inputsets = numinputsets;
  sp->num_magics    = nummagics;
  sp->num_inputs    = numinputs;
  sp->rects         = rects;
  sp->frames        = frames;
  sp->actions       = actions;
  sp->inputsets     = inputsets;
  sp->inputs        = inputs;

  return 1;
}

void gfsprite_unload(gfsprite *sp) {
  free(sp->rects);
  free(sp->frames);
  free(sp->actions);
  free(sp->inputsets);
  free(sp->inputs);
}

int  gfsprite_process_inputset(gfsprite *sp, gfsprite *enemy, gfinputset *is,
			       int offsetx, int offsety) {
  //This function process inputSets received by the sprite
  static int i;
  sp->current_side = (sp->x > enemy->x) ? SPRITE_SIDERIGHT : SPRITE_SIDELEFT;
  for (i=0; i<sp->num_inputs; i++) {
    if (is->keys[0] == (sp->inputsets[sp->inputs[i].input_set].keys[0]))
      if ((sp->inputs[i].input_level)>
	  (sp->actions[sp->current_action].input_level)) {
	if ((sp->current_frame)>=sp->actions[sp->current_action].number_of_frames) {
	  sp->current_frame = 0;
	  sp->current_action = (sp->y <(offsety))?
	    sp->actions[sp->current_action].index_next_action_if_jump  :
	    sp->actions[sp->current_action].index_next_action_if_on_ground  ;
	}
	if (sp->current_action != sp->inputs[i].action) {
	  sp->current_action = sp->inputs[i].action;
	  sp->current_frame  = 0;
	  return 1;
	}
      }
  }
  return 0;
}

int gfsprite_draw(gfsprite *sp, gfscreen *sc, int screen_width, int offsetx, int offsety, int *offsetxdone) {
  static SDL_Rect r1;
  static SDL_Surface *image;

  if ((sp->current_frame)>=sp->actions[sp->current_action].number_of_frames) {
    sp->current_frame = 0;
	  sp->current_action = (sp->y <(offsety))?
	    sp->actions[sp->current_action].index_next_action_if_jump  :
	    sp->actions[sp->current_action].index_next_action_if_on_ground  ;
  }

  image = sp->frames[(sp->actions[sp->current_action].frames[sp->current_frame])
  ].image[sp->current_side];
  sp->x += sp->frames[(sp->actions[sp->current_action].frames[sp->current_frame])
  ].motion_x;
  if (sp->x < offsetx-(image->w/2)) {
    *offsetxdone += (sp->x) - (offsetx-(image->w/2));
    //    sp->x = offsetx;
  } else if (sp->x > screen_width - offsetx - (image->w/2)) {
    *offsetxdone += sp->x - (screen_width - offsetx - (image->w/2));
    //    sp->x = screen_width - offsetx - (image->w);
  }

  sp->y -= sp->frames[(sp->actions[sp->current_action].frames[sp->current_frame])
  ].motion_y;
  /*  printf("%d %d %d\n",
      sp->current_action,
      sp->current_frame
      ,sp->frames[(sp->actions[sp->current_action].frames[sp->current_frame])].motion_y);
  */
  r1.x = offsetx + sp->x - (image->w)/2;
  r1.y = offsety - sp->y - image->h;
  r1.w = image->w;
  r1.h = image->h;
  SDL_BlitSurface(image, NULL, sc->sdl_surface, &r1);
  
  sp->current_frame ++ ;
  return 1;
}

int gfsprite_be_on_screen(gfsprite *sp, gfscreen *sc, int offsetx, int offsety) {
  static SDL_Surface *image;

  image = sp->frames[(sp->actions[sp->current_action].frames[sp->current_frame-1])
  ].image[sp->current_side];
  
  if (sp->x>(sc->sdl_surface->w-(offsetx)-(image->w/2)) )
    sp->x =(sc->sdl_surface->w-(offsetx)-(image->w/2));
  else if (sp->x < (offsetx)-(image->w/2)) 
    sp->x = (offsetx)-(image->w/2);
  
  return 1;
}

int gfsprite_process_colision(gfsprite *sp, gfsprite *enemy) {
  int i, j;
  //In case of multiple rects colliding, consider only the rect with greater powerlevel
  int rect_to_consider_i=-1, rect_to_consider_j=-1;
  int max_power_level=-1;
  //My rect and rect from enemy
  gfrect *gfr1, *gfr2;
  int power_level_dif=0;
  for (i=0; i< (sp->frames[sp->current_frame]).num_rects ; i++) {
  	for (j=0; j<enemy->frames[enemy->current_frame].num_rects; j++) {
      gfr1=&(sp->rects   [ (sp->frames[   sp->current_frame   ].rects[i])]);
      gfr2=&(enemy->rects[ (enemy->frames[enemy->current_frame].rects[j])]);
   	if (!(gfr2->defense)) {
      	if (gfrect_collide(gfr1, gfr2 )) {
            if (gfr1->power_level>max_power_level) { //Consider the colided rect with maximum power level
               max_power_level=gfr1->power_level;
               rect_to_consider_i=i;
               rect_to_consider_j=j;
            }
	      }
      }
  	}
  }
  if ((rect_to_consider_i<0) || (rect_to_consider_j<0)) return 0;
  //Act on rect selected
  gfr1=&(sp->rects   [ (sp->frames[   sp->current_frame   ].rects[rect_to_consider_i])]);
  gfr2=&(enemy->rects[ (enemy->frames[enemy->current_frame].rects[rect_to_consider_j])]);
  power_level_dif = gfr1->power_level - gfr2->power_level;
  sp->energy += power_level_dif;
  if (sp->energy<=0) { //Action die
  		sp->current_action = gfr1->index_action_die;
		sp->current_frame  = 0;
  } else if (enemy->energy<=0) { //Action win
  		sp->current_action = gfr1->index_action_win;
		sp->current_frame  = 0;
  } else if (power_level_dif<-DIFERENCE_TO_LOSE_MUCH) { //Lose much action
  		sp->current_action = gfr1->index_action_losemuch;
	  	sp->current_frame  = 0;
  } else if (power_level_dif<0) { //Lose action
  		sp->current_action = gfr1->index_action_lose;
  		sp->current_frame  = 0;
  }
  return 1;
}














