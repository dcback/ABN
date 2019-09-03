#define NANO        // NANO 보드인 경우 define
//#define BLUEPILL  // BLUEPILL 보드인 경우 define
//#define NODEMCU   // NODEMCU 보드인 경우 define

#ifdef NANO             // NANO가 정의되면
#define relayPin 6      // relayPin을 6로 하고
#define ledPin   13     // ledPin을 13로 하고
#endif                  // #ifdef 사용 후 반드시 #endif

#ifdef BLUEPILL         // BLUEPILL이 정의되면
#define relayPin PB9    // relayPin을 PB9로 하고
#define ledPin   PC13   // ledPin을 13로 하고
#endif                  // #ifdef 사용 후 반드시 #endif

#ifdef NODEMCU          // BLUEPILL이 정의되면
#define relayPin D3     // relayPin을 D3로 하고
#define ledPin   D4     // ledPin을 D4로 하고
#endif                  // #ifdef 사용 후 반드시 #endif

void setup()
{
    pinMode(relayPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    digitalWrite(relayPin, HIGH);    // Buzz On HIGH
    digitalWrite(ledPin, HIGH);      // LED On
    delay(1000);                     // 1초 지연
    digitalWrite(relayPin, LOW);     // Buzz Off LOW
    digitalWrite(ledPin, LOW);       // LED Off
    delay(1000 );                    // 1초 지연
}
