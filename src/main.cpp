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

// For test
DigitalOut myled(LED1);

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
DigitalOut N_20(D9);

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

//set all register pins to LOW
void clearRegisters()
{
  int i=0;
  for(i = p_numOfRegisterPins - 1; i >=  0; i--)
     p_registers[i] = LOW;

  for(i = n_numOfRegisterPins - 1; i >=  0; i--)
     n_registers[i] = LOW;

  for(i = 16; i<21 ; i++)
     n_registers[i] = LOW;
}

//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)
void writeRegisters()
{
   int i =0;
  //digitalWrite(P_SHCP_Pin, LOW);
  P_SHCP_Pin = LOW;
  //digitalWrite(N_SHCP_Pin, LOW);
  N_SHCP_Pin = LOW;

  for(i = p_numOfRegisterPins - 1; i >=  0; i--)
  {
    //digitalWrite(P_STCP_Pin, LOW);
    P_STCP_Pin = LOW;

    int val = p_registers[i];

    //digitalWrite(P_DS_Pin, val);
    P_DS_Pin = val;
    //digitalWrite(P_STCP_Pin, HIGH);
    P_STCP_Pin = HIGH;
  }

  for(i = n_numOfRegisterPins - 1; i >=  0; i--)
  {
    //digitalWrite(N_STCP_Pin, LOW);
    N_STCP_Pin = LOW;

    int val = n_registers[i];

    //digitalWrite(N_DS_Pin, !val);
    N_DS_Pin = !val;
    //digitalWrite(N_STCP_Pin, HIGH);
    N_STCP_Pin = HIGH;
  }

   for(i = 16; i <  21; i++)
   {
    int val = n_registers[i];
     if (i == 16 ) {
        //digitalWrite(N_16, !val);
        N_16 = !val;
     } else if (i == 17) {
        //digitalWrite(N_17, !val);
        N_17 = !val;
     } else if (i == 18) {
        //digitalWrite(N_18, !val);
        N_18 = !val;
     } else if (i == 19) {
        //digitalWrite(N_19, !val);
        N_19 = !val;
     } else if (i == 20) {
        //digitalWrite(N_20, !val);
        N_20 = !val;
     }
  }

  //digitalWrite(N_SHCP_Pin, HIGH);
  N_SHCP_Pin = HIGH;
  //digitalWrite(P_SHCP_Pin, HIGH);
  P_SHCP_Pin = HIGH;

}

//==============================================================================

void clear_lignes()
{
  for ( int ligne=0; ligne<21; ligne++)
     p_registers[ligne] = LOW;
}

void clear_colonnes()
{
  for ( int colonne=0; colonne<21; colonne++)
     n_registers[colonne] = LOW;
}


//==============================================================================

//set an individual pin HIGH or LOW
void set_p_RegisterPin(int index, int value)
{
  p_registers[index] = value;
}

//set an individual pin HIGH or LOW
void set_n_RegisterPin(int index, int value)
{
  n_registers[index] = value;
}

//==============================================================================================================

//===========================================================================
//                 ==  Afficher_image pour X secondes  ==
//            Afficher une image sur un tableau 21*21
//===========================================================================

/**
 *  Afficher l'image une seule fois = un balayage de toutes les lignes.
**/
void afficher_image_une_fois(bool mon_tab[NB_LIGNE][NB_COLONNE])
{
    // Traitement de toutes les lignes et colonnes
    for (int ligne = 0; ligne < NB_LIGNE; ligne++)
    {
        // Allumer la ligne
        set_p_RegisterPin(ligne,HIGH);
        // Allumer toutes les colonnes voulues
        for (int colonne = 0; colonne < NB_COLONNE; colonne++)
        {
            if (mon_tab[NB_LIGNE - 1 - ligne][NB_COLONNE - 1 - colonne])
               set_n_RegisterPin(NB_COLONNE - 1 - colonne,HIGH);
            else
               set_n_RegisterPin(NB_COLONNE - 1 - colonne,LOW);
        } // fin du for traitement colonnes

        // On a une ligne allumee et les colonnes correspondant aux LED de cette ligne
        // On les affiche
        writeRegisters();
        wait_ms(DELAY);  // Persistance retiniene ensuite qui dure 20ms
        set_p_RegisterPin(ligne,LOW);
    }
}

// Programme du tableau de LED
/** Afficher une image pendant X ms */
void afficher_image(bool mon_tab[NB_LIGNE][NB_COLONNE], int temps_ms)
{
  // Temps d'affichage de l'image
  long start_time = time(NULL);
  long temps_total = 0;

  while ( temps_total < temps_ms )
  {
      afficher_image_une_fois( mon_tab );
      temps_total = time(NULL) - start_time;
   }
}

//===========================================================================
//                 ==  Allumer une ligne ou colonne pour X secondes  ==
//            Allumer une ligne sur un tableau 21*21
//===========================================================================
void allumer_ligne(float temps_ms, int n_ligne)
{
  int colonne = 0;

  set_p_RegisterPin(n_ligne,HIGH);
  // Allumer toutes les colonnes
  for (colonne = 0; colonne < NB_COLONNE; colonne++)
      set_n_RegisterPin(colonne,HIGH);

  writeRegisters();
  wait_ms(temps_ms);
  set_p_RegisterPin(n_ligne,LOW);
}


 void allumer_colonne(float temps_ms, int n_colonne)
 {
  int ligne = 0;

  set_n_RegisterPin(n_colonne,HIGH);
  // Allumer toutes les colonnes
  for (ligne = 0; ligne < NB_LIGNE; ligne++)
      set_p_RegisterPin(ligne,HIGH);

  writeRegisters();
  wait_ms(temps_ms);
  set_n_RegisterPin(n_colonne,LOW);
}

 //==========================================================================================
 //============ AFFICHAGE DE LA DATA RECUE

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
 }

// =============================================================================================================

void init()
{
	//HAL_Init();

	//GPIO_initOut(GPIOA, GPIO_PIN_5, 0);

	//BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);

	//Serial.begin(BAUD_SPEED);

	/*GPIO_initOut(P_DS_Port, P_DS_Pin, 0);
	GPIO_initOut(P_SHCP_Port, P_SHCP_Pin, 0);
	GPIO_initOut(P_STCP_Port, P_STCP_Pin, 0);

	GPIO_initOut(N_DS_Port, N_DS_Pin, 0);
	GPIO_initOut(N_SHCP_Port, N_SHCP_Pin, 0);
	GPIO_initOut(N_STCP_Port, N_STCP_Pin, 0);

	GPIO_initOut(N_16_Port, N_16_Pin, 0);
	GPIO_initOut(N_17_Port, N_17_Pin, 0);
	GPIO_initOut(N_18_Port, N_18_Pin, 0);
	GPIO_initOut(N_19_Port, N_19_Pin, 0);
	GPIO_initOut(N_20_Port, N_20_Pin, 0);*/

	//reset all register pins
	clearRegisters();
	writeRegisters();
}

int main(void)
{
	init();

	/*
	 * For test
	 */
    /*while(1)
    {
        myled = 1; // LED is ON
        wait(0.2); // 200 ms
        myled = 0; // LED is OFF
        wait(5.0); // 1 sec
    }*/

	for(;;)
	{
		//clearRegisters();
		// Phase de demarrage
		for (int i = 0; i < NB_LIGNE; i++)
		{
		   allumer_ligne( 120 , i ) ;
		}

		boucle_image_recue();

		clearRegisters();
		writeRegisters();
		while(1);
	}
}

