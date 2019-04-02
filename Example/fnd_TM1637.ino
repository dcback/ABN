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

#include <TM1637.h>

TM1637 led;

void setup() {
}

void loop() {
    for (int i = 0; i < 10000; i++)
    {
        led.DigitDisplayWrite(SCL, SDA, i);
        delay(10);
    }
}
