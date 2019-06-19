#pragma once
//#include <SDL.h>
//#include"GameStateMachine.h"
//#include"MenuState.h"
//#include"PlayState.h"
#include <SDL.h>
#include"GameStateMachine.h"

class Global
{
public:
	Global();
	~Global();

	static SDL_Color menuSelectedColor;
	static SDL_Color menuDeselectedColor;
	
	static SDL_Window* window;
	static SDL_Renderer* renderer;
	static bool quitGame;
	
	static GameStateMachine gameStateMachine;
	
};


