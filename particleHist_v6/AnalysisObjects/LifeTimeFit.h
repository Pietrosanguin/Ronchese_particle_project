#ifndef LifeTimeFit_h
#define LifeTimeFit_h
#include <vector>

class Event;

class LifeTimeFit {

private:

  double min, max, minTime, maxTime, minScan, maxScan, scanStep, meanLifeTime, errorMeanLifeTime;
  std::vector<double> decaytimes;	


 public:

        LifeTimeFit( double min, double max, double minTime, double maxTime, double minScan, double maxScan, double scanStep); 
        ~LifeTimeFit();

       //funzione per aggiungere un evento
       bool add( const Event& e );   
       //funzione per calcolare fit con parabola (minimizzazione)
       void compute(); 
       //funzione che ritorna l'evento selezionato  
       unsigned int nEvents() const  ;                  
       double lifeTime();
       double lifeTimeError();

  

};
#endif

