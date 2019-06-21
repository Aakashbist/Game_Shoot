#pragma once
#include<string>
#include<SDL.h>

class GameState
{
public:
	//whether this state is omple or not
	bool done = false;


	virtual void update() = 0;
	virtual void render() = 0;
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	virtual std::string getStateID() = 0;
    SDL_Texture* backgroundTexture;

};

