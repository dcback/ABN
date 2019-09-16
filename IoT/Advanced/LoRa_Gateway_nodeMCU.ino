#include <SPI.h>              
#include <LoRa.h>

//#define NANO // NANO 보드인 경우 define
//#define BLUEPILL // BLUEPILL 보드인 경우 define
#define NODEMCU // NODEMCU 보드인 경우 define

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
    Serial.println("LoRa Simple Gateway");
    Serial.println("Only receive messages from nodes");
    Serial.println("Tx: invertIQ enable");
    Serial.println("Rx: invertIQ disable");
    Serial.println();

    LoRa.onReceive(onReceive);
    LoRa_rxMode();
}

void loop() 
{
    if (runEvery(5000)) // repeat every 5000 millis
    { 
        String message = "HeLoRa World! ";
        message += "I'm a Gateway! ";
        message += millis();

        LoRa_sendMessage(message); // send a message

        Serial.println("Send Message!");
    }
}

void LoRa_rxMode() 
{
    LoRa.disableInvertIQ();               // normal mode
    LoRa.receive();                       // set receive mode
}

void LoRa_txMode() 
{
    LoRa.idle();                          // set standby mode
    LoRa.enableInvertIQ();                // active invert I and Q signals
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

    Serial.print("Gateway Receive: ");
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
