# Temperature Control System Arduino Code

## Table of Contents

- [Description](#description)
  - [Components](#components)
  - [Functionality](#functionality)
  - [Usage](#usage)
  - [Website](#website)
  - [Preview](#preview)
  - [Code](#code)

## Description

This Arduino code is for a temperature control system using a temperature sensor, fan, heater, and LEDs. The system reads temperature from an analog sensor, displays it on a 16x2 LCD screen, and controls the fan and heater based on predefined temperature thresholds.

### Components

- **Temperature Sensor (Thermistor):** Connected to analog pin A0 to measure ambient temperature.
- **Fan:** Connected to pin 13. Turns on when the temperature exceeds a certain threshold.
- **Heater:** Connected to pin 9. Activates when the temperature falls below a specific value.
- **RGB LEDs (Red, Green, Blue):** Indicate the system's status. Red for cooling, blue for heating, and green for normal operation.
- **LCD Display:** 16x2 character display to show the current temperature and status.

### Functionality

1. **Initialization:**
   - Initializes the LCD, printing a welcome message.
   - Sets pins for fan, heater, and LEDs as outputs.

2. **Main Loop:**
   - Reads temperature from the sensor.
   - Displays temperature on the LCD.
   - Controls the fan, heater, and LEDs based on temperature conditions:
     - If the temperature is above 35°C, the fan is turned on, the heater is turned off, and the red LED is activated.
     - If the temperature is below 10°C, the fan is turned off, the heater is turned on, and the blue LED is activated.
     - For temperatures between 10°C and 35°C, both the fan and heater are turned off, and the green LED is activated.

3. **Serial Communication:**
   - Initializes serial communication for debugging purposes.
   - Outputs the temperature readings to the Serial Monitor at a baud rate of 9600.

### Usage

- Connect the components as specified in the code comments.
- Upload the code to an Arduino board.
- Monitor the Serial Monitor for temperature readings and system status.
- Observe the LCD display for real-time temperature information.

This code serves as a foundation for a simple temperature control system and can be extended for various applications, such as climate control in a small enclosure.

## Website

Visit the website: [Tinkercad](https://www.tinkercad.com/things/lkMVj33GXHf-grand-waasa-juttuli/editel?sharecode=DjNJQOOczI-CBgYnawW1SOL2jJRtoMNiXq1EuLQmK-s)

## Preview

![Project Preview](/graph.png)

## Code

```// Libraries included
#include <LiquidCrystal.h>


// Declare constants
const int temPin = A0;      // Analog pin for temperature sensor
const int fan = 13;         // Pin for controlling the fan
const int heater = 9;       // Pin for controlling the heater
const int LedRed = 12;      // Pin for the red LED
const int LedGreen = 11;    // Pin for the green LED
const int LedBlue = 10; 



// Pin for the blue LED

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);  
// Initialize serial communication for debugging
  lcd.begin(16, 2);          // Initialize the LCD display
  lcd.print("Hello EveryBody!");  // Display a welcome message on the LCD
  pinMode(fan, OUTPUT);       // Set the fan pin as an output
  pinMode(heater, OUTPUT);    // Set the heater pin as an output
  pinMode(LedRed, OUTPUT);    // Set the red LED pin as an output
  pinMode(LedGreen, OUTPUT);  // Set the green LED pin as an output
  pinMode(LedBlue, OUTPUT);   // Set the blue LED pin as an output
  delay(2000);                // Pause for 2 seconds
  lcd.clear();                // Clear the LCD display
  lcd.print("Temp= ");        // Display temperature label
  lcd.setCursor(0,1);
  lcd.print("Fan= ");          // Display fan label
  lcd.setCursor(8,1);
  lcd.print("&");
  lcd.setCursor(9,1);
  lcd.print("Hot= ");          // Display heater label
}

void loop() {
  float temp = analogRead(temPin);   // Read temperature from the sensor
  temp *= 5.0;
  temp /= 1024.0;
  temp -= 0.5;
  temp *= 100.0;
  
  lcd.setCursor(6,0);
  lcd.print(temp);                    // Display the temperature on the LCD
    
  // Section for controlling the fan and heater based on temperature
  if (temp > 35){
    digitalWrite(fan, HIGH);         // Turn on the fan
    digitalWrite(heater, LOW);       // Turn off the heater
    digitalWrite(LedRed, HIGH);      // Turn on the red LED
    digitalWrite(LedGreen, LOW);
    digitalWrite(LedBlue, LOW);
    lcd.setCursor(5,1);
    lcd.print("ON ");                 // Display status on the LCD
    lcd.setCursor(13,1);
    lcd.print("OFF ");
  }
  else if(temp < 10) {
    digitalWrite(fan, LOW);          // Turn off the fan
    digitalWrite(heater, HIGH);       // Turn on the heater
    digitalWrite(LedRed, LOW);
    digitalWrite(LedGreen, LOW);
    digitalWrite(LedBlue, HIGH);      // Turn on the blue LED
    lcd.setCursor(5,1);
    lcd.print("OFF");
    lcd.setCursor(13,1);
    lcd.print("ON ");
  }
  else {
    digitalWrite(fan, LOW);          // Turn off the fan
    digitalWrite(heater, LOW);        // Turn off the heater
    digitalWrite(LedRed, LOW);
    digitalWrite(LedGreen, HIGH);     // Turn on the green LED
    digitalWrite(LedBlue, LOW);
    lcd.setCursor(5,1);
    lcd.print("OFF");
    lcd.setCursor(13,1);
    lcd.print("OFF ");
  }
   
  delay(1000);   // Pause for 1 second
}
```
