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
	Game(const char * bla);
	~Game();
	void update();
	void draw();
	void drawMenu();
	void setUpShooter(shooterData& dataS, bulletData& dataB);
	void addMinion(targetData& dataT);
	void addMinion();
	void setUpTarget(targetData& dataT);
	void setUpScoreboard(textData& dataSB);
	void setUpStartboard(textData& dataSB);

	void shoot();
	
	Shooter * shooter;
	vector<Target> minions;
	Target * target;
	level_t Level;

private:
	ALLEGRO_BITMAP * background;

	
	ScoreBoard * score;
	StartBoard * menu;

	targetData * dataMN;
	targetData * dataT;
	shooterData * dataS;

	



};

