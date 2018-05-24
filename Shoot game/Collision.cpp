#include "Collision.h"

void removeShips(vector<SpaceShip*>& ships, vector <int> &shipsExist, float y, float x, float w, float h);
vector<int> areThereShips(vector<SpaceShip*>& ships, float x, float y, float lenght);
bool isThereBullet(bullet& bullet, float x, float y, float lenght);

#define prueba 123

void collision(bullet & bullet, vector<SpaceShip*>& ships, int lenght, int x, int y, int size, CollisionType& retValue, int thresholdSize)
{
	bool papa =isThereBullet(bullet, x, y, lenght);
 
	vector <int> shipsExist = areThereShips(ships,x,y,lenght);

	if (!papa && shipsExist.size() != 0) {
		removeShips(ships, shipsExist,y,x ,lenght ,lenght );
		return;
	}
	else if (papa  && shipsExist.size() == 0) {
		return;
	}
	else if (retValue != CollisionType::NoCollision) {
		return;
	}
	else if (papa && shipsExist.size() != 0) {
		if (lenght < thresholdSize) {
			for (int pos : shipsExist) {
				if (bullet.collide(ships[pos]->getXValue(), ships[pos]->getYValue(), ships[pos]->getWValue(), ships[pos]->getHValue())) {
					if (ships[pos]->isMainTarget())
						retValue = CollisionType::CollisionPoint;
					else
						retValue = CollisionType::CollisionEnd;
					return;
				}
				return;
			}
		}
		else {
			collision(bullet, ships, lenght / 2, x, y, size, retValue, thresholdSize);
			collision(bullet, ships, lenght / 2, x + lenght / 2, y, size, retValue, thresholdSize);
			collision(bullet, ships, lenght / 2, x, y + lenght / 2, size, retValue, thresholdSize);
			collision(bullet, ships, lenght / 2, x + lenght / 2, y + lenght / 2, size, retValue, thresholdSize);
		}	
	}
}


void removeShips(vector<SpaceShip*>& ships, vector <int> &shipsExist, float y, float x, float w, float h) {

	for (int pos : shipsExist) {
		if (ships[pos]->getXValue() >x  && (ships[pos]->getXValue() + ships[pos]->getWValue()) < (x + w) )
			if ((ships[pos]->getYValue() > y && (ships[pos]->getYValue() + ships[pos]->getHValue()) < (y + h)))
				ships.erase(ships.begin() + pos);
	}
}

vector<int> areThereShips(vector<SpaceShip*>& ships, float x, float y, float lenght) {
	vector<int> ret;
	for (int i = ships.size()-1; i >=0 ; i--) {
		if (ships[i]->getXValue() + ships[i]->getWValue() >= x && ships[i]->getXValue() <= x + lenght)
			if (ships[i]->getYValue() + ships[i]->getHValue() >= y && ships[i]->getYValue() <= y + lenght)
				ret.push_back(i);
	}

	return ret;
}

bool isThereBullet(bullet& bullet, float x, float y, float lenght) {
	bool retValue = false;
	if (bullet.getXValue() + bullet.getWidth() >= x && bullet.getXValue() <= x + lenght)
		if (bullet.getYValue() + bullet.getHeight() >= y && bullet.getYValue() <= y + lenght)
			retValue = true;
	return retValue;
}

void findNextPower(unsigned int& num) {

	double log = log2(num);
	if (log - (unsigned int)log)					// Si es 0, entonces el numero ya es una potencia de dos.
		num = pow(2, (unsigned int)(log + 1));
}