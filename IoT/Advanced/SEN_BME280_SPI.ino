/***************************************************************
    [SPI]       NANO        BLUEPILL    NODEMCU         BME280
    MOSI        D11(11)     PA7         D7(GPIO13)      SDI/SDA
    MISO        D12(12)     PA6         D6(GPIO12)      SDO
    SCK/CLK     D13(13)     PA5         D5(GPIO14)      SCK/SCL
    CS/SS       D10(10)     PA4         D8{GPIO15)      CSB
****************************************************************/
// First include the DS18B20 libraries
#include <Wire.h>               // I2C 사용
#include <Adafruit_Sensor.h>    // BME280 Library
#include <Adafruit_BME280.h>    // BME280 Library

#define NANO        // NANO 보드인 경우 define
//#define BLUEPILL  // BLUEPILL 보드인 경우 define
//#define NODEMCU   // NODEMCU 보드인 경우 define

#ifdef NANO
#define BME_CS  10
#endif

#ifdef BLUEPILL
#define BME_CS  PA4
#endif

#ifdef NODEMCU
#define BME_CS  D8
#endif

// 고도 계산에 필요한 변수(해수면 압력)정의
#define SEALEVELPRESSURE_HPA (1013.25)

/**********************  3-Mode Setting  **********************/
//Adafruit_BME280 bme; // I2C
Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

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
