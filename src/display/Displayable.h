#pragma once

#include <display/Rect.h>
#include <display/Effect.h>

enum led_state_t
{
	ON = 1,
	OFF = 0
};

class Displayable : private Rect
{
public:
	Displayable(uint16_t p_x, uint16_t p_y, uint16_t p_width, uint16_t p_height, effect_t p_effect_name, uint32_t p_duration_ms);
	Displayable(uint16_t p_x, uint16_t p_y, uint16_t p_width, uint16_t p_height, Effect &p_effect);
	~Displayable();

	led_state_t get_value(uint16_t p_x, uint16_t p_y) const;

private:
	Effect m_effect;

};
