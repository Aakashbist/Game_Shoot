#pragma once
#include "Entity.h"
#include "Global.h"
#include "Setting.h"
#include "Animation.h"
#include <cmath>

class Bullet :
	public Entity
{
public:

	Animation* animation;
	Bullet();
	~Bullet();

	const int BULLET_SPEED = 5;
	int height;
	int width;


	void setAnimation(Animation* animation);
	void update(float dt);
	void draw();

	virtual std::string getStateID();
};

