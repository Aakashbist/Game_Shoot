#pragma once
#include <list>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "GameState.h"
#include "Global.h"
#include <iostream>
#include "Hero.h"
#include <stdlib.h>
#include "Texture.h"
#include "Astroid.h"


#include "KeyboardHandler.h"

class PlayState :
	public GameState
{
public:
	SDL_Texture* heroTexture;
	SDL_Texture* astroidTexture;
	Animation* astroidAnimation;
	Animation* heroAnimation;
	Hero* hero;
	SDL_Texture* astroidtexture2;
	Animation* astroidAnimation2;
	Bullet* bullet;
	

	SDL_Texture* textTexture;

	list<Entity*> entities;

	
	KeyboardHandler keyboardHandler;
	
	//TIME STUFF
	Uint32 lastUpdate; //last sdl_ticks
	float dt;//time since last update

	Uint32 TIMER_IN_MILLIS = 2000;
	Uint32 NEXT_TIMER_TICK = SDL_GetTicks() + TIMER_IN_MILLIS;


	PlayState();
	~PlayState();

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID();
};

