/* TP8, inf1995

Constantin Bouis
Andrei Catana
Timothee Laborde
Anis Redjdal

programme de définition de la classe DEL
*/

#ifndef DEL_H
#define DEL_H

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "delayLoc.h"



class Del{

public:

	Del();
	
	~Del();	
	
	void allumerRouge(double duree);

	void allumerVert(double duree);
		
	void allumerAmbre(double duree);     
	
	void decroitreCouleur(double duree);
	
	void clignoterDel(double duree);

		
};
#endif
