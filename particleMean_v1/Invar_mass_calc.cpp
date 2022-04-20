#include<cmath>

// compute invariant mass from momentum x,y,z components and energy

double Invar_mass_calc(double px, double py, double pz, double energy) {

    //Considero c=1
    double  invar_mass = sqrt(pow(energy, 2) - (pow(px, 2) + pow(py, 2) + pow(pz, 2)));
    return invar_mass;
}