# Automatic Plant Watering System - Component List

## Core Electronics

### 1. Microcontroller

#### ESP32 DevKit V1

- 32-bit dual-core processor (240 MHz)
- Operating voltage: 3.3V (5V tolerant on VIN)
- GPIO pins: 30 digital I/O, 16 analog inputs
- ADC resolution: 12-bit
- Built-in peripherals: I2C, SPI, UART, PWM
- USB programming via CP2102 chip
- **Link**: [DOIT ESP32 DevKit V1](https://www.amazon.com/dp/B0718T232Z)
- **Price**: ~$8-12

### 2. Soil Moisture Sensor

#### EQV Humidity Sensor Module

- Corrosion-resistant (no exposed metal contacts)
- Operating voltage: 3.3-5.5V
- Output voltage: 0-3.0V (analog)
- Interface: 3-pin (VCC, GND, AOUT)
- Size: 99mm x 16mm
- Better accuracy than resistive sensors
- **Link**: [Capacitive Soil Moisture Sensor](https://www.aliexpress.com/item/32562744759.html?spm=a2g0o.order_detail.order_detail_item.4.152af19cv1S7KZ#nav-specification)
- **Price**: ~$3-5

## Water System Components

### 3. Water Pump

#### Micro Submersible and Amphibious DC Motor Pump Water pump

- Operating voltage: 3-5V DC
- Flow rate: 80-120L/h
- Current: 130-220mA
- Dimensions: Compact design for small containers
- Suitable for small to medium plants
- **Link**: [Mini Submersible Pump](https://www.aliexpress.com/item/32894401053.html?spm=a2g0o.new_account_index.0.0.5e1f25b9WRHyjS)
- **Price**: ~$5-8

### 4. Water Control

#### Single Channel 5V Relay Module

- Controls pump power on/off
- Operating voltage: 5V
- Max switching capacity: 10A 250VAC / 10A 30VDC
- Optocoupler isolation for safety
- LED indicators for status
- **Link**: [5V Relay Module](https://www.amazon.com/dp/B00VRUAHLE)
- **Price**: ~$2-4

### 5. Tubing and Water Distribution

#### Silicone Tubing (6-7mm outer diameter)

- Length: 1-2 meters
- Food-grade silicone material
- Flexible and durable
- **Price**: ~$3-5

## Display (Optional)

### 6. Status Display

#### 16x2 LCD with I2C Module

- Display: 16 characters × 2 lines
- Interface: I2C (4 wires: VCC, GND, SDA, SCL)
- Adjustable contrast via potentiometer
- Blue backlight with white characters
- Operating voltage: 5V
- I2C address: 0x27 (configurable to 0x20-0x27)
- **Link**: [16x2 LCD I2C Module](https://www.amazon.com/dp/B07S7PJYM6)
- **Price**: ~$8-12

## Power Supply

### 7. Main Power Supply

#### 5V USB Power Adapter

- For continuous AC power operation
- Output: 5V, 2A minimum recommended
- Standard USB-A or wall adapter with micro-USB cable
- Most reliable power source for continuous operation
- **Link**: [5V 2A USB Power Adapter](https://www.amazon.com/dp/B00MARDJZ4)
- **Price**: ~$5-10

#### USB Cable (Micro-USB)

- For programming ESP32 and power delivery
- Length: 1-2 meters recommended
- Data + charging cable (not charging-only)
- **Link**: [Micro-USB Cable](https://www.amazon.com/dp/B0711PVX6Z)
- **Price**: ~$3-5

## Supporting Components

### 8. Connections and Assembly

#### Breadboard

- For prototyping and testing connections
- Half-size breadboard (400 tie points)
- **Link**: [Half-Size Breadboard](https://www.amazon.com/dp/B0135IQ0ZC)
- **Price**: ~$3-5

#### Jumper Wires

- Male-to-Male, Male-to-Female assortment
- Various lengths (10cm, 20cm)
- For connecting components
- **Link**: [Jumper Wire Kit](https://www.amazon.com/dp/B01EV70C78)
- **Price**: ~$3-5

### 9. Enclosure and Protection

#### Waterproof Project Box

- Plastic enclosure with sealed lid
- Dimensions: ~150×100×70mm minimum
- IP65 water resistance rating
- **Price**: ~$8-15

### 10. Water Storage

#### Water Container

- 2-5 liter capacity
- Wide opening for easy filling
- Food-grade plastic material
- **Price**: ~$5-10

## Cost Summary

### Complete System (~$50-65)

- ESP32 DevKit V1: $10
- Capacitive soil sensor: $4
- Mini water pump: $6
- Relay module: $3
- 16x2 LCD I2C: $10
- USB power supply: $8
- USB cable: $4
- Breadboard and jumper wires: $8
- Water container and tubing: $8
- Project enclosure: $12

**Total Estimated Cost: $73**

## Project Notes

### Based on Your Learning Objectives

1. **Moisture Sensor Experience**: The capacitive sensor is more reliable and educational than resistive types
2. **Actuator Control Learning**: The relay module provides clear on/off pump control
3. **Physical System Design**: Start with single plant, expand to multiple plants later

### Getting Started Approach

**Phase 1: Basic System**

- Build on breadboard first for learning and testing
- Use USB power supply for reliable operation
- Focus on core functionality: sensor → decision → pump control

**Phase 2: Improvements**

- Move to permanent connections
- Add weatherproof enclosure
- Expand to multiple plants with additional sensors
