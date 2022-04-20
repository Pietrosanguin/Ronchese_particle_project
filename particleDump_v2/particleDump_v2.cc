#include <iostream>
#include<fstream>
#include<string>
#include "EventParticle.h"

using namespace std;

void dump(const event& ev);

event* read(ifstream& file);

void clear(const  event* ev);

int main()
{
	
	
	//apro il file
	 string nome_file;
	cout<<"Inserire nome file .txt" <<endl;
	cin>>nome_file;
	ifstream input_file;
	input_file.open(nome_file);
	
	event const *ev=new event;
	
	while(!input_file.eof()){
	
    ev=read(input_file);
	dump(*ev);
	clear(ev);
		
}
	
	return 0;
	
}





