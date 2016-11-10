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
		myScreenVector[myScreenVector.size()-12].replace(getX(), 70, "   \\\\\\\\|//// ");
		myScreenVector[myScreenVector.size()-11].replace(getX(), 70, "    |~ ////  ");
		myScreenVector[myScreenVector.size()-10].replace(getX(), 70, "    |O  //   ");
		myScreenVector[myScreenVector.size()-9].replace(getX(), 70, "   <    |    ");
		myScreenVector[myScreenVector.size()-8].replace(getX(), 70, "    |_/ |    ");
		myScreenVector[myScreenVector.size()-7].replace(getX(), 70, "--o |__/     ");
		myScreenVector[myScreenVector.size()-6].replace(getX(), 70, "   \\__|      ");
		myScreenVector[myScreenVector.size()-5].replace(getX(), 70, "      |      ");
		myScreenVector[myScreenVector.size()-4].replace(getX(), 70, "     /|      ");
		myScreenVector[myScreenVector.size()-3].replace(getX(), 70, "   \\/_|      ");
		myScreenVector[myScreenVector.size()-2].replace(getX(), 70, "      |      ");
		myScreenVector[myScreenVector.size()-1].replace(getX(), 70, "    \\||      ");
		break;

	case RIGHT:
		myScreenVector[myScreenVector.size()-12].replace(getX(), 100, " \\\\\\\\|////   ");
		myScreenVector[myScreenVector.size()-11].replace(getX(), 100, "  \\\\\\\\ ~|    ");
		myScreenVector[myScreenVector.size()-10].replace(getX(), 100, "   \\\\  O|    ");
		myScreenVector[myScreenVector.size()-9].replace(getX(), 100, "    |    >   ");
		myScreenVector[myScreenVector.size()-8].replace(getX(), 100, "    | \\_|    ");
		myScreenVector[myScreenVector.size()-7].replace(getX(), 100, "     \\__| o--");
		myScreenVector[myScreenVector.size()-6].replace(getX(), 100, "      |__/   ");
		myScreenVector[myScreenVector.size()-5].replace(getX(), 100, "      |      ");
		myScreenVector[myScreenVector.size()-4].replace(getX(), 100, "      |\\     ");
		myScreenVector[myScreenVector.size()-3].replace(getX(), 100, "      |_\\/    ");
		myScreenVector[myScreenVector.size()-2].replace(getX(), 100, "      |     ");
		myScreenVector[myScreenVector.size()-1].replace(getX(), 100, "      ||/    ");
		break;

	case UP:
		myScreenVector[myScreenVector.size()-10].replace(getX(), 100, " \\\\\\\\\\|///// ");
		myScreenVector[myScreenVector.size()-9].replace(getX(), 100, "  \\\\|\\ /|//  ");
		myScreenVector[myScreenVector.size()-8].replace(getX(), 100, "   \\|O O|/   ");
		myScreenVector[myScreenVector.size()-7].replace(getX(), 100, "    | ^ |    ");
		myScreenVector[myScreenVector.size()-6].replace(getX(), 100, " \\  | - |  / ");
		myScreenVector[myScreenVector.size()-5].replace(getX(), 100, "  o |___| o  ");
		myScreenVector[myScreenVector.size()-4].replace(getX(), 100, "   \\__|__/   ");
		myScreenVector[myScreenVector.size()-3].replace(getX(), 100, "      |     ");
		myScreenVector[myScreenVector.size()-2].replace(getX(), 100, "      |     ");
		myScreenVector[myScreenVector.size()-1].replace(getX(), 100, "     _|_     ");
		break;

	case DOWN:
	case NO_DIR:
		myScreenVector[myScreenVector.size()-10].replace(getX(), 100, " \\\\\\\\\\|///// ");
		myScreenVector[myScreenVector.size()-9].replace(getX(), 100, "  \\\\|~ ~|//  ");
		myScreenVector[myScreenVector.size()-8].replace(getX(), 100, "   \\|O O|/   ");
		myScreenVector[myScreenVector.size()-7].replace(getX(), 100, "    | ^ |    ");
		myScreenVector[myScreenVector.size()-6].replace(getX(), 100, "    | v |    ");
		myScreenVector[myScreenVector.size()-5].replace(getX(), 100, "    |___|    ");
		myScreenVector[myScreenVector.size()-4].replace(getX(), 100, "    __|__    ");
		myScreenVector[myScreenVector.size()-3].replace(getX(), 100, "    \\ | /    ");
		myScreenVector[myScreenVector.size()-2].replace(getX(), 100, "     0|0     ");
		myScreenVector[myScreenVector.size()-1].replace(getX(), 100, "     _|_     ");
		break;

	}

	return false;
}
