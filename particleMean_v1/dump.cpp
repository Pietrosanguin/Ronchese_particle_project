#include <iostream>
#include "EventParticle.h"

using namespace std;

void dump(const Event& ev)
{

	cout << ev.id << endl;
	cout << ev.x << " " << ev.y << " " << ev.z << endl;
	cout << ev.n_particelle << endl;

	for (int i = 0; i < ev.n_particelle; ++i) {

		cout << ev.corpuscolo[i]->q << " " << ev.corpuscolo[i]->px << " " << ev.corpuscolo[i]->py << ev.corpuscolo[i]->pz << endl;


	}


}

