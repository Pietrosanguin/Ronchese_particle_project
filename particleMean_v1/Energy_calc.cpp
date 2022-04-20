#include<cmath>

// compute energy from momentum x,y,z components and invariant mass

double Energy_calc(double px, double py, double pz, double invar_mass) {

    //Considero c=1
    double energy = sqrt(pow(px, 2) + pow(py, 2) + pow(pz, 2) + pow(invar_mass, 2));
    return energy;
}