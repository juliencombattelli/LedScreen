/*
 * Picture.h
 *
 *  Created on: 14 janv. 2017
 *      Author: guill
 */

#ifndef SRC_DISPLAY_PICTURE_H_
#define SRC_DISPLAY_PICTURE_H_

#include <display/Displayable.h>
#include <vector/Vector2D.h>

const Vector2D<uint8_t> grand_smiley ={ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
										{0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
										{0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0},
										{0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
										{0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},
										{0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},
										{0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0},
										{0,1,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,1,0,0},
										{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
										{1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0},
										{1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0},
										{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
										{0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,0,0},
										{0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,0,0,0},
										{0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0},
										{0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
										{0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
										{0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0},
										{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0},
										{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };

const Vector2D<uint8_t> petit_smiley ={ {0,1,0,1,0},
										{0,1,0,1,0},
										{0,0,0,0,0},
										{1,0,0,0,1},
										{0,1,1,1,0} };

class Picture : public Displayable
{
public:
	Picture(const Vector2D<uint8_t> &p_vector, uint16_t p_x, uint16_t p_y, uint16_t p_width, uint16_t p_height, effect_t p_effect_name, uint32_t p_duration_ms);
	Picture(const Vector2D<uint8_t> &p_vector, uint16_t p_x, uint16_t p_y, uint16_t p_width, uint16_t p_height, Effect &p_effect);
	Picture(const Vector2D<uint8_t> &p_vector, uint16_t p_x, uint16_t p_y, uint16_t p_width, uint16_t p_height);
	Picture(const Vector2D<uint8_t> &p_vector, uint16_t p_x, uint16_t p_y);
	~Picture();
private:
	Vector2D<uint8_t> m_vector;

	virtual led_state_t get_value(uint16_t p_x, uint16_t p_y) const;
};



#endif /* SRC_DISPLAY_PICTURE_H_ */
