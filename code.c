// Libraries included
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
