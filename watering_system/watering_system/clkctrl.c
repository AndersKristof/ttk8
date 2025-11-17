/*
 * clkctrl.c
 *
 * MCU clock configuration for the watering system.
 * Sets the main clock source and prescalers appropriate for low-power
 * sampling and peripheral usage.
 */

#include <avr/io.h>

#include "clkctrl.h"

void clkctrl_init()
{
	_PROTECTED_WRITE(CLKCTRL_MCLKCTRLA, CLKCTRL_CLKSEL_OSC20M_gc);
	_PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, (CLKCTRL_PDIV_10X_gc | CLKCTRL_PEN_bm));
}