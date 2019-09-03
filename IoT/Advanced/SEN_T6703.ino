/******************************************
   I2C    Arduino  STM32F103  ESP8266
   SDA      A4        PB7     D2(GPIO4)
   SCL      A5        PB6     D1(GPIO5)
*******************************************/
#include <Wire.h>

#define ADDR_6713 0x15 // default I2C slave address

byte data[6];
int CO2ppmValue;

void setup()
{
    Wire.begin();
    Serial.begin(115200);
}

void loop()
{
    GetCO2PPM();
    Serial.print("T6703 CO2 Value : ");
    Serial.print(CO2ppmValue);
    Serial.println(" ppm");
    delay(2000);
}

void GetCO2PPM()
{
    // start I2C
    Wire.beginTransmission(ADDR_6713);
    Wire.write(0x04);
    Wire.write(0x13);
    Wire.write(0x8B);
    Wire.write(0x00);
    Wire.write(0x01);

    // end transmission
    Wire.endTransmission();

    // read report of current gas measurement in ppm after delay!
    delay(10);
    Wire.requestFrom(ADDR_6713, 4); // request 4 bytes from slave device
    data[0] = Wire.read();
    data[1] = Wire.read();
    data[2] = Wire.read();
    data[3] = Wire.read();
    CO2ppmValue = ((data[2] & 0x3F) << 8) | data[3];
}
