
#
include ../makedefs

PGM = adi

OBJS = \
	main.o \
	Adi.o \
	sdl_utils.o

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o
	-rm -f $(PGM)
