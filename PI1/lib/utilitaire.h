/* TP8, inf1995

Constantin Bouis
Andrei Catana
Timothee Laborde
Anis Redjdal

programme contenant diverses fonctions utiles mais sans attachements à une classe
*/

#ifndef UTILITAIRE_H
#define UTILITAIRE_H
#define F_CPU 8000000

#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "del.h"
#include <avr/io.h>
#include <string.h>
#include "Son.h"
#include "PwmSon.h"
#include "moteur.h"
#include "GestionMoteur.h"
#include "global.h"



using namespace std;

GestionMoteur leMoteur = GestionMoteur();
Son son(0);
uint8_t compteur = 0;
uint8_t nrBarres = 3; 
uint8_t compteurBarresLongues = 0;
uint8_t nrBarresLongues;
bool noir = false;
Del del1();


/****************************************************************************************/
// Fonction qui permet d'utiliser une variable pour la fonction delay_ + ajoute de la precision a la
//fonction delay_ms classique

void delay(double temps){

	for(int i = 0 ; i<=temps  ; i++) {
		_delay_ms(1) ;
	}

}

/***********************************  sonnerFn  *****************************************/
// Fonction pour emmetre un son, prends en paramettre la frequence et le delay

void sonner(uint8_t freq, uint8_t duree){

		son.setFrequence(freq);
		son.startSon();
		delay(duree);
		son.stopSon();
}


/****************************************************************************************/
//fonction qui retourne vrai si le bouton est appuyé, avec la vérification de rebond


bool isPressed()
{



	if(PIND & 0x04)
	{
		_delay_ms(10);

			if(PIND & 0x04)
			{
			return true;
			}
			else
			{
			return false;
			}
	}
	else
	{
	return false;
	}
}

/*************fonction qui reutrne le resultat de l'operation et logique (&) *************/

uint8_t masqueFn(uint8_t pin, uint8_t discrim){

	uint8_t temp1=0, temp2=1;

	while (temp1 != temp2){

		temp1 = pin & discrim;
		delay(10);
		temp2 = pin & discrim;
	}

		return temp1;

}

/****************************************************************************************/
//fonction qui retourne vrai si la couleur est vert, avec la vérification de rebond
//bouton a droite PINA 5, bouton a gauche PINA 6,


bool choixVertFn()
{

	sonner(60,50);
	bool paisse = false;

	while(PINA & 0x20)
	{
		if(paisse == false)
		{
			if(!(PINA & 0x10))
			{
				delay(10);

					if(!(PINA & 0x10))
					{
						sonner(60,50);
						if(PORTB == 0x01){
							PORTB = 0x02;
							}
						else
							PORTB = 0x01;
					}
				paisse = true;
			}
		}

		if (PINA & 0x10)
			paisse = false;

	}

	if(PORTB == 0x01)
		return true;
	else
		return false;

}




/****************************************************************************************/
//Initialisation est utile pour linterruption et la configuration des ports
//
void  initialisation (int a , int b , int c , int d) {

		// cli est une routine qui bloque toutes les interruptions.

		// Il serait bien mauvais d'etre interrompu alors que

		// le microcontroleur n'est pas pret...

		cli ();

		// configurer et choisir les ports pour les entrees

		// et les sorties. DDRx... Initialisez bien vos variables

		DDRA = a;
		DDRB = b;
		DDRC = c;
		DDRD = d;

		// cette procédure ajuste le registre EIMSK

		// de ATmega324PA pour permettre les interruptions externes

		EIMSK |= _BV(INT0);

		// il faut sensibiliser les interruptions externes aux

		// changements de niveau du bouton-poussoir

		// en ajustant le registre EICRA

   		EICRA |=  _BV(ISC00);

		// sei permet de recevoir a nouveau des interruptions.

		sei ();

	}

/************************** tounreGaucheFn ************************************************/
//permet de tourner avec des petites frequences, donne une bonne precision

void tournerGaucheFn(uint8_t nrFois){

	for(uint8_t i=0; i < nrFois; i++){

		leMoteur.tournerGauche();
	}
}


/************************** tounreDroiteFn ************************************************/
//permet de tourner avec des petites frequences, donne une bonne precision

void tournerDroiteFn(uint8_t nrFois){

	for(uint8_t i=0; i < nrFois; i++){

		leMoteur.tournerDroite();
	}
}

/************************** avancerFn ************************************************/
//permet de tourner avec des petites frequences, donne une bonne precision

void avancerFn(uint8_t nrFois){

	for(uint8_t i=0; i < nrFois; i++){

		leMoteur.avancer(140);
		delay(100);
							   //   0001 1110
		if(PINC & 0x03)
		leMoteur.ajusterGauche(200);

		if(PINC & 0x18)
		leMoteur.ajusterDroite(200);

	}
	leMoteur.arreter();
}

/**************************  pinZeroFn  ****************************************************/
//Fonction qui renvoie True lorsque le capteurs sont a zero ///// Permet d'eviter l'antirebond

