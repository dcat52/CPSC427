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
		myScreenVector[17].replace(getX(), 100, "   \\\\\\\\|//// ");
		myScreenVector[18].replace(getX(), 100, "    |~ ////  ");
		myScreenVector[19].replace(getX(), 100, "    |O  //   ");
		myScreenVector[20].replace(getX(), 100, "   <    |    ");
		myScreenVector[21].replace(getX(), 100, "    |_/ |    ");
		myScreenVector[22].replace(getX(), 100, "--o |__/     ");
		myScreenVector[23].replace(getX(), 100, "   \\__|      ");
		myScreenVector[24].replace(getX(), 100, "      |      ");
		myScreenVector[25].replace(getX(), 100, "     /|      ");
		myScreenVector[26].replace(getX(), 100, "   \\/_|      ");
		myScreenVector[27].replace(getX(), 100, "      |      ");
		myScreenVector[28].replace(getX(), 100, "    \\||      ");
		break;

	case RIGHT:
		myScreenVector[17].replace(getX(), 100, " \\\\\\\\|////   ");
		myScreenVector[18].replace(getX(), 100, "  \\\\\\\\ ~|    ");
		myScreenVector[19].replace(getX(), 100, "   \\\\  O|    ");
		myScreenVector[20].replace(getX(), 100, "    |    >   ");
		myScreenVector[21].replace(getX(), 100, "    | \\_|    ");
		myScreenVector[22].replace(getX(), 100, "     \\__| o--");
		myScreenVector[23].replace(getX(), 100, "      |__/   ");
		myScreenVector[24].replace(getX(), 100, "      |      ");
		myScreenVector[25].replace(getX(), 100, "      |\\     ");
		myScreenVector[26].replace(getX(), 100, "      |_\\/    ");
		myScreenVector[27].replace(getX(), 100, "      |     ");
		myScreenVector[28].replace(getX(), 100, "      ||/    ");
		break;

	case UP:
		myScreenVector[19].replace(getX(), 100, " \\\\\\\\\\|///// ");
		myScreenVector[20].replace(getX(), 100, "  \\\\|\\ /|//  ");
		myScreenVector[21].replace(getX(), 100, "   \\|O O|/   ");
		myScreenVector[22].replace(getX(), 100, "    | ^ |    ");
		myScreenVector[23].replace(getX(), 100, " \\  | - |  / ");
		myScreenVector[24].replace(getX(), 100, "  o |___| o  ");
		myScreenVector[25].replace(getX(), 100, "   \\__|__/   ");
		myScreenVector[26].replace(getX(), 100, "      |     ");
		myScreenVector[27].replace(getX(), 100, "      |     ");
		myScreenVector[28].replace(getX(), 100, "     _|_     ");
		break;

	case DOWN:
		myScreenVector[19].replace(getX(), 100, " \\\\\\\\\\|///// ");
		myScreenVector[20].replace(getX(), 100, "  \\\\|~ ~|//  ");
		myScreenVector[21].replace(getX(), 100, "   \\|O O|/   ");
		myScreenVector[22].replace(getX(), 100, "    | ^ |    ");
		myScreenVector[23].replace(getX(), 100, "    | v |    ");
		myScreenVector[24].replace(getX(), 100, "    |___|    ");
		myScreenVector[25].replace(getX(), 100, "    __|__    ");
		myScreenVector[26].replace(getX(), 100, "    \\ | /    ");
		myScreenVector[27].replace(getX(), 100, "     0|0     ");
		myScreenVector[28].replace(getX(), 100, "     _|_     ");
		break;

	}

	return false;
}
