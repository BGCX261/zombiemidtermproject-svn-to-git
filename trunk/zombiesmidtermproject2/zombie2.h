#ifndef ZOMBIE2_H
#define ZOMBIE2_H
#include "SDL.h"
#include "SDLGraphics.h"
#include "Die.h"
#include "constants.h"

class zombie
{
public:
	zombie(SDLGraphics* graphics, Die* myDie, int living,
                     int imageX, int imageY,
                     int width, int height,
                     int transparentR, int transparentG, int transparentB,
                     const char* bitmapFileName,
                     float x, float y,
                     float maxSpeed);
	~zombie();

	  // This must be called each frame
   void update(float deltaTime);

   void draw();

   void moveLeft();
   void moveRight();
   void moveUp();
   void moveDown();
   void stopMoving();
   void randomMovement();
   void lifeOutCome();

private:
   SDLGraphics* m_graphics;
   SDL_Surface* m_bitmap;

   float m_x;
   float m_y;
   float m_width;
   float m_height;

   float m_imageX;
   float m_imageY;

   float m_maxSpeed;
   float m_currentSpeedX;
   float m_currentSpeedY;

   int life;

   Die* m_die;
};

#endif