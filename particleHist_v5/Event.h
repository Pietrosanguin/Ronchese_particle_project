#ifndef Particle_h
#define Particle_h
#include<vector>

struct Particle {

	int  q;
	double px;
	double py;
	double pz;


};

class Event {

public:

	//Costruttore
	Event(int id, double x, double y, double z);
	~Event();

	//funzione per aggiungere una particella all'evento
	void add(int q, double px, double py, double pz);
	// funzione che ritorna il numero di evento
	int eventNumber() const;
	// funzioni che ritornano le coordinate

	float Getx() const;
	float Gety() const;
	float Getz() const;

	//funzione che ritorna il numero di particelle
	int nParticles() const;

	typedef Particle* pointpart;
	pointpart getParticle(int n) const;

private:

	int id;
	float x;
	float y;
	float z;
	std::vector<pointpart> corpuscolo;




};



#endif
