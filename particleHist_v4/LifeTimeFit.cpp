#include "LifeTimeFit.h"
#include "Event.h"
#include <math.h>
#include "ParticleReco.h"
#include<iostream>


LifeTimeFit::LifeTimeFit( double min, double max ):
 // initializations  
 min_inv_mass(min), max_inv_mass(max), selected_event(0)
  {	 
}


LifeTimeFit::~LifeTimeFit() {
}

unsigned int LifeTimeFit::nEvents() const{
	return selected_event;
}



// add data from a new event
bool LifeTimeFit::add( const Event& e ) {
	static ParticleReco* mass= ParticleReco::instance();
	float invMass=mass->mass();
    // check if accepted
	if( invMass<min_inv_mass || invMass >max_inv_mass) return false;
    // update counter
	selected_event++;
	return true;
	
}
void LifeTimeFit::compute ()
{

}





