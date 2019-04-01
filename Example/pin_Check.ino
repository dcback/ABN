/********************************
    #define ARDUINO   0
    #define BLUEPILL  1
    #define NODEMCU   2

    #define MY_MCU  NODEMCU

    #if MY_MCU == ARDUINO
        #define Pins and Funcs()
        #include <abc.h>
    #elif MY_MCU == BLUEPILL
        #define Pins and Funcs()
        #include <def.h>
    #else // MY_MCU == NODEMCU
        #define Pins and Funcs()
        #include <ghi.h>
    #endif
*******************************************************************************************
    Adruino : 1~13, A0~A7
    STM32   : PA0~PA15, PB0~PB15, PC0~PC15
    ESP8266 : D0~D10(D0=16, D1=5, D2=4, D3=0, D4=2, D5=14, D6=12, D7=13, D8=15, D9=3, D10=1
*******************************************************************************************/
#define ARDUINO   0
#define BLUEPILL  1
#define NODEMCU   2
    
#define MY_MCU  NODEMCU

#if MY_MCU == ARDUINO
    #define MAX_GPIO_CNT  8
    int pinNo[MAX_GPIO_CNT] = { A0, A1, A2, A3, A4, A5, A6, A7 };
#elif MY_MCU == BLUEPILL
    #define MAX_GPIO_CNT  16
    int pinNo[MAX_GPIO_CNT] = { PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9, PA10, PA11, PA12, PA13, PA15 };
#else //MY_MCU == NODEMCU
    #define MAX_GPIO_CNT  11
    int pinNo[MAX_GPIO_CNT] = { D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10 };
#endif

void setup() {
    Serial.begin(9600);
}

void loop() {
    for ( int i = 0; i < MAX_GPIO_CNT; i++) {
        Serial.print("GPIO"); Serial.print(i); Serial.print(" = ");
        Serial.println(pinNo[i]);
        delay(1000);
    }
}
