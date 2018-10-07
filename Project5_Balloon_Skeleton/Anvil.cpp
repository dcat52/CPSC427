#pragma once
#include "Anvil.h"
#include "Moveable.h"
#include "Controller.h"

//constructor for ANVIL
Anvil::Anvil(sizeofScreenBuffer myScreenBufferSize, location myLoc, int iHowLongBeforeFall, SPEED spd, DIRECTION dir) :Moveable(myScreenBufferSize, myLoc, spd, dir)
{
	this->myScreenBufferSize = myScreenBufferSize;
	this->myLoc = myLoc;
	this->iHowLongBeforeFall = iHowLongBeforeFall;
	this->spd = spd;
	this->dir = dir;
	this->col = NO;
	this->iTimeSinceAnvilCreation = 0;
	this->iLastMoveTime = 0;
	this->iTimeBetweenMovements = ANVIL_MOVE_WAIT_TIME;
	this->anvilOuchTime = 0;
	this->type = ANVIL;
	this->setCollidable(true);
}

Anvil::~Anvil(void)
{
}

//returns true if its time to delete this anvil
bool Anvil::draw(std::vector<std::string> &myScreenVector) {			//pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	
	bool aDeleteMe = false;
	col = this->col;
	iTimeSinceAnvilCreation++;
	switch (col) {

		//if ANVIL collides with cosmo then...
	case ANVIL_SMASH:
		myScreenVector[getY() + 0].replace(getX(), 5, "OUCH!");
		myScreenVector[getY() + 1].replace(getX(), 5, "OUCH!");
		myScreenVector[getY() + 2].replace(getX(), 5, "OUCH!");
		myScreenVector[getY() + 3].replace(getX(), 5, "OUCH!");

		this->setCollidable(false);
		if (anvilOuchTime == 0) {
			anvilOuchTime = iTimeSinceAnvilCreation;
		}
		if (iTimeSinceAnvilCreation - anvilOuchTime >= ANVIL_OUCH_DISPLAY) {
			aDeleteMe = true;
		}
		break;

		//if ANVIL does not smash cosmo then it will keep falling and be removed from the polymorphic vector
	case NO:

		if (getY() + ANVIL_HEIGHT + spd < myScreenBufferSize.y)
		{
			if (iHowLongBeforeFall <= iTimeSinceAnvilCreation  && iTimeBetweenMovements <= iTimeSinceAnvilCreation - iLastMoveTime)
			{
				iLastMoveTime = iTimeSinceAnvilCreation;
				setY(getY() + spd);
				setLocation(myLoc);
			}
		}
		else
		{
			aDeleteMe = true;
		}

		//what the anvil looks likes when it's fall but not smashing cosmo
		myScreenVector[getY() + 0].replace(getX(), ANVIL_WIDTH, "    __     ");
		myScreenVector[getY() + 1].replace(getX(), ANVIL_WIDTH, "   /__/\\   ");
		myScreenVector[getY() + 2].replace(getX(), ANVIL_WIDTH, "  /   \\ \\  ");
		myScreenVector[getY() + 3].replace(getX(), ANVIL_WIDTH, " /     \\ \\ ");
		myScreenVector[getY() + 4].replace(getX(), ANVIL_WIDTH, "/_______\\/ ");

		break;
	}

	return aDeleteMe;
}