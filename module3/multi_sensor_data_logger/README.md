# Multi-Sensor Data Logger

## Components Used
- Arduino Uno
- DHT11 Sensor
- LDR
- Potentiometer
- 10kΩ Resistor

## Description
This project reads data from an LDR, a potentiometer, and a DHT11 sensor every 5 seconds. The readings are displayed in CSV format on the Serial Monitor. The last 10 readings are stored using arrays, and the average values are calculated every minute.
