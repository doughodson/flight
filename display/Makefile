
#
include ../makedefs

PGM = display

OBJS = \
	main.o \
	Display.o \
	Instrument.o \
	sdl_utils.o \
	instruments/Adi.o \
	instruments/Alt.o \
	instruments/Asi.o \
	instruments/Hsi.o \
	instruments/Nav.o \
	instruments/Tc.o \
	instruments/Vsi.o

all: $(PGM)

$(PGM): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

clean:
	-rm -f *.o instruments/*.o
	-rm -f $(PGM)

