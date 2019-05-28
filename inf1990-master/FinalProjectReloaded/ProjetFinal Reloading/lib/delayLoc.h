
#ifndef DELAY_LOC_H
#define DELAY_LOC_H

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

void delayLoc(double temps){ 

	for(int i = 0 ; i<=temps  ; i++) {
		_delay_ms(1) ;
	}
	
}

#endif



