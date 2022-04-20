#include<iostream>
#include<cmath>
#include "EventParticle.h"
//firma per funzione che calcola la massa 
double mass (const Event& ev);

bool add(const Event& ev, float min, float max, double& sum_mass, double& sum_squares) {

    double massa = mass(ev);
    if (massa<max && massa>min)
    {
        sum_mass += massa;
        sum_squares += pow(massa, 2);
        return true;
    }
    else return false;
}

