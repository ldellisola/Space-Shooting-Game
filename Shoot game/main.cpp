#include <allegro5\allegro.h>
#include <allegro5\allegro_color.h>
#include <stdio.h>
#include <vector>
#include "ImportantConstats.h"

// Important compiling stuff

#define FONT_C
//#define AUDIO_C
#define KEYBOARD_C
#define MOUSE_C
#define IMAGE_C

// Important Display Constants
#define DISPLAYW (1000)
#define DISPLAYH (1500)

// Important Timer Constants
#define REFRESHRATE (60.0)

// Important Font Constants
#ifdef FONT_C
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#define FONTPATH "path"
#define FONTSIZE (10)
#endif

// Important Music Constants
#ifdef AUDIO_C
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_audio.h>
#define SONGPATH "path"
#define NUMBEROFSAMPLES (1)
#define VOLUME (1.0)
#define SONGSPEED (1.0)
#endif

// Important Image Constants
#ifdef IMAGE_C
#include <allegro5\allegro_image.h>
#endif

// Important Shooter Constants
#include "shooter.h"
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
#include "target.h"
#define YOFFSET_TARGET (100)
#define INITIALX_TARGET (DISPLAYW /2.0)
#define INITIALY_TARGET (YOFFSET_TARGET)
#define SPEED_TARGET (0)
#define SPRITE_TARGET "MainTarget.png"

#define SPEED_STARGET (3)
#define INITIALX_STARGET (0)
#define INITIALY_STARGET (YOFFSET_TARGET + DISPLAYH / 10.0)
#define SPRITE_STARGET "SecTarget.png"

// Important Scoreboard Constatns
#include "ScoreBoard.h"
#define INITIALX_SCORE (0)
#define INITIALY_SCORE (0)
#define WIDTH_SCORE (200)
#define HEIGHT_SCORE (100)
#define FONTSIZE_SCORE (30)
#define FONTPATH_SCORE "poke_font.ttf"
#define FONTCOLOR_SCORE "white"



using namespace std;

enum resources
{
	ALLEGRO, DISPLAY,SCREENBITMAP, EVENTQUEUE, TIMER, TTFADDON, FONT, AUDIO, CODEC, SONG, RESERVESAMPLES, IMAGE, LAST
};

bool resourcesLoaded(bool * array, int size);

