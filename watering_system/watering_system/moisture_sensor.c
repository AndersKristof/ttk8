/*
 * moisture_sensor.c
 *
 * Created: 16.11.2025 14:09:50
 *  Author: ankristo
 */ 

#include <avr/io.h>

#include "moisture_sensor.h"

void moisture_sensor_init()
{
	// Set up power pins for moisture sensor
	PORTE_DIRSET = (PIN0_bm | PIN1_bm);
	PORTE_OUTSET = PIN1_bm;
	PORTE_OUTCLR = PIN0_bm;
}
