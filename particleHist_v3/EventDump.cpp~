#include "EventDump.h"
#include "Event.h"
#include <iostream>

using namespace std;


EventDump::EventDump() {
}


EventDump::~EventDump() {
}


// function to be called at execution start
void EventDump::beginJob() {
    return;
}


// function to be called at execution end
void EventDump::endJob() {
    return;
}


// function to be called for each event
void EventDump::process(const Event& ev) {

	cout << ev.eventNumber() << endl;
	cout << ev.Getx() << " " << ev.Gety() << " " << ev.Getz() << endl;
	cout << ev.nParticles() << endl;

	for (int i = 0; i < ev.nParticles(); ++i) {

		cout << ev.getParticle(i)->q << " " << ev.getParticle(i)->px << " " << ev.getParticle(i)->py << ev.getParticle(i)->pz << endl;


	}

}
