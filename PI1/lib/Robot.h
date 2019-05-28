#ifndef ROBOT_H
#define ROBOT_H

#include "Engine.h"
#include "delayLoc.h"

class Robot
{
public:
	
   	Robot();
   
	~Robot();
	
	void moveFwd(uint8_t speed); 				
	void moveBwd(uint8_t speed);
	void stop(); 
	void turnLeft();				// turn around
	void turnRight();				// turn around
	void adjustLeft(uint8_t speed);			// turn in movement
	void adjustRight(uint8_t speed);		// turn in movement
	void adjustLeftBwd(uint8_t speed);		// turn in back movement
	void adjustRightBwd(uint8_t speed);		// turn in back movement
	
	
private:
	Engine engineL_;
	Engine engineR_;
};

#endif
