#ifndef HANDLE_EVENTS_H
#define HANDLE_EVENTS_H

#include "SDL.h"
#include "zombie.h"

class Handle_Events
{
public:
	void setHandle_Events(int vel_X, int vel_Y, int hitPoints, int offX, int offY, int num, int cube, bool On, int x, int y);
	Handle_Events(int vel_X = 0, int vel_Y = 0, int hitPoints = 0, int offX = 0, int offY = 0, int num = 0, int cube = 0, bool On = true, int x = 0, int y = 0);
	bool getRunning();
	void event_state();
	~Handle_Events();


private:
	SDL_Event event;
	zombie myZombie;
	int speedX, speedY;
	bool isRunning;
};

#endif