/*
 * Effect.cpp
 *
 *  Created on: 14 janv. 2017
 *      Author: guill
 */

#include <display/Effect.h>

Effect::Effect(effect_t p_effect_name, uint32_t p_duration_ms)
{
	m_effect_name = p_effect_name;
	m_duration_ms = p_duration_ms;
	m_x_index = 0;
	m_y_index = 0;
}


