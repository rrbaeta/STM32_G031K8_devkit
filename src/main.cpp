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
  static bool flag_100_ms = false;
  static bool flag_1_s = false;

  //set timer flags so they are not reset mid loop
  flag_100_ms = timers.t_100_ms;
  flag_1_s = timers.t_1_s;

  //Read Inputs
  if(flag_100_ms)
  {

  }

  if(flag_1_s)
  {
    
  }

  //Calculations
  if(flag_100_ms)
  {

  }

  if(flag_1_s)
  {
    
  }

  //Set outputs
  if(flag_100_ms)
  {
    digitalWrite(PB7, !digitalRead(PB6));
    flash_led();
  }

  if(flag_1_s)
  {

  }

  //reset timer flags
  flag_100_ms = false;
  timers.t_100_ms = false;
  flag_1_s = false;
  timers.t_1_s = false;
}

// put function definitions here:
void flash_led(void) 
{
  static bool LED_state = false;

  digitalWrite(PC6, !LED_state);
  digitalWrite(PA0, LED_state);

  LED_state = !LED_state;
}