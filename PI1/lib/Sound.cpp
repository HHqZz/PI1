#ifndef F_CPU
#define F_CPU 8000000
#endif
#include "Sound.h"
#include "delayLoc.h"

using namespace std;

Sound::Sound() 
{

	uint8_t array[69] = {	252, 237, 224, 211, 119, 188, 177,  		// 69 MIDI notes from 35 to 103 
				167, 158, 149, 141, 133, 125, 118, 
				111, 105, 99, 93, 88, 83, 78, 					
				74, 70, 66, 62, 58, 55, 52,
				49, 46, 43, 41, 38, 36, 34,
				32, 30, 28, 27, 25, 24, 22,
				21, 20, 18, 17, 16, 15, 14,
				13, 13, 12, 11, 10, 10, 9,
				8, 8, 7, 7, 6, 6, 6, 
				5, 5, 4, 4, 4, 3 };

	for (int i = 0; i <= 68; i++)
	{
		periodTable_[i] = array[i];
	}

	period_ = 0;
}



Sound::~Sound() {}


void Sound::setBitRate(uint16_t bitRate)
{
	
	period_ = bitRate/60;
	period_ = 1000/period_;
	
}

void Sound::setFrequence(uint8_t musicNote) 
{	
	if (musicNote >= 35 && musicNote <= 103)
		pwmSound_.setSpeed(periodTable_[musicNote - 35]);
		
}


void Sound::start() 
{
	pwmSound_.start();
}

void Sound::stop() 
{
	pwmSound_.stop();
}


void Sound::playBit(uint8_t musicNote) 
{
	if (musicNote >= 35 && musicNote <= 103)
	{
		setFrequence(musicNote);
		start();
		delayLoc(period_);
		stop();
	}
	else
	{	
		stop();
		delayLoc(period_);
	}	
		
}




