#ifndef ParticleLifeTime_h
#define ParticleLifeTime_h

#include "include/ActiveObserver.h"
#include "AnalysisSteering.h"
#include "LifeTimeFit.h"
#include "AnalysisFactory.h"
#include "ProperTime.h"
#include "EventDump.h"
#include <vector>
#include <string>

class Event;
class LifeTimeFit;
class TH1F;

using namespace std;

class ParticleLifeTime: public AnalysisSteering,
              public ActiveObserver<Event> {

 public:

  ParticleLifeTime(const AnalysisInfo* info);
  
  ParticleLifeTime( const ParticleLifeTime& x ) = delete;
  ParticleLifeTime& operator=( const ParticleLifeTime& x ) = delete;

  ~ParticleLifeTime() override;

  
  void beginJob() override;
 
  void   endJob() override;

  void update( const Event& e ) override; 

  

  private:
  struct Particle{
		string nome;  
		LifeTimeFit*   mean; 
		TH1F*       h; 
	};
	  vector<Particle*> pList;


	void pCreate( const string& nome, float min, float max, float timeMin, float timeMax);
};
#endif