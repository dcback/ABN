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

int num = 8;
int tones[] = {261, 294, 329, 349, 392, 440, 493, 523}; //도 레 미..주파수

void setup()
{
}

void loop()
{
    for (int i = 0; i < num; i++)
    {
        tone(buzzPin, tones[i]); // tone(pin, frequency)
        delay(1000);
    }
    noTone(buzzPin); // noTone(pin)
    delay(1000);
}
