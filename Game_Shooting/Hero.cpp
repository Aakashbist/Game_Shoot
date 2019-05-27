#include "Hero.h"



Hero::Hero()
{
	animation = NULL;
	active = true;
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
	printf("size = %d", bullets.size());
	//Remove all game entities that are not active
	for (auto bullet = bullets.begin(); bullet != bullets.end();)
	{
		if ((*bullet)->position.y < -100)
		{
			//not active
			delete *bullet;
			bullet = bullets.erase(bullet);
		}
		else {
			(*bullet)->update(dt);
			bullet++;
		}

	}
	/*for (auto bullet : bullets) {
		if (bullet->position.y < -100) {
			bullets.remove(bullet);
			printf("size after delete = %d", bullets.size());
		}

	}*/


}

void Hero::draw() {
	if (active) {
		animation->draw(position.x, position.y);
	}

	for (auto bullet : bullets) {

		bullet->draw();


	}

}

std::string Hero::getStateID()
{
	return "hero";
}
