// Version pour Arduino IDE < 1.0
#include <SoftwareSerial.h>    
 
SoftwareSerial mySerial(2, 3);

void setup()
{
  mySerial.begin(19200);  // Paramètres par défaut du port série du GPRS shield (19200bps 8-N-1)
  mySerial.print("\r");   // Envoyer un retour à la ligne <CR>
  delay(1000);                    // Attendre une seconde que le modem retourne "OK"
  mySerial.print("AT+CMGF=1\r");  // Envoyer un SMS en mode texte
  delay(1000);
 
  //mySerial.print("AT+CSCA=\"+919032055002\"\r");// Configurer le centre de message SMS,  
  //delay(1000);                                  // Retirer les commentaire seulement si nécessaire et
                                                  // remplacer le No avec celui obtenu auprès de votre
                                                  // fournisseur de service mobile.
                                                  //Note: pour inclure un " dans une chaine de caractère
                                                  //  il faut utiliser la notation \"
 
  mySerial.print("AT+CMGS=\"+3360124xxxx\"\r");   // Commencer un SMS à envoyer au numéro +91....
                                                  // l'encodage du texte suivra plus bas.
                                                  // Remplacer le No avec celui de votre destinataire.
  delay(1000);
  mySerial.print("Bienvenu chez MCHobby!\r");     // Le texte du message
  delay(1000);
  mySerial.write(26);  // Equivalent du Ctrl+Z (fin de texte du SMS)
                       // Note: ici il faut utiliser l'instruction write pour écrire un byte. 
}
 
void loop()
{
      // Nous voulons seulement envoyer le SMS une seule fois, il n'y a donc rien dans la boucle loop().
      // Si nous mettons le code du SMS ici, alors il sera envoyer encore et encore (Oups! cela couterait cher).
}

