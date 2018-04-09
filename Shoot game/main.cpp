
#include <stdio.h>
#include <vector>
#include "ImportantConstats.h"

#include "Game.h"
#include "AllegroClass.h"


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
#define FONTSIZE_MENU (50)
#define FONTPATH_MENU "poke_font.ttf"
#define FONTCOLOR_MENU "white"
#define STRING_MENU "Hello there, press 'space' to play..."








using namespace std;



int main()
{
	AllegroClass allegro(DISPLAYW,DISPLAYH,REFRESHRATE);
	Game game;

	shooterData dataS = { INITIALX_SHOOTER ,INITIALY_SHOOTER ,SPEED_SHOOTER , DISPLAYH, DISPLAYW,SPRITE_SHOOTER };
	bulletData dataB = { SPRITE_BULLET ,XSPEED_BULLET ,YSPEED_BULLET };
	game.setUpShooter(dataS, dataB);

	targetData dataT = { INITIALX_TARGET ,INITIALY_TARGET ,SPEED_TARGET,DISPLAYW, DISPLAYH,SPRITE_TARGET,NEW_STARGET_OFFSET };
	game.setUpTarget(dataT);

	targetData dataST = { INITIALX_STARGET ,INITIALY_STARGET ,SPEED_STARGET,DISPLAYW, DISPLAYH,SPRITE_STARGET,NEW_STARGET_OFFSET };
	game.addMinion(dataST);

	textData dataSC = { INITIALX_SCORE ,INITIALY_SCORE ,WIDTH_SCORE ,HEIGHT_SCORE,FONTSIZE_SCORE, (string)"",FONTPATH_SCORE,FONTCOLOR_SCORE };
	game.setUpScoreboard(dataSC);

	textData dataM = { INITIALX_MENU ,INITIALY_MENU ,WIDTH_MENU ,HEIGHT_MENU,FONTSIZE_MENU, STRING_MENU,FONTPATH_MENU,FONTCOLOR_MENU };
	game.setUpStartboard(dataM);
		
	bool keep = true;

		while (keep)
		{
			ALLEGRO_EVENT ev;

			if (al_get_next_event(eventQueue, &ev))
			{
				switch (ev.type)
				{
				case ALLEGRO_EVENT_DISPLAY_CLOSE:
					keep = false;
					break;
				case ALLEGRO_EVENT_KEY_DOWN:
					switch (ev.keyboard.keycode)
					{
					case ALLEGRO_KEY_SPACE:
						if (!Level.gameMenu)
						{
							if (!shooter.bulletIsActive())
								shooter.bulletFire();
						}
						else
							Level.gameMenu = false;

						break;
					case ALLEGRO_KEY_ESCAPE:
						keep = false;
						break;
					case ALLEGRO_KEY_LEFT:
						shooter.setMovement(MOVELEFT);
						break;
					case ALLEGRO_KEY_RIGHT:
						shooter.setMovement(MOVERIGHT);
						break;
					case ALLEGRO_KEY_A:
						shooter.bulletMoveLeft();
						break;
					case ALLEGRO_KEY_D:
						shooter.bulletMoveRight();
						break;
					}
					break;
				case ALLEGRO_EVENT_KEY_UP:
					shooter.setMovement(NOMOVE);
					shooter.bulletDontMove();
					break;
				

				case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
					break;
				case ALLEGRO_EVENT_TIMER:
					game.update();
					game.draw();
					allegro.updateDisplay();
					break;
				}
			}
		}






	
	
	return 0;
}

