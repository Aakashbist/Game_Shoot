#include "Astroid.h"

Astroid::Astroid()
{

	

	speed = rand() % 4 + 1;
	

}

Astroid::~Astroid()
{
}

void Astroid::setAnimation(Animation* animation) {
	this->animation = animation;
	height = this->animation->frameHeight;
	width = this->animation->frameWidth;
}

void Astroid::update(float dt) {
	if (active) {

		if (position.y > WINDOW_HEIGHT + 100)
		{
			active = false;

		}

		position.y += speed;
		updateMovement(dt);
	}
}

void Astroid::draw() {
	if (active) {

		animation->draw(position.x, position.y);
		//draw hitbox
		if (Global::isDebug)
			drawDebugMarker(animation);
	}
}

std::string Astroid::getStateID()
{
	return "astroid";
}




Astroid Astroid::astroid;

