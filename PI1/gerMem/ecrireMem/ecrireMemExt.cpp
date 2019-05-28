/********************************************
 * Titre: implementation fonction ecrireMemExt
 * Date: 17 mars 2017
 * Auteur:equipe 4446
 * Constantin Bouis
 * Andrei Catana
 * Timothee Laborde
 * Anis Redjdal
 *******************************************/


#ifndef ECRIREMEMEXT_CPP
#define ECRIREMEMEXT_CPP
#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "memoire24.h"
#include "fonctionsUSART.h"


int main(){

	DDRA=0xFF;

	initialisationUSART();

	Memoire24CXXX memoire= Memoire24CXXX();
	
	for(int i=0;i<2;i++){

		memoire.ecriture(i,receptionUSART()); 
 		_delay_ms(5);					      
	}
	
	uint8_t taille[2];
	memoire.lecture(0,&taille[0]);
	memoire.lecture(1,&taille[1]);
	
	uint16_t size_bytes;
	size_bytes=taille[0]<<8;
	size_bytes+=taille[1];
	

	for (uint8_t i=2; i < size_bytes; i++ ) {  


		while ( !(UCSR0A & (1<<RXC0)) ) {
			PORTA = 0x1;
		}

		memoire.ecriture(i,receptionUSART());
		_delay_ms(5);

	} 
	

}
#endif
