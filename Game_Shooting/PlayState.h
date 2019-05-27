#pragma once
#include <list>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "GameState.h"
#include "Global.h"
#include <iostream>
#include "Hero.h"
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
	Astroid* astroid;
	Bullet* bullet;
	
	SDL_Texture* textTexture;

	list<Entity*> entities;

	KeyboardHandler keyboardHandler;
	
	//TIME STUFF
	Uint32 lastUpdate; //last sdl_ticks
	float dt;//time since last update

	PlayState();
	~PlayState();

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID();
};

