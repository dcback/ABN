/********************************************
    [I2C]    ATm328P   STM32F103  ESP8266
    SDA      A4        PB7        D2(GPIO4)
    SCL      A5        PB6        D1(GPIO5)
*********************************************/
#define ARDUINO_NANO
//#define BLUEPILL
//#define NODEMCU         // LCD VCC : 3V -> 5V

#ifdef ARDUINO_NANO
    #define SDA 4
    #define SCL 5
#elif defined BLUEPILL
    #define SDA PB7
    #define SCL PB6
#else //NODEMCU
    #define SDA D2
    #define SCL D1
#endif

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16x2 display

void setup() {
    lcd.begin();        // LCD initialize
    lcd.backlight();    // Backlight on

    lcd.setCursor(3, 0);
    lcd.print("Hello, world!");
    lcd.setCursor(1, 1);
    lcd.print("DC Back's Arduino!");
    lcd.setCursor(0, 2);
    lcd.print("Arduino LCM IIC 2019");
    lcd.setCursor(2, 3);
    lcd.print("Power By DC Back!");
}

void loop() {
}
