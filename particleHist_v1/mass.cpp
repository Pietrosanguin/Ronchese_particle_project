#include<iostream>
#include <cmath>
#include "Event.h"
#include "Constants.h"
#include "Utilities.h"


double mass(const Event& ev) {

    // positive / negative track counters
    int neg_part = 0;
    int pos_part = 0;

    // variables for momentum sums
    float sum_px = 0;
    float sum_py = 0;
    float sum_pz = 0;

    // variables for energy sums, for K0 and Lambda0
    double sum_E_K0 = 0;
    double sum_E_L0 = 0;

    // variables for invariant mass sums, for K0 and Lambda0
    double inv_K0;
    double inv_L0;

    //puntatore a particle
    Event::pointpart pp;


    // I increase the correct counter and set the correct mass with the charge sign 

    for (int i = 0; i < ev.nParticles(); ++i) {

        //prendo il puntatore a particle
        pp = ev.getParticle(i);

        //aggiorno somme momento
        sum_px += pp->px;
        sum_py += pp->py;
        sum_pz += pp->pz;

        //aggiorno somme energie per K0
        sum_E_K0 += Utilities::Energy_calc(pp->px, pp->py, pp->pz, Constants::massPion);

        //diversi casi per L0, aggiorno le energie
        if (pp->q > 0) {

            sum_E_L0 += Utilities::Energy_calc(pp->px, pp->py, pp->pz, Constants::massProton);

            pos_part++;

        }

        else {

            sum_E_L0 += Utilities::Energy_calc(pp->px, pp->py, pp->pz, Constants::massPion);

            neg_part++;
        }

    }



    //Verifico se una è positiva e una è negativa altrimenti ritonìrno valore negativo

    if (pos_part != 1 || neg_part != 1)  return -1;

    else
    {
        inv_K0 = Utilities::Invar_mass_calc(sum_px, sum_py, sum_pz, sum_E_K0);
        inv_L0 = Utilities::Invar_mass_calc(sum_px, sum_py, sum_pz, sum_E_L0);
    }

    //confronto le due masse invarianti e restituisco quella più vicina al valore noto
    double differenceK0 = fabs(Constants::massK0 - inv_K0);
    double differenceL0 = fabs(Constants::massLambda0 - inv_L0);


    if (differenceK0 > differenceL0) return inv_L0;
    else
        return inv_K0;


}







