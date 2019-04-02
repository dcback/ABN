/******************************************
    I2C    Arduino  STM32F103  ESP8266    
    SDA      4         PB7     D2(GPIO4)     
    SCL      5         PB6     D1(GPIO5)     
*******************************************/
#define ARDUINO_NANO
//#define BLUEPILL
//#define NODEMCU

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

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16x2 display

void setup() {
    lcd.begin();        // LCD initialize
    lcd.backlight();    // Backlight on

    lcd.setCursor(3, 0);
    lcd.print("Hello, world!");
    lcd.setCursor(2, 1);
    lcd.print("Ywrobot Arduino!");
    lcd.setCursor(0, 2);
    lcd.print("Arduino LCM IIC 2019");
    lcd.setCursor(2, 3);
    lcd.print("Power By DC Back!");
}

void loop() {
}
