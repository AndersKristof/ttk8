/*
 * relay.h
 *
 * Public relay control API. Provides initialization and simple on/off
 * control functions used by the application to drive the external relay.
 */


#ifndef RELAY_H_
#define RELAY_H_

void relay_init();
void relay_on();
void relay_off();
void relay_toggle();



#endif /* RELAY_H_ */