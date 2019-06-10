#pragma once
#include "GameState.h"
#include "MenuState.h"
class EndState:public GameState
{
public:
	EndState();
	~EndState();

	SDL_Texture* gameOverTexture;
	Animation* gameOverAnimation;
	Hero* dhero;
	SDL_Rect textDestination;
	SDL_Texture* textTexture;

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID();
};

