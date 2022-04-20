#include "ParticleMass.h"
#include "ParticleReco.h"
#include "Event.h"
#include "AnalysisInfo.h"
#include "AnalysisFactory.h"
#include "EventDump.h"
#include "MassMean.h"

#include "TH1F.h"
#include "TFile.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;


// concrete factory to create a ParticleMass analyzer
class ParticlemassFactory: public AnalysisFactory::AbsFactory {
 public:
  // assign "MassPlot" as name for this analyzer and factory
  ParticlemassFactory(): AnalysisFactory::AbsFactory( "MassPlot" ) {}
  // create a ParticleMass when builder is run
  AnalysisSteering* create( const AnalysisInfo* info ) override {
    return new ParticleMass( info );
  }
};
// create a global ParticlemassFactory, so that it is created and registered 
// before main execution start:
// when the AnalysisFactory::create function is run,
// an ParticlemassFactory will be available with name "MassPlot".
static ParticlemassFactory pm;
double mass( const Event& e);


ParticleMass::ParticleMass( const AnalysisInfo* info ):
 AnalysisSteering( info ) {
}

ParticleMass::~ParticleMass() {
}
void ParticleMass::pCreate( const string& nome, float min, float max ) {

  // create name for TH1F object
  const char* name =  nome.c_str();

  // create TH1F and statistic objects and store their pointers
  Particle* part = new Particle;
  part->nome=name;
  //part-> nome =strcat("mass",name);
  part->mean = new MassMean( min, max );
  part->h = new TH1F(name, name, 200, min-(max-min)*0.01, max+(max-min)*0.01 );
  pList.push_back( part );

  return;

}
 void ParticleMass::beginJob()
 {
	pList.reserve(2);
	pCreate( "K0_mass", 0.495, 0.500 );
	pCreate("Lambda0_mass", 1.115, 1.116 );
	return;
 }
 void ParticleMass::endJob()
 {
	 TDirectory* currentDir = gDirectory;
	 	// open histogram file
		const string nomeroot1= "mass_";
		const string nomeroot2=aInfo->value( "MassPlot" );
		const string nomeroot=nomeroot1+nomeroot2;
		const char* name=nomeroot.c_str();
	 TFile* file = new TFile( name , "RECREATE" );

        for ( Particle* p: pList ) {
			MassMean*  mean = p->mean;
			TH1F*      h = p->h;
		mean->compute();
	h->Write();
	
		}
		file->Close();
	delete file;
	// restore working area
	currentDir->cd();
 }
 void ParticleMass::update(const Event& e)
 {
       static ParticleReco* mass= ParticleReco::instance();
	float invMass=mass->mass();
	for ( Particle* p: pList ){
		MassMean*  mean = p->mean; 
		if(mean->add(e)){
			p->h->Fill(invMass);
		}
	} 
	
	return;
 }

