/* config.h
 *
 * Central configuration for the automatic watering firmware.
 * Adjust the macros below to tune behavior without changing application code.
 *
 */

#ifndef CONFIG_H_
#define CONFIG_H_

/* Moisture thresholds (in percent) */
#define MOISTURE_THRESHOLD_PERCENT	 15		/* Below this -> start watering */

/* Watering and timing (milliseconds) */
#define WATER_DURATION_MS    500UL     /* Watering duration in ms */
#define SAMPLE_INTERVAL_MS   60000UL   /* Sample every X ms */
#define MIN_OFF_TIME_MS      300000UL  /* Minimum time after watering before re-evaluating (5 minutes) */

/* UART */
#define UART_BAUD_FREQ            9600U
#define UART_BAUD_REGISTER_VALUE  (4*F_CPU/UART_BAUD_FREQ)

/* Relay polarity: set to 1 if a logic-high activates the relay, 0 if logic-low activates it. */
#define RELAY_ACTIVE_LEVEL   1

/* Test Mode: set to 1 if you want test mode. 0 activates the system in regular watering mode. */
#define TEST_MODE_ACTIVE     1

#endif /* CONFIG_H_ */
