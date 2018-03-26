#include "bullet.h"



bullet::bullet(float x_, float y_, int height_, int width_, float yVelocity_, const char * spritePath, float xVelocity_, float maxX_, float maxY_)
{
	this->x = x_;
	this->y = y_;
	this->height = height_;
	this->width = width_;
	this->yVelocity = yVelocity_;
	this->xVelocity = xVelocity_;
	this->yActive = false;
	this->xActive = 0;
	this->bitmap = al_load_bitmap(spritePath);
	this->maxX = maxX_;
	this->maxY = maxY_;
}

void bullet::update()
{
	if (this->yActive)
	{
		if (this->y - this->yVelocity > 0)
			this->y -= this->yVelocity;
		else
			this->yActive = false;

		if ((this->x - this->xVelocity > 0) && (this->x + this->xVelocity < this->maxX))
			this->x += this->xActive * this->xVelocity;

	}
}

bool bullet::isActive()
{
	return this->yActive;
}

void bullet::startOver(float x_, float y_)
{
	this->x = x_;
	this->y = y_;
	this->yActive = false;
}

float bullet::getXCoord()
{
	return this->x;
}

int bullet::getWidth()
{
	return this->width;
}

void bullet::setMovementEffect(int direction)
{
	if (this->yActive)
		this->xActive = direction;
}

float bullet::getYValue()
{
	return this->y;
}

void bullet::fire()
{
	this->yActive = true;
}

void bullet::draw()
{
	al_draw_bitmap(this->bitmap, this->x, this->y, 0);
}



bullet::~bullet()
{
	al_destroy_bitmap(this->bitmap);
}
