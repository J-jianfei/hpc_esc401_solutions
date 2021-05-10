#include "jacobi.h"

/**
 * @brief      Computes norm of the difference between two matrices
 *
 * @param[in]  p     Parameters
 * @param      mat1  The matrix 1
 * @param      mat2  The matrix 2
 *
 * @return     Returns \sqrt{\sum(mat1_{ij} - mat2_{ij})^2/(nx*ny)}
 */
double norm_diff(params p, double** mat1, double** mat2){
    double val,sum;
    sum = 0.0;
    for(int i=0;i<p.nx;i++){
    for(int j=0;j<p.ny;j++){
    sum += (mat1[i][j] - mat2[i][j])*(mat1[i][j]-mat2[i][j]);}}
    val = sqrt(sum/(p.nx*p.ny));
    return val;
}

/**
 * @brief      Compute a Jacobi iteration to solve Poisson equation. This function updates
 *             u_new and u_old in-place.
 *
 * @param[in]  p      Parameters
 * @param      u_new  The new solution
 * @param      u_old  The old solution
 * @param      f      The source term
 */
void jacobi_step(params p, double** u_new, double** u_old, double** f){
    double dx = 1.0/p.nx;
    double dy = 1.0/p.ny;

    for (int i=0; i<p.nx; i++){
        for (int j=0; j<p.ny; j++){
         int k = (i-1)%p.nx; int l= (i+1)%p.nx;int m = (j-1)%p.ny; int n = (j+1)%p.ny;
         u_new[i][j] =1/4 *(u_old[k][j] + u_old[l][j]+ u_old[i][m] + u_old[i][n] - dx*dy*f[i][j]);
        }
    }
   
}
