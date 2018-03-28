#pragma once
#include "SpaceShip.h"
#include "bullet.h"
#include "ImportantConstats.h"

class shooterMan : public SpaceShip
{
public:
	
	shooterMan(float x_, float y_, const char * spritePath, float velocity_, float maxX_, float maxY_)
		:SpaceShip(x_, y_, velocity_, spritePath, maxX_, maxY_) {}
	~shooterMan();
	
	void update();		// Both update and draw also handle the bullter update and draw
	void draw();

	// Bullet functions
	void createBullet(const char * spritePath_, float speedX_, float speedY_);

	void bulletStartOver();

	void bulletFire();

	void bulletMoveLeft();
	void bulletMoveRight();
	void bulletDontMove();

	// Getters de Bullet
	bool bulletIsActive();
	float bulletGetTopLeftX();
	float bulletGetTopLeftY();
	float bulletGetBotRightX();
	float bulletGetBotRightY();
	
private:
	bullet * shot;
};

