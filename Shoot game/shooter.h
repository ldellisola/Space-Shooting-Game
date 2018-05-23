#pragma once
#include "SpaceShip.h"
#include "bullet.h"
#include "ImportantConstats.h"



typedef struct {
	float x, y, speed, displayH, displayW;
	const char * sprite;
}shooterData;

class Shooter : public SpaceShip
{
public:
	
	Shooter(float x_, float y_, const char * spritePath, float velocity_, float maxX_, float maxY_)
		:SpaceShip(x_, y_, velocity_, spritePath, maxX_, maxY_) {}
	~Shooter();
	
	void update();		// Both update and draw also handle the bullter update and draw
	void draw();

	bool isMainTarget();

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

	bullet * getBullet();

	void setCoord(float x_, float y_) {
		SpaceShip::setCoord(x_, y_);
		shot->startOver(this->x - this->shot->getWidth() / 2.0, y_);
	}
	
private:
	bullet * shot;
};