bool pinZeroFn()
{
	uint8_t masque_pin;
	masque_pin = PINC & 0x1F;
	if(masque_pin == 0)
	{
	    delay(10); // Permet de faire perdre du temps a l'AVR

		masque_pin = PINC & 0x1F;
		if( masque_pin == 0) // Permet de savoir si le signal 2 du port D est à 1.
		{
			return true;
		}
        else
            return false;

	}
        else

        return false;
}


/********************************** verifierLigne ***************************************/
/** returne true si la ligne est trouve **** false si la ligne est  inexistante  ********/

bool verifierLigneFn(){

	if(!pinZeroFn())
		return true;
								sonner(75,50);
	tournerDroiteFn(2);
	delay(400);

	if(!pinZeroFn())
		return true;
	else{
						sonner(120,50);
		tournerGaucheFn(4);

		if(!pinZeroFn())
			return true;
		else{
						delay(200);

			if(pinZeroFn())
				return false;
			else{
				leMoteur.avancer(120);
				delay(400);
				leMoteur.arreter();
				return true;
			}
		}
	}
}



/*******************************  suivreLigneFn  *****************************************/
// Fonction qui permet de suivre la ligne


void suivreLigneFn(uint8_t vitesse)
{
		bool sortir = false;
		uint8_t masque_no;

		while(sortir == false){

			leMoteur.avancer(vitesse);

 			masque_no = masqueFn(PINC, 0x1E);
			if(masque_no != 0x1E){
				if(PINC & 0x03)
				leMoteur.ajusterGauche(vitesse+90);

				if(PINC & 0x18)
				leMoteur.ajusterDroite(vitesse+90);

			}

			masque_no = masqueFn(PINC, 0x1F);
			if(masque_no == 0x1F || masque_no == 0x1E || masque_no == 0x1C){
				leMoteur.avancer(150);
				delay(600);
				leMoteur.arreter();
				sortir = true;
			}

			if(masqueFn(PINC, 0x1F) == 0){
				delay(10);
				if(masqueFn(PINC, 0x1F) == 0)
					sortir = true;
			}
		}
		leMoteur.arreter();

}


/******************************* compteurFn  *******************************************/
// fonction pour compter le variations noir/blanc


bool compteurFn(){


		uint8_t masque_n = masqueFn(PINC, 0x1F);

		if(masque_n == 0x1F || masque_n == 0x1E || masque_n == 0x0F)
			noir = true;

		if(noir){

			if(masqueFn(PINC, 0x11) == 0x00 || masqueFn(PINC, 0x10) == 0x00){
				sonner(75,50);
				noir = false;
				return true;
			}
			else
				return false;
		}
		else
			return false;

}

/******************************* compteuPointillesFn  *******************************************/
// fonction pour compter le variations noir/blanc


bool compteurPointillesFn(){


		if(masqueFn(PINC, 0x1F) == 0)
			noir = true;

		if(noir){

			if(masqueFn(PINC, 0x1F)){

				noir = false;
				return true;
			}
			else
				return false;
		}
		else
			return false;

}


/******************************* compteurFn  *******************************************/
// fonction pour compter le variations noir/blanc


bool compteurBarresLonguesFn(){


		uint8_t masque_n = masqueFn(PINC, 0x18);

		if(masque_n == 0x18 )
			noir = true;

		if(noir){

			if(masqueFn(PINC, 0x18) == 0x00){
				sonner(75,50);
				noir = false;
				return true;
			}
			else
				return false;
		}
		else
			return false;

}
/*******************************   suivreLigneSt1Fn  *************************************/
// suivre ligne pour le stationnement 2 (compteur = 6)
void suivreLigneSt1Fn(uint8_t vitesse)
	{

		leMoteur.avancer(vitesse);
							   //   0001 1110
		if(PINC & 0x03)
		leMoteur.ajusterGauche(vitesse+60);

		if(PINC & 0x18)
		leMoteur.ajusterDroite(vitesse+60);

	}

/*******************************   suivreLignePointillesFn  *************************************/
// suivre ligne pour le stationnement 2 (compteur = 6)
void suivreLignePointillesFn(uint8_t vitesse)
	{
		leMoteur.avancer(vitesse);
		if(PINC & 0x03)
		leMoteur.ajusterGauche(vitesse+60);

		if(PINC & 0x18)
		leMoteur.ajusterDroite(vitesse+60);

		if(!(PINC & 0x1F)){

		leMoteur.avancer(vitesse);
		delay(100);
		}


	}

/****************************************************************************************/
/****************************************************************************************/
/******************************* compteurFn540  *******************************************/
// fonction pour compter le variations noir/blanc

bool compteurFn540(){
		

		uint8_t masque_n = masqueFn(PINC, 0x01);
		
		if(masque_n == 0x01)
			noir = true;

		if(noir){
		
			if(masqueFn(PINC, 0x01) == 0x00){// capter trois variations noir/blanc
				sonner(75,30);
				noir = false;
				return true;
			}
			else
				return false;
		}
		else
			return false;
}

#endif
