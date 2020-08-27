#include <Arduino.h>
#include <LiquidCrystal.h>
#define SensorPin A0
float sensorValue = 0;
float moisturePercent = 0;
String moistureStats;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  // Set up the Serial monitor.
  Serial.begin(9600);
  // Set up the LCD's number of columns and rows.
  lcd.begin(16, 2);
  // Print starting info.
  lcd.print("Calculating...");
}
void loop() {
  // Analog calculations.
  for (int i = 0; i <= 100; i++)
  {
    sensorValue = sensorValue + analogRead(SensorPin);
    delay(1);
  }
  sensorValue = sensorValue/100.0;
  moisturePercent = (sensorValue/1024)*100;
  // Define the values for your plant.
  if (moisturePercent > 0 && moisturePercent < 30) {
    moistureStats = "very dry";
  } else if (moisturePercent > 29 && moisturePercent < 40) {
    moistureStats = "desaturated";
  } else if (moisturePercent > 39 && moisturePercent < 60) {
    moistureStats = "okay";
  } else if (moisturePercent > 59 && moisturePercent < 80) {
    moistureStats = "perfect";
  } else if (moisturePercent > 79 && moisturePercent < 101) {
    moistureStats = "oversaturated";
  }
  

  // Experimental!
  delay(60);
  // Print the values to the serial monitor.
  Serial.println("The soil moisture is " + moistureStats + ".");


  // Clear the LCD for proper use.
  lcd.clear();
  // Set the cursor to the first first line.
  lcd.setCursor(0, 0);
  // Print "Soil moisture" to the LCD.
  lcd.print("Soil is:");
  // Set the cursor to the second line.
  lcd.setCursor(0, 1);
  // Print the soil moisture value.
  lcd.print(moistureStats);
}
