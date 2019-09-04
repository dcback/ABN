/***************************************************
    [SPI]       ATm328p     STM32       ESP8266
    MOSI        D11         PA7         D7(GPIO13)
    MISO        D12         PA6         D6(GPIO12)
    SCK/CLK     D13         PA5         D5(GPIO14)
    NSS/CSN     D10         PA4         D8{GPIO15)
    NRESET      D9          PA3         D0(GPIO16)
    DIO0        D2          PB12        D1(GPIO5)
****************************************************/
#include <SPI.h>
#include <LoRa.h>

int counter = 0;
bool ledStatus = HIGH;

#define NANO        // NANO 보드인 경우 define
//#define BLUEPILL  // BLUEPILL 보드인 경우 define
//#define NODEMCU   // NODEMCU 보드인 경우 define

#ifdef NANO
#define csPin       10
#define resetPin    9
#define irqPin      2
#define ledPin      13
#endif

#ifdef BLUEPILL
#define csPin       PA4
#define resetPin    PA3
#define irqPin      PB12
#define ledPin      PC13
#endif

#ifdef NODEMCU
#define csPin       D8
#define resetPin    D0
#define irqPin      D1
#define ledPin      D4
#endif

void setup()
{
    Serial.begin(115200);
    while (!Serial);

    pinMode(ledPin, OUTPUT);

    LoRa.setPins(csPin, resetPin, irqPin); // CS, RST, IRQ Pin Set

    Serial.println("LoRa Receiver");

    if (!LoRa.begin(915E6))
    {
        Serial.println("Starting LoRa failed!");
        while (1);
    }
}

void loop()
{
    // try to parse packet
    int packetSize = LoRa.parsePacket();
    if (packetSize)
    {
        // received a packet
        Serial.print("Received packet '");

        // read packet
        while (LoRa.available())
        {
            Serial.print((char)LoRa.read());
        }

        // print RSSI of packet
        Serial.print("' with RSSI ");
        Serial.println(LoRa.packetRssi());

        ledStatus = !ledStatus;
        digitalWrite(ledPin, ledStatus);
    }
}
