/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include <mbed.h>
#include <stdint.h>
#include <time.h>
#include <LedScreen.h>
#include <vector>

const bool SPACE[5][5] ={{0,0,0,0,0},
                    {0,0,0,0,0},
                    {0,0,0,0,0},
                    {0,0,0,0,0},
                    {0,0,0,0,0}};

const bool A[5][5] ={{0,0,1,0,0},
                    {0,1,0,1,0},
                    {0,1,1,1,0},
                    {0,1,0,1,0},
                    {0,1,0,1,0}};

const bool B[5][5] ={{0,1,1,0,0},
                    {0,1,0,1,0},
                    {0,1,1,1,0},
                    {0,1,0,1,0},
                    {0,1,1,0,0}};

const bool C[5][5] ={{0,1,1,1,0},
                    {0,1,0,0,0},
                    {0,1,0,0,0},
                    {0,1,0,0,0},
                    {0,1,1,1,0}};

const bool D[5][5] ={{0,1,1,0,0},
                    {0,1,0,1,0},
                    {0,1,0,1,0},
                    {0,1,0,1,0},
                    {0,1,1,0,0}};

const bool E[5][5] ={{0,1,1,1,0},
                    {0,1,0,0,0},
                    {0,1,1,0,0},
                    {0,1,0,0,0},
                    {0,1,1,1,0}};

const bool F[5][5] ={{0,1,1,1,0},
                    {0,1,0,0,0},
                    {0,1,1,0,0},
                    {0,1,0,0,0},
                    {0,1,0,0,0}};

const bool G[5][5] ={{0,0,1,1,0},
                    {0,1,0,0,0},
                    {0,1,1,1,1},
                    {0,1,0,1,0},
                    {0,1,1,1,0}};

const bool H[5][5] ={{0,1,0,1,0},
                    {0,1,0,1,0},
                    {0,1,1,1,0},
                    {0,1,0,1,0},
                    {0,1,0,1,0}};

const bool I[5][5] ={{0,1,1,1,0},
                    {0,0,1,0,0},
                    {0,0,1,0,0},
                    {0,0,1,0,0},
                    {0,1,1,1,0}};

const bool J[5][5] ={{0,1,1,1,0},
                    {0,0,1,0,0},
                    {0,0,1,0,0},
                    {1,0,1,0,0},
                    {0,1,0,0,0}};

const bool K[5][5] ={{0,1,1,1,0},
                    {0,0,1,0,0},
                    {0,0,1,0,0},
                    {1,0,1,0,0},
                    {0,1,0,0,0}};

const bool L[5][5] ={{0,1,0,0,0},
                    {0,1,0,0,0},
                    {0,1,0,0,0},
                    {0,1,0,0,0},
                    {0,1,1,1,0}};

const bool M[5][5] ={{0,1,0,1,0},
                    {0,1,1,1,0},
                    {0,1,0,1,0},
                    {0,1,0,1,0},
                    {0,1,0,1,0}};

const bool N[5][5] ={{0,1,0,1,0},
                    {0,1,1,1,0},
                    {0,1,1,1,0},
                    {0,1,0,1,0},
                    {0,1,0,1,0}};

const bool O[5][5] ={{0,1,1,1,0},
                    {0,1,0,1,0},
                    {0,1,0,1,0},
                    {0,1,0,1,0},
                    {0,1,1,1,0}};

const bool P[5][5] ={{0,1,1,1,0},
                    {0,1,0,1,0},
                    {0,1,1,1,0},
                    {0,1,0,0,0},
                    {0,1,0,0,0}};



bool image_smiley1[21][21] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
                              {0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0},
                              {0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
                              {0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0},
                              {0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0},
                              {0,1,1,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,1,0,0},
                              {0,1,0,0,0,1,1,1,1,0,0,1,1,1,1,0,0,0,1,0,0},
                              {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
                              {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
                              {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0},
                              {1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0},
                              {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
                              {0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,0,0},
                              {0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,1,1,0,0,0},
                              {0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0},
                              {0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
                              {0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
                              {0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };

bool image_smiley[21][21] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							  {0,1,1,1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
							  {0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0},
							  {0,1,1,1,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0},
							  {0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0},
							  {0,1,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							  {0,1,0,0,0,0,1,0,0,1,1,0,0,1,0,1,0,0,0,0,0},
							  {0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0},
							  {0,1,0,0,0,1,1,1,0,1,1,0,0,1,0,1,0,0,0,0,0},
							  {0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0},
							  {0,1,1,1,0,1,0,1,0,1,1,0,0,1,0,1,0,0,0,0,0},
							  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
							  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                              {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };


int main(void)
{
	bool* temp[21];
	for (int i = 0; i < 21; ++i)
		temp[i] = image_smiley1[i];

	bool** smiley = temp;

	SN74HC595_Config rowConfig;
	rowConfig.chainedComponents = 3;
	rowConfig.DS = D11;
	rowConfig.SHCP = D12;
	rowConfig.STCP = D13;

	SN74HC595_Config columnConfig;
	columnConfig.chainedComponents = 3;
	columnConfig.DS = D2;
	columnConfig.SHCP = D3;
	columnConfig.STCP = D4;

	LedScreen ledScreen(21, 21, rowConfig, columnConfig);

	for(;;)
	{
		ledScreen.display(smiley);
		/*ledScreen.scrollRows(120);
		ledScreen.clear();*/
		/*wait(2);
		ledScreen.scrollColumns(120);
		ledScreen.clear();
		wait(2);*/
	}
}

