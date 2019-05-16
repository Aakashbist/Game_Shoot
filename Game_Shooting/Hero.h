#pragma once
#include<SDL.h>

#include "Entity.h"
#include "Animation.h"
#include<math.h>
#include "Bullet.h"
class Hero: public Entity
{
private:
	Animation* animation;
	double rotationAngle;
	SDL_Event* event;
	double speed=50;
	double maxSpeed=200;
public:
	Hero();
	~Hero();

	void setAnimation(Animation* animation);
	void consumeKeyboardEvent(SDL_Event* event,float dt);
	void shoot(float dt);

	//override
	virtual void update(float dt);
	virtual void draw();

};

