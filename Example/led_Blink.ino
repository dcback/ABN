/*******************************************************************************
    #define ARDUINO
    #define BLUEPILL
    #define NODEMCU

    #ifdef ARDUINO
        #define Pins and Funcs()
        #include <abc.h>
    #endif
    #ifdef BLUEPILL
        #define Pins and Funcs()
        #include <abc.h>
    #endif   
    #ifdef
        #define Pins and Funcs()
        #include <abc.h>
    #endif
********************************************************************************
    Adruino : 1~13, A0~A7
    STM32   : PA0~PA15, PB0~PB15, PC0~PC15
    ESP8266 : D0~D10(D0=16, D1=5, D2=4, D3=0, D4=2, D5=14, D6=12, D7=13, D8=15,
********************************************************************************/
//#define ARDUINO 
//#define BLUEPILL  
#define NODEMCU         

#ifdef ARDUINO
    #define ledPin 13
#endif
#ifdef BLUEPILL
    #define ledPin PC13 
#endif    
#ifdef NODEMCU
    #define ledPin 2
#endif

unsigned int cnt;

void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);

    Serial.print(cnt); Serial.print(" >> GPIO: "); Serial.println(ledPin);
    cnt++;
}
