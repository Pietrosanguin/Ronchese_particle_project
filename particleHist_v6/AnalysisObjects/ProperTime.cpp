#include "../AnalysisObjects/ProperTime.h"
#include <iostream>
#include <cmath>
#include "../AnalysisObjects/ParticleReco.h"
using namespace std;

// constructor
ProperTime::ProperTime() {
}


// destructor
ProperTime::~ProperTime() {
}


// recompute tag informations for new event
void ProperTime::update( const Event& e ) {


//compute distance from origin
 double d=sqrt(pow(e.Getx(),2)+pow(e.Gety(),2)+pow(e.Getz(),2));
 //get mass and energy data about decay
 static ParticleReco* mass= ParticleReco::instance();
	float m=mass->mass();
  static ParticleReco* energy= ParticleReco::instance();
	float en=energy->energy();

  //compute proper time
 time=d*m/(sqrt(pow(en,2)-pow(m,2))*Constants::lightVelocity);
  return;

}

double ProperTime::DecayTime() {
 check();
return time;
}

