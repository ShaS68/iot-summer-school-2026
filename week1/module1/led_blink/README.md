# LED Blink Project

## Project Title

LED Blink using Arduino Uno

## Hardware Required

- Arduino Uno
- LED
- 220 Ω Resistor
- Breadboard
- Jumper Wires
- USB Cable
- Potentiometer (Optional)

## Circuit Diagram Description

The LED is connected to digital pin 13 of the Arduino Uno through a 220 Ω resistor. The other terminal of the LED is connected to GND. If a potentiometer is used, its output pin is connected to analog pin A0 to control the blinking speed.

## How to Upload

1. Connect the Arduino Uno to the computer using a USB cable.
2. Open the Arduino IDE.
3. Select **Arduino Uno** under **Tools → Board**.
4. Select the correct COM port under **Tools → Port**.
5. Open the `blink.ino` file.
6. Click the **Upload** button.
7. Wait until the upload is completed successfully.

## Expected Output

- The LED connected to pin 13 blinks continuously.
- If a potentiometer is connected, the blinking speed changes according to the potentiometer position.
- The Serial Monitor displays the LED status (ON/OFF), if enabled in the program.

## Troubleshooting Tips

1. Check that the Arduino board is connected properly.
2. Verify that the correct COM port is selected.
3. Ensure the LED polarity is correct.
4. Check all jumper wire connections.
5. Make sure the correct Arduino board is selected in the IDE.
