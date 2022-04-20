#include "Event.h"

void Event::add(int q, double px, double py, double pz) {

        if (n_particelle < max_n_part)
        {
            corpuscolo[n_particelle] = new Particle();
            corpuscolo[n_particelle]->px = px,
            corpuscolo[n_particelle]->py = py,
            corpuscolo[n_particelle]->pz = pz,
            corpuscolo[n_particelle]->q = q;
            n_particelle++;
        }
    }

int Event::eventNumber() const {

    return id;
}

float Event::Getx() const {

    return x;
}

float Event::Gety() const {

    return y;
}

float Event::Getz() const {

    return z;
}

int Event::nParticles() const {

    return n_particelle;
}

Event::pointpart Event::getParticle(int n) const {

    if (n < max_n_part) {

        return corpuscolo[n];
    }
    else

    return nullptr;

}

//Costruttore

Event::Event(int id, double x, double y, double z) {

    *corpuscolo = new Particle[max_n_part];
    this->x = x;
    this->y = y;
    this->z = z;
    this->id = id;


}

//distruttore

Event::~Event()
{
    for (int i = 0; i < n_particelle; ++i)
    {
        delete[] corpuscolo[i];
    }

}
