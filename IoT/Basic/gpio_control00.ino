#define NANO        // NANO 보드인 경우 define
//#define BLUEPILL  // BLUEPILL 보드인 경우 define
//#define NODEMCU   // NODEMCU 보드인 경우 define

#ifdef NANO         // NANO가 정의되면
#define swPin A2    // swPin을 A2로 하고 
#define ledPin 13   // ledPin을 13로 하고
#endif              // #ifdef 사용 후 반드시 #endif

#ifdef BLUEPILL     // BLUEPILL이 정의되면
#define swPin PB13  // swPin을 PB13로 하고
#define ledPin PC13 // ledPin을 13로 하고
#endif              // #ifdef 사용 후 반드시 #endif

#ifdef NODEMCU      // BLUEPILL이 정의되면
#define swPin D3    // swPin을 D3로 하고
#define ledPin D4   // ledPin을 D4로 하고
#endif              // #ifdef 사용 후 반드시 #endif

void setup()
{
    pinMode(swPin, INPUT);      // swPin을 입력으로 정의
    pinMode(ledPin, OUTPUT);    // ledPin핀을 출력으로 정의
    Serial.begin(115200);       // 시리얼 출력(115200) 사용
}

void loop()
{
    int readValue = digitalRead(swPin);
    digitalWrite(ledPin, readValue);
    Serial.print("read Value = "); Serial.print(readValue);
    Serial.println(""); // 다음 줄에 Printing
    delay(1000);        // 1초 지연
}
