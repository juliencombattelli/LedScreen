/*
 * LedScreen.cpp
 *
 *  Created on: 12 janv. 2017
 *      Author: JulienCombattelli
 */

#include <LedScreen.h>

LedScreen::LedScreen(int rowCount, int columnCount, const SN74HC595_Config& rowConfig, const SN74HC595_Config& columnConfig) :
	m_rowCount(rowCount), m_columnCount(columnCount),
	m_rows(rowConfig), m_columns(columnConfig)
{

}

void LedScreen::display(bool matrix[][])
{
    for(int row = 0; row < m_rowCount; row++)
    {
        m_rows[row] = 1;

        for(int column = 0; column < m_columnCount; column++)
        {
            if (matrix[m_rowCount - 1 - row][m_columnCount - 1 - column])
            	m_columns[m_columnCount - 1 - column] = 1;
            else
            	m_rows[m_rowCount - 1 - row] = 0;
        }

        m_rows.write();
        m_columns.write();
        wait_ms(DELAY);
        m_rows[row] = 0;
    }
}

void LedScreen::display(bool matrix[][], int duration_ms)
{
	time_t startTime = time(NULL);
	time_t timeTotal = 0;

	while( timeTotal < duration_ms )
	{
		afficher_image_une_fois( mon_tab );
		timeTotal = time(NULL) - startTime;
	}
}
