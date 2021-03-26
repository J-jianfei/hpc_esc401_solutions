#include <vector>
#include <random>
#include <stdio.h>
#include "forces.h"
#include "initial_conditions.h"

struct particle {
        float x, y, z; // position 
        float vx, vy, vz; // velocity 
        float ax, ay, az; // acceleration
};

typedef std::vector<particle> particles;

int main(int argc, char *argv[]) {
	int N=20'000; // number of particles
	particles plist; // vector of particles
	ic(plist,N); // initialize starting position/velocity 
	forces(plist); // calculate the forces
	return 0;
}
