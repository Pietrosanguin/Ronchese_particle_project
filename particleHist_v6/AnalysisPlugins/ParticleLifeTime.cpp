#include "ParticleLifeTime.h"
#include "../AnalysisObjects/ParticleReco.h"
#include "../AnalysisFramework/Event.h"
#include "../AnalysisFramework/AnalysisInfo.h"
#include "../include/TFileProxy.h" 
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
void ParticleLifeTime::pCreate( const string& nome, float min, float max, float timeMin, float timeMax, float minScan, float maxScan, float scanStep) {

  // create name for TH1F object
  const char* name =  nome.c_str();
 
  // create TH1F and statistic objects and store their pointers
  Particle* part = new Particle;
  part->nome=name;
  part->mean = new LifeTimeFit( min, max, timeMin, timeMax, minScan, maxScan, scanStep);
  part->h = new TH1F(name, name, 200, timeMin-(timeMax-timeMin)*0.01, timeMax+(timeMax-timeMin)*0.01 );
  pList.push_back( part );

  return;

}
 void ParticleLifeTime::beginJob()
 {
	pList.reserve(2);
	string nome;
	double min, max, timeMin, timeMax, minScan, maxScan, scanStep;

	//se scrivo fitters in linea di comando
	const string settings=aInfo->value( "fitters" );
	if (settings=="set") //se scrivo set fitters
	{
		//for K0
		nome= "K0";
		std::cout<<"set for K0: "<<std::endl;
		std::cout<<"set min : ";
		cin>>min;
		std::cout<<"set max : ";
		cin>>max;
		std::cout<<"set min time: ";
		cin>>timeMin;
		std::cout<<"set min time: ";
		cin>>timeMax;
		std::cout<<"set min scan: ";
		cin>>minScan;
		std::cout<<"set max scan: ";
		cin>>maxScan;
		std::cout<<"set scan step: ";
		cin>>scanStep;
		pCreate( nome, min, max, timeMin, timeMax, minScan, maxScan, scanStep );

	//for Lambda 0
		nome= "Lambda0";
		std::cout<<"set for Lambda0: "<<std::endl;
		std::cout<<"set min : ";
		cin>>min;
		std::cout<<"set max : ";
		cin>>max;
		std::cout<<"set min time: ";
		cin>>timeMin;
		std::cout<<"set min time: ";
		cin>>timeMax;
		std::cout<<"set min scan: ";
		cin>>minScan;
		std::cout<<"set max scan: ";
		cin>>maxScan;
		std::cout<<"set scan step: ";
		cin>>scanStep;
	    pCreate( nome, min, max, timeMin, timeMax, minScan, maxScan, scanStep );
		
		 return;

	}

	ifstream file( aInfo->value( "fitters" ).c_str() );

	//lettura da file
	
  while ( file >> nome >> min >> max >> timeMin >> timeMax >> minScan >> maxScan >> scanStep ) 
  pCreate( nome, min, max, timeMin, timeMax, minScan, maxScan, scanStep );

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
                        LifeTimeFit*  mean = p->mean;

    //calcolo tempo di vita medio ed errore
             
 mean->compute();
 //stampo a schermo i risultati nan...
 //cout << mean->lifeTime() <<" "<<mean->lifeTimeError()<< endl;
	
		
	h->Write();
	
		}
		file->Close();
	delete file;

	currentDir->cd(); //rimette l'area di lavoro
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

