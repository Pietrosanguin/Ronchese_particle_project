#ifndef Utilities_h
#define Utilities_h

#include<cmath>

class Utilities {

public:

	Utilities();
	//elimino il costruttore di copia e assegnazione per non copiare inavvertitamente
	Utilities(const Utilities& x) = delete;
	Utilities& operator=(const Utilities& x) = delete;

	~Utilities();


   static double Energy_calc(double px, double py, double pz, double invar_mass);
   
   static double Invar_mass_calc(double px, double py, double pz, double energy);


};


#endif