#include "Bullet.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{

}

void Bullet::update(float dt) {
	//convert angle in degrees to radians(for trigonometry)
	float angleInRadians = angle / 180 * M_PI;

	velocity.x = movementSpeed*cos(angleInRadians);
	velocity.y = movementSpeed*sin(angleInRadians);

	updateMovement(dt);

}
void Bullet::draw() {
	SDL_SetRenderDrawColor(Global::renderer, 255, 255, 0, 255);//yellow
	SDL_Rect bulletRect = { position.x, position.y , 20, 20 };
	SDL_RenderFillRect(Global::renderer, &bulletRect);
}
