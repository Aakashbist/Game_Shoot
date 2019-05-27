#include "Global.h"
Global::Global()
{
}


Global::~Global()
{
}


SDL_Window* Global::window = NULL;
SDL_Renderer* Global::renderer = NULL;
bool Global::quitGame = false;
GameStateMachine Global::gameStateMachine;
