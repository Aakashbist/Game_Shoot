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
	
}


void Entity::updateMovement(float dt) {

	velocity.x += (acceleration.x*dt);
	velocity.y += (acceleration.y*dt);

	position.x = position.x + (velocity.x*dt);
	position.y = position.y + (velocity.y*dt);
}

 
void Entity::draw() {
	//same as update
}

list<Entity*>* Entity::entities = NULL;