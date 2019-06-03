#include "Hero.h"



Hero::Hero()
{
	animation = NULL;

}


Hero::~Hero()
{

}

void Hero::setAnimation(Animation* animation) {
	this->animation = animation;
	height = this->animation->frameHeight;
	width = this->animation->frameWidth;
}


void Hero::shoot() {

	Bullet* bullet = new Bullet();
	bullet->setRenderer(Global::renderer);
	bullet->setXY(position.x, position.y);

	bullets.push_back(bullet);

}

void Hero::update(float dt) {

	for (auto bullet = bullets.begin(); bullet != bullets.end(); bullet++)
	{

		if ((*bullet)->position.y < -100)
		{
			(*bullet)->active = false;
		
		}
		else {
			(*bullet)->update(dt);

		}

	}
}

void Hero::draw() {
	if (active) {
		animation->draw(position.x, position.y);

		for (auto bullet : bullets) {

			bullet->draw();
		}

	}

}

Hero Hero::hero;


std::string Hero::getStateID()
{
	return "hero";
}
