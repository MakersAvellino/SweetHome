char lettera;
int  statoEntrata  = 0;
int  statoCucina   = 0;
int  statoStanza   = 0;
int  statoSoffitta = 0;
int  statoStudio   = 0;

const int pinSoffitta =  9;                                         // Declare room-pin association.
const int pinStanza   = 12;                                         // Declare room-pin association.
const int pinEntrata  = 10;                                         // Declare room-pin association.
const int pinStudio   = 11;                                         // Declare room-pin association.
const int pinCucina   =  8;                                         // Declare room-pin association.
/* changes to try ***
import countable.h
import hashmap.h

CreateHashMap (room, char *, int, 3);
room ["Kitchen"] =  8;
room ["Bedroom"] = 12;
room ["Attic"]   =  9;
*/


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinEntrata, OUTPUT);    digitalWrite(pinEntrata, LOW);
  pinMode(pinCucina, OUTPUT);     digitalWrite(pinCucina, LOW);
  pinMode(pinStanza, OUTPUT);     digitalWrite(pinStanza, LOW);
  pinMode(pinSoffitta, OUTPUT);   digitalWrite(pinSoffitta, LOW);
  pinMode(pinStudio, OUTPUT);     digitalWrite(pinStudio, LOW);
}

void loop() {
  while (Serial.available() > 0) {
    lettera = Serial.read();
    Serial.println(lettera);
    Serial.println("Entrata: "  + (String)statoEntrata);
    Serial.println("Cucina: "   + (String)statoCucina);
    Serial.println("Stanza: "   + (String)statoStanza);
    Serial.println("soffitta: " + (String)statoSoffitta);
    Serial.println("Studio: "   + (String)statoStudio);
  }

 switch (lettera) {
  case 'A':
    // you clicked on "Entrata" room button, if state was ON this click made it OFF and viceversa.
    lettera=' ';
    digitalWrite( pinEntrata, !digitalRead(pinEntrata) );
    Serial.println("Stato Entrata: " + (String) digitalRead(pinEntrata));
    Serial.flush();
    break;
      
  case 'B':
    // you clicked on "Cucina" room button, if state was ON this click made it OFF and viceversa.
    lettera=' ';
    digitalWrite( pinCucina, !digitalRead(pinCucina) );
    Serial.println("Stato Cucina: " + (String) digitalRead(pinCucina));
    Serial.flush();
    break;
      
  case 'C':
    // you clicked on "Stanza" room button, if state was ON this click made it OFF and viceversa.
    lettera=' ';
    digitalWrite( pinStanza, !digitalRead(pinStanza) );
    Serial.println("Stato Stanza: " + (String) digitalRead(pinStanza));
    Serial.flush();
    break;
      
  case 'D':
    // you clicked on "Soffitta" room button, if state was ON this click made it OFF and viceversa.
    lettera=' ';
    digitalWrite( pinSoffitta, !digitalRead(pinSoffitta) );
    Serial.println("Stato Soffitta: " + (String) digitalRead(pinSoffitta));
    Serial.flush();
    break;
      
  case 'E':
    // you clicked on "Studio" room button, if state was ON this click made it OFF and viceversa.
    lettera=' ';
    digitalWrite( pinStudio, !digitalRead(pinStudio) );
    Serial.println("Stato Studio: " + (String) digitalRead(pinStudio));
    Serial.flush();
    break;
      
  default:
    Serial.println("Error: Wrong letter state");
    break;
 }
}
