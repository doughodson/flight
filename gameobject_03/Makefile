
#
include ../makedefs

PGM = gameobject

OBJS = \
	main.o \
	Game.o \
	sdl_utils.o \
	gameobjects/Chopper.o \
	gameobjects/Tank.o \
	gameobjects/Pacman.o

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o gameobjects/*.o
	-rm -f $(PGM)
