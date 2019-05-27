#pragma once
#include "GameState.h"
#include <SDL.h>
#include "Global.h"
#include <iostream>
#include "PlayState.h"

class MenuState :
	public GameState
{
public:
	SDL_Texture* backgroundTexture;
	
	MenuState();
	~MenuState();


	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID();
};

