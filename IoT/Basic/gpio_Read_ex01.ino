/**************************************************************************
    Adruino : 1~13, A0~A7(A0=14, A1=15, A2=16, A3=17, A4=18, A5=19, A6=20,
              A7=21)
    STM32   : PA0~PA15(0~15), PB0~PB15(16~31), PC13~PC15(32~34)
    ESP8266 : D0~D10(D0=16, D1=5, D2=4, D3=0, D4=2, D5=14, D6=12, D7=13,
              D8=15)
**************************************************************************/
#define NANO        // NANO 보드인 경우 define
//#define BLUEPILL  // BLUEPILL 보드인 경우 define
//#define NODEMCU   // NODEMCU 보드인 경우 define

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    for ( int i = 0; i < 22; i++ )
    {
        int readValue = digitalRead(i);
        Serial.print(readValue); Serial.print(" ");
    }
    Serial.println("");

    for ( int i = 0; i < 22; i++ )
    {
        int readValue = analogRead(i);
        Serial.print(readValue); Serial.print(" ");
    }
    Serial.println("");
    delay(1000);
}
