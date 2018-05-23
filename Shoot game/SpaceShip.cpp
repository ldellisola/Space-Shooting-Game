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
	if (this->stringPath)
		this->bitmap = al_load_bitmap(this->stringPath);
	this->width = al_get_bitmap_width(this->bitmap);
	this->x -= this->width / 2.0;
	this->height = al_get_bitmap_height(this->bitmap);
	
}

SpaceShip::~SpaceShip()
{
	if (stringPath)				// If string != NULL it means that the class created the bitmap, not the structure and therefor
		al_destroy_bitmap(this->bitmap);	// It must destroy it
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

float SpaceShip::getWValue()
{
	return this->width;
}

float SpaceShip::getHValue()
{
	return this->height;
}

void SpaceShip::setCoord(float x_, float y_)
{
	this->x = x_ - this->width/2.0;
	this->y = y_;
}


