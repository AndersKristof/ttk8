/*
 * relay.c
 *
 * Created: 14.11.2025 15:07:29
 *  Author: ankristo
 */ 

#include <avr/io.h>

#include "relay.h"

void relay_init()
{
	PORTE_DIRSET = (PIN0_bm | PIN1_bm | PIN2_bm);
	PORTE_OUTSET = PIN2_bm;
	PORTE_OUTCLR = (PIN1_bm | PIN0_bm);
}

void relay_off()
{
	PORTE_OUTCLR = PIN0_bm;
}

void relay_on()
{
	PORTE_OUTSET = PIN0_bm;
}