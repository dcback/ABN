/******************************************************************************************
    #define ARDUINO_NANO
    #define BLUEPILL
    #define NODEMCU
    #ifdef ARDUINO_NANO
        #define Pins and Funcs()
        #include <aaa.h>
    #elif defined BLUEPILL
        #define Pins and Funcs()
        #include <bbb.h>
    #else //NODEMCU
        #define Pins and Funcs()
        #include <ccc.h>
    #endif
*******************************************************************************************
    Adruino : 1~13, A0~A7(14~21)
    STM32   : PA0~PA15(0~15), PB0~PB15(16~31), PC13~PC15(32~34)
    ESP8266 : D0~D10(D0=16, D1=5, D2=4, D3=0, D4=2, D5=14, D6=12, D7=13, D8=15, D9=3, D10=1
*******************************************************************************************/
#define ARDUINO_NANO
//#define BLUEPILL
//#define NODEMCU

#ifdef ARDUINO_NANO
    #define ledPin 13
#elif defined BLUEPILL
    #define ledPin PC13
#else //NODEMCU
    #define ledPin 2
#endif

void LED_BLINK();

void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
}

void loop() {
#ifdef ARDUINO_NANO
    int pinNo[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3, A4, A5, A6, A7 };

    int MAX_GPIO_CNT = sizeof(pinNo) / sizeof(int);

    for ( int i = 0; i < MAX_GPIO_CNT; i++) {
        if ( i <= 13 ) {
            Serial.print("D"); Serial.print(i); Serial.print(" = "); Serial.println(pinNo[i]);
        }

        if ( i > 13  ) {
            Serial.print("A"); Serial.print(i - 14); Serial.print(" = "); Serial.println(pinNo[i]);
        }
        LED_BLINK();
    }
#endif

#ifdef BLUEPILL
    int pinNo[] = { PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9, PA10, PA11, PA12, PA13, PA14, PA15,
                    PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8, PB9, PB10, PB11, PB12, PB13, PB14, PB15,
                    PC13, PC14, PC15
                  };
    int MAX_GPIO_CNT = sizeof(pinNo) / sizeof(int); // 35
    for ( int i = 0; i < MAX_GPIO_CNT ; i++) {
        if ( i <= 15 ) {
            Serial.print("PA"); Serial.print(i); Serial.print(" = "); Serial.println(pinNo[i]);
        }
        else if ( 16 <= i && i <= 31 ) {
            Serial.print("PB"); Serial.print(i - 16); Serial.print(" = "); Serial.println(pinNo[i]);
        }
        else  {
            Serial.print("PC"); Serial.print(i - 19); Serial.print(" = "); Serial.println(pinNo[i]);
        }
        LED_BLINK();
    }
#endif

#ifdef NODEMCU
    int pinNo[] = { D0, D1, D2, D3, D4, D5, D6, D7, D8, D9, D10 };
    int MAX_GPIO_CNT = sizeof(pinNo) / sizeof(int);
    for ( int i = 0; i < MAX_GPIO_CNT; i++) {
        Serial.print("D"); Serial.print(i); Serial.print(" = "); Serial.println(pinNo[i]);
        LED_BLINK();
    }
#endif
}

void LED_BLINK() {
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
}
