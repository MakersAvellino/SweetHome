char lettera;
int  statoEntrata  = 0;
int  statoCucina   = 0;
int  statoStanza   = 0;
int  statoSoffitta = 0;
int  statoStudio   = 0;

const int pinSoffitta =  9;
const int pinStanza   = 12;
const int pinEntrata  = 10;
const int pinStudio   = 11;
const int pinCucina   =  8;

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
  // put your main code here, to run repeatedly:

  while (Serial.available() > 0) {
    lettera = Serial.read();
    Serial.println(lettera);
    Serial.println("Entrata: "  + (String)statoEntrata);
    Serial.println("Cucina: "   + (String)statoCucina);
    Serial.println("Stanza: "   + (String)statoStanza);
    Serial.println("soffitta: " + (String)statoSoffitta);
    Serial.println("Studio: "   + (String)statoStudio);
  }

  if (lettera == 'A') {
    lettera=' ';
    digitalWrite( pinEntrata, !digitalRead(pinEntrata) );
    Serial.println("Stato Entrata: " + (String) digitalRead(pinEntrata));
    Serial.flush();
  }

  if (lettera == 'B') {
    lettera=' ';
    digitalWrite( pinCucina, !digitalRead(pinCucina) );
    Serial.println("Stato Cucina: " + (String) digitalRead(pinCucina));
    Serial.flush();
  }


  if (lettera == 'C') {
    lettera=' ';
    digitalWrite( pinStanza, !digitalRead(pinStanza) );
    Serial.println("Stato Stanza: " + (String) digitalRead(pinStanza));
    Serial.flush();
  }


  if (lettera == 'D') {
    lettera=' ';
    digitalWrite( pinSoffitta, !digitalRead(pinSoffitta) );
    Serial.println("Stato Soffitta: " + (String) digitalRead(pinSoffitta));
    Serial.flush();
  }


  if (lettera == 'E') {
    lettera=' ';
    digitalWrite( pinStudio, !digitalRead(pinStudio) );
    Serial.println("Stato Studio: " + (String) digitalRead(pinStudio));
    Serial.flush();
  }
}