int main()
{
	ALLEGRO_DISPLAY * display = NULL;
	ALLEGRO_EVENT_QUEUE * eventQueue = NULL;
	ALLEGRO_TIMER * timer = NULL;
	ALLEGRO_BITMAP * screen = NULL;
#ifdef FONT_C
	ALLEGRO_FONT * font = NULL;
#endif
#ifdef AUDIO_C
	ALLEGRO_SAMPLE * song = NULL;
#endif
	ALLEGRO_BITMAP * bitmap_ = NULL;


	
	bool keep = true;


	bool initResources[LAST];
	for (int i = 0; i < LAST; ++i)
		initResources[i] = false;

	if (al_init())
	{
		initResources[ALLEGRO] = true;
#ifdef KEYBOARD_C
		al_install_keyboard();
#endif
#ifdef MOUSE_C
		al_install_mouse();
#endif
#ifdef IMAGE_C
		if (al_init_image_addon())
			initResources[IMAGE] = true;
#else
		initResources[IMAGE] = true;
#endif

		if (display = al_create_display(DISPLAYW, DISPLAYH))
		{
			initResources[DISPLAY] = true;
			
			if (screen = al_load_bitmap("space.jpg"))
				initResources[SCREENBITMAP] = true;
		}
		if (eventQueue = al_create_event_queue())
			initResources[EVENTQUEUE] = true;
		if (timer = al_create_timer(1 / REFRESHRATE))
			initResources[TIMER] = true;



#ifdef FONT_C
		al_init_font_addon();
		if (al_init_ttf_addon())
		{
			initResources[TTFADDON] = true;
		
				initResources[FONT] = true;
		}
#else
		initResources[TTFADDON] = true;
		initResources[FONT] = true;
#endif

#ifdef AUDIO_C
		if (al_install_audio())
			initResources[AUDIO] = true;
		if (al_init_acodec_addon())
			initResources[CODEC] = true;
		if (al_reserve_samples(NUMBEROFSAMPLES))
		{
			initResources[RESERVESAMPLES] = true;
			if (song = al_load_sample(SONGPATH))
				initResources[SONG] = true;
		}
#else
		initResources[AUDIO] = true;
		initResources[CODEC] = true;
		initResources[RESERVESAMPLES] = true;
		initResources[SONG] = true;
#endif
	}

	if (resourcesLoaded(initResources, LAST))
	{
		shooterMan shooter(INITIALX_SHOOTER, INITIALY_SHOOTER, SPRITE_SHOOTER, SPEED_SHOOTER,DISPLAYW,DISPLAYH);
		shooter.init();
		shooter.createBullet(SPRITE_BULLET, XSPEED_BULLET, YSPEED_BULLET);
		target mainTarget(INITIALX_TARGET, INITIALY_TARGET, SPEED_TARGET,DISPLAYW, DISPLAYH, SPRITE_TARGET);
		mainTarget.init();
		ScoreBoard board(INITIALX_SCORE, INITIALY_SCORE, WIDTH_SCORE, HEIGHT_SCORE, FONTSIZE_SCORE,(string) "" , FONTPATH_SCORE, FONTCOLOR_SCORE);
		
		vector<target> drones;
		drones.reserve(3);
		for (int i = 1; i < 4; ++i)
			drones.emplace_back(target(INITIALX_STARGET, INITIALY_STARGET * i, SPEED_STARGET * i, DISPLAYW, DISPLAYH, SPRITE_STARGET));

		for (target& ship : drones)
			ship.init();

		al_register_event_source(eventQueue, al_get_display_event_source(display));
		al_register_event_source(eventQueue, al_get_timer_event_source(timer));
#ifdef MOUSE_C
		al_register_event_source(eventQueue, al_get_mouse_event_source());
#endif
#ifdef KEYBOARD_C
		al_register_event_source(eventQueue, al_get_keyboard_event_source());
#endif

		al_start_timer(timer);

#ifdef AUDIO_C
		al_play_sample(song, VOLUME, 0, SONGSPEED, ALLEGRO_PLAYMODE_LOOP, NULL);
#endif

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
						if (! shooter.bulletIsActive())
							shooter.bulletFire();
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
					if (!shooter.bulletIsActive())
						shooter.bulletStartOver();
					else
						if (mainTarget.collision(shooter.bulletGetTopLeftX(),shooter.bulletGetTopLeftY(), shooter.bulletGetBotRightX(), shooter.bulletGetBotRightY())) // Tengo que repensar esto. no deberia mandar el objeto
						{
							shooter.bulletStartOver();
							board.updateScore();
						}
						else 
							for (target& ship : drones)
							{
								if (ship.collision(shooter.bulletGetTopLeftX(), shooter.bulletGetTopLeftY(), shooter.bulletGetBotRightX(), shooter.bulletGetBotRightY()))
								{
									shooter.bulletStartOver();
									board.reset();
								}

							}

					al_draw_bitmap(screen, 0, 0, 0);	
					board.draw();
					mainTarget.draw();
					shooter.update();
					shooter.draw();
					for (target& ship : drones)
					{
						ship.setMovement();
						ship.update();
						ship.draw();
					}

					al_flip_display();
				}
			}
		}

	}
	else
	{
		printf("Resources were not loaded properly\n Shutting down\n");
		getchar();
	}





#ifdef AUDIO_C
	al_stop_samples();
	if (initResources[CODEC] && initResources[AUDIO] && initResources[RESERVESAMPLES])
	{
		if (initResources[SONG])
			al_destroy_sample(song);
	}
#endif
#ifdef FONT_C
	if (initResources[TTFADDON])
	{
		if (initResources[FONT])
			al_destroy_font(font);
	}
#endif

	if (initResources[EVENTQUEUE])
		al_destroy_event_queue(eventQueue);

	if (initResources[TIMER])
		al_destroy_timer(timer);

	if (initResources[DISPLAY])
	{
		al_destroy_display(display);
		if(initResources[SCREENBITMAP])
			al_destroy_bitmap(screen);
	}
	
	
	return 0;
}

bool resourcesLoaded(bool * array, int size)
{
	bool retValue = true;

	for (int i = 0; (i < size) && retValue; ++i)
		if (array[i] == false)
			retValue = false;
	return retValue;
}
