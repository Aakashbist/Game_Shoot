#pragma once
#include "GameState.h"
#include "MenuState.h"
#include "HighScore.h"
class HallOfFameState :
	public GameState
{
public:
	HallOfFameState();
	~HallOfFameState();



	HighScore* highScore;
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID();
};

