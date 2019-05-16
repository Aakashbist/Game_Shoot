#include "Hero.h"


Hero::Hero()
{
	rotationAngle = 0.0;
	
	animation = NULL;

}


Hero::~Hero()
{
}

void Hero::setAnimation(Animation* animation) {
	this->animation = animation;
}

void Hero::consumeKeyboardEvent(SDL_Event * event, float dt)
{
	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	//check held down keys
	if (keystates[SDL_SCANCODE_LEFT]) {
		rotationAngle -= 5.00;
	}
	if (keystates[SDL_SCANCODE_RIGHT]) {
		rotationAngle += 5.00;
	}
	
	double newAngle = abs(rotationAngle);
	newAngle = fmod(newAngle, 360);

	if (keystates[SDL_SCANCODE_UP]) {
		acceleration.x -= speed * sin(newAngle);
		acceleration.y -= speed * cos(newAngle);
	}
	if (keystates[SDL_SCANCODE_DOWN]) {
		acceleration.x += speed * sin(newAngle);
		acceleration.y += speed * cos(newAngle);
	}
	printf("acceleration:%f,   %f, %f\n", newAngle, acceleration.x, acceleration.y);

	if (event->key.keysym.scancode == SDL_SCANCODE_SPACE && event->key.repeat == 0) {
		shoot(dt);
		printf("Shoot shoot %f\n", 00.00);
	}

;
}

void Hero::shoot(float dt) {

	Bullet* bullet = new Bullet();
	bullet->setRenderer(renderer);
	bullet->setXY(position.x, position.y);
	bullet->angle = rotationAngle;
	bullet->movementSpeed = 200;
	
	bullet->draw();

	
}


void Hero::update(float dt) {

	Entity::update(dt);

	//update movement based on velocity
	updateMovement(dt);

	if (animation != NULL)
		animation->update(dt);
}
void Hero::draw() {

	animation->draw(position.x, position.y, rotationAngle);
}
