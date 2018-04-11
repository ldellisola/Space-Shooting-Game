#pragma once

#include <allegro5\allegro.h>
#include <array>
#include "Game.h"
#include "Timer.h"

using namespace std;

typedef enum Evnt
{
	LEFTB, RIGHTB,LEFTS, RIGHTS, NOEVENT, SHOOT, TIMER, QUIT
};

typedef struct {
	Evnt Event;
	Evnt lastEv;
	Timer * time;
	bool active;
	int keycode;

	void activate() {
		if (Event == NOEVENT)
			Event = lastEv;
		active = true;
	}
	void deactivate() {
		active = false;
		lastEv = Event;

	}
	void newTimer() {
		time = new Timer();
	}
	bool timerExist() {
		return time != NULL;
	}

	void killTimer() {
		delete time;
		time = NULL;
	}

	bool timerGreaterThan(float ms)
	{
		bool retValue = false;
		time->stop();
		if (time->getTime() >= ms)
			retValue = true;
		killTimer();

		return retValue;
	}
}Ev_t;

class EventHandler {
public:
	EventHandler();

	bool getEvent(ALLEGRO_EVENT_QUEUE *  eq);		// Gets the event from the event queue and/or other mediums not yet implemented
	bool isThereEvent();							// Checks if there is an active event
	void handleEventDispatcher(Game& game);
private:

	void setEvent(Evnt ev, int element);				// Sets the event but it does not activate it.
	void dispatchEvent(Evnt ev, Game& game);		// The actual dispatcher for every single event


	array<Ev_t, 3> events;
};