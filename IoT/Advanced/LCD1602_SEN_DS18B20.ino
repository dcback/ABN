#include <Wire.h>              // I2C
#include <DallasTemperature.h> // DS18B20
#include <LiquidCrystal_I2C.h> // LCD1602

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
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address(I2C) to 0x27

void setup()
{
    Serial.begin(115200); // start serial port
    lcd.begin();          // LCD initialize
    tempSensor.begin();   // Start up tempSensor
}

void loop()
{
    tempSensor.requestTemperatures(); // 온도를 읽기위한 명령 요청
    // 0 refers to first DS18B20 on the wire
    float tempDS18B20 = tempSensor.getTempCByIndex(0);

    // LCD1602_I2C Display
    lcd.setCursor(0, 0); // cursor at x=0, y=0 position
    lcd.print("DS18B20 Sensor");

    lcd.setCursor(0, 1); // cursor at x=0, y=1 position
    lcd.print("TEMP is: ");
    lcd.print(tempDS18B20);
    lcd.print(" C");

    // Serial monitor
    Serial.print("DS18B20 Temperature: ");
    Serial.print(tempDS18B20);
    Serial.println(" *C");
    delay(1000);
}
