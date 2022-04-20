#include <iostream>
#include<fstream>
#include "Event.h"


using namespace std;



Event* read(ifstream& file)
{
    int id, n_particelle;
    double x, y, z;
    int c;


    if (!(file >> c)) return nullptr;


    file >> id >> x >> y >> z >> n_particelle;

    Event* ev = new Event(id, x, y, z);

    for (int i = 0; i < n_particelle; ++i) {

        Particle* p = new Particle;

        file >> p->q >> p->px >> p->py >> p->pz;

        ev->add(p->q, p->px, p->py, p->pz);

    }

    return ev;

}








