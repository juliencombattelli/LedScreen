/*
 * main.cpp
 *
 *  Created on: 11 janv. 2017
 *      Author: JulienCombattelli
 */

#include <mbed.h>

DigitalOut myled(LED1);

int main()
{
    while(1)
    {
        myled = 1; // LED is ON
        wait(0.2); // 200 ms
        myled = 0; // LED is OFF
        wait(5.0); // 1 sec
    }
}
