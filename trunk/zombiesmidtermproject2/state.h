#ifndef STATE_H
#define STATE_H

#include "constants.h"
#include "SDLGraphics.h"
#include "input.h"
#include "timer.h"

class stateManager;

class state
{
public:
	state(SDLGraphics* graphics, Input* input): m_graphics(graphics),
												m_input(input),
												m_isRunning(true)
	{}

	state(){}

	virtual bool run(stateManager* state_manager)= 0;

	virtual bool handleInput(stateManager* state_manager)= 0;


protected:
	SDLGraphics* m_graphics;
	Input* m_input;

	bool m_isRunning;
};
#endif