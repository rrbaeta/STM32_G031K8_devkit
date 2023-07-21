#include <Arduino.h>

#include "isr.hpp"
#include "buttons.hpp"

HardwareSerial serial();

//function declarations
void flash_led(void);

void setup() 
{
  pinMode(PC6, OUTPUT);
  pinMode(PA0, OUTPUT);
  pinMode(PB6, INPUT);
  pinMode(PB7, OUTPUT);

  digitalWrite(PC6, LOW);

  delay(1000);
  
  //Uart
  Serial.begin(9600);
  Serial.println("+++++Init+++++");

  isr_init();
}

void loop() 
{

  //Read Inputs

  //Calculations

  //Set outputs






  // put your main code here, to run repeatedly:
  flash_led();

  digitalWrite(PB7, !digitalRead(PB6));
}

// put function definitions here:
void flash_led(void) 
{
  //digitalWrite(PC6, HIGH);
  digitalWrite(PA0, HIGH);
  delay(100);
  //digitalWrite(PC6, LOW);
  digitalWrite(PA0, LOW);
  delay(100);
}