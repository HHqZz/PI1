/* 

Andrei Catana

Implementation of class Engine
*/


#include "Engine.h"  
using namespace std;

Engine::Engine()	
					
{
	direction_= 1;				// movement direction
	position_ = Left;			
	if (position_ == Right) {
		pwm_ = PWM(A);
	} else {
		pwm_ = PWM(B);
	}
}

Engine::Engine(Position position)	
					
{
	direction_= 1;				// movement direction
	position_ = position;			
	if (position_ == Right) {
		pwm_ = PWM(A);
	} else {
		pwm_ = PWM(B);
	}
}

Engine::~Engine(){}

void Engine::start(uint8_t speed)		
{
	
	pwm_.setPwm(speed);			
	pwm_.startPwm();
}

void Engine::stop()			
{
	pwm_.stopPwm();
}


void Engine::setDirection(bool direction)	//method for choosing the rotating direction
						
{
	if (direction) {
		if (position_ == Left) {	
			PORTD &= ~_BV(PD6);		//forward for left engine
		} else { 			
			PORTD &= ~_BV(PD7);		//forward for right engine
		}				

	} else {
						
		if (position_ == Left) {
			PORTD |= _BV(PD6);		//backward for left engine
		} else {
			PORTD |= _BV(PD7);		//backward for right engine
		}
	}
}

