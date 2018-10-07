#pragma once
#include "Moveable.h"
#include "Balloon.h"

class TerribleBalloon :
	public Balloon
{
public:
	//constructor for terrible balloon
	TerribleBalloon(sizeofScreenBuffer myScreenBufferSize, location myLoc, int iHowLongBeforeFall, SPEED spd = NO_SPD, DIRECTION dir = DOWN);
	virtual ~TerribleBalloon(void);

	//returns true if its time to delete
	virtual bool draw(std::vector<std::string> &myScreenVector);
private:
	BALLOON_STATE bState;
	bool bFlapping;
	int dirInt;
};

