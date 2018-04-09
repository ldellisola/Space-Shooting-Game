#pragma once

#include <allegro5\allegro.h>
#include <array>
#include "Game.h"

using namespace std;

typedef enum Evnt
{
	LEFTB, RIGHTB,LEFTS, RIGHTS, NOEVENT, SHOOT, TIMER, KEYFREED, QUIT
};

typedef struct {
	Evnt Event;
	bool active;

	void activate() {
		active = true;
	}
	void deactivate() {
		active = false;
	}

}Ev_t;

class EventHandler {
public:
	EventHandler();

	bool getEvent(ALLEGRO_EVENT_QUEUE *  eq);		// Gets the event from the event queue and/or other mediums not yet implemented
	bool isThereEvent();							// Checks if there is an active event
private:

	void setEvent(Evnt ev, int worm);				// Sets the event but it does not activate it.
	void dispatchEvent(Evnt ev, Game& game);		// The actual dispatcher for every single event


	array<Ev_t, 3> events;
}