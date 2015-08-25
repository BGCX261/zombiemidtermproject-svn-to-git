#include "Animation.h"

Animation::Animation()
{
	status = 0;
	frame = 0;
}

Animation::~Animation()
{
}

Animation::Animation(int state, int scene)
{
	status = state;
	frame = scene;
}

int Animation::getFrame()
{
	return frame;
}

int Animation::getStatus()
{
	return status;
}

void Animation::setFrame(int scene)
{
	frame = scene;
}

void Animation::setStatus(int state)
{
	status = state;
}
