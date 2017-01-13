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

#define NB_LIGNE 21
#define NB_COLONNE 21
#define TAILLE_TAB NB_LIGNE*NB_COLONNE
#define BAUD_SPEED 9600

#define LOW  (0u)
#define HIGH (1u)

//How many of the shift registers - change this
#define p_number_of_74hc595s 3
#define n_number_of_74hc595s 2

//do not touch
#define p_numOfRegisterPins p_number_of_74hc595s * 8
#define n_numOfRegisterPins n_number_of_74hc595s * 8

/** Delai entre chaque ligne : 21*X < 20 ms --> X=0.9 pour la persistance retinienne **/
#define DELAY 0.5
/*
// Pins pour les positifs (lignes)
DigitalOut P_DS_Pin(D11);
DigitalOut P_SHCP_Pin(D12);
DigitalOut P_STCP_Pin(D13);

// Pins pour les négatifs (colonnes)
DigitalOut N_DS_Pin(D2);
DigitalOut N_SHCP_Pin(D3);
DigitalOut N_STCP_Pin(D4);

DigitalOut N_16(D5);
DigitalOut N_17(D6);
DigitalOut N_18(D7);
DigitalOut N_19(D8);
DigitalOut N_20(D9);*/

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

bool p_registers[p_numOfRegisterPins];
bool n_registers[n_numOfRegisterPins+5];

void convertBoolTab(uint8_t input[TAILLE_TAB], bool output[NB_LIGNE][NB_COLONNE]);
void SerialprintBoolTab(bool tab[NB_LIGNE][NB_COLONNE]);


 //==========================================================================================
 //============ AFFICHAGE DE LA DATA RECUE
/*
 void boucle_image_recue()
 {
    bool imageReceived[NB_LIGNE][NB_COLONNE];
    uint8_t bufferImageReceived[TAILLE_TAB];
    // Image smiley par defaut
    for (int ligne = 0; ligne < NB_LIGNE; ligne++)
    {
      for (int colonne = 0; colonne < NB_COLONNE; colonne++)
        imageReceived[ligne][colonne] = image_smiley[ligne][colonne];

    }
    // Debut de la boucle
    while(1)
    {
       afficher_image_une_fois(imageReceived);
    }
 }*/

// =============================================================================================================

int main(void)
{
	SN74HC595_Config rowConfig;
	rowConfig.chainedComponents = 3;
	rowConfig.DS = D11;
	rowConfig.SHCP = D12;
	rowConfig.STCP = D13;

	SN74HC595_Config columnConfig;
	columnConfig.chainedComponents = 2;
	columnConfig.DS = D2;
	columnConfig.SHCP = D3;
	columnConfig.STCP = D4;

	LedScreen ledScreen(21, 21, rowConfig, columnConfig);

	for(;;)
	{
		ledScreen.scrollRows(120);
		ledScreen.clear();
		wait(2);
		ledScreen.scrollColumns(120);
		ledScreen.clear();
		wait(2);

		/*boucle_image_recue();

		clearRegisters();
		writeRegisters();
		while(1);*/
	}
}

