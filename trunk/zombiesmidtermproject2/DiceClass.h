#ifndef DICECLASS_H
#define DICECLASS_H

#include "MersenneTwister.cpp"

class DiceClass
{
private:
	MTRand dice[2];
public:
	int rollDice(int dicenum)
	{
		if (dicenum < 0 || dicenum > 1)
			return 0;
		else
			return (dice[dicenum].randInt(5) + 1);
	}
};

#endif