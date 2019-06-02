#pragma once
#include "Entity.h"
#include "Animation.h"
#include<math.h>
#include "Bullet.h"
#include "Setting.h"
#include "Texture.h"
#include<stdlib.h>
#include <list>
class Hero: public Entity
{
private:
	Animation* animation;
	SDL_Event* event;
	
public:
	Hero();
	~Hero();
	int height;
	int width;

	void setAnimation(Animation* animation);
	
	void shoot();

	//override
	virtual void update(float dt);
	virtual void draw();
	virtual std::string getStateID();
	 list<Bullet* > bullets;
};

