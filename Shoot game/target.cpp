#include "target.h"

bool target::collision(bullet * shot)
{
	bool retValue = false;

	if ( (shot->getYValue() <= this->y + this->height) && (shot->getYValue() >= this->y) )
		if ( (shot->getXCoord() <= this->x + this->width) && (shot->getXCoord() + shot->getWidth() > this->x) )
			retValue = true;
	return retValue;
}



void target::setMovement()
{
	if ((this->x <= 0))
		SpaceShip::setMovement(MOVERIGHT);
	else if (this->x + this->width >= al_get_display_width(al_get_current_display()))
		SpaceShip::setMovement(MOVELEFT);


}


