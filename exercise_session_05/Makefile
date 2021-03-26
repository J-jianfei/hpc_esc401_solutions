CC=gcc
CFLAGS=-g -O3 -ffast-math -mavx2

forces.o: forces.cpp forces.h

initial_conditions.o: initial_conditions.cpp initial_conditions.h

nbody.o: nbody_copy.cpp forces.h initial_conditions.h

nbody_sprt: nbody.o forces.o initial_conditions.o

all: forces.o initial_conditions.o nbody.o nbody_sprt

clean: 
	rm -f forces.o initial_conditions.o nbody.o nbody_sprt
