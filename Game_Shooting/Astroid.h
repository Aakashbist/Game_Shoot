#pragma once
#include "Entity.h"
#include "Global.h"
#include "Animation.h"


class Astroid : public Entity
{
public:
	float gravity;
	Animation* animation;

	int height;
	int width;

	Astroid();
	~Astroid();
	void setAnimation(Animation* animation);
	void update(float dt);
	void draw();
	virtual std::string getStateID() ;
	//static list<Astroid*> astroides;

};