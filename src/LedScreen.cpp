/*
 * LedScreen.cpp
 *
 *  Created on: 12 janv. 2017
 *      Author: JulienCombattelli
 */

#include <LedScreen.h>

LedScreen::LedScreen(int rowCount, int columnCount, const SN74HC595_Config& rowConfig, const SN74HC595_Config& columnConfig) :
	m_rowCount(rowCount), m_columnCount(columnCount),
	m_delay_ms(RETINAL_PERSISTENCE_MS / rowCount),
	m_rows(rowConfig), m_columns(columnConfig, true)
{
	clear();
}

void LedScreen::display(const bool **matrix)
{
    for(int rowIndex = 0; rowIndex < m_rowCount; rowIndex++)
    {
        m_rows[rowIndex] = 1;

        for(int columnIndex = 0; columnIndex < m_columnCount; columnIndex++)
        {
            if (matrix[m_rowCount - 1 - rowIndex][columnIndex])
            	m_columns[columnIndex] = 1;
            else
            	m_columns[columnIndex] = 0;
        }

        m_rows.write();
        m_columns.write();

        wait_ms(m_delay_ms);

        m_rows[rowIndex] = 0;

        m_columns.clear();
        m_columns.write();
    }
}

void LedScreen::display(const bool **matrix, int frameTime_ms)
{
	time_t startTime = time(NULL);
	time_t timeTotal = 0;

	while( timeTotal < frameTime_ms )
	{
		display(matrix);
		timeTotal = time(NULL) - startTime;
	}
}

void LedScreen::display(const Displayable &displayable)
{
	for(int rowIndex = 0; rowIndex < m_rowCount; rowIndex++)
	{
		m_rows[rowIndex] = 1;

		for(int columnIndex = 0; columnIndex < m_columnCount; columnIndex++)
			m_columns[columnIndex] = displayable.get_value(columnIndex, rowIndex);

		m_rows.write();
		m_columns.write();

		wait_ms(m_delay_ms);

		m_rows[rowIndex] = 0;

		m_columns.clear();
		m_columns.write();
	}
}

void LedScreen::display(const Displayable &displayable, int duration_ms)
{
	time_t startTime = time(NULL);
	time_t timeTotal = 0;

	while( timeTotal < duration_ms )
	{
		display(displayable);
		timeTotal = time(NULL) - startTime;
	}
}

void LedScreen::displayRow(int rowIndex, int frameTime_ms)
{
	m_rows[rowIndex] = 1;

	for(int columnIndex = 0; columnIndex < m_columnCount; columnIndex++)
		m_columns[columnIndex] = 1;

	m_rows.write();
	m_columns.write();
	wait_ms(frameTime_ms);
	m_columns.clear();
	m_rows[rowIndex] = 0;
}

void LedScreen::displayColumn(int columnIndex, int frameTime_ms)
{
	m_columns[columnIndex] = 1;

	for(int rowIndex = 0; rowIndex < m_rowCount; rowIndex++)
		m_rows[rowIndex] = 1;

	m_rows.write();
	m_columns.write();
	wait_ms(frameTime_ms);
	m_rows.clear();
	m_columns[columnIndex] = 0;
}

void LedScreen::scrollRows(int frameTime_ms)
{
	for(int i = 0; i < m_rowCount; i++)
	{
		displayRow(i , frameTime_ms);
	}
}

void LedScreen::scrollColumns(int frameTime_ms)
{
	for(int i = 0; i < m_columnCount; i++)
	{
		displayColumn(i , frameTime_ms);
	}
}

void LedScreen::clear()
{
	m_rows.clear();
	m_rows.write();
	m_columns.clear();
	m_columns.write();
}
