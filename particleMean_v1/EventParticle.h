#ifndef Particle_h
#define Particle_h

struct Particle {

	int  q;
	float px;
	float py;
	float pz;


};

struct Event {

	int id;
	float x;
	float y;
	float z;
	int n_particelle;
	Particle** corpuscolo = new Particle*;



};



#endif
