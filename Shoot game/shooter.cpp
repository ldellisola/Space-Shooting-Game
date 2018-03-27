#include "shooter.h"

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
	}


}
