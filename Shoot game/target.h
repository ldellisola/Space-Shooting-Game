#pragma once
#include "bullet.h"
#include "SpaceShip.h"
#include "ImportantConstats.h"

typedef struct targetData
{
	float x, y, speed, displayW, displayH;
	const char * sprite;
	float newOffset;
	ALLEGRO_BITMAP * bitmap;

	void loadBitmap() {
		bitmap = al_load_bitmap(sprite);
	}
	~targetData() {
		al_destroy_bitmap(bitmap);
	}
};


class Target : public SpaceShip
{
public:
	Target(float x_, float y_, float velocity_, float maxX_, float maxY_, const char * stringPath, bool mainTarget_)
		:SpaceShip(x_, y_, velocity_, stringPath, maxX_, maxY_) {
		mainTarget = mainTarget_;
	}
	Target(float x_, float y_, float velocity_,float maxX_, float maxY_, ALLEGRO_BITMAP * bitmap_, bool mainTarget_)
		:SpaceShip(x_, y_, velocity_, NULL, maxX_,maxY_) {
		this->bitmap = bitmap_;
		mainTarget = mainTarget_;
	}
	bool collision(float Ax, float Ay, float Dx, float Dy);
	void setMovement();
	void draw();
	bool isMainTarget();
	
private:
	bool mainTarget;
};

