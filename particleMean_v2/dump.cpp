#include <iostream>
#include "Event.h"

using namespace std;

void dump(Event* ev)
{

	cout << ev->eventNumber() << endl;
	cout << ev->Getx() << " " << ev->Gety() << " " << ev->Getz() << endl;
	cout << ev->nParticles() << endl;

	for (int i = 0; i < ev->nParticles(); ++i) {

		cout << ev->getParticle(i)->q << " " << ev->getParticle(i)->px << " " << ev->getParticle(i)->py << ev->getParticle(i)->pz << endl;


	}


}
