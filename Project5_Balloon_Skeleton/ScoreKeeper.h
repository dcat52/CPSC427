#pragma once
#include <string>

class ScoreKeeper
{
public:
	ScoreKeeper(void);
	~ScoreKeeper(void);

	//pass in a string and put cosmos score at beginning and Balloons at end
	//WILL NOT ALTER LENGTH OF STRING (fails if string not long enough)
	bool getDisplayString(std::string &scoreString);

	//returns the score of balloons
	inline int getScoreBalloon(){return scoreBalloon;};
	//returns the score of cosmo
	inline int getScoreCosmo(){return scoreBalloon;};

	//typically its 1 at a time
	inline  void incScoreBalloon(int i=1){scoreBalloon+=i;};
	inline  void incScoreCosmo(int i=1){scoreCosmo+=i;};
	//sets both the score for cosmo and balloon to 0
	inline  void resetScores(){scoreBalloon=0;scoreCosmo=0;};

private:
	//scores
	int scoreBalloon;
	int scoreCosmo;

	int windowX;
};

