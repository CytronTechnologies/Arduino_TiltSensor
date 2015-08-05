/* 
  The circuit:
 * 16x2 character LCD to ARDUINO UNO
 * LCD RS pin to digital pin 8
 * LCD Enable pin to digital pin 9
 * LCD D4 pin to digital pin 4
 * LCD D5 pin to digital pin 5
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 7
 * LCD R/W pin to ground
 
 Tilt Sensor module to Arduino UNO
 *VCC to 5V 
 *GND to GND
 *Do to D2
 *AO of tilt sensor is not used
 */
  
// include the library code:
#include <LiquidCrystal.h>
#include<Wire.h>

#define Tilt     2  //Digital output from tilt sensor module is connected to D2
#define BUZZER     3  //LED at D3 pin

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  //setup the input or output pin
  pinMode(BUZZER, OUTPUT);
  pinMode(Tilt, INPUT);
  digitalWrite(BUZZER, LOW);  //off LED  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("   Lecture");
  lcd.setCursor(0,1);
  lcd.print("    Alarm");
  delay(1000);  //delay for 1 second 
 lcd.clear(); 
}

void loop() {    
 
  if(digitalRead(Tilt)) //if the DO from Tilt sensor is low, no tilt detected. You might need to adjust the potentiometer to get reading
  {   
    digitalWrite(BUZZER,HIGH);
    lcd.setCursor(0, 0);  //move LCD cursor
    lcd.print("SLEEPING");  //Display message    
  }
  else 
  {    
    digitalWrite(BUZZER,LOW);
    lcd.setCursor(0, 0);  //move LCD cursor    
    lcd.print("AWAKE   ");  //Display message   
  } 
}

