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
    Adruino : 0~13, A0~A7
    STM32   : PB0~PB15, PB0~PB15, PC0~PC15
    ESP8266 : D0~D10(D0=16, D1=5, D2=4, D3=0, D4=2, D5=14, D6=12, D7=13, D8=15, D9=3, D10=1
*******************************************************************************************/
#define ARDUINO   0
#define BLUEPILL  1
    
#define MY_MCU  BLUEPILL

#if MY_MCU == ARDUINO
    #define MAX_GPIO_CNT  14
    int pinNo[MAX_GPIO_CNT] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
#else //MY_MCU == BLUEPILL
    #define MAX_GPIO_CNT  16
    int pinNo[MAX_GPIO_CNT] = { PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8, PB9, PB10, PB11, PB12, PB13, PB15 };
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
