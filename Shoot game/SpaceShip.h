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
	void init();
	void draw();
	void update();
	void setMovement(int direction);
	float getXValue();
	float getYValue();
	

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

