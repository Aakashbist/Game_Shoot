#pragma once
#include <SDL.h>
#include "Hero.h"


class InputHandler
{
public:
	Hero* hero;

	InputHandler();
	~InputHandler();

	virtual void update(SDL_Event* event) = 0;
};
