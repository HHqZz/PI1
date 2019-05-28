/* 

Andrei Catana

definition class PWM
*/

#ifndef PWM_H
#define PWM_H

#define F_CPU 8000000
#include <avr/io.h>

using namespace std;

enum OCR { A,B };

class PWM
{
	public:
		
		PWM(OCR port);
		PWM(OCR port, uint8_t speed);
		void initialisationPwm();
		
		void startPwm();
		void stopPwm();
		
		void setSpeed(uint8_t speed);		
	 	
	private:
	
		OCR port_;
		
	
};
#endif
