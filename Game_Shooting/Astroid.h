#pragma once
#include "Entity.h"
#include "Global.h"
#include "Animation.h"
#include "Setting.h"
#include<stdlib.h>


class Astroid : public Entity
{
public:
	
	Animation* animation;


	Astroid();
	~Astroid();
	void setAnimation(Animation* animation);
	void update(float dt);
	void draw();
	virtual std::string getStateID();
	
	list<Astroid*> astroides;
	static Astroid astroid;

	
};