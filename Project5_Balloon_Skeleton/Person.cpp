#include "Person.h"

Person::Person(sizeofScreenBuffer myScreenBufferSize,location myLoc, SPEED spd, DIRECTION dir ):Moveable(myScreenBufferSize,myLoc, spd, dir),bLegChangePosition(false)
{
}


Person::~Person(void)
{
}

//always return false since person never deleted
bool Person::draw(std::vector<std::string> &myScreenVector){			//pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	

	bLegChangePosition = !bLegChangePosition;
	
	switch(dir){
	case LEFT:
		if (myLoc.x - spd > 0)
		{
			myLoc.x = myLoc.x - spd;
		}
		myScreenVector[getY() + 0].replace(getX(), PERSON_WIDTH+spd, "   \\\\\\\\|//// ");
		myScreenVector[getY() + 1].replace(getX(), PERSON_WIDTH + spd,  "    |~ ////  ");
		myScreenVector[getY() + 2].replace(getX(), PERSON_WIDTH + spd,  "    |O  //   ");
		myScreenVector[getY() + 3].replace(getX(), PERSON_WIDTH + spd,  "   <    |    ");
		myScreenVector[getY() + 4].replace(getX(), PERSON_WIDTH + spd,  "    |_/ |    ");
		myScreenVector[getY() + 5].replace(getX(), PERSON_WIDTH + spd,  "--o |__/      ");
		myScreenVector[getY() + 6].replace(getX(), PERSON_WIDTH + spd, "   \\__|      ");
		myScreenVector[getY() + 7].replace(getX(), PERSON_WIDTH + spd,  "      |      ");
		if (bLegChangePosition)
		{
			myScreenVector[getY() + 8].replace(getX(), PERSON_WIDTH + spd, "     /|      ");
			myScreenVector[getY() + 9].replace(getX(), PERSON_WIDTH + spd, "   \\/_|      ");
		}
		else
		{
			myScreenVector[getY() + 8].replace(getX(), PERSON_WIDTH + spd, "      |      ");
			myScreenVector[getY() + 9].replace(getX(), PERSON_WIDTH + spd, "    \\||      ");
		}
		break;

	case RIGHT:
		if (myLoc.x + spd < myScreenBufferSize.x - 14)
		{
			myLoc.x = myLoc.x + spd;
		}
		myScreenVector[getY() + 0].replace(getX(), PERSON_WIDTH, " \\\\\\\\|////   ");
		myScreenVector[getY() + 1].replace(getX(), PERSON_WIDTH,  "  \\\\\\\\ ~|    ");
		myScreenVector[getY() + 2].replace(getX(), PERSON_WIDTH,    "   \\\\  O|    ");
		myScreenVector[getY() + 3].replace(getX(), PERSON_WIDTH,      "    |    >   ");
		myScreenVector[getY() + 4].replace(getX(), PERSON_WIDTH,     "    | \\_|    ");
		myScreenVector[getY() + 5].replace(getX(), PERSON_WIDTH,     "     \\__| o--");
		myScreenVector[getY() + 6].replace(getX(), PERSON_WIDTH,      "      |__/   ");
		myScreenVector[getY() + 7].replace(getX(), PERSON_WIDTH,      "      |      ");
		if (bLegChangePosition)
		{
			myScreenVector[getY() + 8].replace(getX(), PERSON_WIDTH, "      |\\     ");
			myScreenVector[getY() + 9].replace(getX(), PERSON_WIDTH, "      |_\\/    ");
		}
		else
		{
			myScreenVector[getY() + 8].replace(getX(), PERSON_WIDTH, "      |     ");
			myScreenVector[getY() + 9].replace(getX(), PERSON_WIDTH, "      ||/    ");
		}
		break;

	case UP:
		myScreenVector[getY() + 0].replace(getX(), PERSON_WIDTH, " \\\\\\\\\\|///// ");
		myScreenVector[getY() + 1].replace(getX(), PERSON_WIDTH,    "  \\\\|\\ /|//  ");
		myScreenVector[getY() + 2].replace(getX(), PERSON_WIDTH,     "   \\|O O|/   ");
		myScreenVector[getY() + 3].replace(getX(), PERSON_WIDTH,      "    | ^ |    ");
		myScreenVector[getY() + 4].replace(getX(), PERSON_WIDTH,     " \\  | - |  / ");
		myScreenVector[getY() + 5].replace(getX(), PERSON_WIDTH,      "  o |___| o  ");
		myScreenVector[getY() + 6].replace(getX(), PERSON_WIDTH,     "   \\__|__/   ");
		myScreenVector[getY() + 7].replace(getX(), PERSON_WIDTH,      "      |     ");
		myScreenVector[getY() + 8].replace(getX(), PERSON_WIDTH,      "      |     ");
		myScreenVector[getY() + 9].replace(getX(), PERSON_WIDTH,      "     _|_     ");
		break;

	case DOWN:
	case NO_DIR:
		myScreenVector[getY() + 0].replace(getX(), PERSON_WIDTH, " \\\\\\\\\\|///// ");
		myScreenVector[getY() + 1].replace(getX(), PERSON_WIDTH,    "  \\\\|~ ~|//  ");
		myScreenVector[getY() + 2].replace(getX(), PERSON_WIDTH,     "   \\|O O|/   ");
		myScreenVector[getY() + 3].replace(getX(), PERSON_WIDTH,      "    | ^ |    ");
		myScreenVector[getY() + 4].replace(getX(), PERSON_WIDTH,      "    | v |    ");
		myScreenVector[getY() + 5].replace(getX(), PERSON_WIDTH,      "    |___|    ");
		myScreenVector[getY() + 6].replace(getX(), PERSON_WIDTH,      "    __|__    ");
		myScreenVector[getY() + 7].replace(getX(), PERSON_WIDTH,     "    \\ | /    ");
		myScreenVector[getY() + 8].replace(getX(), PERSON_WIDTH,      "     0|0     ");
		myScreenVector[getY() + 9].replace(getX(), PERSON_WIDTH,      "     _|_     ");
		break;

	}

	return false;
}
