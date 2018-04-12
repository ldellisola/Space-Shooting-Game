#include "EventHandler.h"

bool validKey(int key, int i);

EventHandler::EventHandler()
{
	for (Ev_t& ev : events)
	{
		ev.deactivate();
		ev.time = NULL;
	}
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
	case ALLEGRO_KEY_SPACE:
		ev = SHOOT;
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
			for (int i = 0; i < 2; ++i)
				if (!this->events[i].active && validKey(ev.keyboard.keycode, i) && !this->events[i].timerExist())
					setEvent(trasformAllegroEvents(ev.keyboard.keycode), i);
		}

		break;
	case ALLEGRO_EVENT_KEY_UP:

		for (int i = 0; i < 2; ++i)
			if (this->events[i].timerExist() && this->events[i].Event == trasformAllegroEvents(ev.keyboard.keycode))
				this->events[i].killTimer();

		break;
	case ALLEGRO_EVENT_TIMER:
		this->setEvent(TIMER, 2);
		this->events[2].activate();

		for (int i = 0; i < 2; ++i)
			if (!this->events[i].active && this->events[i].timerExist())
			{
				this->events[i].time->stop();
				if (this->events[i].time->getTime() >= 10)
				{
					this->events[i].activate();
					this->events[i].time->start();
				}
			}

		break;
	case ALLEGRO_EVENT_DISPLAY_CLOSE:
		quit = true;
		break;
	}

	if (quit)
		for (int i = 0; i < 2; i++)
			if (this->events[i].timerExist())
				this->events[i].killTimer();

	return !quit;
}

bool EventHandler::isThereEvent()
{
	return this->events[0].active || this->events[1].active || this->events[2].active;
}

void EventHandler::handleEventDispatcher(Game& game)
{
	for (int i = 0; i <this->events.size(); i++)
	{
		if (this->events[i].active)
		{
			dispatchEvent(this->events[i].Event, game);
			this->events[i].deactivate();
		}
	}
}

void EventHandler::setEvent(Evnt ev, int element)
{

	this->events[element].Event = ev;

	if (ev != TIMER)
		this->events[element].newTimer();
}

void EventHandler::dispatchEvent(Evnt ev, Game& game)
{
	switch (ev)
	{
	case LEFTB:if (!game.Level.gameMenu) game.shooter->bulletMoveLeft(); break;
	case RIGHTB:if (!game.Level.gameMenu)game.shooter->bulletMoveRight(); break;
	case LEFTS:if (!game.Level.gameMenu)game.shooter->setMovement(MOVELEFT);; break;
	case RIGHTS:if (!game.Level.gameMenu)game.shooter->setMovement(MOVERIGHT);; break;
	case SHOOT: if (!game.Level.gameMenu)game.shoot();
				else game.Level.gameMenu = false; break;
	case TIMER: if (!game.Level.gameMenu)game.update(); game.draw(); break;
	default: game.shooter->setMovement(NOMOVE);  game.shooter->bulletDontMove(); break;
	}

}

bool validKey(int key, int i)
{
	bool retValue = false;

	switch (i)
	{
	case 0: retValue = (key == ALLEGRO_KEY_LEFT) || (key == ALLEGRO_KEY_RIGHT) || (key == ALLEGRO_KEY_SPACE);
		break;
	case 1: retValue = (key == ALLEGRO_KEY_A) || (key == ALLEGRO_KEY_D);
		break;
	}
	return retValue;
}