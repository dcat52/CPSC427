#include "Balloon.h"
#include "Moveable.h"
#include "Controller.h"

Balloon::Balloon(sizeofScreenBuffer myScreenBufferSize,location myLoc,int iHowLongBeforeFall, SPEED spd, DIRECTION dir ):Moveable(myScreenBufferSize,myLoc,spd, dir)
{
	this->myScreenBufferSize = myScreenBufferSize;
	this->myLoc = myLoc;
	this->iHowLongBeforeFall = iHowLongBeforeFall;
	this->spd = spd;
	this->dir = dir;
	this->col = NO;
	this->iTimeSinceCreation = 0;
	this->iLastMoveTime = 0;
	this->iTimeBetweenMovements = BALLOON_MOVE_WAIT_TIME;
	this->balloonPopTime = 0;
}

Balloon::~Balloon(void)
{
}

//returns true if its time to delete this balloon
bool Balloon::draw(std::vector<std::string> &myScreenVector){ //pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	
	bool bDeleteMe = false;
	col = this->col;
	iTimeSinceCreation++;
	switch(col) {
		case COSMO_POPPED:
			myScreenVector[getY() + 0].replace(getX(), BALLOON_WIDTH, "       ");
			myScreenVector[getY() + 1].replace(getX(), BALLOON_WIDTH, "    |  ");
			myScreenVector[getY() + 2].replace(getX(), BALLOON_WIDTH, "  \\   /");
			myScreenVector[getY() + 3].replace(getX(), BALLOON_WIDTH, " - pop-");
			myScreenVector[getY() + 4].replace(getX(), BALLOON_WIDTH, "  /   \\");
			myScreenVector[getY() + 5].replace(getX(), BALLOON_WIDTH, "    |  ");
			myScreenVector[getY() + 6].replace(getX(), BALLOON_WIDTH, "       ");

			if (balloonPopTime == 0) {
				balloonPopTime = iTimeSinceCreation;
			}
			if (iTimeSinceCreation - balloonPopTime >= BALLOON_POP_DISPLAY) {
				bDeleteMe = true;
			}
			break;
			
		case BALLOON_CLOBBERED_COSMO:
			myScreenVector[getY() + 0].replace(getX(), BALLOON_WIDTH, "   *   ");
			myScreenVector[getY() + 1].replace(getX(), BALLOON_WIDTH, " *   * ");
			myScreenVector[getY() + 2].replace(getX(), BALLOON_WIDTH, "* * * *");
			myScreenVector[getY() + 3].replace(getX(), BALLOON_WIDTH, "*BOOM *");
			myScreenVector[getY() + 4].replace(getX(), BALLOON_WIDTH, "* * * *");
			myScreenVector[getY() + 5].replace(getX(), BALLOON_WIDTH, " *   * ");
			myScreenVector[getY() + 6].replace(getX(), BALLOON_WIDTH, "   *   ");

			if (balloonPopTime == 0) {
				balloonPopTime = iTimeSinceCreation;
			}
			if (iTimeSinceCreation - balloonPopTime >= BALLOON_POP_DISPLAY) {
				bDeleteMe = true;
			}
			break;
		
		case NO:
			
			if (getY() + BALLOON_HEIGHT + spd < myScreenBufferSize.y)
			{
				if (iHowLongBeforeFall <= iTimeSinceCreation  && iTimeBetweenMovements <= iTimeSinceCreation - iLastMoveTime)
				{
					iLastMoveTime = iTimeSinceCreation;
					setY(getY() + spd);
					setLocation(myLoc);
				}
			}
			else
			{
				bDeleteMe = true;
			}

			myScreenVector[getY() + 0].replace(getX(), BALLOON_WIDTH, "  ___  ");
			myScreenVector[getY() + 1].replace(getX(), BALLOON_WIDTH, " //\\ \\ ");
			myScreenVector[getY() + 2].replace(getX(), BALLOON_WIDTH, "| \\/  |");
			myScreenVector[getY() + 3].replace(getX(), BALLOON_WIDTH, " \\   / ");
			myScreenVector[getY() + 4].replace(getX(), BALLOON_WIDTH, "  \\ /  ");
			myScreenVector[getY() + 5].replace(getX(), BALLOON_WIDTH,  "   |   ");
			myScreenVector[getY() + 6].replace(getX(), BALLOON_WIDTH,  "   |   ");

			break;
	}

	return bDeleteMe;
}