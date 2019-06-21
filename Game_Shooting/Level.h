#pragma once

#include "MenuState.h"
class Level:public GameState
{
public:
	Level();
	~Level();
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID();
	friend void levelOption(int num);

	int selectedIndex = 1;
};

