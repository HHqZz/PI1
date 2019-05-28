
/********************************************
* Titre: implementation del.cpp
* Date: 17 mars 2017
* Auteur:equipe 4446
* Constantin Bouis
* Andrei Catana
* Timothee Laborde
* Anis Redjdal

*******************************************/

#include "del.h"



	Del::Del(){};
	
	Del::~Del(){};


		//porte B en sortie
		//branchement sur les pins 1 et 2

	void Del::allumerRouge(double duree){
				
		PORTB=0x01;
		delayLoc(duree);

		}

	void Del::allumerVert(double duree){
		PORTB=0x02;
		delayLoc(duree);

		}
		
	void Del::allumerAmbre(double duree){
		
		for(int i=0;i<=duree;i++){

			PORTB=0x01; 		
		        delayLoc(1); //Melange de rouge et vert pour creer la couleur Ambre
			PORTB=0x02;
			delayLoc(1); 
		}
		}      
	
	void Del::decroitreCouleur(double duree){

		
		for(int i=0; i<duree;i++){

			int a=0;				      
			while (a < 1700){ 					

				for (int i=0; i<a;i++){
					_delay_us(1);   
					PORTB=0x00;
				}
	               		for(int j=1700; j>a; j--){
					_delay_us(1);
					PORTB=0x01; 							}
					a++; 
				}
			}
		}

	void Del::clignoterDel(double duree){
		
		for(int i=0; i<=duree; i++){

			PORTB=0x02 ;
			delayLoc(250) ;
			PORTB=0x00 ; 
			delayLoc(250) ; 
			}
		}		
		



