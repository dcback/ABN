#include <Wire.h>
#include <SPI.h>
#include <LoRa.h>
#include <Adafruit_Sensor.h>    // BME280
#include <Adafruit_BME280.h>    // BME280

#define NANO // NANO 보드인 경우 define
//#define BLUEPILL // BLUEPILL 보드인 경우 define
//#define NODEMCU // NODEMCU 보드인 경우 define

#ifdef NANO
#define csPin 10
#define resetPin 9
#define irqPin 2
#define ledPin 13
#endif

#ifdef BLUEPILL
#define csPin PA4
#define resetPin PA3
#define irqPin PB12
#define ledPin PC13
#endif

#ifdef NODEMCU
#define csPin D8
#define resetPin D0
#define irqPin D1
#define ledPin D4
#endif

const long frequency = 915E6;  // LoRa Frequency

#define SEALEVELPRESSURE_HPA (1013.25) // Altitude ref for BME280
Adafruit_BME280 bme;

bool ledStatus = HIGH ;
char buf[100];

// Sensor Variables
char tempStr[10];
char humiStr[10];
char pressStr[10];
char altiStr [10];

void setup()
{
    Serial.begin(115200);                   // initialize serial
    while (!Serial);

    LoRa.setPins(csPin, resetPin, irqPin);

    if (!LoRa.begin(frequency))
    {
        Serial.println("LoRa init failed. Check your connections.");
        while (true);                       // if failed, do nothing
    }

    Serial.println("LoRa init succeeded.");
    Serial.println();
    Serial.println("LoRa Simple Node");
    Serial.println("Only receive messages from gateways");
    Serial.println("Tx: invertIQ disable");
    Serial.println("Rx: invertIQ enable");
    Serial.println();

    LoRa.onReceive(onReceive);
    LoRa_rxMode();

    bme.begin(0x76); //BME280 Begin
}

void loop()
{
    if (runEvery(1000))     // repeat every 1000 millis
    {
        float tempVal = bme.readTemperature();          // 온도 값 읽기
        float humiVal = bme.readHumidity();             // 습도 값 읽기
        float pressVal = bme.readPressure() / 100.0F ;  // 기압 값 읽기
        float altiVal = bme.readAltitude(SEALEVELPRESSURE_HPA); // 고도 값 읽기

        // float to string
        dtostrf (tempVal, 2 , 2 , tempStr);
        dtostrf (humiVal, 2 , 2 , humiStr);
        dtostrf (pressVal, 3 , 2 , pressStr);
        dtostrf (altiVal, 3 , 2 , altiStr);

        // buf에 센싱 값 문자열로 저장
        sprintf(buf, ">>>[%s %s %s %s]" , tempStr, humiStr, pressStr, altiStr);
        Serial.println(buf);

        String message = "Node_ID:";
        message += "001-";
        message += buf;
        message += ": RSSI : ";
        message += LoRa.packetRssi();

        LoRa_sendMessage(message); // send a message

        Serial.println("Send Message!");
    }
}

void LoRa_rxMode()
{
    LoRa.enableInvertIQ();                // active invert I and Q signals
    LoRa.receive();                       // set receive mode
}

void LoRa_txMode()
{
    LoRa.idle();                          // set standby mode
    LoRa.disableInvertIQ();               // normal mode
}

void LoRa_sendMessage(String message)
{
    LoRa_txMode();                        // set tx mode
    LoRa.beginPacket();                   // start packet
    LoRa.print(message);                  // add payload
    LoRa.endPacket();                     // finish packet and send it
    LoRa_rxMode();                        // set rx mode
}

void onReceive(int packetSize)
{
    String message = "";

    while (LoRa.available())
    {
        message += (char)LoRa.read();
    }
    Serial.print("Node Receive: ");
    Serial.println(message);
}

boolean runEvery(unsigned long interval)
{
    static unsigned long previousMillis = 0;
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;
        return true;
    }
    return false;
}
