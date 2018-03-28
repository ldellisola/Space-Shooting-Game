#include "shooter.h"

void shooterMan::createBullet(const char * spritePath_, float speedX_, float speedY_)
{
	this->shot = new bullet(this->x + (this->width / 2.0), this->y, speedY_, spritePath_, speedX_, this->maxX, this->maxY);
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


}
