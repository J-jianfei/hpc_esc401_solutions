EX1 "grep" practice
grep ..............00 binary.txt
grep 1..............1 binary.txt
grep 110 binary.txt
grep .*1.*1.*1.* binary.txt
grep .*111.*111.*111.* binary.txt

EX2
compling by using command "CC -g -O3 -ffast-math -o nbody nbody.cpp", 
one executable nbody is produced, while another file nbody+orig is also produced

From performance file, line 22 and line 23 take much longer time than others, 65% and 14% respectively.
Since those two lines correspond to distance calculation and acceleration calculation, they contain square root and division operation which take longer time than addition and multiplication.

I don't know how to separate it into modules. I hardly use C++ before.

Ex3
I guess adding omp parallel directive to both loops is the most efficient because the calculations in each loop are all independent from each other.  

A linear increase is expected. But by doing fitting, a nearly quadratic increase is seen.
