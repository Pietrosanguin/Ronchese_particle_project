#include <iostream>
#include<fstream>
#include<string>
#include<cmath>
#include "Event.h"
#include"MassMean.h"
#include"Constants.h"
#include"Utilities.h"

using namespace std;

//scrivere i dati a schermo
void dump(const Event& ev);

//leggere i dati
Event* read(ifstream& file);


int main()
{
	//limiti min e max per la massa invariante (inizializzazione in MassMean.cpp)
	MassMean K0(0.495, 0.500), L0(1.115, 1.116);

	//apro il file
	string nome_file;
	cout << "Inserire nome file .txt" << endl;
	cin >> nome_file;
	ifstream input_file;
	input_file.open(nome_file);
	const Event* evento;


	while (!input_file.eof()) {

		evento = read(input_file);

		//dump(*evento); //per fare il dump a schermo

		K0.add(*evento);
		L0.add(*evento);

		delete evento; //chiama il distruttore dell'evento

		K0.compute();
		L0.compute();

	}

	cout << "media K0: " << K0.MEAN() << endl;
	cout << "media L0: " << L0.MEAN() << endl;
	cout << "rms K0: " << K0.RMS() << endl;
	cout << "rms L0: " << L0.RMS() << endl;

	input_file.close(); //closes file
	return 0;
}




