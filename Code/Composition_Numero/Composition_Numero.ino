// Importation des librairies
#include <SoftwareSerial.h>
#include <String.h>
SoftwareSerial sim800l(2,3);          // RX, TX
boolean call;

void setup(){
  sim800l.begin(9600);  // Démarrage du modem
  Serial.begin(9600);   // Initialisation de la communication série
  delay(500); 
  call = true;
  if(sim800l.available()) 
  Serial.write(sim800l.read());
  } 

void loop(){ 
  if(call==true){
    voicecall();
    call = false;
   }
 } 

void voicecall(){ 
  Serial.println("Make voice call"); 
  Serial.println("Enter the phone number you want to call"); 
  char number[20]; 
  readSerial(number); 
  Serial.print("Calling: "); 
  Serial.println(number); 
  delay(100); 
  sim800l.print("ATD");   // Appel 
  sim800l.print(number); 
  sim800l.print(";\r"); 
  delay(3000); 
  Serial.println("Hung up in 10 sec");
  delay(10000); 
  sim800l.print("ATH\r");    
  // Raccroche 
  Serial.println("Call ended"); 
  sim800l.println(); 
} 

int readSerial(char result[]) { 
  int i = 0; 
  while (1) { 
    while (Serial.available() > 0) { 
    char inChar = Serial.read(); 
    if (inChar == '\n') { 
      result[i] = '\0';
      Serial.flush(); 
      return 0; 
    }
    if (inChar != '\r'){
      result[i] = inChar; i++; 
    } 
   }
  }
}
