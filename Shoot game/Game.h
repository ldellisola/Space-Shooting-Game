#pragma once
#include <allegro5\allegro.h>
#include <vector>
#include <array>
#include "shooter.h"
#include "target.h"
#include "ScoreBoard.h"
#include "StartBoard.h"

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
	void setUpTarget(targetData& dataT);
	void setUpScoreboard(textData& dataSB);
	void setUpStartboard(textData& dataSB);
	
	Shooter * shooter;
	vector<Target> minions;
	Target * target;

private:
	ALLEGRO_BITMAP * background;
	ScoreBoard * score;
	StartBoard * menu;
	level_t Level;

};
