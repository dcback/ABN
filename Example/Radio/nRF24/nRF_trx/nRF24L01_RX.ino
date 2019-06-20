// https://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/
/***************************************************
    [SPI]       ATm328p     STM32       ESP8266
    MOSI        D11(11)     PA7         D7(GPIO13)
    MISO        D12(12)     PA6         D6(GPIO12)
    SCK/CLK     D13(13)     PA5         D5(GPIO14)
    CSN         D10(10)     PA4         D8{GPIO15)
    CE          D9(9)       PC14        D0(GPIO16)
    VCC         3.3V        3.3V        3.3V
****************************************************/
//#define ARDUINO_NANO
//#define BLUEPILL
#define NODEMCU

#ifdef ARDUINO_NANO
    #include <nRF24L01.h>
    #include <RF24.h>
    #define ledPin      13
    #define CE          9
    #define CSN         10
#elif defined BLUEPILL
    #include <RF24_STM32.h>
    #define ledPin      PC13
    #define CE          PC14
    #define CSN         PA4
#else //NODEMCU
    #include <nRF24L01.h>
    #include <RF24.h>
    #define ledPin      D4
    #define CE          D0
    #define CSN         D8
#endif

#include <SPI.h>

RF24 radio(CE, CSN);    // CE, CSN
const byte addresses[][6] = { "00001", "00002", "00003", "00004", "00005" };
int rxValue = 0;
int txValue = 4321;

void setup() {
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);

    radio.begin();
    radio.openWritingPipe(addresses[0]);    // openWritingPipe(Pipe open WR_addr):WR[0]<->RD[1]
    radio.openReadingPipe(1, addresses[1]); // openReadingPipe(pipeNo[1~5], Pipe open RD_addr):RD[1]<->WR[0]
    radio.setPALevel(RF24_PA_MIN);

    Serial.println(F(">>> RX Start.."));
}

void loop() {
    radio.startListening();
    if ( radio.available()) {
        while (radio.available()) {
            radio.read(&rxValue, sizeof(rxValue));
        }
    }

    delay(100);
    radio.stopListening();
    radio.write(&txValue, sizeof(txValue));

    Serial.print("rxValue : ");
    Serial.println(rxValue);

    led_Blink();
}

// ===========================
// Functions()
// ===========================
void led_Blink() {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
}
