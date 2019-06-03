#include "Bullet.h"

Bullet::Bullet()
{
	animation = NULL;
	active = true;

}


Bullet::~Bullet()
{
}

void Bullet::setAnimation(Animation* animation) {
	this->animation = animation;
	
}


void Bullet::update(float dt) {
	if (active) {
		position.y -= BULLET_SPEED;
		updateMovement(dt);
	}	
}

void Bullet::draw() {
	if(active){
	SDL_SetRenderDrawColor(Global::renderer, 0, 255, 0, 255);
	SDL_Rect bulletRect = { position.x + 50 , position.y -25 , 4, 20 };
	height = bulletRect.h;
	width = bulletRect.w;
	SDL_RenderFillRect(Global::renderer, &bulletRect);
	}
}


std::string Bullet::getStateID()
{
	return "bullet";
}
