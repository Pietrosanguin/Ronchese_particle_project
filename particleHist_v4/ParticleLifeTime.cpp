#include "ParticleLifeTime.h"
#include "ParticleReco.h"
#include "Event.h"
#include "AnalysisInfo.h"
#include "AnalysisFactory.h"
#include "EventDump.h"
#include "include/TFileProxy.h"
#include "TH1F.h"
#include "TFile.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;


// concrete factory to create an ParticleLifeTime analyzer
class ParticleLifeTimeFactory: public AnalysisFactory::AbsFactory {
 public:
  // assign "TimePlot" as name for this analyzer and factory
  ParticleLifeTimeFactory(): AnalysisFactory::AbsFactory( "TimePlot" ) {}
  // create a ParticleLifeTime when builder is run
  AnalysisSteering* create( const AnalysisInfo* info ) override {
    return new ParticleLifeTime( info );
  }
};
// create a global ParticleLifeTimeFactory, so that it is created and registered 
// before main execution start:
// when the AnalysisFactory::create function is run,
// a ParticleLifeTimeFactory will be available with name "TimePlot".
static ParticleLifeTimeFactory pm;
double mass( const Event& e);
ParticleLifeTime::ParticleLifeTime( const AnalysisInfo* info ):
 AnalysisSteering( info ) {
}

ParticleLifeTime::~ParticleLifeTime() {
}
void ParticleLifeTime::pCreate( const string& nome, float min, float max, float timeMin, float timeMax ) {

  // create name for TH1F object
  const char* name =  nome.c_str();
 
  // create TH1F and statistic objects and store their pointers
  Particle* part = new Particle;
  part->nome=name;
  part->mean = new LifeTimeFit( min, max );
  part->h = new TH1F(name, name, 200, timeMin-(timeMax-timeMin)*0.01, timeMax+(timeMax-timeMin)*0.01 );
  pList.push_back( part );

  return;

}
 void ParticleLifeTime::beginJob()
 {
	pList.reserve(2);
	pCreate( "K0_time", 0.495, 0.500, 10, 500 );
	pCreate("Lambda0_times", 1.115, 1.116, 10, 1000);
	return;
 }
 void ParticleLifeTime::endJob()
 {
	 TDirectory* currentDir = gDirectory;
	 	// open histogram file
		const string nomeroot1= "time_";
		const string nomeroot2=aInfo->value( "TimePlot" );
		const string nomeroot=nomeroot1+nomeroot2;
		
		const char* name=nomeroot.c_str();
	
	 TFile* file = new TFile( name , "RECREATE" );

        for ( Particle* p: pList ) {
			TH1F*      h = p->h;
		

	
	h->Write();
	
		}
		file->Close();
	delete file;
	// restore working area
	currentDir->cd();
 }
 void ParticleLifeTime::update(const Event& e)
 {
       static ProperTime* t= ProperTime::instance();
	float time=t->DecayTime();
	for ( Particle* p: pList ){
		LifeTimeFit*  mean = p->mean; 
		if(mean->add(e)){
			p->h->Fill(time);
		}
	} 
	
	return;
 }

