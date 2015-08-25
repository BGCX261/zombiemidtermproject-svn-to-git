#include "zombie2.h"

zombie::zombie(SDLGraphics* graphics, Die* myDie,int living,
                     int imageX, int imageY,
                     int width, int height,
                     int transparentR, int transparentG, int transparentB,
                     const char* bitmapFileName,
                     float x, float y,
                     float maxSpeed) : m_graphics(graphics), m_die(myDie), life(living),
                                       m_imageX(imageX), m_imageY(imageY),
                                       m_width(width), m_height(height),
                                       m_x(x), m_y(y),
                                       m_maxSpeed(maxSpeed),
                                       m_currentSpeedX(0.0f),
									   m_currentSpeedY(0.0f)
{
   m_bitmap = m_graphics->loadBitmap(bitmapFileName,
                                     transparentR, transparentG, transparentB);
	  
   
}

zombie::~zombie()
{
   m_graphics->closeBitmap(m_bitmap);
}

void zombie::update(float deltaTime)
{
   m_x += m_currentSpeedX * deltaTime;
   m_y += m_currentSpeedY * deltaTime;
}

void zombie::draw()
{
   m_graphics->drawSprite(m_bitmap,
                          m_imageX, m_imageY,
                          m_x, m_y,
                          m_width, m_height);
}

void zombie::moveLeft()
{
   m_currentSpeedX = -m_maxSpeed;
   if( m_x < 0)
   {
	 m_currentSpeedX = m_maxSpeed;	
   }
}

void zombie::moveRight()
{
   m_currentSpeedX = m_maxSpeed;
   if(m_x + ZOMBIE_SPRITE_IMAGE_WIDTH > WINDOW_WIDTH)
   {
	   m_currentSpeedX = -m_maxSpeed;
   }
}

void zombie::moveUp()
{
	m_currentSpeedY = -m_maxSpeed;
	if(m_y < 0)
	{
		m_currentSpeedY = m_maxSpeed;
	}
}

void zombie::moveDown()
{
	m_currentSpeedY = m_maxSpeed;
	if(m_y + ZOMBIE_SPRITE_IMAGE_HEIGHT > WINDOW_HEIGHT)
	{
		m_currentSpeedY = -m_maxSpeed;
	}
}

void zombie::stopMoving()
{
   m_currentSpeedX = 0.0f;
   m_currentSpeedY = 0.0f;
}

void zombie::randomMovement()
{
	switch(m_die->calculateDie(0,0))
	{
	case 1:
		switch(m_die->calculateDie(0,0))
		{
		case 1:moveDown();break;
		case 2:moveUp();break;
		case 3:moveRight();break;
		case 4:moveLeft();break;
		case 5:moveDown();break;
		case 6:moveUp();break;
		}
		break;
	case 2:
		switch(m_die->calculateDie(0,0))
		{
		case 1:moveUp();break;
		case 2:moveLeft();break;
		case 3:moveDown();break;
		case 4:moveRight();break;
		case 5:moveLeft();break;
		case 6:moveDown();break;
		}
		break;
	case 3:
		switch(m_die->calculateDie(0,0))
		{
		case 1:moveDown();break;
		case 2:moveRight();break;
		case 3:moveUp();break;
		case 4:moveLeft();break;
		case 5:moveDown();break;
		case 6:moveRight();break;
		}
		break;
	case 4:
		switch(m_die->calculateDie(0,0))
		{
		case 1:moveRight();break;
		case 2:moveUp();break;
		case 3:moveLeft();break;
		case 4:moveDown();break;
		case 5:moveRight();break;
		case 6:moveLeft();break;
		}
	case 5:
		switch(m_die->calculateDie(0,0))
		{
		case 1:moveLeft();break;
		case 2:moveRight();break;
		case 3:moveDown();break;
		case 4:moveUp();break;
		case 5:moveLeft();break;
		case 6:moveDown();break;
		}
		break;
	case 6:
		switch(m_die->calculateDie(0,0))
		{
		case 1:moveRight();break;
		case 2:moveLeft();break;
		case 3:moveDown();break;
		case 4:moveUp();break;
		case 5:moveLeft();break;
		case 6:moveDown();break;
		}
		break;

	}

}

void zombie::lifeOutCome()
{
	life = m_die->calculateDie(0,0);

	switch(life)
	{
	case 1:
		m_graphics->drawText("ZOMBIE BITES YOUR HEAD OFF !",
							  20, 250, 
							  0,250, 
							  0, 0, 
							  0, 0, 0);
		break;
	case 2:
		m_graphics->drawText("ZOMBIE TEARS YOUR ARMS OFF !",
							  20, 250, 
							  0,250, 
							  0, 0, 
							  0, 0, 0);
		break;
	case 3:
		m_graphics->drawText("YOU SHOOT THE ZOMBIE TO PIECES!",
							  20, 250, 
							  0,250, 
							  0, 0, 
							  0, 0, 0);
		break;
	case 4:
		m_graphics->drawText("YOU SHOOT THE ZOMBIE'S ARMS OFF!",
							  20, 250, 
							  0,250, 
							  0, 0, 
							  0, 0, 0);
		break;
	case 5:
		m_graphics->drawText("YOU SHOOT THE ZOMBIE IN HALF!",
							  20, 250, 
							  0,250, 
							  0, 0, 
							  0, 0, 0);

		break;
	case 6:
		m_graphics->drawText("YOU SHOOT THE ZOMBIE'S HEAD OFF!",
							  20, 250, 
							  0,250, 
							  0, 0, 
							  0, 0, 0);
		m_graphics->endScene();
		break;

	}

	

}