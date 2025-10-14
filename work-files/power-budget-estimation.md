# Power Budget Estimation - Automatic Plant Watering System

## Overview

This document provides a detailed power consumption analysis for the automatic plant watering system based on the selected components. The analysis includes different operating modes and scenarios to help understand the system's power requirements.

## System Components Power Specifications

### 1. ESP32 DevKit V1 - Microcontroller

**Operating Modes:**

- **Active Mode (no WiFi/BT)**: 80-150 mA @ 3.3V
- **Active Mode (with WiFi/BT)**: 150-250 mA @ 3.3V
- **Peak Current**: Up to 500 mA (during WiFi transmission)
- **Deep Sleep Mode**: 10-150 μA @ 3.3V

**Operating Voltage**: 3.3V (internal), 5V input via USB
**Notes**: Since we're not using WiFi, expect 80-150 mA typical consumption

### 2. Capacitive Soil Moisture Sensor

**Current Consumption**: 5-6 mA @ 3.3V-5V
**Operating Voltage**: 3.3V-5V  
**Power-down Mode**: 80-140 μA (when not actively measuring)
**Notes**: Can be powered down between readings to save energy

### 3. 16x2 LCD Display with I2C

**LCD Controller**: 2-3 mA @ 5V
**Backlight**: 120-200 mA @ 5V (typical: 150 mA)
**Total (with backlight)**: 152-203 mA @ 5V
**Total (without backlight)**: 2-3 mA @ 5V
**Notes**: Backlight is the major power consumer and can be controlled

### 4. Single Channel 5V Relay Module

**Quiescent Current**: 5 mA @ 5V (relay OFF)
**Active Current**: 50 mA @ 5V (relay ON)
**Trigger Current**: 2-4 mA @ 5V (control signal)
**Notes**: Only consumes high current when actively switching pump ON

### 5. Mini Submersible Water Pump

**Operating Current**: 130-220 mA @ 3-5V (typical: 180 mA)
**Operating Voltage**: 3-5V DC
**Notes**: Only operates during watering cycles (intermittent use)

## Power Budget Calculations

### Scenario 1: Normal Operation (Monitoring Only)

**Components Active:**

- ESP32 (no WiFi): 120 mA @ 3.3V = 396 mW
- Soil Sensor: 6 mA @ 3.3V = 19.8 mW
- LCD (with backlight): 150 mA @ 5V = 750 mW
- Relay Module (standby): 5 mA @ 5V = 25 mW

**Total Current from 5V Supply**:

- 5V rail: 150 + 5 = 155 mA
- 3.3V rail: 120 + 6 = 126 mA

**Total Power Consumption**: 396 + 19.8 + 750 + 25 = **1,190.8 mW (~1.19 W)**

### Scenario 2: Watering Active (Peak Consumption)

**Components Active:**

- ESP32 (no WiFi): 120 mA @ 3.3V = 396 mW
- Soil Sensor: 6 mA @ 3.3V = 19.8 mW
- LCD (with backlight): 150 mA @ 5V = 750 mW
- Relay Module (active): 50 mA @ 5V = 250 mW
- Water Pump: 180 mA @ 5V = 900 mW

**Total Current from 5V Supply**:

- 5V rail: 150 + 50 + 180 = 380 mA
- 3.3V rail: 120 + 6 = 126 mA

**Total Power Consumption**: 396 + 19.8 + 750 + 250 + 900 = **2,315.8 mW (~2.32 W)**

### Scenario 3: Power Saving Mode (Backlight OFF)

**Components Active:**

- ESP32 (no WiFi): 120 mA @ 3.3V = 396 mW
- Soil Sensor: 6 mA @ 3.3V = 19.8 mW
- LCD (no backlight): 3 mA @ 5V = 15 mW
- Relay Module (standby): 5 mA @ 5V = 25 mW

**Total Current from 5V Supply**:

- 5V rail: 3 + 5 = 8 mA
- 3.3V rail: 120 + 6 = 126 mA

