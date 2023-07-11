#include <Arduino.h>

// put function declarations here:
void flash_led(void);

void setup() {
  // put your setup code here, to run once:
  pinMode(PC6, OUTPUT);
  pinMode(PA0, OUTPUT);
  pinMode(PB6, INPUT);
  pinMode(PB7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  flash_led();

  digitalWrite(PB7, !digitalRead(PB6));
}

// put function definitions here:
void flash_led(void) 
{
  digitalWrite(PC6, HIGH);
  digitalWrite(PA0, HIGH);
  delay(100);
  digitalWrite(PC6, LOW);
  digitalWrite(PA0, LOW);
  delay(100);
}