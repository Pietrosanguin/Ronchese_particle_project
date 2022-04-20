#include <iostream>
#include<fstream>


using namespace std;



int read(ifstream& file, float &x, float &y, float &z, int q[], float px[], float py[], float pz[]  )
{


	
 file>>x>>y>>z;
 int n_particelle;
 file>>n_particelle;
 
 
 for(int i=0; i<n_particelle; ++i){
 	
 	file>>q[i]>>px[i]>>py[i]>>pz[i];
 	
 	
 		
 }


return n_particelle;
	
	
	
}



