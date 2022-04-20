#include"Utilities.h"
#include <cmath>

Utilities::Utilities() {
}

Utilities::~Utilities() {
}


double Utilities::Energy_calc(double px, double py, double pz, double invar_mass) {

    //Considero c=1
    double energy = sqrt(pow(px, 2) + pow(py, 2) + pow(pz, 2) + pow(invar_mass, 2));
    return energy;
}


double Utilities::Invar_mass_calc(double px, double py, double pz, double energy) {

    //Considero c=1
    double  invar_mass = sqrt(pow(energy, 2) - (pow(px, 2) + pow(py, 2) + pow(pz, 2)));
    return invar_mass;
}
