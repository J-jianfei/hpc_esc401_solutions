CFLAGS=-O3 -ffast-math -mavx2
CC=cc

cpi_mpi : cpi_mpi.o gettime.o

cpi_mpi.o : cpi_mpi.c gettime.h

cpi : cpi.o gettime.o

cpi.o : cpi.c gettime.h

gettime.o : gettime.c gettime.h

clean: 	
	rm -f cpi cpi.o gettime.o
