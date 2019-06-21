#pragma once
#include <SDL.h>
#include "Vector.h"
#include "Animation.h"
#include "Point.h"
#include <list>


using namespace std;

class Entity
{
protected:
	SDL_Renderer* renderer;
	

public:

	Vector position;
	Vector velocity;
	Vector acceleration;
	bool active = true;
	void drawDebugMarker(Animation* anim);
	
	Entity();
	~Entity();
	//friend double applyFriction(double value);
	void setRenderer(SDL_Renderer* renderer);
	void setXY(float x, float y);
	float getX();
	float getY();

	virtual void update(float dt);
	virtual void updateMovement(float dt);
	virtual void draw();
	bool hitDetection(int x, int y);
	bool hitDetection(int x, int y,int w,int h);
	friend bool inRange(int low, int high, int x);
	

	int width;
	int height;

	virtual std::string getStateID() = 0;

	static list<Entity*> *entities;
	

};



