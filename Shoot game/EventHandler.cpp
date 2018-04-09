#include "EventHandler.h"



EventHandler::EventHandler()
{
}

Evnt trasformAllegroEvents(int key)
{
	Evnt ev = NOEVENT;

	switch (key)
	{
	case ALLEGRO_KEY_A:
		ev = LEFTB;
		break;
	case ALLEGRO_KEY_D:
		ev = RIGHTB;
		break;
	case ALLEGRO_KEY_LEFT:
		ev = LEFTS;
		break;
	case ALLEGRO_KEY_RIGHT:
		ev = RIGHTS;
		break;
	case ALLEGRO_KEY_ESCAPE:
		ev = QUIT;
		break;
	}
	return ev;
}

bool EventHandler::getEvent(ALLEGRO_EVENT_QUEUE * eq)
{
	ALLEGRO_EVENT ev;
	bool quit = false;

	al_get_next_event(eq, &ev);


	switch (ev.type)
	{
	case ALLEGRO_EVENT_KEY_DOWN:

		if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			quit = true;
		else
		{
			setEvent(trasformAllegroEvents(ev.keyboard.keycode), 0);
			this->events[0].activate();
		}

		break;
	case ALLEGRO_EVENT_KEY_UP:

		setEvent(KEYFREED, 0);
		this->events[0].activate();

		break;
	case ALLEGRO_EVENT_TIMER:
		this->setEvent(TIMER, 2);
		this->events[2].activate();



		break;
	case ALLEGRO_EVENT_DISPLAY_CLOSE:
		quit = true;
		break;
	}


	return !quit;
}

