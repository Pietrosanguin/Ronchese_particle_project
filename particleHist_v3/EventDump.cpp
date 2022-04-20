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



EventDump::EventDump( const AnalysisInfo* info):
  AnalysisSteering( info) {
}


EventDump::~EventDump() {
}


// function to be called at execution start
void EventDump::beginJob() {
    return;
}


// function to be called at execution end
void EventDump::endJob() {
    return;
}


// function to be called for each event
void EventDump::process(const Event& ev) {

	cout << ev.eventNumber() << endl;
	cout << ev.Getx() << " " << ev.Gety() << " " << ev.Getz() << endl;
	cout << ev.nParticles() << endl;

	for (int i = 0; i < ev.nParticles(); ++i) {

		cout << ev.getParticle(i)->q << " " << ev.getParticle(i)->px << " " << ev.getParticle(i)->py << ev.getParticle(i)->pz << endl;


	}

}
