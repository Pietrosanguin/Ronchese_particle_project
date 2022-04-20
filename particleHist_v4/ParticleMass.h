#ifndef ParticleMass_h
#define ParticleMass_h

#include "include/ActiveObserver.h"
#include "AnalysisSteering.h"

#include "AnalysisFactory.h"
#include "EventDump.h"
#include <vector>
#include <string>

class Event;
class MassMean;
class TH1F;

using namespace std;

class ParticleMass: public AnalysisSteering,
              public ActiveObserver<Event> {

 public:

  ParticleMass(const AnalysisInfo* info);
  
  ParticleMass( const ParticleMass& x ) = delete;
  ParticleMass& operator=( const ParticleMass& x ) = delete;

  ~ParticleMass() override;

  
  void beginJob() override;
 
  void   endJob() override;

  void update( const Event& e ) override; 

  

  private:
  struct Particle{
		string nome;  
		MassMean*   mean; 
		TH1F*       h; 
	};
	  vector<Particle*> pList;


	void pCreate( const string& nome, float min, float max );
};
#endif
