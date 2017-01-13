#include "rect.h"

rect::rect(unsigned int p_x, unsigned int p_y, unsigned int p_width, unsigned int p_height)
{
	x= p_x;
	y = p_y;
	width = p_width;
	height = p_height;
}

rect::~rect()
{

}

bool rect::is_inside(unsigned int p_x, unsigned int p_y)
{
	if((p_x >= x) && (p_y >= y) && (p_x <= x + width) && (p_y <= y + height))
		return true;
	else
		return false;
}
