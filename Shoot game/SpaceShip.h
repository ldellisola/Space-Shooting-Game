#pragma once
#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_color.h>
#include <allegro5\allegro_image.h>

class SpaceShip
{
public:
	SpaceShip(float x_, float y_, float velocity_, const char * spritePath, float maxX_, float maxY_);
	~SpaceShip();
	virtual void init();
	virtual void draw();
	virtual void update();
	virtual void setMovement(int direction);
	virtual float getXValue();
	virtual float getYValue();
	virtual float getWValue();
	virtual float getHValue();
	virtual void setCoord(float x_, float y_);
	virtual bool isMainTarget() = 0;
	

protected:
	int move;
	float maxX;
	float maxY;
	float x;
	float y;
	int width;
	int height;
	float velocity;
	const char * stringPath;
	ALLEGRO_BITMAP * bitmap = NULL;


};

