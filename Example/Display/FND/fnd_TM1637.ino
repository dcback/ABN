/*******************************************************************************************
    Adruino : 1~13, A0~A7(14~21)
    STM32   : PA0~PA15(0~15), PB0~PB15(16~31), PC13~PC15(32~34)
    ESP8266 : D0~D10(D0=16, D1=5, D2=4, D3=0, D4=2, D5=14, D6=12, D7=13, D8=15, D9=3, D10=1
********************************************************************************************/
#define ARDUINO_NANO
//#define BLUEPILL
//#define NODEMCU

#ifdef ARDUINO_NANO
    #define DIO A1  
    #define CLK A0
#elif defined BLUEPILL
    #define DIO PA1
    #define CLK PA0
#else //NODEMCU
    #define DIO D1
    #define CLK D0
#endif

#include <TM1637.h>

TM1637 led;

void setup() {
}

void loop() {
    for (int i = 0; i < 10000; i++)
    {
        led.DigitDisplayWrite(CLK, DIO, i);
        delay(10);
    }
}
