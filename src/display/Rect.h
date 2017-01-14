#pragma once

#include <cstdint>

class Rect
{
public:
	Rect(uint16_t p_x, uint16_t p_y, uint16_t p_width, uint16_t p_height);
	~Rect();

	bool is_inside(uint16_t p_x, uint16_t p_y) const;

protected:
	unsigned int m_x;
	unsigned int m_y;
	unsigned int m_width;
	unsigned int m_height;
};
