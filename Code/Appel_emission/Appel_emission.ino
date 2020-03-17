#include <SoftwareSerial.h>   
 
SoftwareSerial mySerial(2, 3); 

// relayer la réponse de fromSerial (type SoftwareSerial) vers
//   le port serie d'Arduino (19200baud). Facile le deboggage
void relayResponse( SoftwareSerial &fromSerial ){
  // Attention, il faut attendre que l'UART réponde
  // avant de lire mySerial (temps conseillé= 1sec)
  //
  while(fromSerial.available())
  {
     // Envoi le résultat sur la connexion série
     char c = fromSerial.read();
     Serial.print(c);
  }
} 

void setup()
{
  mySerial.begin(19200);   // GPRS baud rate   
  Serial.begin(19200);     // GPRS baud rate   
  delay(2000);
  mySerial.println("ATD+3360124xxx;"); // xxxxxxxxx est le numéro a appeler.  
         
  // NB: Une boucle while serait plus appropriée que la section de code ci-dessous.
  //     Je vous propose d'appeler la fonction suivante: 
  //     relayResponse( mySerial ) 
  if(mySerial.available()) 
  {
    char c = mySerial.read();
    Serial.print( c );
  }  
  
  delay(10000); 
  delay(10000); 

  mySerial.println("ATH"); // Fin d'appel.
  if(mySerial.available()) // Voir commentaire précédent.
  {
    char c = mySerial.read();
    Serial.print( c );
  }    
}
 
void loop()
{
  // Ne rien faire
}
