
#include <stdio.h>
#include <vector>
#include "ImportantConstats.h"

#include "Game.h"
#include "AllegroClass.h"
#include "EventHandler.h"






bool startGame(ALLEGRO_EVENT_QUEUE * eq);


int main()
{
	AllegroClass allegro(DISPLAYW,DISPLAYH,REFRESHRATE);
	Game game("space.jpg");

	EventHandler eventSystem;

	shooterData dataS = { INITIALX_SHOOTER ,INITIALY_SHOOTER ,SPEED_SHOOTER , DISPLAYH, DISPLAYW,SPRITE_SHOOTER };
	bulletData dataB = { SPRITE_BULLET ,XSPEED_BULLET ,YSPEED_BULLET };
	game.setUpShooter(dataS, dataB);

	targetData dataT = { INITIALX_TARGET ,INITIALY_TARGET ,SPEED_TARGET,DISPLAYW, DISPLAYH,SPRITE_TARGET,NEW_STARGET_OFFSET };
	game.setUpTarget(dataT);

	targetData dataST = { INITIALX_STARGET ,INITIALY_STARGET ,SPEED_STARGET,DISPLAYW, DISPLAYH,SPRITE_STARGET,NEW_STARGET_OFFSET };
	dataST.loadBitmap();
	game.addMinion(dataST);

	textData dataSC = { INITIALX_SCORE ,INITIALY_SCORE ,WIDTH_SCORE ,HEIGHT_SCORE,FONTSIZE_SCORE, (string)"",FONTPATH_SCORE,FONTCOLOR_SCORE };
	game.setUpScoreboard(dataSC);

	textData dataM = { INITIALX_MENU ,INITIALY_MENU ,WIDTH_MENU ,HEIGHT_MENU,FONTSIZE_MENU, STRING_MENU,FONTPATH_MENU,FONTCOLOR_MENU };
	game.setUpStartboard(dataM);

	game.drawMenu();
	allegro.updateDisplay();
		
	while (startGame(allegro.getEventQueue())) {
		while (eventSystem.getEvent(allegro.getEventQueue()))
		{
			if (eventSystem.isThereEvent())
			{
				eventSystem.handleEventDispatcher(game);
				allegro.updateDisplay();
			}
		}
		game.drawMenu();
		allegro.updateDisplay();
	}



	return 0;
}



bool startGame(ALLEGRO_EVENT_QUEUE * eq) {

	ALLEGRO_EVENT ev;
	bool start = false, leave = false;

	while (!leave) {
		if (al_get_next_event(eq, &ev)){
			switch (ev.type) {
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				leave = true;
				break;
			case ALLEGRO_EVENT_KEY_DOWN:

				if (ev.keyboard.keycode == ALLEGRO_KEY_SPACE) {
					start = true;
					leave = true;
				}
				else if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
					leave = true;
			}
		}
	}

	al_flush_event_queue(eq);
	return start;
}