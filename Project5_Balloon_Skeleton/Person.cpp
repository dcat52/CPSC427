#include "Person.h"

std::string blanks = "";

Person::Person(sizeofScreenBuffer myScreenBufferSize,location myLoc, SPEED spd, DIRECTION dir ):Moveable(myScreenBufferSize,myLoc, spd, dir),bLegChangePosition(false)
{
	for (int i = 1; i < spd; i++) {
		blanks += " ";
	}
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
		myScreenVector[myScreenVector.size()-10].replace(getX(), getX() + PERSON_WIDTH + spd, "   \\\\\\\\|//// " + blanks);
		myScreenVector[myScreenVector.size()-9].replace(getX(), getX() + PERSON_WIDTH + spd,  "    |~ ////  " + blanks);
		myScreenVector[myScreenVector.size()-8].replace(getX(), getX() + PERSON_WIDTH + spd,  "    |O  //   " + blanks);
		myScreenVector[myScreenVector.size()-7].replace(getX(), getX() + PERSON_WIDTH + spd,  "   <    |    " + blanks);
		myScreenVector[myScreenVector.size()-6].replace(getX(), getX() + PERSON_WIDTH + spd,  "    |_/ |    " + blanks);
		myScreenVector[myScreenVector.size()-5].replace(getX(), getX() + PERSON_WIDTH + spd,  "--o |__/      " + blanks);
		myScreenVector[myScreenVector.size()-4].replace(getX(), getX() + PERSON_WIDTH + spd, "   \\__|      " + blanks);
		myScreenVector[myScreenVector.size()-3].replace(getX(), getX() + PERSON_WIDTH + spd,  "      |      " + blanks);
		if (bLegChangePosition)
		{
			myScreenVector[myScreenVector.size() - 2].replace(getX(), getX() + PERSON_WIDTH, "     /|      " + blanks);
			myScreenVector[myScreenVector.size() - 1].replace(getX(), getX() + PERSON_WIDTH, "   \\/_|      " + blanks);
		}
		else
		{
			myScreenVector[myScreenVector.size() - 2].replace(getX(), getX() + PERSON_WIDTH, "      |      " + blanks);
			myScreenVector[myScreenVector.size() - 1].replace(getX(), getX() + PERSON_WIDTH, "    \\||      " + blanks);
		}
		break;

	case RIGHT:
		if (myLoc.x + spd < myScreenBufferSize.x - 14)
		{
			myLoc.x = myLoc.x + spd;
		}
		myScreenVector[myScreenVector.size()-10].replace(getX(), getX() + PERSON_WIDTH, " \\\\\\\\|////   ");
		myScreenVector[myScreenVector.size()-9].replace(getX(), getX() + PERSON_WIDTH,  "  \\\\\\\\ ~|    ");
		myScreenVector[myScreenVector.size()-8].replace(getX(), getX() + PERSON_WIDTH,    "   \\\\  O|    ");
		myScreenVector[myScreenVector.size()-7].replace(getX(), getX() + PERSON_WIDTH,      "    |    >   ");
		myScreenVector[myScreenVector.size()-6].replace(getX(), getX() + PERSON_WIDTH,     "    | \\_|    ");
		myScreenVector[myScreenVector.size()-5].replace(getX(), getX() + PERSON_WIDTH,     "     \\__| o--");
		myScreenVector[myScreenVector.size()-4].replace(getX(), getX() + PERSON_WIDTH,      "      |__/   ");
		myScreenVector[myScreenVector.size()-3].replace(getX(), getX() + PERSON_WIDTH,      "      |      ");
		if (bLegChangePosition)
		{
			myScreenVector[myScreenVector.size() - 2].replace(getX(), getX() + PERSON_WIDTH, "      |\\     ");
			myScreenVector[myScreenVector.size() - 1].replace(getX(), getX() + PERSON_WIDTH, "      |_\\/    ");
		}
		else
		{
			myScreenVector[myScreenVector.size() - 2].replace(getX(), getX() + PERSON_WIDTH, "      |     ");
			myScreenVector[myScreenVector.size() - 1].replace(getX(), getX() + PERSON_WIDTH, "      ||/    ");
		}
		break;

	case UP:
		myScreenVector[myScreenVector.size()-10].replace(getX(), getX() + PERSON_WIDTH, " \\\\\\\\\\|///// ");
		myScreenVector[myScreenVector.size()-9].replace(getX(), getX() + PERSON_WIDTH,    "  \\\\|\\ /|//  ");
		myScreenVector[myScreenVector.size()-8].replace(getX(), getX() + PERSON_WIDTH,     "   \\|O O|/   ");
		myScreenVector[myScreenVector.size()-7].replace(getX(), getX() + PERSON_WIDTH,      "    | ^ |    ");
		myScreenVector[myScreenVector.size()-6].replace(getX(), getX() + PERSON_WIDTH,     " \\  | - |  / ");
		myScreenVector[myScreenVector.size()-5].replace(getX(), getX() + PERSON_WIDTH,      "  o |___| o  ");
		myScreenVector[myScreenVector.size()-4].replace(getX(), getX() + PERSON_WIDTH,     "   \\__|__/   ");
		myScreenVector[myScreenVector.size()-3].replace(getX(), getX() + PERSON_WIDTH,      "      |     ");
		myScreenVector[myScreenVector.size()-2].replace(getX(), getX() + PERSON_WIDTH,      "      |     ");
		myScreenVector[myScreenVector.size()-1].replace(getX(), getX() + PERSON_WIDTH,      "     _|_     ");
		break;

	case DOWN:
	case NO_DIR:
		myScreenVector[myScreenVector.size()-10].replace(getX(), getX() + PERSON_WIDTH, " \\\\\\\\\\|///// ");
		myScreenVector[myScreenVector.size()-9].replace(getX(), getX() + PERSON_WIDTH,     "  \\\\|~ ~|//  ");
		myScreenVector[myScreenVector.size()-8].replace(getX(), getX() + PERSON_WIDTH,      "   \\|O O|/   ");
		myScreenVector[myScreenVector.size()-7].replace(getX(), getX() + PERSON_WIDTH,       "    | ^ |    ");
		myScreenVector[myScreenVector.size()-6].replace(getX(), getX() + PERSON_WIDTH,       "    | v |    ");
		myScreenVector[myScreenVector.size()-5].replace(getX(), getX() + PERSON_WIDTH,       "    |___|    ");
		myScreenVector[myScreenVector.size()-4].replace(getX(), getX() + PERSON_WIDTH,       "    __|__    ");
		myScreenVector[myScreenVector.size()-3].replace(getX(), getX() + PERSON_WIDTH,      "    \\ | /    ");
		myScreenVector[myScreenVector.size()-2].replace(getX(), getX() + PERSON_WIDTH,       "     0|0     ");
		myScreenVector[myScreenVector.size()-1].replace(getX(), getX() + PERSON_WIDTH,       "     _|_     ");
		break;

	}

	return false;
}
