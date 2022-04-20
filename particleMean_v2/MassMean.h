#ifndef MassMean_h
#define MassMean_h

class Event;
 
class MassMean {

private:

	double min_inv_mass;
	double max_inv_mass;
	int selected_event;
	double mean, rms, massum, squaresum;

public:

	MassMean(double min_inv_mass,double max_inv_mass);
	~MassMean(); 

	//funzione per aggiungere un evento
    void add(const Event& ev);
	//funzione per calcolare mean e rms
	void compute();
	//funzione che ritorna l'evento selezionato
	int nEvents() const;
    //funzioni che ritornano i valori numerici
    double MEAN() const;           
	double RMS() const;
};






#endif 

