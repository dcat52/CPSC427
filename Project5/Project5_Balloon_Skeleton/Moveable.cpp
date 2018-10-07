#include "Moveable.h"


Moveable::Moveable(sizeofScreenBuffer myScreenBufferSize,location myLoc, SPEED spd, DIRECTION dir, int pointsIfMoveableWins, int pointsIfCosmoWins ):myScreenBufferSize(myScreenBufferSize),myLoc(myLoc),spd(spd)
{
}
//sets the dirction of the object UP, DOWN, LEFT, RIGHT or NO (does not have a direction)
void Moveable::setDirection(DIRECTION dir){
	this->dir = dir;
}
//sets the speed of how fast or slow the object will be moving
void Moveable::setSpeed(SPEED spd){
	this->spd = spd;
}
Moveable::~Moveable(void){

}

void Moveable::setCollidedState(COLLISION col)
{
	if(col!=NO)
		setCollidable(false);
	this->col = col;
}


