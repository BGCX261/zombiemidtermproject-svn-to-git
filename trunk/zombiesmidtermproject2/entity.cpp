#include "entity.h"

Entity::Entity(SDLGraphics *graphics, SDL_Surface *bitmap, float x, float y, int imageX, int imageY, int width, int height): m_graphics(graphics),
																															 m_bitmap(bitmap),
																															 m_x(x), m_y(y),
																															 m_imageX(imageX),
																															 m_imageY(imageY),
																															 m_width(width),
																															 m_height(height)
{}


void Entity::Draw()
{
	m_graphics->drawSprite(m_bitmap,m_imageX, m_imageY,(int)m_x,
						  (int)m_y, m_width, m_height);

}
SDL_Rect Entity::getRect()
{
	SDL_Rect r;
	r.x = (int)m_x;
	r.y = (int)m_y;
	r.w = m_width;
	r.h = m_height;

	return r;
}