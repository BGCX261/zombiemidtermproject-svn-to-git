#include "Handle_Events.h"

Handle_Events::Handle_Events(int vel_X, int vel_Y, int hitPoints, int offX, int offY, int num, int cube, bool On, int x, int y): myZombie(vel_X,vel_Y,hitPoints,offX,offY,num,cube)
{
	isRunning = On;
	speedX = x;
	speedY = y;
}

void Handle_Events::setHandle_Events(int vel_X, int vel_Y, int hitPoints, int offX, int offY, int num, int cube, bool On, int x, int y)
{
	myZombie.setVelocity(vel_X,vel_Y);
	myZombie.setOffSet(offX, offY);
	myZombie.setLife(hitPoints,num,cube);

	speedX = y;
	speedY = x;
	isRunning = On;

}

bool Handle_Events::getRunning()
{
	return isRunning;
}

Handle_Events::~Handle_Events()
{
}

void Handle_Events::event_state()
{

	while(SDL_PollEvent(&event))
	{
		
		switch(event.type)
		{
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
			{//if( event.type == SDL_KEYDOWN )
        //Set the velocity
        //switch( event.key.keysym.sym )
        //{
			case SDLK_RIGHT: speedX  += ZOMBIE_WIDTH; break;
			case SDLK_LEFT:	 speedX  -= ZOMBIE_WIDTH; break;
			case SDLK_UP: speedY  += ZOMBIE_HEIGHT; break;
			case SDLK_DOWN: speedY -= ZOMBIE_HEIGHT; break;
			case SDLK_ESCAPE: isRunning = false; break;
			}
			break;
		case SDL_KEYUP:
			switch(event.key.keysym.sym)
			{
				case SDLK_RIGHT: speedX  -= ZOMBIE_WIDTH; break;
				case SDLK_LEFT:speedX  += ZOMBIE_WIDTH; break;
				case SDLK_UP: speedY -= ZOMBIE_HEIGHT; break;
				case SDLK_DOWN: speedY += ZOMBIE_HEIGHT; break;
			}
			break;
		case SDL_QUIT:
			isRunning = false;
			break;
		}
	}
}





//        }
//    }
//    //If a key was released
//    else if( event.type == SDL_KEYUP )
//    {
//        //Set the velocity
//        switch( event.key.keysym.sym )
//        {
//		case SDLK_RIGHT: VelX  -= ZOMBIE_WIDTH / 4; break;
//		case SDLK_LEFT:VelX  += ZOMBIE_WIDTH / 4; break;
//		case SDLK_UP: VelY -= ZOMBIE_HEIGHT / 4; break;
//		case SDLK_DOWN: VelY += ZOMBIE_HEIGHT/ 4; break;
//		case SDL_QUIT: isRunning = false; break;
//        }
//    }
//
//}