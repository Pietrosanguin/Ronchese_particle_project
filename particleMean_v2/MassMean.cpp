#include "MassMean.h"
#include "Event.h"
#include <cmath>

double mass(const Event& ev);

//costruttore e inizializzazione variabili
MassMean::MassMean(double min_inv_mass, double max_inv_mass) :
	 
	min_inv_mass(min_inv_mass), max_inv_mass(max_inv_mass),
	selected_event(0), mean(0), rms(0),
	massum(0), squaresum(0)
{
}

//distruttore
MassMean::~MassMean() {
}


// aggiungo dati da un nuovo evento
void MassMean::add(const Event& ev) {

	double invMass;
	invMass = mass(ev) - min_inv_mass;

	// controllo di accettazione
	if ((invMass < 0) || (invMass > (max_inv_mass - min_inv_mass))) return;

	// aggiorna il contatore
	selected_event++;
	massum += invMass;
	squaresum += pow(invMass, 2);

}

void MassMean::compute() 
	{
		mean = massum / (selected_event * 1.0);
		rms = sqrt(squaresum / (selected_event * 1.0) - pow(mean, 2));
		mean += min_inv_mass;
		
	}

int MassMean::nEvents() const {
	return selected_event;
}


double MassMean::MEAN() const {
	return mean;
}

double MassMean::RMS() const {
	return rms;
}



