// First include the DS18B20 libraries
#include <OneWire.h>
#include <DallasTemperature.h>

#define NANO        // NANO 보드인 경우 define
//#define BLUEPILL  // BLUEPILL 보드인 경우 define

#ifdef NANO                 // NANO가 정의되면
#define ONE_WIRE_BUS  3     // tempPin을 3로 하고 
#endif                      // #ifdef 사용 후 반드시 #endif

#ifdef BLUEPILL             // BLUEPILL이 정의되면
#define ONE_WIRE_BUS PB5    // tempPin을 PB5로 하고
#endif                      // #ifdef 사용 후 반드시 #endif

OneWire oneWire(ONE_WIRE_BUS); // 모든 OneWire device 통신 설정
DallasTemperature tempSensor(&oneWire); // DallasTemperature instance 설정

void setup(void)
{
    Serial.begin(115200);
    tempSensor.begin();
}
void loop(void)
{
    tempSensor.requestTemperatures(); // 온도를 읽기위한 명령 요청
    
    // 버스라인에 최초(0) Sensor값 읽기
    Serial.println(tempSensor.getTempCByIndex(0));
    delay(1000);
}
