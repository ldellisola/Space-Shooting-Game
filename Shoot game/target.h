#pragma once
#include "bullet.h"
#include "SpaceShip.h"
#include "ImportantConstats.h"

typedef struct targetData
{
	float x, y, speed, displayW, displayH;
	const char * sprite;
	float newOffset;
};


class Target : public SpaceShip
{
public:
	Target(float x_, float y_, float velocity_,float maxX_, float maxY_, const char * spritePath)
		:SpaceShip(x_, y_, velocity_, spritePath, maxX_,maxY_) {}
	bool collision(float Ax, float Ay, float Dx, float Dy);
	void setMovement();
	void draw();
	
};

