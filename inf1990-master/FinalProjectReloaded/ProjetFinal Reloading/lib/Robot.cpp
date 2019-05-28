/********************************************

Andrei Catana

Methods for managing robot's behaviour (movement, playing sound, 
LED lighting)

*******************************************/



#include "Robot.h"



using namespace std;
//Position posLeft = Left;
//Position posRight = Right;


Robot::Robot(): engineL_(Left), engineR_(Right) {}

//destructeur
Robot::~Robot(){}


/**********************************************************************************************************/
//Fonction qui permet de faire avancer le robot en utilisant la direction et l'ajustement de la vitesse


void GestionMoteur::avancer(uint8_t vitesse)
{
	moteurD.setDirection(0);
	moteurG.setDirection(0);
	moteurD.demarrer(255-vitesse+20);
	moteurG.demarrer(255-vitesse+20);

}


/***********************************************************************************************************************************/
// Fonction qui permet de faire reculer le robot en fonction d'une vitesse, en utilisant la direction et lajustement de la vitesse

void GestionMoteur::reculer(uint8_t vitesse)
{
	moteurD.setDirection(1);
	moteurG.setDirection(1);
	moteurD.demarrer(255-(vitesse*100/100)+20);
	moteurG.demarrer(255-(vitesse*100/100)+20);
}



/***********************************************************************************************************************************/
// Fonction qui permet de faire arreter le robot

void GestionMoteur::arreter()
{
	PORTD=0x00;
	moteurD.arreterMoteur();
	moteurG.arreterMoteur();
}




/***********************************************************************************************************************************/
//Fonction qui permet de faire tourner le robot vers la droite
void GestionMoteur::tournerDroite()
{
	moteurD.setDirection(1);
	moteurG.setDirection(0);
	moteurD.demarrer(255-(120*100/100)+10);
	moteurG.demarrer(255-(120*100/100)+10);
	delayLoc(100);
	arreter();
}


/***********************************************************************************************************************************/
// Fonction qui permet de faire tourner le robot vers la gauche

void GestionMoteur::tournerGauche()
{
	moteurD.setDirection(0);
	moteurG.setDirection(1);
	moteurD.demarrer(255-(120*100/100)+10);
	moteurG.demarrer(255-(120*100/100)+10);
	delayLoc(100);
	arreter();
}


/***********************************************************************************************************************************/
// Fonction qui permet d'ajuster legerement la direction du robot vers la gauche
void GestionMoteur::ajusterGauche(uint8_t vitesse)
{
	moteurD.setDirection(0);
	moteurG.setDirection(0);
	moteurD.demarrer(255-(vitesse*100/100)+20);
	delayLoc(50);
	arreter();
}



/***********************************************************************************************************************************/
// Fonction qui permet d'ajuster legerement la direction du robot vers la drotie
void GestionMoteur::ajusterDroite(uint8_t vitesse)
{
	moteurD.setDirection(0);
	moteurG.setDirection(0);
	moteurG.demarrer(255-(vitesse*100/100)+20);
	delayLoc(50);
	arreter();
}



/***********************************************************************************************************************************/
// Fonction qui permet d'ajuster la direction du robot vers la gauche lorsque celui ci est en marche arriere

void GestionMoteur::ajusterReculGauche(uint8_t vitesse)
{
	moteurD.setDirection(1);
	moteurG.setDirection(1);
	moteurD.demarrer(255-(vitesse*100/100)+20);
	delayLoc(50);
	arreter();
}



/***********************************************************************************************************************************/
// Fonction qui permet d'ajuster la direction du robot vers la droite lorsque celui ci est en marche arriere

void GestionMoteur::ajusterReculDroite(uint8_t vitesse)
{
	moteurD.setDirection(1);
	moteurG.setDirection(1);
	moteurG.demarrer(255-(vitesse*100/100)+20);
	delayLoc(50);
	arreter();
}




/***********************************************************************************************************************************/
// Fonction qui permet de faire tourner le robot sur la gauche tant que le moteur est en marche

void GestionMoteur::ajusterGaucheFn(uint8_t vitesse)
{
	moteurD.setDirection(0);
	moteurG.setDirection(0);
	moteurD.demarrer(255-(vitesse*100/100)+20);

}



/***********************************************************************************************************************************/
// Fonctrion qui permet de faire tourner le robot sur la droite tant que le moteur est en marche

void GestionMoteur::ajusterDroiteFn(uint8_t vitesse)
{
	moteurD.setDirection(0);
	moteurG.setDirection(0);
	moteurG.demarrer(255-(vitesse*100/100)+20);

}

/***  END GestionMoteur ***/
