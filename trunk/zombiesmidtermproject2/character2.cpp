// Character.cpp 

#include "character2.h"

Character::Character(SDLGraphics* graphics,
                     int imageX, int imageY,
                     int width, int height,
                     int transparentR, int transparentG, int transparentB,
                     const char* bitmapFileName,
                     float x, float y,
                     float maxSpeed) : m_graphics(graphics),
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

Character::~Character()
{
   m_graphics->closeBitmap(m_bitmap);
}

void Character::update(float deltaTime)
{
   m_x += m_currentSpeedX * deltaTime;
   m_y += m_currentSpeedY * deltaTime;
}

void Character::draw()
{
   m_graphics->drawSprite(m_bitmap,
                          m_imageX, m_imageY,
                          m_x, m_y,
                          m_width, m_height);
}

void Character::moveLeft()
{
   m_currentSpeedX = -m_maxSpeed;

   if( m_x < 0)
   {
	 m_currentSpeedX = m_maxSpeed;	
   }
}

void Character::moveRight()
{
   m_currentSpeedX = m_maxSpeed;

   if(m_x + SPRITE_PLAYER_IMAGE_WIDTH > WINDOW_WIDTH)
   {
	   m_currentSpeedX = -m_maxSpeed;
   }
}

void Character::moveUp()
{
	m_currentSpeedY = -m_maxSpeed;
	if(m_y < 0)
	{
		m_currentSpeedY = m_maxSpeed;
	}
}

void Character::moveDown()
{
	m_currentSpeedY = m_maxSpeed;
	if(m_y + SPRITE_PLAYER_IMAGE_HEIGHT > WINDOW_HEIGHT)
	{
		m_currentSpeedY = -m_maxSpeed;
	}
}

void Character::stopMoving()
{
   m_currentSpeedX = 0.0f;
   m_currentSpeedY = 0.0f;
}



