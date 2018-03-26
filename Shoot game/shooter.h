#pragma once
#include "SpaceShip.h"
#include "ImportantConstats.h"

class shooterMan : public SpaceShip
{
public:
	
	shooterMan(float x_, float y_, int width_, int height_, const char * spritePath, float velocity_, float maxX_, float maxY_)
		:SpaceShip(x_, y_, velocity_, width_, height_, spritePath, maxX_, maxY_) {}
};

