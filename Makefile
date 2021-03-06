cpi_omp: cpi_omp.c
	cc -O3 -o cpi_omp -fopenmp cpi_omp.c 

cpi_mpi: cpi_mpi.c
	cc -O3 -o cpi_mpi cpi_mpi.c 
cpi_c: cpi.c
	 cc -O3 -o cpi_c cpi.c
all: cpi_omp cpi_mpi cpi_c

clean:
	rm -f cpi_omp cpi_mpi cpi_c

