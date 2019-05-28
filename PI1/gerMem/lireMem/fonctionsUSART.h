/* TP8, inf1995

Constantin Bouis
Andrei Catana
Timothee Laborde
Anis Redjdal
 
programme contenant fonctions utiles pour gerer la memoire externe 
*/
#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>


void initialisationUSART ( void ) {

	UBRR0H = 0;// 2400 bauds. Nous vous donnons la valeur des deux

	UBRR0L = 0xCF;// premier registres pour vous éviter des complications


	// permettre la reception et la transmission par le UART0

	UCSR0A = _BV(UDRE0); //_BV(RXCO) | _BV(TXC0)

	UCSR0B =  _BV(RXEN0) | _BV(TXEN0);

	// Format des trames: 8 bits, 1 stop bits,none parity

	UCSR0C = _BV(UCSZ01) | _BV(UCSZ00) ;

}

void transmissionUSART ( unsigned char data ) {

  	while(!(UCSR0A & (1<<UDRE0)))   // wait for empty transmit buffer
  	;

 	 UDR0=data;  //  put data into buffer, sends the data

  	}



unsigned char receptionUSART ( void ) {

	while(!(UCSR0A & (1<<RXC0)))      // wait for data to be received 
		;

	return UDR0;  // get and return received data from buffer

}

