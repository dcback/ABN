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
    uint8_t data[] = {0xff, 0xff, 0xff, 0xff};
    display.setSegments(data); // array data[] display(all on)
    delay(1000);

    // encode digit 이용 배열 각 내용 값을 입력
    // 0 ~ 9를 입력하면 숫자 그대로 표시
    // 10 ~ 15까지는 알파벳 순으로 A ~ F 가 출력
    data[0] = display.encodeDigit(1);
    data[1] = display.encodeDigit(2);
    data[2] = display.encodeDigit(3);
    data[3] = display.encodeDigit(4);

    display.setSegments(data); // array data[] display
    delay(1000);

    data[0] = display.encodeDigit(10);
    data[1] = display.encodeDigit(11);
    data[2] = display.encodeDigit(12);
    data[3] = display.encodeDigit(13);

    display.setSegments(data); // array data[] display
    delay(1000);

    // 567(표시숫자) false(0제외)/true(0표시)
    // 3(숫자길이) 1(표시위치, 왼쪽->오른쪽:0~3)
    display.showNumberDec(567, false, 3, 1); // 152 number display
    delay(1000);

    uint8_t dataOff[] = {0x0, 0x0, 0x0, 0x0};
    display.setSegments(dataOff); // array dataOff[] display(all off)
    delay(1000);
}
