#include "EventReadFromFile.h"

#include "Event.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// read data from file "name"
EventReadFromFile::EventReadFromFile(const string& name) {
    file = new ifstream(name);
}


EventReadFromFile::~EventReadFromFile() {
    delete file;
}


// get an event
const Event* EventReadFromFile::get() {
    return readFile();
}


// read an event
const Event* EventReadFromFile::readFile() {

    int id, n_particelle;
    double x, y, z;
    int c;


    if (!(*file >> c)) return nullptr;


    *file >> id >> x >> y >> z >> n_particelle;

    Event* ev = new Event(id, x, y, z);

    for (int i = 0; i < n_particelle; ++i) {

        Particle* p = new Particle;

        *file >> p->q >> p->px >> p->py >> p->pz;

        ev->add(p->q, p->px, p->py, p->pz);

    }

    return ev;


}
