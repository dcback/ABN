#define ARDUINO_NANO
//#define BLUEPILL
//#define NODEMCU

#ifdef ARDUINO_NANO
    #include "SoftwareSerial.h"
    #define GPIO_SERIAL_RX    A2
    #define GPIO_SERIAL_TX    A3
    SoftwareSerial mySerial(GPIO_SERIAL_RX, GPIO_SERIAL_TX);
#elif defined BLUEPILL
    #include "SoftSerialSTM32.h"
    #define GPIO_SERIAL_RX    PA2
    #define GPIO_SERIAL_TX    PA3
    SoftSerialSTM32 mySerial(GPIO_SERIAL_RX, GPIO_SERIAL_TX);
#else //NODEMCU
    #include "SoftwareSerial.h"
    #define GPIO_SERIAL_RX    D2
    #define GPIO_SERIAL_TX    D3
    SoftwareSerial mySerial(GPIO_SERIAL_RX, GPIO_SERIAL_TX);
#endif

char buf[6];

void setup() {
    Serial.begin(9600);
    mySerial.begin(9600);
}

void loop() {

    if (mySerial.available()) {

        mySerial.readBytes(buf, sizeof(buf));
        
        Serial.println(sizeof(buf));

        for (int i = 0; i < sizeof(buf); i++) {
            Serial.print(buf[i]);
        }
        Serial.println();
        Serial.println(buf[0]);
        Serial.println(buf[1]);
        Serial.println(buf[2]);
        Serial.println(buf[3]);
        Serial.println(buf[4]);
        Serial.println(buf[5]); 
        delay(1000);
    }
}
