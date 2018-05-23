#pragma once

#include <math.h>
#include <vector>
#include "SpaceShip.h"
#include "bullet.h"
#include "AllegroClass.h"

using namespace std;

enum class CollisionType
{
	NoCollision, CollisionEnd, CollisionPoint
};



void collision(bullet & bullet, vector<SpaceShip*>& ships, int lenght, int x, int y, int size, CollisionType& retValue, int thresholdSize);

void findNextPower(unsigned int& num);