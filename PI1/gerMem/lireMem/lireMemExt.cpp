#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "memoire24.h"
#include "fonctionsUSART.h"


int main(){

	initialisationUSART();

	Memoire24CXXX memoire;

	
	uint8_t taille[2];
	memoire.lecture(0,&taille[0]);
	memoire.lecture(1,&taille[1]);
	
	uint16_t size_bytes;
	size_bytes=taille[0]<<8;
	size_bytes+=taille[1];
	

	for (uint8_t i=0; i < size_bytes; i++ ) {
		// memoire.lecture(i,&(data[i]));
		uint8_t datum;
		memoire.lecture(i, &datum);
		_delay_ms(5);
		transmissionUSART(datum);

	}



	return 0;

}
