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
	PORTD_DIRSET = PIN7_bm;
}

void relay_off()
{
	PORTD_OUTCLR = PIN7_bm;
}

void relay_on()
{
	PORTD_OUTSET = PIN7_bm;
}

void relay_toggle()
{
	PORTD_OUTTGL = PIN7_bm;
}