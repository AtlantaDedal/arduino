
/*
  Зажигаем светодиод на одну секунду, затем выключаем его на
  одну  секунду в цикле.
*/

#include "Ultrasonic.h"
#include "TM1638.h"
TM1638 module(8, 9, 10);

// sensor connected to:
// Trig - 12, Echo - 13

#define ANALOG_SENSOR_PIN  A0 
#define DIGITAL_SENSOR_PIN 3


Ultrasonic ultrasonic(12, 11);


int red = 6;
int laser = 13;
int yellow = 5;
int green = 7;

int  LightAnalogValue; /* Holds the last analog value */

void setup() {
  Serial.begin(9600);             // start the serial port
  // Инициализируем цифровой вход/выход в режиме выхода.
  // Выход 13 на большинстве плат Arduino подключен к светодиоду на плате.
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(laser, OUTPUT);


}

void loop() {
  float dist_cm = ultrasonic.Ranging(CM);   // get distance
  //Serial.println(dist_cm);          // print the distance
  if (dist_cm < 10.0) {
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
  }
  if ((dist_cm > 10.0) && (dist_cm < 20.0)) {
    digitalWrite(red, HIGH);
    digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);
  }
  if (dist_cm > 20.0) {
    digitalWrite(red, HIGH);
    digitalWrite(yellow, HIGH);
    digitalWrite(green, HIGH);
  }
  
  String d;
  int cm =dist_cm;
  
  d=(String)cm;
  module.clearDisplay();
  module.setDisplayToString(d);
  digitalWrite(laser, HIGH);
  delay(100);
  digitalWrite(laser, LOW);
  delay(100);

  LightAnalogValue = analogRead(ANALOG_SENSOR_PIN);  //Read the voltage from sensor
  Serial.print("Analog Value (0 to 1023)"); 
  Serial.println(LightAnalogValue,DEC);


  

}
