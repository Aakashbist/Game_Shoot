#include "Global.h"
Global::Global()
{
}


Global::~Global()
{
}

SDL_Color Global::menuSelectedColor = { 255, 0, 0, 255 };
SDL_Color Global::menuDeselectedColor = { 100, 0, 0, 255 };
SDL_Window* Global::window = NULL;
SDL_Renderer* Global::renderer = NULL;
bool Global::quitGame = false;
bool Global::isDebug=false;
GameStateMachine Global::gameStateMachine;
