#include"ParticleMass.h"
#include "Event.h"
#include "MassMean.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

ParticleMass::ParticleMass() {
}

ParticleMass::~ParticleMass() {
}

void ParticleMass::beginJob(){

	// create mass ranges for different decay modes
	pList.reserve(2);
	// K0
	pList.push_back(new MassMean(0.495, 0.500));
	// Lambda0
	pList.push_back(new MassMean(1.115, 1.116));

	return;

}

// function to be called at execution end
void ParticleMass::endJob() {

	// loop over MassMean objects
	for (MassMean* pMean : pList) {
		// compute results
		pMean->compute();
		// get mean and rms mass
		const double mean = pMean->MEAN();
		const double rms = pMean->RMS();

		// print number of events
		cout << pMean->nEvents() << endl;
		// print mass and rms
		cout << mean << ' ' << rms << endl;
	}

	return;
}

// function to be called for each event
void ParticleMass::process(const Event& ev) {
	// loop over mass ranges and pass event to each of them
	for (MassMean* pMean : pList) pMean->add(ev);
	return;
}