#include <stdio.h>
#include "mpi.h"
<<<<<<< HEAD

=======
#include "gettime.h"
>>>>>>> 27834fe43f89e3d7a7f54c68791749ea298f06d9
static long nSteps = 1000000000;
static double PI25DT = 3.141592653589793238462643;

int main(int argc, char** argv){
    int n, myRank, nProcs, i;
    double mypi, pi, h, sum, x;
    double tWStart, tWElapsed;
<<<<<<< HEAD

=======
    double tStart, tElapsed;

    tStart = getTime();
>>>>>>> 27834fe43f89e3d7a7f54c68791749ea298f06d9
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD,&nProcs);
    MPI_Comm_rank(MPI_COMM_WORLD,&myRank);

    printf("Process rank: %d\n", myRank);
  
	h   = 1.0 / (double) nSteps;
	sum = 0.0;

    tWStart = MPI_Wtime();

	for (i = myRank ; i < nSteps; i += nProcs) {
	    x = h * ((double)i - 0.5);
	    sum += 4.0 / (1.0 + x*x);
	}
	mypi = h * sum;
    
	MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0,
		   MPI_COMM_WORLD);
<<<<<<< HEAD
    
=======
       
>>>>>>> 27834fe43f89e3d7a7f54c68791749ea298f06d9
    tWElapsed = MPI_Wtime() - tWStart;
	if (myRank == 0){
	    printf("pi is approximately %.16f, Error is %.16f\n",
		        pi, pi - PI25DT);
        printf("Computed in %.4g seconds\n", tWElapsed);
<<<<<<< HEAD
    }
    MPI_Finalize();
=======
      
    }
    MPI_Finalize();
    tElapsed = getTime() - tStart;
    
    printf("Duration recorded by gettime function is %.4g seconds\n",tElapsed);
>>>>>>> 27834fe43f89e3d7a7f54c68791749ea298f06d9
    return 0;
}
