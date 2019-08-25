/**************************************************************************
   #define NANO
   #define BLUEPILL
   #define NODEMCU
 
   #ifdef NANO
       #define Pins and Funcs()
       #include <aaa.h>
   #elif defined BLUEPILL
       #define Pins and Funcs()
       #include <bbb.h>
   #else                   //NODEMCU
       #define Pins and Funcs()
       #include <ccc.h>
   #endif
***************************************************************************
   Adruino : 1~13, A0~A7(A0=14, A1=15, A2=16, A3=17, A4=18, A5=19, A6=20,
             A7=21)
   STM32   : PA0~PA15(0~15), PB0~PB15(16~31), PC13~PC15(32~34)
   ESP8266 : D0~D10(D0=16, D1=5, D2=4, D3=0, D4=2, D5=14, D6=12, D7=13, 
             D8=15, D9=3, D10=1)
**************************************************************************/
#define NANO
//#define BLUEPILL
//#define NODEMCU
 
#ifdef NANO
#define ledPin 13
#elif defined BLUEPILL
#define ledPin PC13
#else //NODEMCU
#define ledPin D4
#endif
 
void setup()
{
   pinMode(ledPin, OUTPUT);
}
 
void loop()
{
   digitalWrite(ledPin, HIGH);
   delay(1000);
   digitalWrite(ledPin, LOW);
   delay(1000);
}
