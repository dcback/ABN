/******************************************
    I2C    Arduino  STM32F103  ESP8266
    SDA      A4        PB7     D2(GPIO4)
    SCL      A5        PB6     D1(GPIO5)
*******************************************/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address(I2C) to 0x27

void setup()
{
    lcd.begin();     // LCD initialize
    lcd.backlight(); // Backlight on
}

void loop()
{
    int tempVal = random(10, 30);    // 10 ~ 30 Random value
    int humiVal = random(50, 80);    // 50 ~ 80 Random value

    // LCD1602_I2C Display
    lcd.clear();         // Clears screen & cursor at upper-left corner.
    lcd.setCursor(0, 0); // cursor at x=0, y=0 position
    lcd.print("Temperature:");
    lcd.print(tempVal);
    lcd.print(" C");

    lcd.setCursor(0, 1); // cursor at x=0, y=1 position
    lcd.print("Humidity:");
    lcd.print(humiVal);
    lcd.print(" %");

    delay(500);
}
