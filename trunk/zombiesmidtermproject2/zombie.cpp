#include "zombie.h"


void zombie::setVelocity(int vel_X, int vel_Y)
{
	velX = vel_X;
	velY = vel_Y;
}

void zombie::setOffSet(int offX, int offY)
{
	x = offX;
	y = offY;
}

void zombie::setLife(int hitPoints, int cube, int num)
{
	life = hitPoints;
	myDie.setDieRoll(cube, num);
}

int zombie::calculateLife(int num, int cube, int hitPoints)
{
	life = 	myDie.calculateDie(num, cube);

	return life;
}

void zombie::zombieOutcome()
{
	switch(life)
	{
	case 0:
	case 1:
		cout << "Zombie Still Alive, and ATTACKS!" 
		<< endl;
		break;
	case 2:
		cout << "Zombie bites your ARMS OFF!" 
		<< endl;
		break;
	case 3:
		cout << "Zombie TEARS your FINGERS OFF!" 
		<< endl;
		break;
	case 4:
		cout << "You shoot the zombie in the FACE and dies!"
		<< endl;
		break;
	case 5:
		cout << "You INCENERATE the zombie and dies!"
		<< endl;
		break;
	case 6:
		cout << "You CUT OFF the zombie's head and dies!"
		<< endl;
		break;
	default:
		cout << "Invalid Die Roll" << endl;
	}
}

int zombie::getLife()
{
	return life;
}

int zombie::getVelocityX()
{
	return 	velX;
}

int zombie::getVelocityY()
{
	return velY;
}

int zombie::getOffSetX()
{
	return x;
}

int zombie::getOffSetY()
{
	return y;
}

void zombie::move()
{
	x += velX;//Moves zombie left or right
    
    //If the zombie went too far to the left or right
    if( ( x < 0 ) || ( x + ZOMBIE_WIDTH > SCREEN_WIDTH ) )
    {
        //move back
        x -= velX;    
    }
    
    //Moves the zombie up or down
    y += velY;
    
    //If the zombie went too far up or down
    if( ( y < 0 ) || ( y + ZOMBIE_HEIGHT > SCREEN_HEIGHT ) )
    {
        //move back
        y -= velY; 
	}


}

zombie::zombie()
{
	x = 0;
	y = 0;
	velX = 0;
	velY = 0;
	life = 0;
}

zombie::zombie(int vel_X, int vel_Y, int hitPoints, int offX, 
			   int offY, int num, int cube): myDie(cube, num)
{
	x = offX;
	y = offY;
	velX = vel_X;
	velY = vel_Y;
	life = hitPoints;
}

