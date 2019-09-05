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
char buf[100];

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

    Serial.println("LoRa Sender");

    if (!LoRa.begin(915E6))
    {
        Serial.println("Starting LoRa failed!");
        while (1);
    }
}

void loop()
{
    Serial.print("Sending packet: ");
    Serial.print(counter);

    int randVal0 = random(10, 100);
    int randVal1 = random(10, 100);
    int randVal2 = random(10, 100);
    int randVal3 = random(10, 100);
    int randVal4 = random(10, 100);

    // buf에 Random값 문자열로 저장
    sprintf(buf, ">>>[%d %d %d %d %d]", randVal0, randVal1, randVal2, randVal3, randVal4);
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
