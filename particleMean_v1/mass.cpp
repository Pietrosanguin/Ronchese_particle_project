#include<iostream>
#include <cmath>
#include "EventParticle.h"

//functions identifiers
double Invar_mass_calc(double px, double py, double pz, double energy);
double Energy_calc(double px, double py, double pz, double invar_mass);


const double massPion = 0.1395706;   // GeV/c^2
const double massProton = 0.938272;    // GeV/c^2
const double massK0 = 0.497611;    // GeV/c^2
const double massLambda0 = 1.115683;    // GeV/c^2

double mass(const Event& ev) {

    // positive / negative track counters
    int neg_part = 0;
    int pos_part = 0;

    // variables for momentum sums
    float sum_px = 0;
    float sum_py = 0;
    float sum_pz = 0;

    // variables for energy sums, for K0 and Lambda0
    float sum_E_K0=0;
    float sum_E_L0=0;

    // variables for invariant mass sums, for K0 and Lambda0
    float mass_K0;
    float mass_L0;
    double invar_mass;

    // retrieve particles in the event
    typedef const struct Particle* part;
    part p;


    // I increase the correct counter and set the correct mass with the charge sign 

    for (int i = 0; i < ev.n_particelle; ++i) {

        p = ev.corpuscolo[i];


        if (p->q > 0) {

            invar_mass = massProton;
            pos_part++;


        }

        if (p->q < 0)
        {
            neg_part++;
            invar_mass = massPion;
            

        }


        sum_px += p->px;
        sum_py += p->py;
        sum_pz += p->pz;
        sum_E_K0 += Energy_calc(p->px, p->py, p->pz, 0.1395706);
        sum_E_L0 += Energy_calc(p->px, p->py, p->pz, invar_mass);
    }

    if (pos_part != 1 || neg_part != 1)
        
        return -1;
    
    else
    {
        mass_K0 = Invar_mass_calc(sum_px, sum_py, sum_pz, sum_E_K0);
        mass_L0 = Invar_mass_calc(sum_px, sum_py, sum_pz, sum_E_L0);
    }
    if (fabs(mass_K0 - 0.497611) < fabs(mass_L0 - 1.115683))
        return mass_K0;
    else
        return mass_L0;

}
