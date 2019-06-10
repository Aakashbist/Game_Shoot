#pragma once
#include "Entity.h"
#include "Animation.h"
#include "Bullet.h"
#include "Setting.h"
#include "Texture.h"
#include "SoundManager.h"

#include<stdlib.h>
#include <list>
#include<math.h>
#include <fstream>

class Hero: public Entity
{
private:
	Animation* animation;
	SDL_Event* event;
	 int score;
	ofstream fout;
	ifstream fin;

public:
	Hero();
	~Hero();
	int height;
	int width;

	void setAnimation(Animation* animation);
	
	void shoot();
	void setScore(int);
	int getScore(void);

	//override
	virtual void update(float dt);
	virtual void draw();
	virtual std::string getStateID();
	 list<Bullet* > bullets;
	 static Hero hero;
};

