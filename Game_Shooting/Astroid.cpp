#include "Astroid.h"



Astroid::Astroid()
{
	velocity.x = 0;
	velocity.y = 0;
	gravity = 100;
	active = true;
}


Astroid::~Astroid()
{


}
void Astroid::setAnimation(Animation* animation) {
	this->animation = animation;
	height = this->animation->frameHeight;
	width = this->animation->frameWidth;
}

void Astroid::update(float dt) {
	//they are in the air,adhere to gravity
	if (position.y < 600) {
		//kepp setting gravity as a constant force 
		acceleration.y = gravity;
	}
	else {
		acceleration.y = 0;
		//on the ground
		//if velocity is push ing the ball down but we hit ground the reverse3 velociy for bounce
		if (velocity.y > 0.1) {
			velocity.y = velocity.y * -0.9;
		}
		else {
			velocity.y = 0;
			velocity.x = velocity.x - 0.99;//apply friction to velocity
		}

	}

	//bouncing of the walls
	//left wall aand moving left		right wall
	if ((position.x <= 0 && velocity.x <= 0) || (position.x >= 800 && velocity.x >= 0)) {

		velocity.x = velocity.x* -0.9;//reverse the velocity direction
	}


	updateMovement(dt);

}
void Astroid::draw() {

		animation->draw(position.x, position.y);
}
std::string Astroid::getStateID()
{
	return "astroid";
}


// list<Astroid*>* Astroid::astroides=NULL;