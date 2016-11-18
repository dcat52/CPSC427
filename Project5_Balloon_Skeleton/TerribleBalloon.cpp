#pragma once
#include "TerribleBalloon.h"
#include "Balloon.h"
#include "Moveable.h"
#include "Controller.h"

//constructor for terrible balloon
TerribleBalloon::TerribleBalloon(sizeofScreenBuffer myScreenBufferSize, location myLoc, int iHowLongBeforeFall, SPEED spd, DIRECTION dir) :Balloon(myScreenBufferSize, myLoc, iHowLongBeforeFall, spd, dir)
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
	this->type = TERRIBLE_BALLOON;
	this->setCollidable(true);
	this->bState = IS_BALLOON;
	this->dirInt = 3;
}

TerribleBalloon::~TerribleBalloon(void)
{
}

//returns true if its time to delete this balloon
bool TerribleBalloon::draw(std::vector<std::string> &myScreenVector) { //pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	
	bool bDeleteMe = false;

	iTimeSinceCreation++;
	if (bState == IS_BALLOON) {
		switch (col) {
			//if TERRIBLEBALLOON is popped by cosmo or it clobbers cosmo then...
		case COSMO_POPPED:
		case BALLOON_CLOBBERED_COSMO:
			myScreenVector[getY() + 0].replace(getX(), BALLOON_WIDTH, "  *  * ");
			myScreenVector[getY() + 1].replace(getX(), BALLOON_WIDTH, "*Bz Bz*");
			myScreenVector[getY() + 2].replace(getX(), BALLOON_WIDTH, " \\ % //");
			myScreenVector[getY() + 3].replace(getX(), BALLOON_WIDTH, " Bzzz ");
			myScreenVector[getY() + 4].replace(getX(), BALLOON_WIDTH, " // % \\");
			myScreenVector[getY() + 5].replace(getX(), BALLOON_WIDTH, "*Bz Bz*");
			myScreenVector[getY() + 6].replace(getX(), BALLOON_WIDTH, "  *  * ");

			this->setCollidable(false);
			if (balloonPopTime == 0) {
				balloonPopTime = iTimeSinceCreation;
			}
			if (iTimeSinceCreation - balloonPopTime >= BALLOON_POP_DISPLAY) {
				bState = IS_BEE;
			}
			break;

			//if not popped by cosmo or terrible ballon does not clobber cosmo then it will keep falling
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

			//what terrible balloon looks like
			myScreenVector[getY() + 0].replace(getX(), BALLOON_WIDTH, "  ___  ");
			myScreenVector[getY() + 1].replace(getX(), BALLOON_WIDTH, " //\\ \\ ");
			myScreenVector[getY() + 2].replace(getX(), BALLOON_WIDTH, "| \\/TB|");
			myScreenVector[getY() + 3].replace(getX(), BALLOON_WIDTH, " \\TB / ");
			myScreenVector[getY() + 4].replace(getX(), BALLOON_WIDTH, "  \\ /  ");
			myScreenVector[getY() + 5].replace(getX(), BALLOON_WIDTH, "   |   ");
			myScreenVector[getY() + 6].replace(getX(), BALLOON_WIDTH, "   |   ");

			break;
		}
	}
	else {
		int change = rand() % 3;
		if(!change)
			dirInt = rand() % 4 + 1;
		switch (dirInt) {
		case UP:
			//draw bee going up
			myScreenVector[getY() + 0].replace(getX(), BEE_WIDTH, "  %  ");
			myScreenVector[getY() + 1].replace(getX(), BEE_WIDTH, " =O= ");
			myScreenVector[getY() + 2].replace(getX(), BEE_WIDTH, "  |  ");

			setY(getY() - 1);
			if (getY() < 0)
				bDeleteMe = true;
			break;

		case DOWN:
			//draw bee going down
			myScreenVector[getY() + 0].replace(getX(), BEE_WIDTH, "  |  ");
			myScreenVector[getY() + 1].replace(getX(), BEE_WIDTH, " =O= ");
			myScreenVector[getY() + 2].replace(getX(), BEE_WIDTH, "  %  ");

			setY(getY() + 1);
			if (getY() + BEE_HEIGHT > myScreenBufferSize.y)
				bDeleteMe = true;
			break;
		
		case LEFT:
			//draw bee going left
			bFlapping = !bFlapping;
			if(bFlapping)
				myScreenVector[getY() + 0].replace(getX(), BEE_WIDTH, " ()) ");
			else
				myScreenVector[getY() + 0].replace(getX(), BEE_WIDTH, " ()  ");

			myScreenVector[getY() + 1].replace(getX(), BEE_WIDTH, "%000-");
			myScreenVector[getY() + 2].replace(getX(), BEE_WIDTH, "     ");

			setX(getX() - 1);
			if (getX() < 0)
				bDeleteMe = true;
			break;

		case RIGHT:
			//draw bee going right
			bFlapping = !bFlapping;
			if (bFlapping)
				myScreenVector[getY() + 0].replace(getX(), BEE_WIDTH, " (() ");
			else
				myScreenVector[getY() + 0].replace(getX(), BEE_WIDTH, "  () ");

			myScreenVector[getY() + 1].replace(getX(), BEE_WIDTH, "-000%");
			myScreenVector[getY() + 2].replace(getX(), BEE_WIDTH, "     ");

			setX(getX() + 1);
			if (getX() + BEE_WIDTH > myScreenBufferSize.x)
				bDeleteMe = true;
			break;
		}

	}

	return bDeleteMe;
}