#include <iostream>
#include<fstream>
#include "EventParticle.h"


using namespace std;



event* read(ifstream& file)
{

//creo e riempio il puntatore alla struttura evento 
event* ev=new event;


if (!file.eof()){
	
	
file>>ev->id>>ev->x>>ev->y>>ev->z>>ev->n_particelle;

 ev->corpuscolo= new particle* [ev->n_particelle];
 
 for(int i=0; i<ev->n_particelle; ++i){
 	
 	particle *p=new particle;
 	
 	file>>p->q>>p->px>>p->py>>p->pz;
 	
 	ev->corpuscolo[i]= p; 
 	
 	}

return ev;

}


return nullptr;

	
	
	
}



