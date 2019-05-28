#ifndef SON_H
#define SON_H

#include <PwmSound.h>
#include <avr/io.h>
#include <util/delay.h>

using namespace std;

class Sound

{

public:
	Sound();						//Constructeur par defaut
	
	~Sound();						//Destructeur
	void setBitRate(uint16_t bitRate);
	void setFrequence(uint8_t musicNote);			//Change la note du son en changeant son PWM

	
	
	void start();						//Produit le son
	void stop();						//Arrête le son

	void playBit(uint8_t musicNote);

private:
	PwmSound pwmSound_;
	uint8_t periodTable_[69];
	uint16_t period_;					//playing time of one note in seconds
						
};

#endif
