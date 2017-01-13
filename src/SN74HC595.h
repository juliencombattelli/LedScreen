/*
 * SN74HC595.h
 *
 *  Created on: 12 janv. 2017
 *      Author: JulienCombattelli
 */

#ifndef SRC_SN74HC595_H_
#define SRC_SN74HC595_H_

#include <bitset>
#include <mbed.h>

#define SN74HC595_OUTPUT_NUMBER (8u*3)

struct SN74HC595_Config
{
	unsigned int chainedComponents;
	PinName DS;
	PinName SHCP;
	PinName STCP;
};

class SN74HC595
{
	using bit_ref = typename std::bitset<SN74HC595_OUTPUT_NUMBER>::reference;

public:

	SN74HC595(const SN74HC595_Config& config, bool invert = false);

	bit_ref operator[](unsigned int index);

	void write();
	void clear();

private:

	const unsigned int m_chainedComponents;
	std::bitset<SN74HC595_OUTPUT_NUMBER> m_dataRegister;

	DigitalOut m_DS;
	DigitalOut m_SHCP;
	DigitalOut m_STCP;
	bool m_invert;
};


#endif /* SRC_SN74HC595_H_ */
