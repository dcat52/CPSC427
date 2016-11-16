#include "ScoreKeeper.h"

const char COSMO_SCORE_PREFIX[]		= "COSMO = ";
const int  LEN_COSMO_SCORE_PREFIX	= 8;
const char BALLOON_SCORE_PREFIX[]	= "BALLOONS = "; 
const int  LEN_BALLOON_SCORE_PREFIX	= 11;
const int  SPACES_FOR_SCORE			= 6;

ScoreKeeper::ScoreKeeper(void)
{
	resetScores();
}

ScoreKeeper::~ScoreKeeper(void)
{
}

bool ScoreKeeper::getDisplayString(std::string &scoreString){
	//TODO calculate the score that goes in the display string here
	std::string scoreRight = COSMO_SCORE_PREFIX + std::to_string(getScoreCosmo());
	std::string scoreLeft = BALLOON_SCORE_PREFIX + std::to_string(getScoreBalloon());
	while (scoreRight.length() < LEN_COSMO_SCORE_PREFIX + SPACES_FOR_SCORE)
		scoreRight += " ";
	while (scoreLeft.length() < LEN_BALLOON_SCORE_PREFIX + SPACES_FOR_SCORE)
		scoreLeft += " ";
	scoreString = scoreString.replace(0, LEN_BALLOON_SCORE_PREFIX + SPACES_FOR_SCORE, scoreLeft);
	scoreString = scoreString.replace(scoreString.length() - LEN_COSMO_SCORE_PREFIX - SPACES_FOR_SCORE, scoreString.length(), scoreRight);
	return true;
}
