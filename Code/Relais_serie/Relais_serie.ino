// Relais série - pour Arduino 1.0
//
// Arduino corrigera une liaison série entre l'ordinateur
// et le shield GPRS à 19200 bps 8-N-1
// l'ordinateur est connecté au hard UART
// GPRS Shield est connecté au soft UART
 
#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(2, 3);
 
void setup()
{
  mySerial.begin(19200);               // GPRS baud rate   
  Serial.begin(19200);                 // GPRS baud rate   
}
 
void loop()
{
    if(Serial.available())
    {
       char c = Serial.read();
       mySerial.print(c);
     }  
    else  if(mySerial.available())
    {
        char c = mySerial.read();
       Serial.print(c);
     }   
}