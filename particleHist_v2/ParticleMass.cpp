#include"ParticleMass.h"
#include "Event.h"
#include "MassMean.h"

#include "TH1F.h"
#include "TFile.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

double mass( const Event& ev);

ParticleMass::ParticleMass() {
}

ParticleMass::~ParticleMass() {
}

void ParticleMass::pCreate( const string& nome, float min, float max){
//creo il nome per TH1F
const char* name = nome.c_str(); // con .c_str() ritorno un puntatore ad array 

// creo TH1F e ne salvo i puntatori

Particle* part = new Particle;
part->nome = name;
part->mean = new MassMean(min,max);
part->h = new TH1F(name, name, 200, min-(max-min)*0.01, max+(max-min)*0.01);
pList.push_back( part );

return;

}


void ParticleMass::beginJob(){

	// create mass ranges for different decay modes
	pList.reserve(2);
	// K0
	pCreate( "K0", 0.495, 0.500);
	// Lambda0
	pCreate( "Lambda0", 1.115, 1.116);

	return;

}

// function to be called at execution end
void ParticleMass::endJob() {

      TDirectory* currentDir = gDirectory;
      TFile* file = new TFile( "histogram.root", "RECREATE");
      
      //apro histogram file loop su Particle objects
      
	for (Particle* p : pList) {
		
		MassMean* mean = p->mean;
		TH1F* h = p->h;
		mean->compute();
		cout << mean->nEvents() << endl;
		cout << mean->MEAN() << ' ' << mean->RMS()  << endl;
		
		h->Write();
	}
	
	file->Close();
	delete file;
	currentDir->cd(); //rimette l'area di lavoro
}

// function to be called for each event
void ParticleMass::process(const Event& ev) {

	// loop over mass ranges and pass event to each of them
	for (Particle* p : pList) {
	MassMean* mean = p->mean;
	
	if(mean->add(ev)){
	  p->h->Fill(mass(ev));
	  }
}	  
	
	
	return;
}
