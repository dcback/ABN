#ifndef LoRa_ABN_H
#define LoRa_ABN_H

#include "Arduino.h"
#include <SPI.h>
#include <LoRa.h>

#define LORA_TX
#define LORA_RX

#define ARDUINO_NANO
//#define BLUEPILL
//#define NODEMCU

#ifdef ARDUINO_NANO
    #define ledPin      13
    #define csPin       10
    #define resetPin    9
    #define irqPin      2
#elif defined BLUEPILL
    #define ledPin      PC13
    #define csPin       PA4
    #define resetPin    PC14
    #define irqPin      PA1
#else //NODEMCU
    #define ledPin      D4
    #define csPin       D8
    #define resetPin    D0
    #define irqPin      D1
#endif

class LoRa_ABN {
    public:
        LoRa_ABN()  {};
        ~LoRa_ABN() {};
        void led_Blink();
        void Init_Send();
        void Init_Receive();
        void LoRa_Send();
        void LoRa_Receive();

    private :
};
#endif
