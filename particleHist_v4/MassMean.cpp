#include "MassMean.h"
#include "Event.h"
#include <math.h>
#include "ParticleReco.h"
double mass( const Event& ev);

MassMean::MassMean( double min, double max ):
 // initializations  
 min_inv_mass(min), max_inv_mass(max), 
 selected_event(0), mean(0), rms(0),
 massum(0), squaresum(0)
  {	 
}


MassMean::~MassMean() {
}

unsigned int MassMean::nEvents() const{
	return selected_event;
}

double MassMean::MEAN() const{
	return mean;
}
double MassMean::RMS() const{
	return rms;
}


// aggiungo dati da un nuovo evento
bool MassMean::add( const Event& e ) {
	static ParticleReco* mass= ParticleReco::instance();
	float invMass=mass->mass();
	
    // controllo di accettazione
	if ((invMass < min_inv_mass) || invMass > max_inv_mass) return false;
 
    // aggiorna il contatore
	selected_event++;
	massum += invMass;
	squaresum   += pow( invMass, 2 );
	return true;
	
}

void MassMean::compute() {
	mean = massum / (selected_event * 1.0);
	rms = sqrt(squaresum / (selected_event * 1.0) - pow(mean, 2));
	mean += min_inv_mass;
}



