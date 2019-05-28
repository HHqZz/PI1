/*  inf1995

Projet final de premiere annee


Auteurs :

Andrei Catana

*/


#define F_CPU 8000000
#include <avr/io.h>
#include <PWM.cpp>
#include <PwmSound.cpp>
#include <Sound.cpp>
#include <Engine.cpp>



using namespace std;


int main()
	{


	DDRD = 0XFF; 			// PORTD output mode
	DDRB = 0xFF;			// PORTB output mode
	PORTD = 0;
		
	/********************* test Engine*******************/
	
	Engine engineLeft(Left);
	Engine engineRight(Right);
	
	engineLeft.setDirection(true);
	engineRight.setDirection(true);
	
	
		
	
	/******************** test Sound **************/
	
	Sound sound;
	sound.setBitRate(1000);
	
	uint8_t part1[] =  { 76, 12, 76, 12, 20, 12, 76, 12, 20, 12, 72, 12, 76, 12, 20, 12, 79, 12, 20, 0, 0, 0, 0, 0, 0, 67, 12, 20, 0, 0, 0, 0, 0};

	uint8_t part2[] =  { 72, 12, 20, 24, 0, 0, 0, 67, 12, 20, 24, 0, 0, 0, 64, 12, 20, 24, 0, 0, 69, 12, 20, 12, 71, 12, 20, 12, 70, 12, 69, 12, 20, 12, 67, 16, 76, 16, 79, 16, 81, 12, 20, 12, 77, 12, 79, 12, 20, 12, 76, 12, 20, 12, 72, 12, 74, 12, 71, 12, 20, 24 };

	uint8_t part3[] =  { 48, 12, 20, 12, 79, 12, 78, 12, 77, 12, 75, 12, 60, 12, 76, 12, 53, 12, 68, 12, 69, 12, 72, 12, 60, 12, 69, 12, 72, 12, 74, 12, 48, 12, 20, 12, 79, 12, 78, 12, 77, 12, 75, 12, 55, 12, 76, 12, 20, 12, 84, 12, 20, 12, 84, 12, 84, 12 };

	uint8_t part4[] =  { 55, 12, 20, 12, 48, 12, 20, 12, 79, 12, 78, 12, 77, 12, 75, 12, 60, 12, 76, 12, 53, 12, 68, 12, 69, 12, 72, 12, 60, 12, 69, 12, 72, 12, 74, 12, 48, 12, 20, 12, 75, 24, 20, 12, 0, 0, 0, 74, 24, 20, 12, 0, 0, 0, 72, 24, 20, 12, 0, 0, 55, 12, 55, 12, 20, 12, 48, 12 };

	uint8_t part5[] =  	 { 72, 12, 72, 12, 20, 12, 72, 12, 20, 12, 72, 12, 74, 12, 20, 12, 76, 12, 72, 12, 20, 12, 69, 12, 67, 12, 20, 12, 43, 12, 20, 12, 72, 12, 72, 12, 20, 12, 72, 12, 20, 12, 72, 12, 74, 12, 76, 12, 55, 12, 20, 24, 48, 12, 20, 24, 43, 12, 20, 12, 72, 12, 72, 12, 20, 12, 72, 12, 20, 12, 72, 12, 74, 12, 20, 12, 76, 12, 72, 12, 20, 12, 69, 12, 67, 12, 20, 12, 43, 12, 20, 12, 76, 12, 76, 12, 20, 12, 76, 12, 20, 12, 72, 12, 76, 12, 20, 12, 79, 12, 20, 12, 0, 0, 0, 0, 67, 12, 20, 12, 0, 0, 0, 0, };

	uint8_t part6[] = { 76, 12, 72, 12, 20, 12, 67, 12, 55, 12, 20, 12, 68, 12, 20, 12, 69, 12, 77, 12, 53, 12, 77, 12, 69, 12, 60, 12, 53, 12, 20, 12, 71, 16, 81, 16, 81, 16, 81, 16, 79, 16, 77, 16, 76, 12, 72, 12, 55, 12, 69, 12, 67, 12, 60, 12, 55, 12, 20, 12, 76, 12, 72, 12, 20, 12, 67, 12, 55, 12, 20, 12, 68, 12, 20, 12, 69, 12, 77, 12, 53, 12, 77, 12, 69, 12, 60, 12, 53, 12, 20, 12, 71, 12, 77, 12, 20, 12, 77, 12, 77, 16, 76, 16, 74, 16, 72, 12, 64, 12, 55, 12, 64, 12, 60, 12, 20, 12 };

	uint8_t part7[] =  { 72, 72, 72, 72, 72, 72, 72, 67, 67, 67, 67, 67, 67, 67, 64, 64, 64, 64, 64, 64, 64, 64, 64, 69, 69, 71, 71, 69, 69, 68, 68, 70, 70, 68, 68, 67, 67, 65, 65, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67 };
		
			
	for (int i = 0; i < 33; i++)
		sound.playBit(part1[i]);
		
	
	engineLeft.start(150);
	engineRight.start(150);
	
		
	
	for (int i = 0; i < 62; i++)
		sound.playBit(part2[i]);
	
	engineLeft.setDirection(false);
	
	
	for (int i = 0; i < 62; i++)
		sound.playBit(part2[i]);
	
	engineLeft.setDirection(true);
	engineRight.setDirection(false);
	
	
	for (int i = 0; i < 58; i++)
		sound.playBit(part3[i]);
	
	engineLeft.setDirection(false);
			
		
	for (int i = 0; i < 68; i++)
		sound.playBit(part4[i]);
	
	engineLeft.setDirection(true);
	engineRight.setDirection(true);
	
	engineLeft.start(120);
	engineRight.start(250);
		
	for (int i = 0; i < 124; i++)
		sound.playBit(part5[i]);
		
	/*for (int i = 0; i < 62; i++)
		sound.playBit(part2[i]);
	
	for (int i = 0; i < 62; i++)
		sound.playBit(part2[i]);
	
	for (int i = 0; i < 118; i++)
		sound.playBit(part6[i]);
	
	for (int i = 0; i < 118; i++)
		sound.playBit(part6[i]);
	
	for (int i = 0; i < 124; i++)
		sound.playBit(part5[i]);*/
	
	engineLeft.start(250);
	engineRight.start(120);
	
	
	for (int i = 0; i < 118; i++)
		sound.playBit(part6[i]);
	
	engineRight.setDirection(false);
	engineLeft.start(250);
	engineRight.start(250);
		
	for (int i = 0; i < 53; i++)
		sound.playBit(part7[i]);
			
	
	engineLeft.stop();
	engineRight.stop();		
			
				
			
	}                                                                                                                                                                                                                                        

