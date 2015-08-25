#include "Die.h"

void Die::setDieRoll(int cube, int num)
{
	die = cube;
	randomNumber = num;
}

int Die::getDie()
{
	return die;
}


int Die::calculateDie(int num, int cube)
{
	srand(time(0));
	randomNumber = rand();
	die = (randomNumber%6)+ 1;

	return die;
}

Die::Die()
{
	die = 0;
	randomNumber = 0;
}

Die::Die(int cube, int num)
{
	die = cube;
	randomNumber = num;
}



