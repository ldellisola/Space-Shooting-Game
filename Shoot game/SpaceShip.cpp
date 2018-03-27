#include "SpaceShip.h"




SpaceShip::SpaceShip(float x_, float y_, float velocity_, const char * spritePath, float maxX_, float maxY_)
{
	this->x = x_;
	this->y = y_;
	this->maxX = maxX_;
	this->maxY = maxY_;
	this->velocity = velocity_;
	this->move = false;
	this->stringPath = spritePath;

	
}

void SpaceShip::init()
{
	this->bitmap = al_load_bitmap(this->stringPath);
	this->width = al_get_bitmap_width(this->bitmap);
	this->height = al_get_bitmap_height(this->bitmap);
}

SpaceShip::~SpaceShip()
{
	if (this->bitmap)
		al_destroy_bitmap(this->bitmap);
}

void SpaceShip::draw()
{
	al_draw_bitmap(this->bitmap, this->x, this->y, 0);
}

void SpaceShip::update()
{
	if (this->move)
		this->x += this->move * this->velocity;
}

void SpaceShip::setMovement(int direction)
{
	this->move = direction;
}

float SpaceShip::getXValue()
{
	return this->x;
}

float SpaceShip::getYValue()
{
	return this->y;
}


