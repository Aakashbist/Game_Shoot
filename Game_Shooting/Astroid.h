#pragma once
#include "Entity.h"
#include "Global.h"
#include "Animation.h"
#include "Setting.h"


class Astroid : public Entity
{
public:
	float gravity;
	Animation* animation;


	Astroid();
	~Astroid();
	void setAnimation(Animation* animation);
	void update(float dt);
	void draw();
	virtual std::string getStateID();
	void push(Astroid* astroid);
	list<Astroid*> astroides;
	static Astroid astroid;

	
};