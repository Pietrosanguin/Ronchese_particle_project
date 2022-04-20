#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


#include "Event.h"
#include "EventSource.h"
#include "SourceFactory.h"
#include "AnalysisInfo.h"
#include "AnalysisSteering.h"
#include "AnalysisFactory.h"
#include "LifeTimeFit.h"
#include"ParticleLifeTime.h"
#include "ProperTime.h"
using namespace std;

int main( int argc, char* argv[] ) {
// store command line parameters
  AnalysisInfo* info = new AnalysisInfo( argc, argv );
//cout<<info->argList()[0];
  // create data source
  EventSource* es = SourceFactory::create( info );

  // create a list of analyzers
  vector<AnalysisSteering*> aList = AnalysisFactory::create( info );

  // initialize all analyzers
  for ( auto as: aList ) 
  {
    as->beginJob();
  }

   es->run();

  // finalize all analyzers
  for ( auto as: aList ) 
  {
    as->endJob();
  }

  return 0;

}

