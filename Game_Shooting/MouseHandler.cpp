#include "MouseHandler.h"


MouseHandler::MouseHandler()
{
	leftMouseHeld = false;
}


MouseHandler::~MouseHandler()
{
}
void MouseHandler::update(SDL_Event* event) {

	if
		(event->type == SDL_MOUSEBUTTONDOWN && event->button.button == SDL_BUTTON_LEFT) {
		//if mouse is clicked over hero
	/*	if (event->button.x >= Texture::instance()->positi && event->button.x < +hero->position.x + 32
			&& event->button.y >= hero->position.y  && event->button.y < +hero->position.y + 32 ) {
			leftMouseHeld = true;
		}*/
	}

	//checked to see if left mouse button was relesed

	if (event->type == SDL_MOUSEBUTTONUP && event->button.button == SDL_BUTTON_LEFT) {
		leftMouseHeld = false;
	}

	//if left is held down and mouse moved drag hero around

	if (leftMouseHeld && event->type == SDL_MOUSEMOTION) {
		hero->setXY(hero->position.x + event->motion.xrel, hero->position.y + event->motion.yrel);
	}
}