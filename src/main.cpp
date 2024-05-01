#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>

#include "config.hpp"
#include "isr.hpp"
#include "buttons.hpp"

// variable declarations
static bool flag_10_ms = false;
static bool flag_100_ms = false;
static bool flag_1_s = false;

// Peripherals
HardwareSerial serial();
LiquidCrystal lcd(LCD_RS, LCD_RW, LCD_EN, LCD_DB4, LCD_DB5, LCD_DB6, LCD_DB7);

// function prototypes
void set_local_timer_flags(void);
void flash_led(void);
void operate_leds(void);

void setup()
{
  gpio_config();

  digitalWrite(PC6, LOW);

  delay(1000);

  // Uart
  Serial.begin(9600);
  Serial.println("+++++Init+++++");

  isr_init();

  // digitalWrite(PB7, false);

  lcd.begin(16, 2);
  lcd.home();

  lcd.setCursor(0, 0); /* Set cursor to column 0 row 0 */
  lcd.print("Boa Noite");
}

void loop()
{
  set_local_timer_flags();

  // Read Inputs
  if (flag_10_ms)
  {
    read_buttons();
  }

  if (flag_100_ms)
  {
  }

  if (flag_1_s)
  {
  }

  // Calculations
  if (flag_10_ms)
  {
  }

  if (flag_100_ms)
  {
  }

  if (flag_1_s)
  {
  }

  // Set outputs
  if (flag_10_ms)
  {
    operate_leds();
  }

  if (flag_100_ms)
  {
    // flash_led();
  }

  if (flag_1_s)
  {
  }

  // //reset timer flags
  flag_10_ms = false;
  flag_100_ms = false;
  flag_1_s = false;
}

void set_local_timer_flags(void)
{
  static bool old_10_ms = false;
  static bool old_100_ms = false;
  static bool old_1_s = false;

  // set timer flags so they are not reset mid loop

  if (old_10_ms != timers.t_10_ms)
  {
    old_10_ms = !old_10_ms;
    flag_10_ms = true;
  }

  if (old_100_ms != timers.t_100_ms)
  {
    old_100_ms = !old_100_ms;
    flag_100_ms = true;
  }

  if (old_1_s != timers.t_1_s)
  {
    old_1_s = !old_1_s;
    flag_1_s = true;
  }
}

void flash_led(void)
{
  static bool LED_state = false;

  digitalWrite(PC6, !LED_state);

  LED_state = !LED_state;
}

void operate_leds(void)
{
  if (button_1.toggle_press)
  {
    button_1.toggle_press = false;
  }

  digitalWrite(ON_BOARD_LED, !digitalRead(BTN_1));

  if (button_1.short_press)
  {
    lcd.setCursor(0, 1); /* Set cursor to column 0 row 0 */
    lcd.print("Hey");
  }

  if (button_1.long_press)
  {
    lcd.clear();
  }
}