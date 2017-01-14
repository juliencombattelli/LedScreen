#include <display/Rect.h>

Rect::Rect(uint16_t p_x, uint16_t p_y, uint16_t p_width, uint16_t p_height)
{
	m_x= p_x;
	m_y = p_y;
	m_width = p_width;
	m_height = p_height;
}

Rect::~Rect()
{

}

bool Rect::is_inside(uint16_t p_x, uint16_t p_y) const
{
	if((p_x >= m_x) && (p_y >= m_y) && (p_x < m_x + m_width) && (p_y < m_y + m_height))
		return true;
	else
		return false;
}
