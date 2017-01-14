#include <display/Displayable.h>

Displayable::Displayable(uint16_t p_x, uint16_t p_y, uint16_t p_width, uint16_t p_height, effect_t p_effect_name, uint32_t p_duration_ms) :
	Rect(p_x, p_y, p_width, p_height), m_effect(p_effect_name, p_duration_ms)
{

}

Displayable::Displayable(uint16_t p_x, uint16_t p_y, uint16_t p_width, uint16_t p_height, Effect &p_effect) :
	Rect(p_x, p_y, p_width, p_height), m_effect(p_effect)
{

}

Displayable::~Displayable()
{

}

led_state_t Displayable::get_led_state(uint16_t p_x, uint16_t p_y) const
{
	if(!is_inside(p_x, p_y))
		return OFF;
	else
	{
		return get_value(p_x, p_y);
	}
}
