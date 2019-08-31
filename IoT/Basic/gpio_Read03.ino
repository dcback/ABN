/**************************************************************************
    Adruino : 1~13, A0~A7(A0=14, A1=15, A2=16, A3=17, A4=18, A5=19, A6=20,
              A7=21)
    STM32   : PA0~PA15(0~15), PB0~PB15(16~31), PC13~PC15(32~34)
    ESP8266 : D0~D10(D0=16, D1=5, D2=4, D3=0, D4=2, D5=14, D6=12, D7=13,
              D8=15), A0
**************************************************************************/
//#define NANO        // NANO 보드인 경우 define
//#define BLUEPILL  // BLUEPILL 보드인 경우 define
#define NODEMCU   // NODEMCU 보드인 경우 define

#ifdef NANO
#define potPin A6
#elif defined BLUEPILL
#define potPin PA0
#else
#define potPin A0
#endif
 
void setup()
{
    pinMode(potPin, INPUT);
    Serial.begin(115200);    // 시리얼 출력(115200) 사용
}

void loop()
{
    int readValue = analogRead(potPin);
    Serial.print("Analog read Value = "); Serial.print(readValue);  
    Serial.println(""); // 다음 줄에 Printing
    delay(1000);        // 1초 지연
}
