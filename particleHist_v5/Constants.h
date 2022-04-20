#ifndef Constants_h
#define Constants_h

class Constants{
	public:
	
	Constants();
	// deleted copy constructor and assignment to prevent unadvertent copy
	Constants           ( const Constants& x ) = delete;
	Constants& operator=( const Constants& x ) = delete;
	
	~Constants();
	
	static constexpr double massPion    = 0.1395706;   // GeV/c^2
	static constexpr double massProton  = 0.938272;    // GeV/c^2
	static constexpr double massK0      = 0.497611;    // GeV/c^2
	static constexpr double massLambda0 = 1.115683;    // GeV/c^2
	static constexpr double lightVelocity = 0.029979246;    // cm/s
};
#endif