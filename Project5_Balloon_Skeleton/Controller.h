#pragma once
#include <vector>
#include "constants.h"
#include "person.h"
#include "balloon.h"
#include "Anvil.h"
#include "scorekeeper.h"
#include "instructions.h"
#include <memory>

class Controller
{
public:
	//pass in width and height of console window, plus default speed
	Controller(int width, int height, SPEED speed=MEDIUM);
	~Controller(void);

	//render the scene
	void draw();
	void createBalloon();
	void createAnvil();

	//change game speed.
	inline void setSpeed(SPEED speed){mSpeed = speed;};


	inline void setTerribleBalloonsOn(bool _terribleBalloonsOn) { terribleBalloonsOn = _terribleBalloonsOn; };
	inline bool getTerribleBalloonsOn() { return terribleBalloonsOn; };

	//current state intro or run
	inline void setControllerState(CONTROLLER_STATE state){mControllerState = state;};

	//test to see if cosmo has run into an object
	COLLISION hasCollidedWithCosmo(Moveable &pMoveable);

	inline void changeCosmoDirection(DIRECTION dir){cosmo.setDirection(dir);};

private:
	//reset it all
	void initialize();

	//fills screen buffer with blanks
	void clearScreen();

	//draw scores if needed
	void renderScoresToScreenbuffer();
	
	SPEED mSpeed;		//game speed
	//number of game ticks before  created
	int iTimeBetweenBalloonCreation;
	sizeofScreenBuffer myScreenBufferSize;	//width and height of consolewindow

	//number of game ticks before anvil is created
	int iTimeBetweenAnvilCreation;

	//holds entire consolewindow screen, 
	//usually 80 chars wide by 24 lines long
	std::vector<std::string> myScreenVector;

	std::vector<std::unique_ptr<Moveable>> myMoveables;

	//cosmo the person
	Person cosmo;

	//for writing instructions
	Instructions myInstructions;

	//max distance between center of squares for a collision to have occured
	//its corner of one object bounding box touching corner of another
	double mCollisionDistance;

	ScoreKeeper scorekeeper;
	CONTROLLER_STATE mControllerState;

	bool terribleBalloonsOn;
};

