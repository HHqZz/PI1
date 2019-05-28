/* 
Andrei Catana
class Engine definition
*/

#ifndef ENGINE_H
#define ENGINE_H

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "PWM.h"

using namespace std;

enum Position { Left, Right };

class Engine {

	public:
	
		Engine();				//constructor by default
		Engine(Position position);		//constructor by parameter
		~Engine();				//destructor
		void start(uint8_t speed);
		void stop();
		void setDirection(bool direction);
	private:
		PWM pwm_ = PWM(A);
		bool direction_;
		Position position_;			
};
#endif
