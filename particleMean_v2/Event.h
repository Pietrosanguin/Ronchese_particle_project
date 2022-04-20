#ifndef Particle_h
#define Particle_h

struct Particle {

	int  q;
	double px;
	double py;
	double pz;


};

class Event {
private:

	int id;
	double x;
	double y;
	double z;
	int n_particelle=0;
	const int max_n_part=10;
	Particle** corpuscolo = new Particle*;

public:

	Event(int id, double x, double y, double z);      //Costruttore
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
	



};



#endif
