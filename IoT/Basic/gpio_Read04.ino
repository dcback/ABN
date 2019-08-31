#define NANO        // NANO 보드인 경우 define
//#define BLUEPILL  // BLUEPILL 보드인 경우 define

#ifdef NANO         // NANO가 정의되면
#define cdsPin A7   // cdsPin을 A7으로 하고 
#endif              // #ifdef 사용 후 반드시 #endif

#ifdef BLUEPILL     // BLUEPILL이 정의되면
#define cdsPin PA1  // cdsPin을 PA1으로 하고
#endif              // #ifdef 사용 후 반드시 #endif
 
void setup()
{
    pinMode(cdsPin, INPUT);
    Serial.begin(115200);    // 시리얼 출력(115200) 사용
}

void loop()
{
    int readValue = analogRead(cdsPin);
    Serial.print("CDS read Value = "); Serial.print(readValue);  
    Serial.println(""); // 다음 줄에 Printing
    delay(1000);        // 1초 지연
}