**Total Power Consumption**: 396 + 19.8 + 15 + 25 = **455.8 mW (~0.46 W)**

### Scenario 4: Deep Sleep Mode (Future Enhancement)

**Components Active:**

- ESP32 (deep sleep): 0.1 mA @ 3.3V = 0.33 mW
- Soil Sensor (powered down): 0.1 mA @ 3.3V = 0.33 mW
- LCD (off): 0 mA @ 5V = 0 mW
- Relay Module (standby): 5 mA @ 5V = 25 mW

**Total Power Consumption**: 0.33 + 0.33 + 0 + 25 = **25.66 mW (~0.026 W)**

## Daily Energy Consumption Estimates

### Operational Profile Assumptions:

- **Monitoring Period**: 23.5 hours/day (normal operation)
- **Watering Period**: 0.5 hours/day (30 minutes total watering)
- **LCD Backlight**: ON during day (12 hours), OFF at night (12 hours)

### Energy Calculations:

**Daytime (12 hours with LCD backlight):**

- Monitoring: 1.19 W × 11.5 hours = 13.69 Wh
- Watering: 2.32 W × 0.5 hours = 1.16 Wh
- **Daytime Total**: 14.85 Wh

**Nighttime (12 hours without LCD backlight):**

- Monitoring: 0.46 W × 12 hours = 5.52 Wh
- **Nighttime Total**: 5.52 Wh

**Daily Total Energy**: 14.85 + 5.52 = **20.37 Wh/day**

## Power Supply Requirements

### Minimum Power Supply Specifications:

**Voltage**: 5V DC (with 3.3V regulator for ESP32)
**Current Capacity**: Minimum 500 mA (recommended: 1A for safety margin)
**Power Rating**: Minimum 2.5W (recommended: 5W for safety margin)

### Recommended Power Supply:

- **5V 2A USB Power Adapter** (10W capacity)
- Provides ample headroom for peak consumption
- Standard and readily available
- Cost-effective solution

## Power Optimization Strategies

### Immediate Optimizations:

1. **LCD Backlight Control**: Implement time-based or motion-sensor backlight control
2. **Sensor Power Management**: Power down soil sensor between readings
3. **Pump Duty Cycle**: Implement smart watering algorithms to minimize pump runtime

### Advanced Optimizations (Future Enhancements):

1. **ESP32 Sleep Modes**: Implement deep sleep with periodic wake-ups
2. **Dynamic Frequency Scaling**: Reduce CPU frequency during low-activity periods
3. **Conditional Display**: Turn off display completely during certain hours

### Potential Energy Savings:

- **Backlight Management**: Up to 50% reduction (750 mW saving)
- **Sleep Mode Implementation**: Up to 95% reduction during inactive periods
- **Smart Sensor Management**: 10-20% reduction in sensor power

## Battery Backup Analysis (Optional Future Enhancement)

### For 24-hour Backup Operation:

**Required Battery Capacity**: 20.37 Wh ÷ 3.7V = 5.5 Ah
**Recommended Battery**: 18650 Li-ion, 6-8 Ah capacity
**Charging Requirements**: 5W solar panel with charge controller

### Emergency Mode Operation:

- Disable LCD backlight: Extends runtime by ~50%
- Reduce measurement frequency: Additional 20% extension
- Emergency runtime with 3000mAh battery: ~30 hours

## Conclusions

### Key Findings:

1. **Normal Operation**: 1.19W average power consumption
2. **Peak Operation**: 2.32W during watering cycles
3. **Daily Energy**: 20.37 Wh total energy requirement
4. **Power Supply**: 5V 2A adapter provides adequate capacity

### Recommendations:

1. Use the recommended 5V 2A power supply for reliable operation
2. Implement LCD backlight control for significant energy savings
3. Consider future sleep mode implementation for battery operation
4. Monitor actual consumption during testing and adjust estimates

### Design Margin:

The recommended power supply provides **2.15x safety margin** over peak consumption, ensuring reliable operation under all conditions.
