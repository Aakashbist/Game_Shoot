#pragma once
#include "GameState.h"
#include <SDL.h>
#include "Global.h"
#include <iostream>
#include "PlayState.h"
#include "HallOfFameState.h"
#include "Level.h"

class MenuState :
	public GameState
{
public:
	
	Mix_Music * music;
	int selectedIndex = 1;
	
	MenuState();
	~MenuState();

	friend void menuOption(int num);
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID();
};

