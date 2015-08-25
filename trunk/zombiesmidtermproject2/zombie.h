#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Defines.h"
#include "Die.h"
#include "SDL.h"
#include "SDLGraphics.h"
#include <iostream>

using namespace std;

class zombie
{
public:
	void setVelocity(int vel_X, int vel_Y);
	void setOffSet(int offX, int offY);
	void setLife(int hitPoints, int num, int cube);
	int calculateLife(int num, int cube, int hitPoints);
	void zombieOutcome();
	int getLife();
	int getVelocityX();
	int getVelocityY();
	int getOffSetX();
	int getOffSetY();
	void move();
	zombie();
	zombie(int vel_X, int vel_Y, int hitPoints, 
		   int offX, int offY, int num = 0, int cube = 0);

private:
	int x, y;
	int velX, velY;
	int life;
	Die myDie;
};
#endif