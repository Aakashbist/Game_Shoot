#pragma once
#include "InputHandler.h"
#include "Texture.h"
class MouseHandler :	public InputHandler
{
public:
	bool leftMouseHeld;
	MouseHandler();
	~MouseHandler();
	virtual void update(SDL_Event* event);
};

