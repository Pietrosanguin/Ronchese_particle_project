#include <iostream>
#include<fstream>
#include "EventParticle.h"


using namespace std;



Event* read(ifstream& file)
{

    //creo e riempio il puntatore alla struttura evento 
    Event* ev = new Event;
  
    int c;
    if (!(file >> c)) return nullptr;


        file >> ev->id >> ev->x >> ev->y >> ev->z >> ev->n_particelle;

        ev->corpuscolo = new Particle * [ev->n_particelle];

        for (int i = 0; i < ev->n_particelle; ++i) {

            Particle* p = new Particle;

            file >> p->q >> p->px >> p->py >> p->pz;

            ev->corpuscolo[i] = p;

        }

        return ev;

    }









