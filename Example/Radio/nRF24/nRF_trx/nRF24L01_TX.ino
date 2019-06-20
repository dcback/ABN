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
int txValue = 1234;

void setup() {
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);

    radio.begin();
    radio.openWritingPipe(addresses[1]);    // openWritingPipe(Pipe open WR_addr):WR[1]<->RD[0]
    radio.openReadingPipe(1, addresses[0]); // openReadingPipe(pipeNo[1~5], Pipe open RD_addr):RD[0]<->WR[1]
    radio.setPALevel(RF24_PA_MIN);

    Serial.println(F(">>> TX Start.."));
}

void loop() {
    radio.stopListening();
    radio.write(&txValue, sizeof(txValue));

    delay(100);
    radio.startListening();
    while (!radio.available());
    radio.read(&rxValue, sizeof(rxValue));

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
