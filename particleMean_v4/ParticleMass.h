#ifndef ParticleMass_h
#define ParticleMass_h

#include "AnalysisSteering.h"
#include "MassMean.h"
#include<vector>

class Event;
class MassMean;

class ParticleMass : public AnalysisSteering {

private:

	// vector of pointers to MassMean objects
	std::vector<MassMean*> pList;


public:

	ParticleMass();
	// deleted copy constructor and assignment to prevent unadvertent copy
	ParticleMass(const ParticleMass& x) = delete;
	ParticleMass& operator=(const ParticleMass& x) = delete;

	~ParticleMass() override;

	// function to be called at execution start
	void beginJob() override;
	// function to be called at execution end
	void   endJob() override;
	// function to be called for each event
	void process(const Event& ev) override;

	



};






#endif 

