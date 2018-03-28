#include "target.h"

bool target::collision(float Ax, float Ay, float Dx, float Dy) // A is the top left and D bottom right
{
	bool retValue = false;

	if ((this->y + this->height >= Ay) && (this->y <= Dy))
		if ((Dx >= this->x) && (Ax < this->x + this->height))
			retValue = true;

	return retValue;
}



void target::setMovement()
{
	if ((this->x <= 0))
		SpaceShip::setMovement(MOVERIGHT);
	else if (this->x + this->width >= this->maxX)
		SpaceShip::setMovement(MOVELEFT);


}

void target::draw()
{
	switch (this->move)
	{
	case MOVERIGHT:
		al_draw_bitmap(this->bitmap, this->x, this->y, 0);
		break;
	case NOMOVE:
		al_draw_bitmap(this->bitmap, this->x, this->y, 0);
		break;
	case MOVELEFT:
		al_draw_rotated_bitmap(this->bitmap,this->width/2.0 ,this->height/2.0 , this->x + this->width/2.0 , this->y + this->height/2.0, ALLEGRO_PI, 0);
		break;

	
	}
}


