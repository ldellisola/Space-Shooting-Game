#pragma once
#include "SpaceShip.h"
#include "ImportantConstats.h"

class shooterMan : public SpaceShip
{
public:
	
	shooterMan(float x_, float y_, const char * spritePath, float velocity_, float maxX_, float maxY_)
		:SpaceShip(x_, y_, velocity_, spritePath, maxX_, maxY_) {}
	void update();
};

