#include <Arduino.h>

#include "isr.hpp"
#include "buttons.hpp"

static bool flag_10_ms = false;
static bool flag_100_ms = false;
static bool flag_1_s = false;
HardwareSerial serial();

//function declarations
void set_local_timer_flags(void);
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
  digitalWrite(PC6, true);

  set_local_timer_flags();

  //Read Inputs
  if(flag_10_ms)
  {
  
  }

  if(flag_100_ms)
  {

  }

  if(flag_1_s)
  {
    
  }

  //Calculations
  if(flag_10_ms)
  {
    
  }

  if(flag_100_ms)
  {

  }

  if(flag_1_s)
  {
    
  }

  //Set outputs
  if(flag_10_ms)
  {
    digitalWrite(PB7, !digitalRead(PB6));
  }

  if(flag_100_ms)
  {
    flash_led();
  }

  if(flag_1_s)
  {

  }

  // //reset timer flags
  flag_10_ms = false;
  flag_100_ms = false;
  flag_1_s = false;

  digitalWrite(PC6, false);
}

void set_local_timer_flags(void)
{
  static bool old_10_ms = false;
  static bool old_100_ms = false;
  static bool old_1_s = false;

  //set timer flags so they are not reset mid loop

  if(old_10_ms != timers.t_10_ms)
  {
    old_10_ms = !old_10_ms;
    flag_10_ms = true;
  }

  if(old_100_ms != timers.t_100_ms)
  {
    old_100_ms = !old_100_ms;
    flag_100_ms = true;
  }

  if(old_1_s != timers.t_1_s)
  {
    old_1_s = !old_1_s;
    flag_1_s = true;
  }
}

// put function definitions here:
void flash_led(void) 
{
  static bool LED_state = false;

  digitalWrite(PA0, !LED_state);

  LED_state = !LED_state;
}