#include <iostream>


using namespace std;

void dump(int id, int n_particelle, float &x, float &y, float &z, int q[], float px[], float py[], float pz[]  )
{
	cout<<id <<"\n" 
	<< x<<" " <<y<< " " <<z <<"\n"
	<<n_particelle<<endl;

	for(int i=0; i<n_particelle; ++i)
	{
		cout<<q[i]<<" "<<px[i]<<" "<<py[i]<<" "<<pz[i]<<"\n";
		
	}
}


