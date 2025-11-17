# Automatic Plant Watering System

## Project Description for TTK8

### Project Overview

This project involves designing and implementing an automatic plant watering system that monitors soil moisture levels and waters plants autonomously when the soil becomes too dry. The system will use embedded sensors to continuously monitor conditions and actuate a watering mechanism when appropriate. Firmware can be found under /watering_system.

### Project Objectives

The primary goal is to create a smart irrigation system that:

- Monitors soil moisture levels in real-time using moisture sensors
- Automatically triggers watering when soil moisture falls below a specified threshold
- Provides feedback on system status and environmental conditions
- Operates autonomously with minimal human intervention
- Prevents overwatering through intelligent control algorithms

### Technical Components

**Hardware:**

- Microcontroller (AtMega4809)
- Soil moisture sensor
- Water pump (WHADDA Water Pump)
- Water reservoir and tubing system
- Power supply system
- Optional: LCD display for status monitoring

**Software:**

- Sensor data acquisition and processing
- Control algorithms for watering decisions
- UART Testing interface

### Learning Objectives

Through this project, I aim to develop my knowledge in several areas:

**New Skills to Acquire:**

**Moisture Sensor**: This is my first time working with soil moisture sensors. I will learn how to use them appropriately.

**Actuator Control**: Learning to control some sort of actuator for the activating and disabling the watering mechanism.

**Design of the Physical System**: I have not made a similar system before, with tubes and tanks for water. I imagine having water throughout the system will bring some challenges of its own.

**Skills to Strengthen:**

**System Integration**: Combining multiple hardware components into a cohesive system
**Data Processing**: Implementing algorithms to process sensor data and make intelligent decisions
**Testing & Validation**: Developing comprehensive testing procedures for autonomous systems

### Expected Challenges

- Waterproofing and protecting electronics in a humid environment
- Calibrating moisture sensors for different soil types
- Preventing water damage to the system
- Implementing reliable fail-safes to prevent plant damage from over/under-watering
- Managing power consumption for long-term operation

### Success Criteria

The project will be considered successful when:

1. The system accurately measures soil moisture levels
2. Watering is triggered automatically when moisture falls below threshold
3. The system prevents overwatering through intelligent control
4. All components operate reliably over extended periods
5. The system demonstrates clear learning outcomes in sensor integration and embedded control
