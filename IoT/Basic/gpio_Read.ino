/**************************************************************************
    Adruino : 1~13, A0~A7(A0=14, A1=15, A2=16, A3=17, A4=18, A5=19, A6=20,
              A7=21)
    STM32   : PA0~PA15(0~15), PB0~PB15(16~31), PC13~PC15(32~34)
    ESP8266 : D0~D10(D0=16, D1=5, D2=4, D3=0, D4=2, D5=14, D6=12, D7=13,
              D8=15)
**************************************************************************/
#define NANO        // NANO 보드인 경우 define
//#define BLUEPILL  // BLUEPILL 보드인 경우 define
//#define NODEMCU   // NODEMCU 보드인 경우 define

void setup()
{
    Serial.begin(115200);    // 시리얼 출력(115200) 사용
}

void loop()
{
#ifdef NANO
  Serial.print("D2="); Serial.print("GPIO["); Serial.print(2, DEC); Serial.print("] ");
  Serial.print("D3="); Serial.print("GPIO["); Serial.print(3, DEC); Serial.print("] ");
  Serial.print("D4="); Serial.print("GPIO["); Serial.print(4, DEC); Serial.print("] ");
  Serial.print("D5="); Serial.print("GPIO["); Serial.print(5, DEC); Serial.print("] ");
  Serial.print("D6="); Serial.print("GPIO["); Serial.print(6, DEC); Serial.print("] ");
  Serial.print("D7="); Serial.print("GPIO["); Serial.print(7, DEC); Serial.print("] ");
  Serial.print("D8="); Serial.print("GPIO["); Serial.print(8, DEC); Serial.print("] ");
  Serial.print("D9="); Serial.print("GPIO["); Serial.print(9, DEC); Serial.print("] ");
  Serial.print("D10="); Serial.print("GPIO["); Serial.print(10, DEC); Serial.print("] ");
  Serial.print("D11="); Serial.print("GPIO["); Serial.print(11, DEC); Serial.print("] ");
  Serial.print("D12="); Serial.print("GPIO["); Serial.print(12, DEC); Serial.print("] ");
  Serial.print("D13="); Serial.print("GPIO["); Serial.print(13, DEC); Serial.print("] ");
  Serial.print("A0="); Serial.print("GPIO["); Serial.print(A0, DEC); Serial.print("] ");
  Serial.print("A1="); Serial.print("GPIO["); Serial.print(A1, DEC); Serial.print("] ");
  Serial.print("A2="); Serial.print("GPIO["); Serial.print(A2, DEC); Serial.print("] ");
  Serial.print("A3="); Serial.print("GPIO["); Serial.print(A3, DEC); Serial.print("] ");
  Serial.print("A4="); Serial.print("GPIO["); Serial.print(A4, DEC); Serial.print("] ");
  Serial.print("A5="); Serial.print("GPIO["); Serial.print(A5, DEC); Serial.print("] ");
  Serial.print("A6="); Serial.print("GPIO["); Serial.print(A6, DEC); Serial.print("] ");
  Serial.print("A7="); Serial.print("GPIO["); Serial.print(A7, DEC); Serial.print("] ");
#endif  

#ifdef BLUEPILL
  Serial.print("PA0="); Serial.print("GPIO["); Serial.print(PA0, DEC); Serial.print("] ");
  Serial.print("PA1="); Serial.print("GPIO["); Serial.print(PA1, DEC); Serial.print("] ");
  Serial.print("PA2="); Serial.print("GPIO["); Serial.print(PA2, DEC); Serial.print("] ");
  Serial.print("PA3="); Serial.print("GPIO["); Serial.print(PA3, DEC); Serial.print("] ");
  Serial.print("PA4="); Serial.print("GPIO["); Serial.print(PA4, DEC); Serial.print("] ");
  Serial.print("PA5="); Serial.print("GPIO["); Serial.print(PA5, DEC); Serial.print("] ");
  Serial.print("PA6="); Serial.print("GPIO["); Serial.print(PA6, DEC); Serial.print("] ");
  Serial.print("PA7="); Serial.print("GPIO["); Serial.print(PA7, DEC); Serial.print("] ");
  Serial.print("PA8="); Serial.print("GPIO["); Serial.print(PA8, DEC); Serial.print("] ");
  Serial.print("PA9="); Serial.print("GPIO["); Serial.print(PA9, DEC); Serial.print("] ");
  Serial.print("PA10="); Serial.print("GPIO["); Serial.print(PA10, DEC); Serial.print("] ");
  Serial.print("PA11="); Serial.print("GPIO["); Serial.print(PA11, DEC); Serial.print("] ");
  Serial.print("PA12="); Serial.print("GPIO["); Serial.print(PA12, DEC); Serial.print("] ");
  Serial.print("PA13="); Serial.print("GPIO["); Serial.print(PA13, DEC); Serial.print("] ");
  Serial.print("PA14="); Serial.print("GPIO["); Serial.print(PA14, DEC); Serial.print("] ");
  Serial.print("PA15="); Serial.print("GPIO["); Serial.print(PA15, DEC); Serial.print("] ");
#endif 

#ifdef NODEMCU
  Serial.print("D0="); Serial.print("GPIO["); Serial.print(D0, DEC); Serial.print("] ");
  Serial.print("D1="); Serial.print("GPIO["); Serial.print(D1, DEC); Serial.print("] ");
  Serial.print("D2="); Serial.print("GPIO["); Serial.print(D2, DEC); Serial.print("] ");
  Serial.print("D3="); Serial.print("GPIO["); Serial.print(D3, DEC); Serial.print("] ");
  Serial.print("D4="); Serial.print("GPIO["); Serial.print(D4, DEC); Serial.print("] ");
  Serial.print("D5="); Serial.print("GPIO["); Serial.print(D5, DEC); Serial.print("] ");
  Serial.print("D6="); Serial.print("GPIO["); Serial.print(D6, DEC); Serial.print("] ");
  Serial.print("D7="); Serial.print("GPIO["); Serial.print(D7, DEC); Serial.print("] ");
  Serial.print("D8="); Serial.print("GPIO["); Serial.print(D8, DEC); Serial.print("] ");
#endif
 
    Serial.println(""); // 다음 줄에 Printing
    delay(1000);        // 1초 지연
}
