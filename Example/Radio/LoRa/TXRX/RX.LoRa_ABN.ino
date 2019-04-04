#include "LoRa_ABN.h"

LoRa_ABN RX;            
#define LORA_RX         

void setup() {
    RX.Init_Receive();
}

void loop() {
    RX.LoRa_Receive();
}
