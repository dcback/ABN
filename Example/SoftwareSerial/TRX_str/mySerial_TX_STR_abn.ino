/********************************************
    ARDUINO  <-> NODEMCU  ok
    BLUEPILL <-> NODEMCU  Data Break
    ARDUINO  <-> BLUEPILL Data Break
/*******************************************/
//#define ARDUINO_NANO
#define BLUEPILL
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

void setup() {
    Serial.begin(9600);
    mySerial.begin(9600);
}

void loop() {
    String str = "ABC";   // must need '\n'    
    mySerial.print(str); 
    delay(1000);
}
