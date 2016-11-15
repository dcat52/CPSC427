#include "Balloon.h"
#include "Moveable.h"
#include "Controller.h"

//std::vector<Moveable*> balloons;

Balloon::Balloon(sizeofScreenBuffer myScreenBufferSize,location myLoc,int iHowLongBeforeFall, SPEED spd, DIRECTION dir ):Moveable(myScreenBufferSize,myLoc,spd, dir)
{
	this->myScreenBufferSize = myScreenBufferSize;
	this->myLoc = myLoc;
	this->iHowLongBeforeFall = iHowLongBeforeFall;
	this->spd = spd;
	this->dir = dir;
}

Balloon::~Balloon(void)
{
}

//returns true if its time to delete this balloon
bool Balloon::draw(std::vector<std::string> &myScreenVector){			//pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	
	bool bDeleteMe = false;

	switch(col) {
		case COSMO_POPPED:
			myScreenVector[getY() + 0].replace(getX(), getX() + BALLOON_WIDTH, "       ");
			myScreenVector[getY() + 1].replace(getX(), getX() + BALLOON_WIDTH, "    |  ");
			myScreenVector[getY() + 2].replace(getX(), getX() + BALLOON_WIDTH, "  \\   /");
			myScreenVector[getY() + 3].replace(getX(), getX() + BALLOON_WIDTH, " - pop-");
			myScreenVector[getY() + 4].replace(getX(), getX() + BALLOON_WIDTH, "  /   \\");
			myScreenVector[getY() + 5].replace(getX(), getX() + BALLOON_WIDTH, "    |  ");
			myScreenVector[getY() + 6].replace(getX(), getX() + BALLOON_WIDTH, "       ");
			bDeleteMe = true;
			break;
			
		case BALLOON_CLOBBERED_COSMO:
			myScreenVector[getY() + 0].replace(getX(), getX() + BALLOON_WIDTH, "   *   ");
			myScreenVector[getY() + 1].replace(getX(), getX() + BALLOON_WIDTH, " *   * ");
			myScreenVector[getY() + 2].replace(getX(), getX() + BALLOON_WIDTH, "* * * *");
			myScreenVector[getY() + 3].replace(getX(), getX() + BALLOON_WIDTH, "*BOOM *");
			myScreenVector[getY() + 4].replace(getX(), getX() + BALLOON_WIDTH, "* * * *");
			myScreenVector[getY() + 5].replace(getX(), getX() + BALLOON_WIDTH, " *   * ");
			myScreenVector[getY() + 6].replace(getX(), getX() + BALLOON_WIDTH, "   *   ");
			bDeleteMe = true;
			break;
		
		case 0:
			myScreenVector[getY() + 0].replace(getX(), getX() + BALLOON_WIDTH, "  ___  ");
			myScreenVector[getY() + 1].replace(getX(), getX() + BALLOON_WIDTH, " //\\ \\ ");
			myScreenVector[getY() + 2].replace(getX(), getX() + BALLOON_WIDTH, "| \\/  |");
			myScreenVector[getY() + 3].replace(getX(), getX() + BALLOON_WIDTH, " \\   / ");
			myScreenVector[getY() + 4].replace(getX(), getX() + BALLOON_WIDTH, "  \\ /  ");
			myScreenVector[getY() + 5].replace(getX(), getX() + BALLOON_WIDTH, "   |   ");
			myScreenVector[getY() + 6].replace(getX(), getX() + BALLOON_WIDTH, "   |   ");
			break;
	}

	return bDeleteMe;
}