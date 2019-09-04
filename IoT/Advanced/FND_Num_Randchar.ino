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

const uint8_t c[] = {     // Custom char setting
    0x0,
    0x0,
    0x0,
    SEG_A | SEG_F | SEG_G,
};

void setup()
{
    display.setBrightness(7); // min(0) ~ max(7)
}

void loop()
{
    int numCnt = 123;

    display.showNumberDec(numCnt, false, 3, 0); // display numCnt value
    display.setSegments(c);     // c display

    // colon/dot Display
    uint8_t segto;
    segto = 0x80;
    // &segto, on(1)/off(0), position(0~2)
    display.setSegments(&segto, 1, 1);
}
