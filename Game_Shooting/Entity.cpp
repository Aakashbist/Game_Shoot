#include "Entity.h"


Entity::Entity()
{

}


Entity::~Entity()
{
	
}

void Entity::setRenderer(SDL_Renderer* renderer) {
	this->renderer = renderer;
}
void Entity::setXY(float x, float y) {
	position.x = x;
	position.y = y;
}
float Entity::getX() {
	return position.x;
}
float Entity::getY() {
	return position.y;
}

void Entity::update(float dt) {
	//do nothing, let sub classes deal with this
	velocity.x = (acceleration.x*dt);
	velocity.y = (acceleration.y*dt);

	//velocity changes position
	position.x = position.x + (velocity.x*dt);
	position.y = position.y + (velocity.y*dt);

	acceleration.x = applyFriction(acceleration.x);
	acceleration.y = applyFriction(acceleration.y);
}

void Entity::updateMovement(float dt) {
	//acceleration changes velocit
}

 double applyFriction(double value) {
	int friction = 1;
	double newValue = value;
	if (value > 0) {
		if (value < friction) {
			newValue = 0;
		}
		else {
			newValue -= friction;
		}
	}
	else {
		if (abs(value) < friction) {
			newValue = 0;
		}
		else {
			newValue += friction;
		}
	}
	return newValue;
}

void Entity::draw() {
	//same as update
}

list<Entity*>* Entity::entities = NULL;