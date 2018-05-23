#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_color.h>
#include <allegro5\allegro_image.h>

typedef struct bulletData
{
	const char * sprite;
	float xSpeed, ySpeed;
};

class bullet
{
public:
	bullet(float x_, float y_, float yVelocity_, const char * imagePath, float xVelocity_, float maxX_, float maxY_);
	void startOver(float x_, float y_);
	void setMovementEffect(int direction);
	
	void update();
	bool isActive();
	void fire();
	void draw();
	~bullet();

	bool collide(float x, float y, float w, float h);

	float getXValue();
	float getYValue();
	int getWidth();
	int getHeight();

private:
	bool yActive;
	int xActive;
	float x;			// Es el valor del medio del sprite
	float y;
	int height;
	int width;
	float maxX;
	float maxY;
	float yVelocity;
	float xVelocity;
	ALLEGRO_BITMAP * bitmap;
};

