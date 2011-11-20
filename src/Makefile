
CC=gcc
PROGNAME=gfighter.exe
LDFLAGS= -lSDL_image -lSDL_mixer $$(sdl-config --libs)
CFLAGS=  -Wall -O2 -g $$(sdl-config --cflags)
OBJS=main.o gfsprite.o gfinput.o gfaction.o rect.o gfrect.o \
	gfgameloop.o gfscreen.o gflevel.o gfinputset.o \
	gfinputset_receiver_key1.o  gfinputset_receiver_key2.o

all: $(OBJS)
	$(CC) $(OBJS) -o $(PROGNAME) $(LDFLAGS)

clean:
	rm -f *.o *~ #$(PROGNAME)

run:  all
	./$(PROGNAME)

brun: clean run


build: clean all



