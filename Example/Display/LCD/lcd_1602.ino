/********************************************
    [I2C]    ATm328P   STM32F103  ESP8266
    SDA      A4        PB7        D2(GPIO4)
    SCL      A5        PB6        D1(GPIO5)
*********************************************/
//#define ARDUINO_NANO
//#define BLUEPILL
#define NODEMCU         // LCD VCC : 3V -> 5V

#ifdef ARDUINO_NANO
    #define SDA A4
    #define SCL A5
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

    lcd.print("ABCDEFGHIJKLMNOP");  // ABCDEFGHIJKLMNOP Print
    lcd.setCursor(0, 1);            // LCD x=0, y=1 point cursor
    lcd.print("QRSTUVWXYZ012345");  // QRSTUVWXYZ012345 Print
    lcd.noDisplay();                // LCD Off
    delay(500);
    lcd.display();                  // LCD On
    delay(500);
}

void loop() {
}
