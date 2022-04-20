#include "Event.h"

void Event::add(int q, double px, double py, double pz) {

    Particle* p = new Particle;
    p->q = q, p->px = px, p->py = py, p->pz = pz;
    corpuscolo.push_back(p);
}

int Event::eventNumber() const {

    return id;
}

float Event::Getx() const{

    return x;
}

float Event::Gety() const {

    return y;
}

float Event::Getz() const {

    return z;
}

int Event::nParticles() const {

    return corpuscolo.size();
}

Event::pointpart Event::getParticle(int n) const {

    //.at ritorna una referenza all'n-esimo elemento del vettore
    return corpuscolo.at(n); 

}

//Costruttore

Event::Event(int id, double x, double y, double z) {

    //il vettore deve contenere almeno 10 elementi
    corpuscolo.reserve(10);
    this->x = x;
    this->y = y;
    this->z = z;
    this->id = id;


}

//distruttore

Event::~Event()
{
    for (unsigned int i = 0; i < corpuscolo.size(); ++i) {
        delete corpuscolo[i];

}
}
