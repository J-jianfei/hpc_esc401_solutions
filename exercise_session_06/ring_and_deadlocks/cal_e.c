#include <stdio.h>
#include "mpi.h"

static long N = 100000;

int main(int argc, char** argv){
        int n, myRank, nProcs, i;
     double my_e, e, fac; 

MPI_Init(&argc, &argv);
MPI_Comm_size(MPI_COMM_WORLD, &nProcs);
MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

fac = 1.0;

for (i=myRank; i<N; i += nProcs){  
for ( int j = 1;j<=i;j++){
fac *= j;}
my_e += 1.0/fac;}

MPI_Reduce(&my_e, &e, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

if (myRank == 0) {

printf("e is approximately %.16f,\n", e);}

MPI_Finalize();
return 0;}
