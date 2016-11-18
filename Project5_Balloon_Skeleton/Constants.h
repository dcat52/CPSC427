#pragma once
//these are my arrow keys
const char LEFT_ARROW	='K';
const char RIGHT_ARROW	='M';
const char UP_ARROW		='H';
const char DOWN_ARROW	='P';	

//used by Moveable and controller
enum DIRECTION{NO_DIR=0, LEFT, RIGHT, UP, DOWN};
enum SPEED{NO_SPD=0,SLOW, MEDIUM, FAST };
enum COLLISION{NO=0, COSMO_POPPED, BALLOON_CLOBBERED_COSMO, ANVIL_SMASH};
enum OBJECT_TYPE{NONE=0, BALLOON, ANVIL, TERRIBLE_BALLOON};

//used by terrible balloon
enum BALLOON_STATE{IS_BALLOON, IS_BEE};

enum CONTROLLER_STATE{SHOW_INTRO, RESET, RUN};

//start off slow
//TODO make sure to set to SLOW before submitting
const SPEED CONTROLLER_SPEED = MEDIUM;

struct location{
	int x;
	int y;
	location(int x, int y){this->x=x; this->y=y;};
};

//screen goes from 0-y, and 0 to x
//do not include the bottom lines used for record keeping
struct sizeofScreenBuffer{
	int x;
	int y;
	sizeofScreenBuffer(int x, int y){this->x=x; this->y=y;};
};

//Miscellaneous
const int ROW_WHERE_SCORES_SHOWN	= 0;
const int SPACE_FOR_CRLF			= 1;

//how far a balloon square and cosmo square must overlap to be considered a collision
const int REQUIRED_OVERLAP = 4;
const int X_OVERLAP_WHERE_COSMO_HIT_ON_HEAD = 4;

//bounding boxes (width , height)
const int BALLOON_WIDTH		= 7;
const int BALLOON_HEIGHT	= 7;
const int PERSON_WIDTH		= 13;
const int PERSON_HEIGHT		= 10;
const int BEE_WIDTH			= 5;
const int BEE_HEIGHT		= 3;
const int ANVIL_WIDTH		= 11;
const int ANVIL_HEIGHT		= 5;

//console defaults, pure guess
const int DEFAULT_WIDTH  =80;
const int DEFAULT_HEIGHT =24;

//wait times go for at least this many cycles
const int MIN_BALLOON_HOVER_TIME	= 60;
const int QUANTUM_WAIT_TIME			= 5;
const int BALLOON_APPEAR_BAND_SIZE	= 5;

const int BALLOON_MOVE_WAIT_TIME = 8;
const int BALLOON_POP_DISPLAY = 5;

const int ANVIL_APPEAR_BAND_SIZE = 3;

const int ANVIL_MOVE_WAIT_TIME = 1;
const int ANVIL_OUCH_DISPLAY = 5;

