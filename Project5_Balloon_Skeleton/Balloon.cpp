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

	/*switch(Controller.hasCollidedWithCosmo()) {
	case COSMO_POPPED:
			"       ");
			"    |  ");
			"  \\   /");
			" - pop-");
			"  /   \\");
			"    |  ");
			"       ");
			bDeleteMe = true;
			break;

		
		"   *   ");
		" *   * ");
		"* * * *");
		"*BOOM *");
		"* * * *");
		" *   * ");
		"   *   ");
		
		

		
		"  ___  ");
		" //\\ \\ ");
		"| \\/  |");
		" \\   / ");
		"  \\ /  ");
		"   |   ");
		"   |   ");
		
	}*/

	return bDeleteMe;
}