#include "target.h"

bool Target::collision(float Ax, float Ay, float Dx, float Dy) // A is the top left and D bottom right
{
	bool retValue = false;

	if ((this->y + this->height >= Ay) && (this->y <= Dy))
		if ((Dx >= this->x) && (Ax < this->x + this->height))
			retValue = true;

	return retValue;
}



void Target::setMovement()
{
	if ((this->x <= 0))
		SpaceShip::setMovement(MOVERIGHT);
	else if (this->x + this->width >= this->maxX)
		SpaceShip::setMovement(MOVELEFT);


}

void Target::draw()
{
	al_draw_bitmap(this->bitmap, this->x, this->y, (this->move >= 0 ? 0 : ALLEGRO_FLIP_HORIZONTAL));
}

bool Target::isMainTarget()
{
	return mainTarget;
}


