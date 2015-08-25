// Character.h 

#ifndef CHARACTER_H
#define CHARACTER_H

#include "SDL.h"
#include "SDLGraphics.h"
#include "constants.h"
#include "Die.h"

class Character
{
// Methods
public:
   // This class holds a pointer to the graphics object but will not destroy it.
   Character(SDLGraphics* graphics,
             int imageX, int imageY,
             int width, int height,
             int transparentR, int transparentG, int transparentB,
             const char* bitmapFileName,
             float x, float y,
             float maxSpeed);

   ~Character();

   // This must be called each frame
   void update(float deltaTime);

   void draw();

   void moveLeft();
   void moveRight();
   void moveUp();
   void moveDown();
   void stopMoving();

// Data
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
};

#endif

