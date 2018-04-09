#pragma once
#include <allegro5\allegro.h>
#include <vector>
#include <array>
#include "shooter.h"
#include "target.h"
#include "ScoreBoard.h"
#include "StartBoard.h"

#define HITSPERLEVEL (2)

using namespace std;

typedef struct {
	unsigned int number = 1;
	bool newLevelAchieved = false;
	bool gameMenu = true;
	void newLevel() {
		++number;
		newLevelAchieved = true;
	}
}level_t;

class Game
{
public:
	Game();
	~Game();
	void update();
	void draw();
	void setUpShooter(shooterData& dataS, bulletData& dataB);
	void addMinion(targetData& dataT);
	void addMinion();
	void setUpTarget(targetData& dataT);
	void setUpScoreboard(textData& dataSB);
	void setUpStartboard(textData& dataSB);
	


private:
	ALLEGRO_BITMAP * background;

	Shooter * shooter;
	vector<Target> minions;
	Target * target;
	ScoreBoard * score;
	StartBoard * menu;

	targetData * dataMN;
	targetData * dataT;
	shooterData * dataS;

	level_t Level;



};

