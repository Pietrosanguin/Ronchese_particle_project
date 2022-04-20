#ifndef LifeTimeFit_h
#define LifeTimeFit_h

class Event;

class LifeTimeFit {

private:

  double min_inv_mass, max_inv_mass;
  unsigned int selected_event;


public:

       LifeTimeFit( double min, double max ); // mass range
       ~LifeTimeFit();
       
       //funzione per aggiungere un evento
       bool add( const Event& e );   
       //funzione per calcolare mean e rms
       void compute(); 
       //funzione che ritorna l'evento selezionato  
       unsigned int nEvents() const  ;   
    


};
#endif

