/*
 * LedScreen.h
 *
 *  Created on: 12 janv. 2017
 *      Author: JulienCombattelli
 */

#ifndef SRC_LEDSCREEN_H_
#define SRC_LEDSCREEN_H_

#include <SN74HC595.h>
#include <display/Displayable.h>
#include <vector>

#define RETINAL_PERSISTENCE_MS (20u)

class LedScreen
{
public:

	LedScreen(int rowCount, int columnCount, const SN74HC595_Config& rowConfig, const SN74HC595_Config& columnConfig);

	void display(const bool **matrix);
	void display(const bool **matrix, int duration_ms);
	void display(Displayable &displayable);
	void display(Displayable &displayable, int duration_ms);
	void display();

	void displayRow(int rowIndex, int frameTime_ms);
	void displayColumn(int columnIndex, int frameTime_ms);

	void scrollRows(int frameTime_ms);
	void scrollColumns(int frameTime_ms);

	void clear();

	void push(Displayable& displayable);

private:

	const int m_rowCount;
	const int m_columnCount;

	const int m_delay_ms;

	SN74HC595 m_rows;
	SN74HC595 m_columns;

	std::vector<Displayable*> m_displayables;
};

#endif /* SRC_LEDSCREEN_H_ */
