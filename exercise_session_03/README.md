EX1: there are two execution times, one is 0.0499 sec and the other is 0.05847 sec recorded by gettime function.
Gettime function records the time of whole parallelization process including i.e. doing the partial sum and reduction, 
while the other time is gotten from the the final step of reduction, do not contain mpi finalize step.
EX2: with -O0 flag, the result is 10022429073.341873, computed in 6.718 sec; 
with -O1 flag, same calculation result but in 2.331 sec;
with -O2 flag, result is slightly different: 10022429072.162807, in 2.078 sec;
with -O3 flag, same result as above, but in 1.659 sec.
can opimize further by adding -ffast-math and -mavx2 flags.
