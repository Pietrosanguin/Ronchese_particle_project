#ifndef ParticleReco_h
#define ParticleReco_h

#include "Event.h"
#include "Utilities.h"
#include "Constants.h"
#include "include/Singleton.h"
#include "include/LazyObserver.h"

class ParticleReco: public Singleton<ParticleReco>,
                    public LazyObserver<Event> {

  friend class Singleton<ParticleReco>;

 public:

  // particle types
  enum ParticleType { K0, Lambda0, unknown };

  // recompute informations for new event
 void update( const Event& ev ) override;

  // return particle type
  ParticleType ptype();
  // return particle energy
  double energy();
  // return particle mass
  double mass();

 private:

  // private constructor and destructor for singleton
  ParticleReco();
  // deleted copy constructor and assignment to prevent unadvertent copy
  ParticleReco           ( const ParticleReco& x ) = delete;
  ParticleReco& operator=( const ParticleReco& x ) = delete;

  // destructor
  ~ParticleReco() override;

  // particle type
 ParticleType p;
  // particle energy
  double totenergy;
  // particle mass
  double invmass;

};

#endif

