#define NANO        // NANO 보드인 경우 define
//#define BLUEPILL  // BLUEPILL 보드인 경우 define
//#define NODEMCU   // NODEMCU 보드인 경우 define

#ifdef NANO             // NANO가 정의되면
#define buzzPin 5       // buzzPin을 A2로 하고 
#endif                  // #ifdef 사용 후 반드시 #endif

#ifdef BLUEPILL         // BLUEPILL이 정의되면
#define buzzPin PB8     // buzzPin을 PB13로 하고
#endif                  // #ifdef 사용 후 반드시 #endif

#ifdef NODEMCU          // BLUEPILL이 정의되면
#define buzzPin D3      // buzzPin을 D3로 하고
#endif                  // #ifdef 사용 후 반드시 #endif

int delayTime = 1;      // 지연시간(1ms) 변수 할당

void setup()
{
    pinMode(buzzPin, OUTPUT);
}

void loop()
{
    digitalWrite(buzzPin, HIGH); // Buzz On HIGH
    delay(delayTime);            // delayTime 지연
    digitalWrite(buzzPin, LOW);  // Buzz Off LOW
    delay(delayTime);            // delayTime 지연
}
