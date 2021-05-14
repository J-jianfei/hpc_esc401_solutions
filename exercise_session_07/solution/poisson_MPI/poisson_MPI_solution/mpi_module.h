#ifndef MPI_MODULE
#define MPI_MODULE

#include <mpi.h>
// #include "init.h"

int start_MPI(int* my_rank, int* size);
int close_MPI();
int mpi_get_domain(int nx, int ny, int my_rank, int size, params *param);
void halo_comm(params p, int my_rank, int size, double** u, 
              double* fromLeft, double* fromRight, double* fromTop, double* fromBottom, 
              MPI_Request* requests);
int ALLREDUCE(double* loc_diff, double* loc_sumdiff, MPI_Comm comm);
int BARRIER(MPI_Comm comm);

#endif