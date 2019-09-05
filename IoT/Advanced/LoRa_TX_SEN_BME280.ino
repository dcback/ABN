#include <SPI.h>
#include <LoRa.h>
#include <Adafruit_Sensor.h>   // BME280
#include <Adafruit_BME280.h>   // BME280

#define NANO        // NANO 보드인 경우 define
//#define BLUEPILL  // BLUEPILL 보드인 경우 define
//#define NODEMCU   // NODEMCU 보드인 경우 define

#ifdef NANO
#define csPin       10
#define resetPin    9
#define irqPin      2
#define ledPin      13
#define potPin      A6
#define cdsPin      A7
#define pirPin      A3
#endif

#ifdef BLUEPILL
#define csPin       PA4
#define resetPin    PA3
#define irqPin      PB12
#define ledPin      PC13
#define potPin      PA0
#define cdsPin      PA1
#define pirPin      PA2
#endif

#ifdef NODEMCU
#define csPin       D8
#define resetPin    D0
#define irqPin      D1
#define ledPin      D4
#define potPin      A0
#define cdsPin      A0  // No Connection(A0 Value)
#define pirPin      A0  // No Connection(A0 Value)
#endif

#define SEALEVELPRESSURE_HPA (1013.25) // Altitude ref for BME280
Adafruit_BME280 bme;

int counter = 0;
bool ledStatus = HIGH;
char buf[100];

// Sensor Variables
char tempStr[10];
char humiStr[10];
char pressStr[10];
char altiStr[10];

void setup()
{
    Serial.begin(115200);
    while (!Serial);

    pinMode(ledPin, OUTPUT);

    LoRa.setPins(csPin, resetPin, irqPin); // CS, RST, IRQ Pin Set

    Serial.println("LoRa Sender");

    if (!LoRa.begin(915E6))
    {
        Serial.println("Starting LoRa failed!");
        while (1);
    }
    bme.begin(0x76);    //BME280 Begin
}

void loop()
{
    Serial.print("Sending packet: ");
    Serial.print(counter);

    float tempVal = bme.readTemperature();                  // 온도 값 읽기
    float humiVal = bme.readHumidity();                     // 습도 값 읽기
    float pressVal = bme.readPressure() / 100.0F;           // 기압 값 읽기
    float altiVal = bme.readAltitude(SEALEVELPRESSURE_HPA); // 고도 값 읽기

    // float to string
    dtostrf(tempVal, 2, 2, tempStr);
    dtostrf(humiVal, 2, 2, humiStr);
    dtostrf(pressVal, 3, 2, pressStr);
    dtostrf(altiVal, 3, 2, altiStr);

    // buf에 센싱 값 문자열로 저장
    sprintf(buf, ">>>[%s %s %s %s]", tempStr, humiStr, pressStr, altiStr);
    Serial.println(buf);

    // send packet
    LoRa.beginPacket();
    LoRa.print(counter);
    LoRa.print(buf);
    LoRa.endPacket();

    counter++;

    ledStatus = !ledStatus;
    digitalWrite(ledPin, ledStatus);
    delay(1000);
}
