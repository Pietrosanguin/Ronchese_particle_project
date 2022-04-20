#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "AnalysisInfo.h"
#include "Event.h"
#include "MassMean.h"
#include "EventReadFromFile.h"
#include "EventSim.h"
#include "AnalysisSteering.h"
#include "ParticleMass.h"
#include "EventDump.h"
#include "EventSource.h"
#include "SourceFactory.h"

using namespace std;

int main(int argc, char* argv[]) {

  //prendo parametri della riga di comando
  AnalysisInfo* info = new AnalysisInfo( argc, argv );
  
    // create data source
    EventSource* es = SourceFactory::create( info );

     // create a list of analyzers
  vector<AnalysisSteering*> aList;
  
  // create object to dump event
  // and store into list of analyzers
 // aList.push_back( new EventDump );  //Riga che permette di fare il dump a schermo
  
  // create object to compute mean and rms energies
  // and store into list of analyzers
  aList.push_back( new ParticleMass );
  
  // initialize all analyzers
  for ( auto as: aList ) as->beginJob();
  
  // loop over events
  const Event* ev;
  while ( ( ev = es->get() ) != nullptr )  {
    for ( auto as: aList ) as->process( *ev );
	delete ev;
  }

  // finalize all analyzers
  for ( auto as: aList ) as->endJob();
  
  delete es;
		   
  return 0;
}
