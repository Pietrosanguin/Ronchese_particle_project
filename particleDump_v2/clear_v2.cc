#include <iostream>
#include<fstream>
#include "EventParticle.h"


using namespace std;

void clear(const  event* ev){
	
	 for (int i=0; i<ev->n_particelle;++i){
	
	 delete[] ev->corpuscolo[i];
	 delete[] ev->corpuscolo;
	 delete ev;
     return ;
  
}

	
	
}








