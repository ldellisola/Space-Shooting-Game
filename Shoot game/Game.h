#pragma once
#include <allegro5\allegro.h>
#include <vector>
#include <array>
#include "shooter.h"
#include "target.h"
#include "ScoreBoard.h"
#include "StartBoard.h"
#include "Collision.h"
// Important Display Constants
#define DISPLAYW (1000)
#define DISPLAYH (1500)

// Important Timer Constants
#define REFRESHRATE (60.0)


// Important Shooter Constants
//#include "shooter.h"
#define YOFFSET_SHOOTER (DISPLAYH / 10.0)
#define INITIALX_SHOOTER ((DISPLAYW /2.0))
#define INITIALY_SHOOTER (DISPLAYH - YOFFSET_SHOOTER)
#define SPEED_SHOOTER (10.0)
#define SPRITE_SHOOTER "shooter.png"

// Important Bullet Constants
#define YSPEED_BULLET (8.0)
#define SPRITE_BULLET "bullet.png"
#define XSPEED_BULLET (1.0)

// Important Target Constants
//#include "target.h"
#define YOFFSET_TARGET (100)
#define INITIALX_TARGET (DISPLAYW /2.0)
#define INITIALY_TARGET (YOFFSET_TARGET)
#define SPEED_TARGET (0)
#define SPRITE_TARGET "MainTarget.png"

#define SPEED_STARGET (3)
#define NEW_STARGET_OFFSET (100)
#define INITIALX_STARGET (50)
#define INITIALY_STARGET (YOFFSET_TARGET + DISPLAYH / 10.0)
#define SPRITE_STARGET "SecTarget.png"

// Important Scoreboard Constatns
//#include "ScoreBoard.h"
#define INITIALX_SCORE (0)
#define INITIALY_SCORE (0)
#define WIDTH_SCORE (200)
#define HEIGHT_SCORE (100)
#define FONTSIZE_SCORE (30)
#define FONTPATH_SCORE "poke_font.ttf"
#define FONTCOLOR_SCORE "white"

// Important Scoreboard Constatns
//#include "StartBoard.h"
#define INITIALX_MENU (0)
#define INITIALY_MENU (DISPLAYH/2.0)
#define WIDTH_MENU (DISPLAYW)
#define HEIGHT_MENU (300)
#define FONTSIZE_MENU (30)
#define FONTPATH_MENU "poke_font.ttf"
#define FONTCOLOR_MENU "white"
#define STRING_MENU "Hello, press 'space' to play..."



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

