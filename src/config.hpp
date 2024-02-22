#ifndef CONFIG_HPP
#define CONFIG_HPP

#define LCD_RS PB4
#define LCD_DB4 PB8
#define LCD_DB5 PA8
#define LCD_DB6 PB9
#define LCD_DB7 PB5
#define LCD_EN PB2

void gpio_config(void);

#endif /* CONFIG_HPP */