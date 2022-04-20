#include "EventSource.h"
#include "../include/Dispatcher.h"
class Event;
EventSource::EventSource() {
}


EventSource::~EventSource() {
}
void EventSource::run ()
{
    const Event* ev;
 while ( ( ev = get() ) != nullptr ) {
    Dispatcher<Event>::notify( *ev );
    delete ev;
  }
  }

