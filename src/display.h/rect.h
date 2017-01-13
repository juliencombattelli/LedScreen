#pragma once

class rect
{
public:
	rect(unsigned int p_x, unsigned int p_y, unsigned int p_width, unsigned int p_height);
	~rect();

	bool is_inside(unsigned int p_x, unsigned int p_y);

private:
	unsigned int x;
	unsigned int y;
	unsigned int width;
	unsigned int height;
};
