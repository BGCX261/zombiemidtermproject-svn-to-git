#ifndef ENTITY_H
#define ENTITY_H

#include "SDLGraphics.h"

class Entity
{
public:
	Entity(SDLGraphics* graphics, SDL_Surface* bitmap, float x, float y, int imageX, int imageY, int width, int height);
	Entity(){}
	virtual void Draw();
	SDL_Rect getRect();
	float getX(){return m_x;}
	float getY(){return m_y;}
	int getWidth(){return m_width;}
	int getHeight(){return m_height;}
	void setX(float x){m_x = x;}
	void setY(float y){m_y = y;}
	void setHeight(int height){m_height = height;}
	void setWidth(int width){m_width = width;}

protected:
	SDLGraphics* m_graphics;
	SDL_Surface* m_bitmap;
	int m_imageX;
	int m_imageY;
	float m_x;
	float m_y;
	int m_width;
	int m_height;
};
#endif