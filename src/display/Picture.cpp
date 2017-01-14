/*
 * Picture.cpp
 *
 *  Created on: 14 janv. 2017
 *      Author: guill
 */

#include <display/Picture.h>

Picture::Picture(const Vector2D<uint8_t> &p_vector, uint16_t p_x, uint16_t p_y, uint16_t p_width, uint16_t p_height, effect_t p_effect_name, uint32_t p_duration_ms) :
	Displayable(p_x, p_y, p_width, p_height, p_effect_name, p_duration_ms)
{
	m_vector = p_vector;
}

Picture::Picture(const Vector2D<uint8_t> &p_vector, uint16_t p_x, uint16_t p_y, uint16_t p_width, uint16_t p_height, Effect &p_effect) :
	Displayable(p_x, p_y, p_width, p_height, p_effect)
{
	m_vector = p_vector;
}

Picture::Picture(const Vector2D<uint8_t> &p_vector, uint16_t p_x, uint16_t p_y, uint16_t p_width, uint16_t p_height) :
	Displayable(p_x, p_y, p_width, p_height, none, 0)
{
	m_vector = p_vector;
}

Picture::Picture(const Vector2D<uint8_t> &p_vector, uint16_t p_x, uint16_t p_y) :
	Displayable(p_x, p_y, p_vector.getColumnCount(), p_vector.getRowCount(), none, 0)
{

}

Picture::~Picture()
{

}

led_state_t Picture::get_value(uint16_t p_x, uint16_t p_y) const
{
	int pictureOrigin_x = p_x - m_x;
	int pictureOrigin_y = p_y - m_y;

	if((pictureOrigin_x < m_vector.getColumnCount()) and (pictureOrigin_y < m_vector.getRowCount()) and m_vector(pictureOrigin_y, pictureOrigin_x))
		return ON;
	else
		return OFF;
}


