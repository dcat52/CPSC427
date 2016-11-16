#include "Anvil.h"
#include "Moveable.h"
#include "Controller.h"

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
	this->iTimeBetweenMovements = BALLOON_MOVE_WAIT_TIME;
	this->anvilPopTime = 0;
}

Anvil::~Anvil(void)
{
}

//returns true if its time to delete this anvil
bool Anvil::draw(std::vector<std::string> &myScreenVector) {			//pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	
	bool bDeleteMe = false;
	col = this->col;
	iTimeSinceAnvilCreation++;
	switch (col) {
	/*case COSMO_POPPED:
		myScreenVector[getY() + 0].replace(getX(), BALLOON_WIDTH, "       ");
		myScreenVector[getY() + 1].replace(getX(), BALLOON_WIDTH, "    |  ");
		myScreenVector[getY() + 2].replace(getX(), BALLOON_WIDTH, "  \\   /");
		myScreenVector[getY() + 3].replace(getX(), BALLOON_WIDTH, " - pop-");
		myScreenVector[getY() + 4].replace(getX(), BALLOON_WIDTH, "  /   \\");
		myScreenVector[getY() + 5].replace(getX(), BALLOON_WIDTH, "    |  ");
		myScreenVector[getY() + 6].replace(getX(), BALLOON_WIDTH, "       ");

		if (anvilPopTime == 0) {
			anvilPopTime = iTimeSinceCreation;
		}
		if (iTimeSinceCreation - anvilPopTime >= BALLOON_POP_DISPLAY) {
			bDeleteMe = true;
		}
		break;*/

	case BALLOON_CLOBBERED_COSMO:
		myScreenVector[getY() + 0].replace(getX(), BALLOON_WIDTH, "OUCH");
		myScreenVector[getY() + 1].replace(getX(), BALLOON_WIDTH, "OUCH");
		myScreenVector[getY() + 2].replace(getX(), BALLOON_WIDTH, "OUCH");
		myScreenVector[getY() + 3].replace(getX(), BALLOON_WIDTH, "OUCH");

		if (anvilPopTime == 0) {
			anvilPopTime = iTimeSinceAnvilCreation;
		}
		if (iTimeSinceAnvilCreation - anvilPopTime >= ANVIL_DISPLAY_TIME) {
			bDeleteMe = true;
		}
		break;

	case NO:

		if (getY() + BALLOON_HEIGHT + spd < myScreenBufferSize.y)
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
			bDeleteMe = true;
		}

		myScreenVector[getY() + 0].replace(getX(), BALLOON_WIDTH, "    --- "    );
		myScreenVector[getY() + 1].replace(getX(), BALLOON_WIDTH, "   /__/\\"   );
		myScreenVector[getY() + 2].replace(getX(), BALLOON_WIDTH, "  /   \\ \\" );
		myScreenVector[getY() + 3].replace(getX(), BALLOON_WIDTH, " /     \\ \\");
		myScreenVector[getY() + 4].replace(getX(), BALLOON_WIDTH, "/_______\\/ ");

		break;
	}

	return bDeleteMe;
}