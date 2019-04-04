#include "LoRa_ABN.h"

LoRa_ABN TX;            
#define LORA_TX         

void setup() {
    TX.Init_Send();
}

void loop() {
    TX.LoRa_Send();
    TX.led_Blink();
}
