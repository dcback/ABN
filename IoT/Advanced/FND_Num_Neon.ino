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

byte data[][4] = {
    {0x01, 0x00, 0x00, 0x08},
    {0x00, 0x01, 0x08, 0x00},
    {0x00, 0x08, 0x01, 0x00},
    {0x08, 0x00, 0x00, 0x01},
    {0x10, 0x00, 0x00, 0x02},
    {0x20, 0x00, 0x00, 0x04}
};

void setup()
{
    display.setBrightness(7);
}

void loop()
{
    for (int i = 0; i < 6; i++)
    {
        display.setSegments(data[i]);
        delay(20);
    }
}
