#ifndef DIE_H
#define DIE_H

#include <cstdlib>
#include <ctime>


class Die
{
public:
	void setDieRoll(int cube, int num);
	int getDie();
	int calculateDie(int num, int cube);
	Die();
	Die(int cube, int num);

private:
	int randomNumber;
	int die;
};
#endif