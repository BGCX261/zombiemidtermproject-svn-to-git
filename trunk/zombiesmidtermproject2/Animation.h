#ifndef ANIMATION_H
#define ANIMATION_H

#include "zombie.h"
#include "Defines.h"

class Animation
{
public:
	int getFrame();
	int getStatus();
	void setFrame(int scene);
	void setStatus(int state);
	Animation();
	~Animation();
	Animation(int state, int scene);
private:
	int status;
	int frame;
};
#endif