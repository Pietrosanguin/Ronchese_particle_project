#include "ParticleMass.h"
#include "../AnalysisObjects/ParticleReco.h"
#include "../AnalysisFramework/Event.h"
#include "../AnalysisFramework/AnalysisInfo.h"
#include "../AnalysisObjects/MassMean.h"

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
	string nome;
	double min, max;
	const string settings=aInfo->value( "fitters" ); //se in linea di comando metto fitters
	
	if (settings=="set") //se metto set invece di fitters
	{
		//for K0
		nome= "K0";
		std::cout<<"set for K0: "<<std::endl;
		std::cout<<"set min : ";
		cin>>min;
		std::cout<<"set max : ";
		cin>>max;
		
		pCreate( nome, min, max);
		//for Lambda 0
		nome= "Lambda0";
		std::cout<<"set for Lambda0: "<<std::endl;
		std::cout<<"set min : ";
		cin>>min;
		std::cout<<"set max : ";
		cin>>max;
		
	    pCreate( nome, min, max );
		
		 return;

	}

	//se voglio prendere il file txt
   ifstream file( aInfo->value( "ranges" ).c_str() );
	//set values reading from file 
   while ( file >> nome >> min >> max ) 
    	//store them
    pCreate( nome, min, max);
	
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

		cout << mean->nEvents() << endl;
		cout << mean->MEAN() << ' ' << mean->RMS()  << endl;

		h->Write();
	
		}
		file->Close();
	delete file;
	
	currentDir->cd(); //rimette l'area di lavoro
 }

// function to be called for each event
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

