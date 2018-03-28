#pragma once
#include "bullet.h"
#include "SpaceShip.h"
#include "ImportantConstats.h"

class target : public SpaceShip
{
public:
	target(float x_, float y_, float velocity_,float maxX_, float maxY_, const char * spritePath)
		:SpaceShip(x_, y_, velocity_, spritePath, maxX_,maxY_) {}
	bool collision(bullet * shot);
	void setMovement();
	void draw();
	
};

