CFLAGS=-O3 -ffast-math -mavx2 -fopenmp 
CC=CC

all: init.o io.o jacobi.o gettime.o main
init.o: init.cpp init.h
io.o: io.cpp io.h
jacobi.o: jacobi.cpp jacobi.h
gettime.o: gettime.cpp gettime.h
main: init.o io.o jacobi.o gettime.o
clean: 
	rm -f main init.o io.o jacobi.o gettime.o
