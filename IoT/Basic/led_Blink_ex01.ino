/**************************************************************************
    #define NANO
    #define BLUEPILL
    #define NODEMCU

    #ifdef NANO
       #define Pins and Funcs()
       #include <aaa.h>
    #elif defined BLUEPILL
       #define Pins and Funcs()
       #include <bbb.h>
    #else                   //NODEMCU
       #define Pins and Funcs()
       #include <ccc.h>
    #endif
***************************************************************************
    Adruino : 1~13, A0~A7(A0=14, A1=15, A2=16, A3=17, A4=18, A5=19, A6=20,
             A7=21)
    STM32   : PA0~PA15(0~15), PB0~PB15(16~31), PC13~PC15(32~34)
    ESP8266 : D0~D10(D0=16, D1=5, D2=4, D3=0, D4=2, D5=14, D6=12, D7=13,
             D8=15, D9=3, D10=1)
**************************************************************************/
#define NANO        // NANO 보드인 경우 define
//#define BLUEPILL  // BLUEPILL 보드인 경우 define
//#define NODEMCU   // NODEMCU 보드인 경우 define

#ifdef NANO             // NANO 보드인 경우
#define ledPin 13       // ledPin을 13핀 으로 정의한다
#elif defined BLUEPILL  // BLUEPILL 보드인 경우
#define ledPin PC13     // ledPin을 PC13핀 으로 정의한다
#else                   // NANO, BLUEPILL도 아닌 경우(NODEMCU인 경우)
#define ledPin D4       // ledPin을 D4핀 으로 정의한다
#endif

int ledState = LOW;     // 정수변수 ledState를 LOW(0)로 정의

// 최초 한번만 실행
void setup()
{
    pinMode(ledPin, OUTPUT); // ledPin핀을 출력으로 정의

    for ( int i = 0 ; i < 10 ; i++)
    {
        digitalWrite(ledPin, HIGH);
        delay(50);
        digitalWrite(ledPin, LOW);
        delay(50);
    }
}

// 무한 반복 실행(실질적 작동단계)
void loop()
{
    digitalWrite(ledPin, ledState); // ledPin핀에 ledState 출력
    delay(500);                    // 1000ms(1초) 지연(유지)
    ledState = !ledState;           // ledState상태 값 반전(!:Logic Not)
}
