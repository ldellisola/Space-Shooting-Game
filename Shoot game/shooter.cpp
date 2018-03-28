#include "shooter.h"

void shooterMan::createBullet(const char * spritePath_, float speedX_, float speedY_)
{
	this->shot = new bullet(this->x + (this->width / 2.0) + 5, this->y, speedY_, spritePath_, speedX_, this->maxX, this->maxY);
}

void shooterMan::bulletStartOver()
{
	this->shot->startOver(this->x + (this->width / 2.0) - (this->shot->getWidth() / 2.0) + 5, this->y - (this->shot->getHeight() / 2.0));
}

void shooterMan::bulletFire()
{
	this->shot->fire();
}

void shooterMan::bulletMoveLeft()
{
	this->shot->setMovementEffect(MOVELEFT);
}

void shooterMan::bulletMoveRight()
{
	this->shot->setMovementEffect(MOVERIGHT);
}

void shooterMan::bulletDontMove()
{
	this->shot->setMovementEffect(NOMOVE);
}



shooterMan::~shooterMan()
{
	delete this->shot;
}

void shooterMan::update()
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

void shooterMan::draw()
{
	SpaceShip::draw();
	this->shot->draw();
}

bool shooterMan::bulletIsActive()
{
	return this->shot->isActive();
}

float shooterMan::bulletGetTopLeftX()
{
	return this->shot->getXValue();
}

float shooterMan::bulletGetTopLeftY()
{
	return this->shot->getYValue();
}

float shooterMan::bulletGetBotRightX()
{
	return this->shot->getXValue() + this->shot->getWidth();
}

float shooterMan::bulletGetBotRightY()
{
	return this->shot->getYValue() + this->shot->getHeight();
}

