#pragma once
#include "GameState.h"
#include "MenuState.h"
#include "HighScore.h"
class EndState:public GameState
{
public:
	EndState();
	EndState( int score);
	~EndState();

	SDL_Texture* gameOverTexture;
	Animation* gameOverAnimation;
	int score;
	HighScore* highScore;
	SDL_Rect textDestination;
	SDL_Texture* textTexture;

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID();
};

