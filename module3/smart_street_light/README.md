# Smart Street Light

## Components Used
- Arduino Uno
- LDR
- PIR Motion Sensor
- LED
- 220Ω Resistor
- 10kΩ Resistor

## Description
This project controls a street light using an LDR and PIR sensor. During the day, the LED remains OFF. At night, the LED turns ON at full brightness when motion is detected. If no motion is detected for 30 seconds, the LED dims to 20% brightness using PWM.

## Output
The Serial Monitor displays whether it is daytime, motion is detected, or the LED has dimmed due to no motion.
