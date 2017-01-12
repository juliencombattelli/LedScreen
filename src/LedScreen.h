/*
 * LedScreen.h
 *
 *  Created on: 12 janv. 2017
 *      Author: JulienCombattelli
 */

#ifndef SRC_LEDSCREEN_H_
#define SRC_LEDSCREEN_H_

#include <SN74HC595.h>

class LedScreen
{
public:

	LedScreen(int rowCount, int columnCount, const SN74HC595_Config& rowConfig, const SN74HC595_Config& columnConfig);

	void display(bool matrix[][]);
	void display(bool matrix[][], int duration_ms);

private:

	const int m_rowCount;
	const int m_columnCount;

	SN74HC595 m_rows;
	SN74HC595 m_columns;
};

#endif /* SRC_LEDSCREEN_H_ */
