#ifndef EventSource_h
#define EventSource_h
#include "AnalysisSteering.h"
#include "Event.h"
#include<vector>
class Event;

class EventSource {

 public:

  EventSource();
  // deleted copy constructor and assignment to prevent unadvertent copy
  EventSource           ( const EventSource& x ) = delete;
  EventSource& operator=( const EventSource& x ) = delete;
 virtual void run();
  virtual ~EventSource();
private:
  // get an event
  virtual const Event* get() = 0;
 
};

#endif

