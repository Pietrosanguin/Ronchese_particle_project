#ifndef ParticleMass_h
#define ParticleMass_h

#include "AnalysisSteering.h"
#include<vector>
#include <string>

class Event;
class MassMean;
class TH1F;

using namespace std;

class ParticleMass : public AnalysisSteering {

private:

struct Particle{
       
       string nome;
       MassMean* mean;
       TH1F* h;
};

void pCreate( const string& nome, float min, float max);
        
	// vector of pointers to Particle
	vector<Particle*> pList;


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

