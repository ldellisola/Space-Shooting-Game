#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_color.h>
#include <allegro5\allegro_image.h>

class bullet
{
public:
	bullet(float x_, float y_, int height_, int width_, float yVelocity_, const char * imagePath, float xVelocity_, float maxX_, float maxY_);
	void startOver(float x_, float y_);
	float getXCoord();
	int getWidth();
	void setMovementEffect(int direction);
	float getYValue();
	void update();
	bool isActive();
	void fire();
	void draw();
	~bullet();
private:
	bool yActive;
	int xActive;
	float x;
	float y;
	int height;
	int width;
	float maxX;
	float maxY;
	float yVelocity;
	float xVelocity;
	ALLEGRO_BITMAP * bitmap;
};

