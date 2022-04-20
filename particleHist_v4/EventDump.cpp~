#include "EventDump.h"
#include "AnalysisFactory.h"
#include "Event.h"
#include <iostream>

using namespace std;
// concrete factory to create an EventDump analyzer
class EventDumpFactory: public AnalysisFactory::AbsFactory {
 public:
  // assign "dump" as name for this analyzer and factory
  EventDumpFactory(): AnalysisFactory::AbsFactory( "dump" ) {}
  // create an EventDump when builder is run
  AnalysisSteering* create( const AnalysisInfo* info ) override {
    return new EventDump( info );
  }
};
// create a global EventDumpFactory, so that it is created and registered 
// before main execution start:
// when the AnalysisFactory::create function is run,
// an EventDumpFactory will be available with name "dump".
static EventDumpFactory ed;

EventDump::EventDump( const AnalysisInfo* info ):
 AnalysisSteering( info ) {
}


EventDump::~EventDump() {
}


// executed at the beginning
void EventDump::beginJob() {
  return;
}


// executed at the end
void EventDump::endJob() {
  return;
}


void EventDump::update( const Event& e ) {

	// print data of event e, repeated for each event
	cout << e.eventNumber() << endl;
	cout << e.getx() << " "
		      << e.gety() << " "
			  << e.getz() << endl;
	 
	cout << e.nParticles()<<endl;
	
	for( int i = 0; i < e.nParticles(); ++i){
		cout << e.getParticle(i)->q << " "
				  << e.getParticle(i)->px << " "
				  << e.getParticle(i)->py << " "
				  << e.getParticle(i)->pz << endl;
	}

	return;

}

