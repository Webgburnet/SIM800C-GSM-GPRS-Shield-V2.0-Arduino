#include <SoftwareSerial.h>   
 
SoftwareSerial mySerial(2, 3); 

int Reception =0;

void setup()
{
  mySerial.begin(19200);   // GPRS baud rate   
  Serial.begin(19200);     // GPRS baud rate     
}
 
void loop()
{
  if(Serial.available()>0)
  {
    Reception=Serial.read();
    Serial.println(Reception);
    if(Reception>0)
    {
      mySerial.println("ATA");
    }
    Reception=0;
  }    
}
