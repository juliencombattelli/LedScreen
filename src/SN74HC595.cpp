/*
 * SN74HC595.cpp
 *
 *  Created on: 12 janv. 2017
 *      Author: JulienCombattelli
 */

#include <SN74HC595.h>

SN74HC595::SN74HC595(const SN74HC595_Config& config) :
	m_chainedComponents(config.chainedComponents), m_DS(config.DS), m_SHCP(config.SHCP), m_STCP(config.STCP)
{

}

SN74HC595::bit_ref SN74HC595::operator[](unsigned int index)
{
	return m_dataRegister[index];
}

void SN74HC595::write()
{
	m_SHCP = 0;

	for(unsigned i = 0; i < SN74HC595_OUTPUT_NUMBER; i++)
	{
		m_STCP = 0;
		m_DS = m_dataRegister[i];
		m_STCP = 1;
	}

	m_SHCP = 1;
}

void SN74HC595::clear()
{
	for(unsigned i = 0; i < SN74HC595_OUTPUT_NUMBER; i++)
		m_dataRegister[i] = 0;
}
