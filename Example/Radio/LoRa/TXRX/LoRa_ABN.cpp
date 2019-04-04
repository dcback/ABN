#include "LoRa_ABN.h"

unsigned int  counter = 0;

void LoRa_ABN::led_Blink() {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
}

void LoRa_ABN::Init_Send() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);

    LoRa.setPins(csPin, resetPin, irqPin);  // CS, RST, IRQ Pin Set
    Serial.println("LoRa Sender");

    if (!LoRa.begin(915E6)) {
        Serial.println("Starting LoRa failed!");
        while (1);
    }
}

void LoRa_ABN::Init_Receive() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);

    LoRa.setPins(csPin, resetPin, irqPin);  // CS, RST, IRQ Pin Set
    Serial.println("LoRa Receiver");

    if (!LoRa.begin(915E6)) {
        Serial.println("Starting LoRa failed!");
        while (1);
    }
}

void LoRa_ABN::LoRa_Send() {
    Serial.print("Sending packet: ");
    Serial.println(counter);

    // send packet
    LoRa.beginPacket();
    LoRa.print("hello ");
    LoRa.print(counter);
    LoRa.endPacket();

    counter++;
}

void LoRa_ABN::LoRa_Receive() {
    // try to parse packet
    int packetSize = LoRa.parsePacket();
    if (packetSize) {
        // received a packet
        Serial.print("Received packet '");

        // read packet
        while (LoRa.available()) {
            Serial.print((char)LoRa.read());
        }

        // print RSSI of packet
        Serial.print("' with RSSI ");
        Serial.println(LoRa.packetRssi());

        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        delay(500);
    }
}
