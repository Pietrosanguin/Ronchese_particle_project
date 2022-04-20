#ifndef Particle_h
#define Particle_h

struct particle{
	
     int  q;
	float px;
	float py;
	float pz;
	
	
};

 struct event{
	
	int id;
	float x;
	float y;
	float z;
	int n_particelle;
	particle** corpuscolo=new particle* ;
	
	
	
};



#endif
