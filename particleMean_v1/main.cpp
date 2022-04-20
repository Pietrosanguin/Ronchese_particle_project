#include <iostream>
#include<fstream>
#include<string>
#include<cmath>
#include "EventParticle.h"

using namespace std;

void dump(const Event& ev);

Event* read(ifstream& file);

void clear(const  Event* ev);

bool add(const Event& ev, float min, float max, double& sum_mass, double& sum_squares);

int main()
{
	int Evento_accettato = 0;
	double sum_mass = 0, sum_squares = 0, mean, rms;

	//apro il file
	string nome_file;
	cout << "Inserire nome file .txt" << endl;
	cin >> nome_file;
	ifstream input_file;
	input_file.open(nome_file);

	Event const* evento = new Event;

	while (!input_file.eof()) {

		evento = read(input_file);
		
		//dump(*evento); //per fare il dump a schermo

		if (add(*evento, 0.490, 0.505, sum_mass, sum_squares) == true)
		{
			Evento_accettato++;
		}
		clear(evento);
	}

	mean = (sum_mass / Evento_accettato);
	rms = sqrt((sum_squares - ((Evento_accettato * pow(mean, 2)))) / Evento_accettato);
	std::cout << "mean= " << mean << " rms= " << rms << std::endl;

	input_file.close(); //closes file
	return 0;
}
	





