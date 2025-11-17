/*
 * adc.h
 *
 * Public ADC interface for the watering system firmware.
 * Provides initialization and a single-call read function returning
 * a filtered 8-bit ADC value (0-255).
 */


#ifndef ADC_H_
#define ADC_H_

void adc_init();
uint8_t adc_get_result();


#endif /* ADC_H_ */