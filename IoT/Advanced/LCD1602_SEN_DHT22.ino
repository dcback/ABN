/******************************************
    I2C    Arduino  STM32F103  ESP8266
    SDA      A4        PB7     D2(GPIO4)
    SCL      A5        PB6     D1(GPIO5)
*****************************************/
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define NANO        // NANO 보드인 경우 define
//#define BLUEPILL  // BLUEPILL 보드인 경우 define

#ifdef NANO             // NANO가 정의되면
#define dhtPin 4        // dhtPin을 4로 하고
#define dhtType DHT22   // DHT22 센서 사용 정의
#endif                  // #ifdef 사용 후 반드시 #endif

#ifdef BLUEPILL         // BLUEPILL이 정의되면
#define dhtPin PB4      // dhtPin을 PB4로 하고
#define dhtType DHT22   // DHT22 센서 사용 정의
#endif                  // #ifdef 사용 후 반드시 #endif

DHT dht22(dhtPin, dhtType);
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address(I2C) to 0x27

void setup()
{
    Serial.begin(115200);
    dht22.begin();

    lcd.begin();     // LCD initialize
    lcd.backlight(); // Backlight on
}

void loop()
{
    // Read DHT22 temperature as Celsius
    float tempDHT22 = dht22.readTemperature();
    float humiDHT22 = dht22.readHumidity();

    // LCD1602_I2C Display
    lcd.setCursor(0, 0); // cursor at x=0, y=0 position
    lcd.print("Temperat:");
    lcd.print(tempDHT22);
    lcd.print(" C");

    lcd.setCursor(0, 1); // cursor at x=0, y=1 position
    lcd.print("Humidity:");
    lcd.print(humiDHT22);
    lcd.print(" %");

    // Serial monitor
    Serial.print("DHT22 Temperature: ");
    Serial.print(tempDHT22);
    Serial.print(" *C");
    Serial.print("\t Humidity: ");
    Serial.print(humiDHT22);
    Serial.println(" %");

    delay(1000);
}
