void setup()
{
  // Définir la broche comme mode de sortie
  pinMode(12,OUTPUT);
  // démarrage GSM
  digitalWrite(12,HIGH);
  delay(2000);
  digitalWrite(12,LOW); 
}
void loop()    
{ 
}
