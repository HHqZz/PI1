/* 
definition PwmSound

Autor: Andrei Catana
date: 30.06.2017

*/


#ifndef PWMSOUND_H
#define PWMSOUND_H
#pragma once


// Output pin (Pin B3 (0:7) )

using namespace std;

	class PwmSound
	{
		public:
			PwmSound();			//Constructeur par defaut
			
			PwmSound(uint8_t speed);	//Constructeur par paramètre

			void setSpeed(uint8_t speed);	//Change la valeur du PWM
			
			void start();			//Lance le PWM

			void stop();			//Arrêtre le PWM
			
			void init();			//Initialise les registres

		private:
	};
#endif
