#ifndef MATH_H
#define MATH_H

#include <time.h>
#include <math.h>

inline bool pointInRect(int point_x, int point_y, 
						int rect_x, int rect_y, 
						int rect_w, int rect_h)
{
	if((point_x >= rect_x)&&(point_x <= rect_x + rect_w-1))
	{
		if ( (point_y >= rect_y) && (point_y <= rect_y + rect_h - 1) )
		{
			return true;
		}
	}
	return false;
}

inline bool pointInRect(int point_x, int point_y, SDL_Rect rect)
{
	return pointInRect(point_x, point_y, rect.x, rect.y, rect.w, rect.h);
}

inline bool rectOnRectCollision(int rect1_x, int rect1_y, int rect1_w, int rect1_h,
								int rect2_x, int rect2_y, int rect2_w, int rect2_h)	
{
	// Check to see if any of rect1's corners are in rect2 
	
	// top-left corner
	if ( pointInRect(rect1_x, rect1_y, rect2_x, rect2_y, rect2_w, rect2_h) )
	{
		return true;
	}

	// top-right corner
	if ( pointInRect(rect1_x + rect1_w - 1, rect1_y, rect2_x, rect2_y, rect2_w, rect2_h) )
	{
		return true;
	}

	// bottom-right corner
	if ( pointInRect(rect1_x + rect1_w - 1, rect1_y + rect1_h - 1, rect2_x, rect2_y, rect2_w, rect2_h) )
	{
		return true;
	}

	// bottom-left corner
	if ( pointInRect(rect1_x, rect1_y + rect1_h - 1, rect2_x, rect2_y, rect2_w, rect2_h) )
	{
		return true;
	}

	// Check to see if any of rect2's corners are in rect1 
	
	// top-left corner
	if ( pointInRect(rect2_x, rect2_y, rect1_x, rect1_y, rect1_w, rect1_h) )
	{
		return true;
	}

	// top-right corner
	if ( pointInRect(rect2_x + rect2_w - 1, rect2_y, rect1_x, rect1_y, rect1_w, rect1_h) )
	{
		return true;
	}

	// bottom-right corner
	if ( pointInRect(rect2_x + rect2_w - 1, rect2_y + rect2_h - 1, rect1_x, rect1_y, rect1_w, rect1_h) )
	{
		return true;
	}

	// bottom-left corner
	if ( pointInRect(rect2_x, rect2_y + rect2_h - 1, rect1_x, rect1_y, rect1_w, rect1_h) )
	{
		return true;
	}

	return false;
}

inline bool rectOnRectCollision(SDL_Rect rect1, SDL_Rect rect2)	
{
	return rectOnRectCollision(rect1.x, rect1.y, rect1.w, rect1.h, rect2.x, rect2.y, rect2.w, rect2.h);
}

inline bool rectOnRectCollision(SDL_Rect rect1, int rect2_x, int rect2_y, int rect2_w, int rect2_h)	
{
	return rectOnRectCollision(rect1.x, rect1.y, rect1.w, rect1.h, rect2_x, rect2_y, rect2_w, rect2_h);
}
#endif