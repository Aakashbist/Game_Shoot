#include "KeyboardHandler.h"
#include"Setting.h"


KeyboardHandler::KeyboardHandler()
{
}


KeyboardHandler::~KeyboardHandler()
{
}

void KeyboardHandler::update(SDL_Event* event) {
	if (event->type == SDL_KEYDOWN) {
		//trigger on R key, but dont do this if repeat event is fired
		if (event->key.keysym.scancode == SDL_SCANCODE_R && event->key.repeat == 0)
		{
			//reset player to starting position
			hero->setXY(200, 200);
		}
		//SHOOT
		if (event->key.keysym.scancode == SDL_SCANCODE_SPACE && event->key.repeat == 0) {
			hero->shoot();
			
		}
	}
}
void KeyboardHandler::updateHeldKeys() {
	//get array of all keyboard key states(1=held, 0=not held down)
	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	if (keystates[SDL_SCANCODE_LEFT]) {
		if (hero->position.x > 0) {
			hero->position.x -= 5;
		}
	}
	if (keystates[SDL_SCANCODE_RIGHT]) {
		if (hero->position.x < WINDOW_WIDTH - 99) {
			hero->position.x += 5;
		}
	}
}

