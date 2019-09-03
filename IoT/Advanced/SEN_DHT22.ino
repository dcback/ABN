#include <DHT.h>

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

void setup()
{
    Serial.begin(115200);
    dht22.begin();
}

void loop()
{
    // Read DHT22 temperature as Celsius
    float tempDHT22 = dht22.readTemperature();
    float humiDHT22 = dht22.readHumidity();

    Serial.print("DHT22 Temperature: ");
    Serial.print(tempDHT22);
    Serial.print(" *C");
    Serial.print("\t Humidity: ");
    Serial.print(humiDHT22);
    Serial.println(" %");

    delay(1000);
}
