#include <TM1637Display.h>

#define NANO        // NANO 보드인 경우 define
//#define BLUEPILL  // BLUEPILL 보드인 경우 define

#ifdef NANO             // NANO가 정의되면
#define CLK A0          // TM1637 CLK핀 정의
#define DIO A1          // TM1637 DIO핀 정의
#endif                  // #ifdef 사용 후 반드시 #endif

#ifdef BLUEPILL         // BLUEPILL이 정의되면
#define CLK PB15        // TM1637 CLK핀 정의
#define DIO PB14        // TM1637 DIO핀 정의
#endif                  // #ifdef 사용 후 반드시 #endif

TM1637Display display(CLK, DIO);

void setup()
{
    display.setBrightness(7); // min(0 ~ max(7)
}

void loop()
{
    int numCnt = random(0, 9999); // random number

    // dot position(0x80 -> 0x40 -> 0x20 -> 0x10)
    display.showNumberDecEx(numCnt, 0x40);
    delay(500);
}
