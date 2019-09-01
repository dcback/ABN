#define NANO      // NANO 보드인 경우 define
//#define BLUEPILL    // BLUEPILL 보드인 경우 define
//#define NODEMCU   // NODEMCU 보드인 경우 define

#ifdef NANO         // NANO가 정의되면
#define pirPin A3   // pirPin을 A7로 하고 
#endif              // #ifdef 사용 후 반드시 #endif

#ifdef BLUEPILL     // BLUEPILL이 정의되면
#define pirPin PA2  // pirPin을 PA2로 하고
#endif              // #ifdef 사용 후 반드시 #endif

#ifdef NODEMCU      // BLUEPILL이 정의되면
#define pirPin A0   // pirPin을 A0로 하고
#endif              // #ifdef 사용 후 반드시 #endif
 
void setup()
{
    pinMode(pirPin, INPUT);
    Serial.begin(115200);    // 시리얼 출력(115200) 사용
}

void loop()
{
    int readValue = analogRead(pirPin);
    Serial.print("PIR read Value = "); Serial.print(readValue);  
    Serial.println(""); // 다음 줄에 Printing
    delay(1000);        // 1초 지연
}
