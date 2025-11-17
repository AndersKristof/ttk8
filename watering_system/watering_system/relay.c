/*
 * relay.c
 *
 * Relay driver implementation. Controls a single relay GPIO (PD7) used to
 * switch the pump/solenoid through a driver transistor. Provides safe
 * default (GPIO configured) and basic on/off/toggle functions.
 */

#include <avr/io.h>

#include "relay.h"

void relay_init()
{
	PORTD_DIRSET = PIN7_bm;
	PORTD_OUTCLR = PIN7_bm;
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