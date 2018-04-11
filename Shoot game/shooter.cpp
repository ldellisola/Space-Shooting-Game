#include "shooter.h"

void Shooter::createBullet(const char * spritePath_, float speedX_, float speedY_)
{
	this->shot = new bullet(this->x + (this->width / 2.0) , this->y, speedY_, spritePath_, speedX_, this->maxX, this->maxY);
}

void Shooter::bulletStartOver()
{
	this->shot->startOver(this->x + (this->width / 2.0) - (this->shot->getWidth() / 2.0) + 5, this->y - (this->shot->getHeight() / 2.0));
}

void Shooter::bulletFire()
{
	this->shot->fire();
}

void Shooter::bulletMoveLeft()
{
	this->shot->setMovementEffect(MOVELEFT);
}

void Shooter::bulletMoveRight()
{
	this->shot->setMovementEffect(MOVERIGHT);
}

void Shooter::bulletDontMove()
{
	this->shot->setMovementEffect(NOMOVE);
}



Shooter::~Shooter()
{
	delete this->shot;
}

void Shooter::update()
{
	switch (this->move)
	{
	case NOMOVE:
		break;
	case MOVERIGHT:
		if(this->x + this->velocity * this->move < this->maxX - this->width/1.3)
			SpaceShip::update();
		break;
	case MOVELEFT:
		if (this->x + this->velocity * this->move >= -this->width/4.0)
			SpaceShip::update();
		break;
	}

	this->shot->update();


}

void Shooter::draw()
{
	SpaceShip::draw();
	this->shot->draw();
}

bool Shooter::bulletIsActive()
{
	return this->shot->isActive();
}

float Shooter::bulletGetTopLeftX()
{
	return this->shot->getXValue();
}

float Shooter::bulletGetTopLeftY()
{
	return this->shot->getYValue();
}

float Shooter::bulletGetBotRightX()
{
	return this->shot->getXValue() + this->shot->getWidth();
}

float Shooter::bulletGetBotRightY()
{
	return this->shot->getYValue() + this->shot->getHeight();
}

