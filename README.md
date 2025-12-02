# Automatic Plant Watering System

## Project Description for TTK8

### Project Overview

This project implements an automatic plant watering system that monitors soil moisture and waters plants autonomously when the soil becomes too dry. The firmware runs on an ATmega4809 MCU and controls a WHADDA Water Pump through a relay. Source code lives under `watering_system/watering_system`.

### Project Objectives

The primary goal is to create a smart irrigation system that:

- Monitors soil moisture levels in real-time using moisture sensors
- Automatically triggers watering when soil moisture falls below a specified threshold
- Provides feedback on system status and environmental conditions
- Operates autonomously with minimal human intervention
- Prevents overwatering through intelligent control algorithms

### Technical Components

**Hardware:**

- Microcontroller: ATmega4809
- Soil moisture sensor (analog output → ADC0 AIN0 = PD0)
- Relay driver on PD7 controlling WHADDA Water Pump
- Water reservoir and tubing
- 12V power supply for water pump
- 5V power supply for MCU, relay and sensor

**Software (current state):**

- `main.c`: Threshold-based watering loop
- `config.h`: Central configuration (threshold %, watering duration, sample interval, UART baud, test flag)
- `moisture_sensor.c/.h`: GPIO setup powering the sensor (PE0/PE1)
- `adc.c/.h`: 8-bit ADC conversion on ADC0; blocking read
- `relay.c/.h`: Relay control on PD7 (init/on/off/toggle)
- `uart.c/.h`: Test-mode only (USART3) for commands and debug output
- `clkctrl.c/.h`: Clock setup (20 MHz internal oscillator with prescaler)

### Learning Objectives

Through this project, I aim to develop my knowledge in several areas:

**New Skills to Acquire:**

**Moisture Sensor**: This is my first time working with soil moisture sensors. I will learn how to use them appropriately.

**Actuator Control**: Learning to control some sort of actuator for the activating and disabling the watering mechanism.

**Design of the Physical System**: I have not made a similar system before, with tubes and tanks for water. I imagine having water throughout the system will bring some challenges of its own.

### Current Behavior and Limitations

- Autonomous mode (`TEST_MODE_ACTIVE=0`): Samples moisture every `SAMPLE_INTERVAL_MS`; waters for `WATER_DURATION_MS` when moisture percent < `MOISTURE_THRESHOLD_PERCENT`.
- UART is disabled in normal operation to reduce power/noise; enabled only in test mode (`TEST_MODE_ACTIVE=1`) with commands:
	- `t`: toggle relay
	- `r`: run one watering cycle
	- `c`: print current moisture percent
- Limitations (to be addressed): No hysteresis (single threshold), minimum off-time not enforced, no ADC averaging; potential re-watering if soil remains dry at each interval.

### Success Criteria

The project is considered successful when:

1. The system measures soil moisture reliably (monotonic percent with wet/dry changes)
2. Watering triggers automatically below threshold and runs for configured duration
3. Relay defaults to OFF on startup and after watering; no unintended activation
4. Components operate reliably over extended periods
5. Clear learning outcomes in sensor integration and embedded control

### How to Build and Run

- Open `watering_system/watering_system/watering_system.cproj` in Microchip Studio or build via the provided `Debug/Makefile`.
- Configure behavior in `watering_system/watering_system/config.h`:
	- `MOISTURE_THRESHOLD_PERCENT` (e.g., 15)
	- `WATER_DURATION_MS` (e.g., 500 ms)
	- `SAMPLE_INTERVAL_MS` (e.g., 60000 ms)
	- `TEST_MODE_ACTIVE` (0 = autonomous, 1 = UART test)
- Flash to ATmega4809; connect pump/relay driver to PD7 and sensor analog to PD0.

### Roadmap

- Add hysteresis (LOW/HIGH thresholds) and enforce minimum off-time
- Introduce ADC averaging/moving window filtering
- Implement low-power periodic wake (RTC/PIT) instead of blocking delays
- LCD screen for live tracking of moisture levels and watering decisions
- Waterproof container for electrical components
- Purpose-built water tank/pot
- Optional: simple UART config commands for runtime tuning in test mode
