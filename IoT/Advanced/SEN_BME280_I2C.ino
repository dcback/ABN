/******************************************
   I2C    Arduino  STM32F103  ESP8266
   SDA      A4        PB7     D2(GPIO4)
   SCL      A5        PB6     D1(GPIO5)
*******************************************/
// First include the DS18B20 libraries
#include <Wire.h>               // I2C 사용
#include <Adafruit_Sensor.h>    // BME280 Library
#include <Adafruit_BME280.h>    // BME280 Library
 
// 고도 계산에 필요한 변수(해수면 압력)정의
#define SEALEVELPRESSURE_HPA (1013.25)
 
Adafruit_BME280 bme;  // BME280 Function -> bme로 정의
 
void setup()
{
   Serial.begin(115200);
 
   if (!bme.begin(0x76))
   {   // BME280(I2C addr=0x76) begin
       Serial.println("Can not find a valid BME280 sensor, check wiring!");
       while (1);
   }
}
 
void loop()
{
   Serial.print("Temperature = ");
   Serial.print(bme.readTemperature());    // 온도 값 가져와서 출력
   Serial.println("*C");
 
   Serial.print("Humidity = ");
   Serial.print(bme.readHumidity());       // 습도 값 가져와서 출력
   Serial.println("%");
 
   Serial.print("Pressure = ");
   Serial.print(bme.readPressure() / 100.0F);  // 기압 값 가져와서 출력
   Serial.println("hPa");
 
   Serial.print("Approx. Altitude = ");
   Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA)); // 고도 값 출력
   Serial.println("m");
 
   Serial.println();
   delay(1000);
}
