/*
 * Effect.h
 *
 *  Created on: 14 janv. 2017
 *      Author: guill
 */

#ifndef SRC_DISPLAY_EFFECT_H_
#define SRC_DISPLAY_EFFECT_H_

#include <cstdint>

enum effect_t
{
	none,
	blink,
	scroll_right,
	scroll_left,
	scroll_up,
	scroll_down
};

class Effect
{
public:
	Effect(effect_t p_effect_name, uint32_t p_duration_ms);
	~Effect();

private:
	effect_t m_effect_name;
	uint32_t m_duration_ms;
	uint16_t m_x_index;
	uint16_t m_y_index;
};



#endif /* SRC_DISPLAY_EFFECT_H_ */
