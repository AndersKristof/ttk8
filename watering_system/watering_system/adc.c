/*
 * adc.c
 *
 * ADC driver implementation for the watering system.
 * Configures ADC0 for 8-bit results and provides a blocking conversion
 * with result-ready wait. The public API is declared in `adc.h`.
 */

#include <avr/io.h>

#include "adc.h"

void adc_init()
{
	ADC0_CTRLA = ADC_RESSEL_8BIT_gc;
	ADC0_CTRLC = ADC_REFSEL_VDDREF_gc | ADC_PRESC_DIV4_gc | ADC_SAMPCAP_bm;
	ADC0_MUXPOS = ADC_MUXPOS_AIN0_gc; // AIN0 is PD0
	ADC0_CTRLA |= ADC_ENABLE_bm;
}

uint8_t adc_get_result()
{
	ADC0_COMMAND = ADC_STCONV_bm;
	while (!(ADC0_INTFLAGS & ADC_RESRDY_bm));
	return ADC0_RES;
}