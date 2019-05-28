/*

Andrei Catana

implementation PWM

*/

#define F_CPU 8000000
#include "PWM.h"



PWM::PWM(OCR port)					// parameter Constructor
{
	port_ = port;
	initialisationPwm();
};

PWM::PWM(OCR port, uint8_t speed)
{
	unPort_ = port;
	initialisationPwm();
	setSpeed(speed);
};

void PWM::initialisationPwm()	
{				

    	TCCR1A = 0;					// reset register to 0
	TCCR1B = 0;					// reset register to 0
	
	TCNT1 = 0; 					// initialise timer1 to 0
	
	TCCR1A |= _BV(WGM10) ;			
	TCCR1B |= _BV(WGM12);				// set mode Fast PWM 8-bit
	
	TCCR1B |= _BV(CS10);				// clock select 1(no prescaling)
};

void PWM::startPwm()		
{

	switch(port_)
	 {
		case A:			
			TCCR1A |= _BV(COM1A1);		// Clear OCnA on Compare Match, set OCnA/OCnB at BOTTOM (non-inverting mode)
							
			break;
		case B:			
			TCCR1A |= _BV(COM1B1);		// Clear OCnB on Compare Match, set OCnA/OCnB at BOTTOM (non-inverting mode)
							
			break;
	 }
};


void PWM::stopPwm() 		
{

	switch(port_) 
	{
	
		case A:			
			TCCR1A &= ~_BV(COM1A1);  
			break;
			
		case B:			
			TCCR1A &= ~_BV(COM1B1);
			break;
	}
};

void PWM::setPwm(uint8_t speed)		
{
	switch(unPort_) 
	{
	
		case A:			
			OCR1A = speed;
			break;
			
		case B:			
			OCR1B = speed;
			break;
			
	}
};

