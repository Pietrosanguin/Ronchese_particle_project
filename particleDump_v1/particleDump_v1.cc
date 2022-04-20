#include <iostream>
#include<fstream>
#include<string>


using namespace std;

void dump(int id, int n_particelle, float &x, float &y, float &z, int q[], float px[], float py[], float pz[]  );

int read(ifstream& file, float &x, float &y, float &z, int q[], float px[], float py[], float pz[]  );

int main()
{
	//dichiaro le variabili 
	int id, n_particelle;
	float x, y, z;
	int q[10];
	float px[10], py[10], pz[10];
	
	
	 string nome_file;
	cout<<"Inserire nome file .txt" <<endl;
	cin>>nome_file;
	ifstream input_file;
	input_file.open(nome_file);
	
	

	
	while(!input_file.eof()){
		
		input_file>>id;
		n_particelle=read(input_file,x,y,z,q,px,py,pz);
		dump(id,n_particelle,x,y,z,q,px,py,pz);
		
	} 


	
	
	return 0;
	
}





