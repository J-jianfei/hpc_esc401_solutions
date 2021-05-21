Exercise 1
the first iteration takes 0.1511 seconds
the rest iterations take around 0.014 seconds
because the time elapsed for the first iteration includes starting time that set up parallel environment, it takes longer than real computation time.
Exercise 2
some iterations give pi = 0, but I don't know why,and take around 0.01 seconds for computing. I guess during those iterations calculation did not actually work.
some gives precise value and computed in 0.086 seconds.

Exercise 3 
I modified the cpi_cuda.cu code directly. just change the part
#define Num_BLOCK (2*n) 
#define Num_Threads (2*n) 
varying n to get different threads per block and blocks

use this command:
salloc --account=uzg2 --partition=debug --constraint=gpu --ntasks=12 --time=00:05:00 
to get a node for running job 
compile with
nvcc --gpu-architecture=sm_60 -o cpi_cuda cpi_cuda.cu gettime.c

and srun cpi_cuda

Here is what I get: 

at 112(2*56) BLOCKS
NUM_THREAD = 16 32 48 64 80 96 112 128 144 160; 
time = 0.08; 0.04; 0.0296; 0.022; 0.018; 0.015; 0.013; 0.011; 0.010; 0.009;

at 16(2*8) threads per Block 
NUM_BLOCK = 60 120 180 240 300 360 420 600
time = 0.159; 0.0816; 0.0552; 0.042; 0.0034; 0.029; 0.025; 0.018;
