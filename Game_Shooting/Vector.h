#pragma once
#include <math.h>

class Vector
{
public:

	float x, y;

	Vector();
	Vector(float x, float y);
	float angle;
	float movementSpeed;

	Vector minus(Vector other);
	float magnitude();
	Vector setAngle(float radians);
};


