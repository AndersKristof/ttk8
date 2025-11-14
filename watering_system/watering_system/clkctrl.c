/*
 * clkctrl.c
 *
 * Created: 14.11.2025 12:15:13
 *  Author: ankristo
 */ 

#include <avr/io.h>

#include "clkctrl.h"

void clkctrl_init()
{
	_PROTECTED_WRITE(CLKCTRL_MCLKCTRLA, CLKCTRL_CLKSEL_OSC20M_gc);
	_PROTECTED_WRITE(CLKCTRL_MCLKCTRLB, (CLKCTRL_PDIV_10X_gc | CLKCTRL_PEN_bm));
}