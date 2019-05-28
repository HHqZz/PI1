/*

Andrei Catana

implementation PWMSound

*/

#define F_CPU 8000000
#include <avr/io.h>
#include "PwmSound.h"


PwmSound::PwmSound()					// parameter Constructor
{

	init();
};

PwmSound::PwmSound(uint8_t speed)
{

	init();
	setSpeed(speed);
};

void PwmSound::init()	
{				

    	TCCR0A = 0;					// reset register to 0
	TCCR0B = 0;					// reset register to 0
	
	TCNT0 = 0; 					// initialise timer0 to 0
	
	TCCR0A |= _BV(WGM01) ;				// set mode CTC
	 	
	TCCR0B |= _BV(CS02);				// clock select clk/256 from prescaler
};

void PwmSound::start()		
{
			
	TCCR0A |= _BV(COM0A0);				// Toggle OC0A on Compare Match
							
};


void PwmSound::stop() 		
{

	TCCR0A &= ~_BV(COM0A0);
	
};

void PwmSound::setSpeed(uint8_t speed)		
{
				
	OCR0A = speed;
						
			
};

