#include <vector>
#include <random>
#include <stdio.h>
#include "gettime.h"
struct particle {
        float x, y, z; // position 
        float vx, vy, vz; // velocity 
        float ax, ay, az; // acceleration
};

typedef std::vector<particle> particles;

void forces(particles &plist) {
        int n = plist.size();
        for(int i=0; i<n; ++i) { // We want to calculate the force on all particles
                plist[i].ax = plist[i].ay = plist[i].az = 0; // start with zero acceleration
               #pragma omp parallel for
                for(int j=0; j<n; ++j) { // Depends on all other particles
                        if (i==j) continue; // Skip self interaction 
                        auto dx = plist[j].x - plist[i].x;
                        auto dy = plist[j].y - plist[i].y;
                        auto dz = plist[j].z - plist[i].z;
                        auto r = sqrt(dx*dx + dy*dy + dz*dz);
                        auto ir3 = 1 / (r*r*r);
                        plist[i].ax += dx * ir3;
                        plist[i].ay += dy * ir3;
                        plist[i].az += dz * ir3;
                }
        }
}

// Initial conditions
void ic(particles &plist, int n) {
        std::random_device rd; //Will be used to obtain a seed for the random number engine 
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd() 
        std::uniform_real_distribution<float> dis(0.0, 1.0);

        plist.clear(); // Remove all particles 
        plist.reserve(n); // Make room for "n" particle 
        for( auto i=0; i<n; ++i) {
                particle p { dis(gen),dis(gen),dis(gen),0,0,0,0,0,0 };
                plist.push_back(p);
        }
}

int main(int argc, char *argv[]) {
	int N[6]; // number of particles
N[0]=100;N[1]=500;N[2]=1000;N[3]=5000;N[4]=10000;N[5]=20000;N[6]=50000;
#pragma omp parallel for 
for( int i=0; i<6; ++i){
	particles plist; // vector of particles
double Tstart = getTime();
	ic(plist,N[i]); // initialize starting position/velocity 
	forces(plist); // calculate the forces
double Telapsed = getTime() - Tstart;
printf("the number of particles is %d,calculated in %f sec.\n",N[i],Telapsed);}
	return 0;
}
