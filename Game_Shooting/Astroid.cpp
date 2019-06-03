#include "Astroid.h"

Astroid::Astroid()
{
	velocity.x = 0;
	velocity.y = 0;
	gravity = 100;

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

		position.y += 1;
		updateMovement(dt);
	}
}

void Astroid::draw() {
	if (active)
		animation->draw(position.x, position.y);
}

std::string Astroid::getStateID()
{
	return "astroid";
}

void Astroid::push(Astroid* astroid)
{/*
	astroides.push_back(astroid);
	Entity::entities->push_back(astroid);*/
}

Astroid Astroid::astroid;

